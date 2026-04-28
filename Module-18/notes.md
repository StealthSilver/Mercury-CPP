# DSA with C++ — Module 18 Notes

OBJECT ORIENTED PROGRAMMING (OOPS)

This is an approach of writing code. In OOPs we create Object and Classes and then write the algorithms

Classes : group of entities
Objects : perticular entities from the group

Object have different properties / attributes associated with them
also there are Functions / Member functions / methods also associated with them

Classes are the blueprints to create objects -> a.cpp , b.cpp

four major concepts in OOPs are 
1. Encaptulation
2. Inheritance
3. Abstraction
4. Polymorphism

ACCESS MODIFIERS : c.cpp

private
data & methods accessible inside class and the friend functions
sensitive properties are stored here 

• public
data & methods accessible to everyone


• protected
data & methods accessible inside class & to its derived class
this is used when we inherit a class

by default all the methods and properties are private and can only be accessed inside the class

GETTERS AND SETTERS -> d.cpp

they are the special methods 

as we cannot access the properties directly so we get and set them using these funcitons

ENCAPTULATION -> d.cpp

Encapsulation is wrapping up of data & member functions (methods) in a single unit.
It also implements data hiding 

we use access modifiers for hiding the data

CONSTRUCTORS -> e.cpp

Special method invoked automatically at time of object creation. Used for Initialisation. The compiler automatically makes the constructor.
• Same name as class
• Constructor doesn't have a return type
• Only called once (automatically), at object creation
• Memory allocation happens when constructor is called

these can be parameterised and non parameterised constructors, by default the constructors are non parameterised

THIS POINTER -> f.cpp

this is a special pointer
this->prop is same as *(this).prop

CONSTRUCTOR OVERLOADING -> g.cpp

writing multiple constructors in the same class, the compiler automatically detects weatehr to call a parameterised constructor or non parameterised one

PRACTICE PROBLEMS -> h.cpp

Create a User class with properties: id (private), username(public) & password (private).
Its id should be initialized in a parameterised constructor.
It should have a Getter & Setter for password.