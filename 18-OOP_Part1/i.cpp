#include <iostream>
#include <string>
using namespace std;

class Sample {
    int id;
    string name;

public:
    Sample(int i, const string& n) : id(i), name(n) {
        cout << "  [normal ctor] Sample(" << id << ", \"" << name << "\")\n";
    }

    // Copy constructor: `other` is the object being copied from.
    // If you omit it, the compiler generates one that copies each member.
    Sample(const Sample& other) : id(other.id), name(other.name) {
        cout << "  [copy ctor]   new object copied from id=" << other.id << "\n";
    }

    void print() const { cout << "    -> id=" << id << " name=\"" << name << "\"\n"; }
};

// Passing by value copies the argument — copy constructor runs for `w`.
void showByValue(Sample w) {
    cout << "  inside showByValue:\n";
    w.print();
}

int main() {
    cout << "1) One object, normal constructor\n";
    Sample a(10, "alpha");
    a.print();

    cout << "\n2) Copy initialization: `Sample b = a;` (copy constructor)\n";
    Sample b = a; // same as: Sample b(a);
    b.print();

    cout << "\n3) Function call with pass-by-value (copy constructor for the parameter)\n";
    showByValue(a);

    cout << "\n4) After the call, original `a` is unchanged (it was a copy that was passed)\n";
    a.print();

    return 0;
}
