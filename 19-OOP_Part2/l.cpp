// Practice: Complex numbers with operator overloading for subtraction.
// For z1 - z2 (usual C++ / math convention):
//   Re(z1 - z2) = Re(z1) - Re(z2)
//   Im(z1 - z2) = Im(z1) - Im(z2)
// i.e. subtract the right-hand side from the left-hand side, component-wise.

#include <iostream>

class Complex {
   public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
};

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
    Complex a(5.0, 3.0);   // 5 + 3i
    Complex b(2.0, 1.0);   // 2 + 1i
    Complex diff = a - b;  // (5-2) + (3-1)i = 3 + 2i

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a - b = " << diff << "\n";

    return 0;
}
