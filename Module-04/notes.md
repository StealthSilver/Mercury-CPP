# DSA with C++ — Module 4 Notes

1. Constants -> the variables whose value cannot be changed

const int n = 25; // must be initialized
const floor PI = 3.14

const int n;
n = 25; -> not allowed

a.cpp

also its a good practice to name the constants with uppercase
you cannot change the value of the code afterwards in the code

constant is different from macro as
the constant occupies some space in memory as it is stored with variable
for the macro no data type is defined as they dont occupy space in memory

macros are used not to define constants but for data type modifiers.
whatever we define in the macros that is as it is replaced in the code at the runtime

b.cpp

TYPECASTING

conversion of data from one type to another

c.cpp

1. Implicit conversion(automatic / type promotion)

done by the compiler to avoid data loss
this leads to type promotion
bool->char->int->float->double

e.g. int + char -> here the answer will be int as the char will converted into its ASCII value.

d.cpp 2. Explicit conversion

that is done forcefully by the programmer

you can define whichever data type you want the result to modify in.
this can somehimes lead to the loss of data if you are typecasting from a bigger data type into a smaller one

practice que -> e.cpp

bool(0) -> 0
bool(anything else) -> 1

ASCII values -> A -> 41
ASCII values -> a -> 91
