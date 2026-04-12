# DSA with C++ — Module 8 Notes

FUNCTIONS - a.cpp

it is a block of code that runs when it is called.

returnType FName(){
// do some work
return someValue; // optional
}

fNmae(); //function call

the functions that dont return anything have hte data type of void.

the execution starts from the main function and then inside the main funciton it one by one calls the other functions.

b.cpp -> calling funciton indirectly

FORWARD DECLERATION -> c.cpp

Decleration : the function's name, return type and parameters (if any);
Defination : the body of the function

you have to declare the functions before the main function, you cna define it later, but decleration must be done before the main function

PARAMETERS -> d.cpp

they are the values that are required by the function for the logic to run.

returnType fName(type param1, type aram2 ...){
// do some work
return someValue;
}

Arguments are the variables that are passed in the function for hte parameters

default parameter -> e.cpp

we can give a default value to the parameters that if any value is not passed then it will take the default value

we can never make the first parameter as the dafault parameter

f.cpp -> function for product of 2 numbers
g.cpp -> function for even odd checking
h.cpp -> factorial of a number

FUNCTIONS IN THE MEMORY

there are two kind of memories, stack (for static memory) , heap (dynamic memory)
stack is the stack (one ontop of other addreses). when a function is executed then a layer is created in the stack called stack frame. all the variables and the parameters of the function are stored in stack frame.

even for main function stack frame is allocated
other functions are created over the main functions stack frame.

when the function retrurs then that stack frame is deleted. the current function is always at the top

SCOPE : this is the region where the variable can be used

there are local and global scope

if a variable is defined in a function can only be used inside the function

there are local scopes, for functions, loops, if-else, or general {}

you can define variables in the global scope outside any funciton in the top of the file

i.cpp -> prime no checker
j.cpp -> binomial coefficient

FUNCTION OVERLOADING

when we have multiple funcitons with the same name but different parameters
k.cpp -> why overloading is necessaey

different parameters can be in two ways : 1 - the type is different , 2 - no. of parameters

for both of them we can just use the same function names. the complier will itself detect which funciton to use when

there cannot be differece in the return type

m.cpp -> printing primes in range 2 to n

n.cpp -> pallindrome checker

o.cpp -> sum of hte digits

p.cpp -> printing character after the given character

q.cpp -> max of three numbers

r.cpp -> finding the whole square
