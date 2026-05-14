// Illustration: function overriding (runtime polymorphism).
// Parent and child define a member with the same name and same parameter list.
// The child's version replaces ("overrides") the parent's for dynamic dispatch
// when the base function is virtual. Without `virtual`, the parent's body
// would still run when calling through a Base* / Base&.

#include <iostream>
#include <memory>

class Animal {
   public:
    // `virtual` lets the program decide at runtime which `speak` to run,
    // using the actual type of the object (Dog, Cat, ...).
    virtual void speak() const {
        std::cout << "Animal: (generic sound)\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
   public:
    // Same signature as Animal::speak — this overrides the parent.
    // `override` is optional but catches signature mistakes at compile time.
    void speak() const override {
        std::cout << "Dog: woof\n";
    }
};

class Cat : public Animal {
   public:
    void speak() const override {
        std::cout << "Cat: meow\n";
    }
};

// Works on any Animal subclass: always calls the *object's* speak().
void listen(const Animal& creature) {
    creature.speak();
}

int main() {
    Dog dog;
    Cat cat;

    // Direct call: type is known at compile time — Dog::speak.
    dog.speak();

    // Polymorphic call: reference is Animal&, object is Dog — Dog::speak.
    Animal& as_animal = dog;
    as_animal.speak();

    listen(cat);

    // Same idea with a pointer to Base, object on the heap.
    std::unique_ptr<Animal> ptr = std::make_unique<Dog>();
    ptr->speak();

    return 0;
}
