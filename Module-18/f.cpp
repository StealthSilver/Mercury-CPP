#include <iostream>
using namespace std;


class Box {
private:
    int width;
    int height;

public:
    Box() : width(0), height(0) {}

    // Same names for parameters and members — `this->` picks the members.
    Box& setDimensions(int width, int height) {
        this->width = width;
        this->height = height;
        return *this; // reference to this object (enables chaining below)
    }

    Box& grow(int delta) {
        this->width += delta;
        this->height += delta;
        return *this;
    }

    // `this` holds the address of the object used in the call.
    const Box* address() const { return this; }

    void show() const {
        cout << "  width=" << width << ", height=" << height << endl;
    }
};

int main() {
    Box b;

    cout << "1) Chaining: setDimensions then grow — each step returns *this\n";
    b.setDimensions(10, 20).grow(5);
    b.show();

    cout << "\n2) `this` inside member functions is the address of that object:\n";
    cout << "   &b == b.address()? " << ((&b == b.address()) ? "yes" : "no") << endl;

    Box b2;
    b2.setDimensions(3, 4);
    cout << "   &b2 == b2.address()? " << ((&b2 == b2.address()) ? "yes" : "no") << endl;

    return 0;
}
