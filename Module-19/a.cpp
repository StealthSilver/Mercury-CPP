// Illustration: function overloading (compile-time polymorphism).
// The compiler picks which function to call from the argument types/count
// at the call site — same name, different parameter lists.

#include <iostream>
#include <string>

// Three overloads of `show` — the name is the same; parameters differ.
void show(int x) {
    std::cout << "show(int): " << x << "\n";
}

void show(double x) {
    std::cout << "show(double): " << x << "\n";
}

void show(int a, int b) {
    std::cout << "show(int, int): " << a << ", " << b << "\n";
}

// Overloads can differ by number of parameters and types.
int compute(int a, int b) {
    std::cout << "compute(int, int) -> sum\n";
    return a + b;
}

double compute(double a, double b) {
    std::cout << "compute(double, double) -> product\n";
    return a * b;
}

int main() {
    show(42);           // resolves to show(int)
    show(3.14);         // resolves to show(double)
    show(1, 2);         // resolves to show(int, int)

    std::cout << "result: " << compute(10, 20) << "\n";
    std::cout << "result: " << compute(2.0, 3.0) << "\n";

    // Literal 5 is int, 6 is int -> compute(int, int)
    // Literal 5.0 is double, 6.0 is double -> compute(double, double)
    return 0;
}
