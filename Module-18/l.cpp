#include <iostream>
#include <string>
using namespace std;

// Inheritance: a derived (child) class receives the data members and member
// functions of a base (parent) class. Use "is-a": Student is-a Person.

class Person {
protected:
    // visible inside Person and in derived classes (typical for inheritance)
    string name;
    int age;

public:
    Person(const string& n, int a) : name(n), age(a) {
        cout << "  [Person ctor] " << name << ", age " << age << "\n";
    }

    void introduce() const {
        cout << "    I am " << name << ", " << age << " years old.\n";
    }
};

// public inheritance: public members of Person stay public on Student;
// protected members of Person stay protected on Student.
class Student : public Person {
    string school;

public:
    Student(const string& n, int a, const string& s)
        : Person(n, a), school(s) {
        cout << "  [Student ctor] studies at " << school << "\n";
    }

    void study() const {
        cout << "    " << name << " is studying at " << school << ".\n";
    }
};

int main() {
    cout << "1) Derived object has base + own parts (constructors: base first).\n\n";
    Student s("Alex", 17, "Mercury High");
    cout << "\n2) Methods from the base class are available on the derived object:\n";
    s.introduce();
    cout << "\n3) Methods defined only in the derived class:\n";
    s.study();

    cout << "\n4) A Student *is-a* Person in an \"is-a\" sense — same public interface "
            "plus extension.\n";
    return 0;
}
