#include <iostream>
#include <string>
using namespace std;

// Types of inheritance (see notes) — each block below is a separate pattern.

// ---------------------------------------------------------------------------
// 1) SINGLE INHERITANCE — one base class, one direct derived class
// ---------------------------------------------------------------------------
class Engine {
public:
    string kind = "generic";
    void ignite() const { cout << "    Engine::ignite (" << kind << ")\n"; }
};

class CarSingle : public Engine {
public:
    void drive() const {
        ignite();
        cout << "    CarSingle::drive\n";
    }
};

// ---------------------------------------------------------------------------
// 2) MULTI-LEVEL INHERITANCE — chain: Base -> Mid -> Leaf
// ---------------------------------------------------------------------------
class LivingThing {
public:
    void breathe() const { cout << "    LivingThing::breathe\n"; }
};

class Animal : public LivingThing {
public:
    void move() const { cout << "    Animal::move\n"; }
};

class Dog : public Animal {
public:
    void bark() const {
        breathe();
        move();
        cout << "    Dog::bark\n";
    }
};

// ---------------------------------------------------------------------------
// 3) MULTIPLE INHERITANCE — one derived class, two+ base classes
//    (notes: “properties of two or more base classes” combined in one derived)
// ---------------------------------------------------------------------------
class Drawable {
public:
    void draw() const { cout << "    Drawable::draw\n"; }
};

class Clickable {
public:
    void onClick() const { cout << "    Clickable::onClick\n"; }
};

class Button : public Drawable, public Clickable {
public:
    void use() const {
        draw();
        onClick();
        cout << "    Button::use (has both Drawable and Clickable)\n";
    }
};

// ---------------------------------------------------------------------------
// 4) HIERARCHICAL — one base, several independent derived classes (“siblings”)
// ---------------------------------------------------------------------------
class FileNode {
public:
    string name;
    explicit FileNode(const string& n) : name(n) {}
    void printName() const { cout << "    FileNode: " << name << "\n"; }
};

class TextFile : public FileNode {
public:
    explicit TextFile(const string& n) : FileNode(n) {}
    void edit() const {
        printName();
        cout << "    TextFile::edit\n";
    }
};

class ImageFile : public FileNode {
public:
    explicit ImageFile(const string& n) : FileNode(n) {}
    void render() const {
        printName();
        cout << "    ImageFile::render\n";
    }
};

// HYBRID — combination of patterns (e.g. multi-level + multiple in one design)
// TA is a Student (which is already a Person) and also an Employee.
class PersonH {
public:
    void id() const { cout << "    PersonH::id\n"; }
};

class StudentH : public PersonH {
public:
    void study() const { cout << "    StudentH::study\n"; }
};

class EmployeeH {
public:
    void work() const { cout << "    EmployeeH::work\n"; }
};

class TeachingAssistant : public StudentH, public EmployeeH {
public:
    void role() const {
        id();
        study();
        work();
        cout << "    TeachingAssistant::role (Student chain + Employee)\n";
    }
};

int main() {
    cout << "=== 1) Single inheritance (one base -> one derived) ===\n";
    CarSingle c;
    c.kind = "V6";
    c.drive();

    cout << "\n=== 2) Multi-level (LivingThing -> Animal -> Dog) ===\n";
    Dog d;
    d.bark();

    cout << "\n=== 3) Multiple inheritance (Drawable + Clickable -> Button) ===\n";
    Button b;
    b.use();

    cout << "\n=== 4) Hierarchical (FileNode -> TextFile, ImageFile) ===\n";
    TextFile t("notes.txt");
    t.edit();
    ImageFile i("pic.png");
    i.render();

    cout << "\n=== Hybrid (example: TA = StudentH<PersonH> + EmployeeH) ===\n";
    TeachingAssistant ta;
    ta.role();

    return 0;
}
