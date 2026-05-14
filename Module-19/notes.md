# DSA with C++ — Module 18 Notes

OOPS PART 2

POLYMORPHISM
Polymorphism is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used.

constructor overloading is a type of polymorphism

there are two types 

1. compile time polymorphism
2. run time polymorphism

COMPILE TIME POLYMORPHISM
decided at the compile time

1. function overloading  -> a.cpp
the parameter inside the function decides which function will be called even if the functions have same name

2. operator overloading -> b.cpp
the operator name will be same but it will be defined and used in different ways

complex numbers can be created this way

returnType operator opSymbol(){....}

RUN TIME POLYMORPHISM 
decided on the runtime

1. Function Overriding -> c.cpp
Parent & Child both contain the same function with different implementation.
The parent class function is said to be ovverridden

2. Virtual Funcions -> d.cpp
A virtual function is a member function that you expect to be redefined in derived classes.

virtual void hello(){}

child function >> inheritance 

1. Virtual functions are Dynamic in nature.
2. Defined by the keyword "virtual" inside a base class and are always declared with a base class and overridden in a child class.
3. A virtual function is called during Runtime

4. ABSTRACTION

Hiding all unnecessary details & showing only the important parts


Abstract Classes & Pure Virtual Functions & access specifieers are a type of implementing abstraction 

ABSTRACT CLASS -> e.cpp
this class's only job is to do inheritaqnce it does not crete its own objects but jsut crates a blueprrint for the child class 

it has at least one pure virtual function

1. Abstract classes are used to provide a base class from which other classes can be derived.
2. They cannot be instantiated (create own objects) and are meant to be inherited.
3. Abstract classes are typically used to define an interface for derived classes

PURE VIRTUAL FUNCTIONS -> f.cpp

A pure virtual function (or abstract function) is a virtual function with no definition/ logic.
It is declared by assigning O at the time of decleration

virtual void fucntion() = 0;

STATIC KEYWORD

Static Variables -> g.cpp
Variables declared as static in a function are created & initialised once for the lifetime of the program. //in Function

Static variables in a class are created & initialised once. They are shared by all the objects of the class. //in Class

Static Objects -> h.cpp

static Example eg1

FRIEND CLASS AND FRIEND FUNCTIONS -> i.cpp
A friend class or a friend function can access private and protected members of other classes in which it is declared as a friend.

PRACTICE QUESTION -> j.cpp
PRACTICE QUESTION -> k.cpp
PRACTICE QUESTION -> l.cpp
Create a class to store Complex numbers. Using operator overloading,
create the logic to subtract one complex number from another.
Note - In Complex numbers, the real part of 1st gets subtracted from the real part of
2nd number. Same goes for the imaginary part.

PRACTICE QUESTION -> m.cpp
Create a class BankAccount with private attributes accountNumber and
balance. Implement public methods deposit(), withdraw(), and getBalance() to
manage the account.

PRACTICE QUESTION -> n.cpp
Create a base class Person with attributes name and age.
Derive a class Student from Person and add an additional attribute studentID.
Implement a method displayStudentInfo( ) in the Student class to display all details.
In main function Student class object will be created in this format:
Student student("Alice", 20, "S12345");