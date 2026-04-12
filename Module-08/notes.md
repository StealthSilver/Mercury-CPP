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
