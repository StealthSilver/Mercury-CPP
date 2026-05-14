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