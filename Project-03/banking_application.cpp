/*
 * =============================================================================
 * PROJECT TITLE: Banking Application (Educational Demo)
 * =============================================================================
 *
 * Single-file teaching project: OOP + exceptions + basic concurrency.
 *
 * Concepts
 * --------
 *   Encapsulation        — balances, PIN, fraud counters, and history are not
 *                          public fields; the class exposes a small, safe API.
 *   Polymorphism         — `SavingsAccount` / `CurrentAccount` share `Account*`;
 *                          virtual hooks (`productName`, interest policy, withdraw
 *                          policy) behave differently per runtime type.
 *   Exception handling — typed errors for bad input, auth, funds, fraud rules.
 *
 * Classes
 * -------
 *   Transaction, Account (abstract), SavingsAccount, CurrentAccount
 *
 * Features
 * --------
 *   Deposit / withdraw, interest (savings), history, PIN auth
 *
 * Advanced twists
 * ---------------
 *   Multi-user concurrency — threads + `mutex` on shared account operations
 *   Fraud detection        — wrong-PIN lockout, rapid-withdraw burst, large-tx block
 *
 * Build:  g++ -std=c++17 -pthread -Wall -Wextra banking_application.cpp -o banking
 * Run:    ./banking
 */

#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

using namespace std;

// -----------------------------------------------------------------------------
// Exception handling — small hierarchy (catch `BankingError` or specific types).
// -----------------------------------------------------------------------------
struct BankingError : public runtime_error {
    explicit BankingError(const string& msg) : runtime_error(msg) {}
};

struct InvalidAmountError : public BankingError {
    explicit InvalidAmountError(const string& msg) : BankingError(msg) {}
};

struct InsufficientFundsError : public BankingError {
    explicit InsufficientFundsError(const string& msg) : BankingError(msg) {}
};

struct AuthError : public BankingError {
    explicit AuthError(const string& msg) : BankingError(msg) {}
};

struct FraudError : public BankingError {
    explicit FraudError(const string& msg) : BankingError(msg) {}
};

// -----------------------------------------------------------------------------
// Transaction — one immutable log line (encapsulation: data + accessors).
// -----------------------------------------------------------------------------
enum class TxKind { Deposit, Withdraw, Interest, Fee };

string toString(TxKind k) {
    switch (k) {
        case TxKind::Deposit: return "DEPOSIT";
        case TxKind::Withdraw: return "WITHDRAW";
        case TxKind::Interest: return "INTEREST";
        case TxKind::Fee: return "FEE";
    }
    return "?";
}

class Transaction {
    TxKind kind_;
    double amount_;
    string note_;
    string ts_;

    static string nowStamp() {
        using clock = chrono::system_clock;
        const auto t = clock::to_time_t(clock::now());
        tm local{};
#if defined(_WIN32)
        localtime_s(&local, &t);
#else
        localtime_r(&t, &local);
#endif
        ostringstream os;
        os << put_time(&local, "%Y-%m-%d %H:%M:%S");
        return os.str();
    }

public:
    Transaction(TxKind k, double amt, string note)
        : kind_(k), amount_(amt), note_(std::move(note)), ts_(nowStamp()) {}

    string describe() const {
        ostringstream os;
        os << "[" << ts_ << "] " << setw(8) << left << toString(kind_) << " "
           << fixed << setprecision(2) << amount_ << "  " << note_;
        return os.str();
    }

    TxKind kind() const { return kind_; }
    double amount() const { return amount_; }
};

// -----------------------------------------------------------------------------
// Account — abstract base: shared rules + mutex + polymorphic hooks.
// -----------------------------------------------------------------------------
class Account {
    string id_;
    int pin_;
    double balance_;
    vector<Transaction> history_;
    mutable mutex mtx_;

    int failedPinAttempts_{0};
    bool locked_{false};
    deque<chrono::steady_clock::time_point> recentWithdrawals_;

    static constexpr int kMaxPinFails = 3;
    static constexpr int kMaxRapidWithdraws = 4;
    static constexpr auto kRapidWindow = chrono::seconds(2);
    static constexpr double kLargeTx = 5000.0;

    void requireUnlocked() const {
        if (locked_) {
            throw FraudError("Account locked after suspicious activity.");
        }
    }

    void recordUnderLock(TxKind k, double amt, const string& note) {
        history_.emplace_back(k, amt, note);
    }

protected:
    // Must be called with `mtx_` held.
    double balanceUnderLock() const { return balance_; }

    // Default: no interest. Savings overrides.
    virtual double computeInterestUnderLock() const { return 0.0; }

    // Shared withdraw path: fraud checks + optional overdraft (current accounts).
    void withdrawWithLimit(double amount, const string& actor, double overdraftAllowance) {
        if (amount <= 0.0) {
            throw InvalidAmountError("Withdraw amount must be positive.");
        }
        requireUnlocked();
        if (amount >= kLargeTx) {
            throw FraudError("Large withdrawal blocked — verify in branch.");
        }
        const auto now = chrono::steady_clock::now();
        while (!recentWithdrawals_.empty() && now - recentWithdrawals_.front() > kRapidWindow) {
            recentWithdrawals_.pop_front();
        }
        recentWithdrawals_.push_back(now);
        if (static_cast<int>(recentWithdrawals_.size()) > kMaxRapidWithdraws) {
            locked_ = true;
            throw FraudError("Rapid withdrawal burst — account locked.");
        }
        const double available = balance_ + overdraftAllowance;
        if (amount > available) {
            throw InsufficientFundsError("Insufficient funds (including overdraft, if any).");
        }
        balance_ -= amount;
        recordUnderLock(TxKind::Withdraw, amount, "Withdraw by " + actor);
    }

public:
    Account(string id, int pin, double opening) : id_(std::move(id)), pin_(pin), balance_(0.0) {
        lock_guard<mutex> lock(mtx_);
        if (opening < 0.0) {
            throw InvalidAmountError("Opening balance cannot be negative.");
        }
        balance_ = opening;
        recordUnderLock(TxKind::Deposit, opening, "Account opened");
    }

    virtual ~Account() = default;

    virtual string productName() const = 0;

    string id() const { return id_; }

    bool authenticate(int pinAttempt) {
        lock_guard<mutex> lock(mtx_);
        requireUnlocked();
        if (pinAttempt != pin_) {
            ++failedPinAttempts_;
            if (failedPinAttempts_ >= kMaxPinFails) {
                locked_ = true;
                throw FraudError("Too many wrong PIN attempts — account locked.");
            }
            throw AuthError("Wrong PIN.");
        }
        failedPinAttempts_ = 0;
        return true;
    }

    void deposit(double amount, const string& actor) {
        if (amount <= 0.0) {
            throw InvalidAmountError("Deposit amount must be positive.");
        }
        lock_guard<mutex> lock(mtx_);
        requireUnlocked();
        if (amount >= kLargeTx) {
            throw FraudError("Large deposit blocked by fraud rules — split the amount.");
        }
        balance_ += amount;
        recordUnderLock(TxKind::Deposit, amount, "Deposit by " + actor);
    }

    virtual void withdraw(double amount, const string& actor) {
        lock_guard<mutex> lock(mtx_);
        withdrawWithLimit(amount, actor, 0.0);
    }

    void applyMonthlyInterest() {
        lock_guard<mutex> lock(mtx_);
        requireUnlocked();
        const double intr = computeInterestUnderLock();
        if (intr > 0.0) {
            balance_ += intr;
            recordUnderLock(TxKind::Interest, intr, "Monthly interest accrual");
        }
    }

    void printHistory(size_t maxLines = 15) const {
        lock_guard<mutex> lock(mtx_);
        cout << "  --- History for " << id_ << " (" << productName() << ") ---\n";
        const size_t n = history_.size();
        const size_t start = n > maxLines ? n - maxLines : 0;
        for (size_t i = start; i < n; ++i) {
            cout << "    " << history_[i].describe() << "\n";
        }
    }

    double snapshotBalance() const {
        lock_guard<mutex> lock(mtx_);
        return balance_;
    }

    void printSummary() const {
        lock_guard<mutex> lock(mtx_);
        cout << "  [" << productName() << "] " << id_
             << "  balance=" << fixed << setprecision(2) << balance_
             << (locked_ ? "  STATUS=LOCKED" : "") << "\n";
    }
};

// -----------------------------------------------------------------------------
// SavingsAccount — interest-bearing; demonstrates `override` + virtual hook.
// -----------------------------------------------------------------------------
class SavingsAccount : public Account {
    double annualRate_;

public:
    SavingsAccount(string id, int pin, double opening, double annualRate)
        : Account(std::move(id), pin, opening), annualRate_(annualRate) {
        if (annualRate < 0.0 || annualRate > 0.25) {
            throw InvalidAmountError("Unrealistic annual rate for this demo.");
        }
    }

    string productName() const override { return "Savings"; }

protected:
    double computeInterestUnderLock() const override {
        const double b = balanceUnderLock();
        if (b <= 0.0) {
            return 0.0;
        }
        return b * (annualRate_ / 12.0);
    }
};

// -----------------------------------------------------------------------------
// CurrentAccount — overdraft-aware withdraw (polymorphism on `withdraw`).
// -----------------------------------------------------------------------------
class CurrentAccount : public Account {
    double overdraftLimit_;

public:
    CurrentAccount(string id, int pin, double opening, double overdraftLimit)
        : Account(std::move(id), pin, opening), overdraftLimit_(overdraftLimit) {
        if (overdraftLimit < 0.0) {
            throw InvalidAmountError("Overdraft limit cannot be negative.");
        }
    }

    string productName() const override { return "Current"; }

    void withdraw(double amount, const string& actor) override {
        lock_guard<mutex> lock(const_cast<mutex&>(static_cast<const Account&>(*this).id().empty() ? mtx_unused() : mtx_unused()));
    }

private:
    mutex mtx_unused() {
        static mutex dummy;
        return dummy;
    }
};
