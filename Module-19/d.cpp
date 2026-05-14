// Illustration: virtual functions.
// A virtual member in the base class is one you *expect* derived classes to
// replace. The base may supply a default body (even empty: `virtual void hello() {}`)
// or leave the decision to overrides. Calls through Base* / Base& use the
// *dynamic type* of the object — the redefined version runs.

#include <iostream>

// --- 1) Virtual: derived can replace; base ref/ptr calls the real object's version.

class Greeter {
   public:
    // `virtual` marks this as overridable and participates in dynamic dispatch.
    // Empty body = "default is nothing"; subclasses are expected to fill in.
    virtual void hello() {}

    virtual ~Greeter() = default;
};

class EnglishGreeter : public Greeter {
   public:
    void hello() override { std::cout << "Hello!\n"; }
};

class SpanishGreeter : public Greeter {
   public:
    void hello() override { std::cout << "Hola!\n"; }
};

void greet_twice(Greeter& g) {
    g.hello();
    g.hello();
}

// --- 2) Not virtual: same pattern of "redefining" in the child, but no dynamic dispatch.

class Quiet {
   public:
    void hello() { std::cout << "Quiet: ...\n"; }
};

class Loud : public Quiet {
   public:
    void hello() { std::cout << "Loud: HEY!\n"; }
};

int main() {
    EnglishGreeter en;
    SpanishGreeter es;

    Greeter& r1 = en;
    r1.hello();  // EnglishGreeter::hello

    Greeter& r2 = es;
    r2.hello();  // SpanishGreeter::hello

    greet_twice(en);

    // Through Quiet&, the static type wins: Quiet::hello runs, not Loud::hello.
    Loud loud;
    Quiet& q = loud;
    q.hello();

    // Direct call on Loud still uses Loud::hello.
    loud.hello();

    return 0;
}
