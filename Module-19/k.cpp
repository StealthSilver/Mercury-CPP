// ---------------------------------------------------------------------------
// Question (original had typos: `<<` not `<` or `«`, `};` not `7;`,
// `class Derived : public Base {` not `Base 1 public:`, `b->print()` not `b-›print()`,
// and `main`/braces must be correct.)
//
// `Base` has `virtual void print()` printing "Base".
// `Derived` overrides `print()` printing "Derived".
// In `main`:
//   Base* b = new Derived();
//   b->print();
//   delete b;
//
// Predict the line(s) printed by `b->print()`.
// Extra: why must `Base` have a `virtual` destructor here?
// ---------------------------------------------------------------------------

#include <iostream>

class Base {
   public:
    virtual void print() { std::cout << "Base" << std::endl; }

    virtual ~Base() = default;  // required for `delete b` when `b` points to Derived
};

class Derived : public Base {
   public:
    void print() override { std::cout << "Derived" << std::endl; }
};

int main() {
    Base* b = new Derived();
    b->print();
    delete b;
    return 0;
}

// --- Answer (predict first, then: c++ -std=c++17 -o k k.cpp && ./k) ----------
// Derived
//
// `print` is virtual, so `b->print()` uses the *dynamic* type (Derived) even
// though the pointer type is Base* — runtime polymorphism.
//
// Without `virtual ~Base()`, `delete b` would be undefined behavior because only
// Base's destructor would be invoked for a Derived object.
