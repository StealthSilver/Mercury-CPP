// Illustration: operator overloading (compile-time polymorphism).
// The symbol (+, <<, etc.) is the same as for built-in types, but for your
// class you supply a function that defines what the operator *means*.
// The compiler picks the right overload from the operand types.

#include <iostream>

class Complex {
   public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // `+` between two Complex values — same token as int+int, different meaning.
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Scalar on the right: c + 3  means add 3 to the real part (illustration).
    Complex operator+(double scalar) const {
        return Complex(real + scalar, imag);
    }
};

// `<<` for printing — must be a free function so std::cout is on the left.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i";
    } else {
        os << " - " << (-c.imag) << "i";
    }
    return os;
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -1.0);

    // Built-in: + adds integers.
    int x = 5 + 7;
    std::cout << "int + int: " << x << "\n";

    // Overloaded: + combines complex parts according to our rules.
    Complex sum = a + b;
    std::cout << "Complex + Complex: " << sum << "\n";

    Complex shifted = a + 10.0;  // uses operator+(double)
    std::cout << "Complex + double: " << shifted << "\n";

    // << prints ints differently from Complex (different overloads of <<).
    std::cout << "cout << int: " << 42 << "\n";
    std::cout << "cout << Complex: " << a << "\n";

    return 0;
}
