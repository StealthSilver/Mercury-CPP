// Illustration: friend functions and friend classes.
//
// `friend` grants selected code access to private and protected members of this
// class. Friendship is *not* mutual and *not* inherited — it is declared only
// inside the class that opens its internals.

#include <iostream>
#include <string>

class Wallet {
    // This free function may read private members of Wallet.
    friend void print_balance(const Wallet& w);

    // Every member of Auditor may access private/protected parts of Wallet.
    friend class Auditor;

   public:
    Wallet(std::string owner, double balance)
        : owner_(std::move(owner)), balance_(balance) {}

   private:
    std::string owner_;
    double balance_;
};

// Definition after Wallet is complete — allowed to touch private fields.
void print_balance(const Wallet& w) {
    std::cout << "print_balance (friend): " << w.owner_ << " has $" << w.balance_
              << "\n";
}

class Auditor {
   public:
    static void inspect(const Wallet& w) {
        std::cout << "Auditor::inspect (friend class): private balance is "
                  << w.balance_ << "\n";
    }

    static void adjust(Wallet& w, double delta) {
        w.balance_ += delta;  // friend class can even modify private data
        std::cout << "Auditor adjusted balance by " << delta << "\n";
    }
};

void try_outsider(const Wallet& w) {
    (void)w;
    // Outsiders cannot use w.balance_ or w.owner_ — uncomment to see errors:
    // std::cout << w.balance_;
}

int main() {
    Wallet w("Ada", 100.0);
    print_balance(w);
    Auditor::inspect(w);
    Auditor::adjust(w, 25.0);
    print_balance(w);
    try_outsider(w);
    return 0;
}
