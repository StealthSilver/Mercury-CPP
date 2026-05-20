// Practice: BankAccount with private fields and public deposit / withdraw /
// getBalance.

#include <iostream>
#include <string>

class BankAccount {
   public:
    BankAccount(std::string account_number, double initial_balance = 0.0)
        : account_number_(std::move(account_number)),
          balance_(initial_balance < 0 ? 0.0 : initial_balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    // Returns false if amount invalid or insufficient funds.
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance_) {
            return false;
        }
        balance_ -= amount;
        return true;
    }

    double getBalance() const { return balance_; }

   private:
    std::string account_number_;
    double balance_;
};

int main() {
    BankAccount acct("ACC-1001", 100.0);
    std::cout << "balance: " << acct.getBalance() << "\n";

    acct.deposit(50.0);
    std::cout << "after deposit 50: " << acct.getBalance() << "\n";

    if (acct.withdraw(30.0)) {
        std::cout << "withdraw 30 ok, balance: " << acct.getBalance() << "\n";
    }

    if (!acct.withdraw(500.0)) {
        std::cout << "withdraw 500 failed (insufficient funds), balance: "
                  << acct.getBalance() << "\n";
    }

    return 0;
}
