// Illustration: abstract classes.
// An abstract class is a base type used as a *blueprint*: it defines an interface
// (what every "shape" must be able to do) but you do not create standalone
// objects of that exact type. It has at least one *pure virtual* function:
//     virtual ReturnType name(...) = 0;
// The `= 0` means "no implementation here — concrete subclasses must provide one."
// Until they do, those subclasses stay abstract too.

#include <iostream>
#include <memory>
#include <vector>

class Shape {
   public:
    // Pure virtual: forces every concrete child to implement `area`.
    virtual double area() const = 0;

    virtual void describe() const = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
   public:
    explicit Circle(double radius) : r_(radius) {}

    double area() const override { return 3.14159265 * r_ * r_; }

    void describe() const override {
        std::cout << "Circle(r=" << r_ << "), area=" << area() << "\n";
    }

   private:
    double r_;
};

class Rectangle : public Shape {
   public:
    Rectangle(double width, double height) : w_(width), h_(height) {}

    double area() const override { return w_ * h_; }

    void describe() const override {
        std::cout << "Rectangle(" << w_ << " x " << h_ << "), area=" << area()
                  << "\n";
    }

   private:
    double w_;
    double h_;
};

void print_any_shape(const Shape& s) {
    s.describe();
}

int main() {
    // You cannot instantiate `Shape` — it is abstract (uncomment to see errors):
    // Shape generic;  // error: variable type 'Shape' is an abstract class

    Circle c(2.0);
    Rectangle r(3.0, 4.0);

    c.describe();
    r.describe();

    // Polymorphic collection: only the abstract *pointer/reference* type is shared.
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(1.0));
    shapes.push_back(std::make_unique<Rectangle>(2.0, 5.0));

    std::cout << "Through Shape*:\n";
    for (const auto& p : shapes) {
        print_any_shape(*p);
    }

    return 0;
}
