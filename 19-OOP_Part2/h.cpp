// Illustration: static objects (static storage duration).
//
// `static Example eg1` can appear at namespace scope or inside a function.
// Such an object lives for the whole program: one instance, destroyed after
// `main` returns (destructors run in reverse order of construction).
//
// Block-scope `static Example eg1` is built the *first time* execution reaches
// that line; later calls skip construction and reuse the same object.

#include <iostream>

class Example {
   public:
    explicit Example(const char* label) : label_(label) {
        std::cout << "  Example ctor: " << label_ << "\n";
    }

    ~Example() { std::cout << "  Example dtor:  " << label_ << "\n"; }

    const char* label() const { return label_; }

   private:
    const char* label_;
};

// File-scope static objects: created before `main` (after zero-init), in order
// of definition within this translation unit.
static Example eg_file_a("eg_file_a (namespace static)");
static Example eg_file_b("eg_file_b (namespace static)");

void use_local_static() {
    // `static Example eg1` — constructed once, first time this function runs.
    static Example eg1("eg1 inside use_local_static()");
    std::cout << "    use_local_static() using " << eg1.label() << "\n";
}

int main() {
    std::cout << "main() starts\n";

    std::cout << "first call:\n";
    use_local_static();

    std::cout << "second call (no second ctor for eg1):\n";
    use_local_static();

    std::cout << "main() ends\n";
    // dtors: block static eg1, then eg_file_b, then eg_file_a (reverse of
    // completion of their construction — local static completes before main ends).
    return 0;
}
