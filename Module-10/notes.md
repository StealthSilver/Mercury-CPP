# DSA with C++ — Module 10 Notes

POINTERS

when a variable is declared the memory is assigned to that variable depending on the size of that variable

every memory location have different addresses in the form of hexadecimal system (base 16) [0 - 9 , a - f]

ADDRESS of Operator -> a.cpp

"&" gives hte address of a variable

&a is equal to -> address of a

Pointers are special variables that store address of another variable -> b.cpp

int \*ptr = &a;

float\* ptr = &b;

char \* ptr = &c;

pointers can be of any data type

the size of pointers in always 8 bytes.

also when the pointer is created it takes 8 bytes in memory. so a new address of 8 bytes is given to the pointer as a variable and the address of hte original variable is stored in the memory location assigned to the pointer

we can also make pointers of pointer -> c.cpp
int \*\*pptr = &ptr;

DEREFRENCE OPERATOR -> d.cpp

gets the value of the variable pointed by any pointer;

\* operator lets us directly access & modify the value of variable.

int a =10;
int \*ptr = &a

\*ptr will be equal to 10

NULL POINTER -> e.cpp

we assign NULL value to apointer to show that it dosen't point to any location.

int \*ptr = NULL;

derefrencing null prt is not possible as it'll result in an error

we use this when we dont want to store any value currently.

0 address is stored at the null pointer and derefrencing it gives a special type of error called the segmentation fault and code execution stops here

we can store values in null pointer later is we want to

PASSING ARGUMENTS

1. pass by value -> f.cpp
   when parameter is a copy of actual argument variable in memory

   here the value does not changes as the passed variable is a copy of original

2. pass by refrence (pass by address) -> g.cpp
   when we pass the reference of argument to the function

   there are two ways to pass by reference

   a. pass by pointers
   b. pass by referece variable

the changes in the copy are reflected as the changes are directly made on the address in the memory
