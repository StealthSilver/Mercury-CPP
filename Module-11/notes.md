# DSA with C++ — Module 11 Notes

data structures are just a way of arranging data

ARRAYS : they are a linear data structure of same kind of elements that are stored together in contiguous memory spaces

arrays have indexes -> they start from 0
array of length 7 - 7 values can be stored will have indices from 0 to 6

CREATING AN ARRAY

int marks[50];

type name[size]; -> upon initializing the array it is filled with garbage values until the values are entered.

Memory is statically allocated at compile time

1. int marks[50]; -> all values are garbage values upon initialising -> a.cpp
2. int marks[50] = {1,2,3} -> remaining values are 0 -> b.cpp
3. int marks[] = {1,2,3,4} -> automatically array of size 4 is created -> c.cpp

cout << sizeof(marks) << endl; -> this gives the bytes that are allocated to the array
for getting the length of the array

sizeof(array) / sizeof(int)

OUTPUT AND INPUT IN ARRAY

d.cpp -> output the elements of the array
e.cpp -> input the elements in the array

f.cpp -> creating the array of n size taken from user at the runtime , this was not possible in the earlier versions of c++

g.cpp -> find the largest in the array and smallest in the array

ARRAYS ARE PASSED BY REFERENCE -> h.cpp

in c++ the array name can be converted into a pointer

the name of hte array is a pointer pointing at hte 0th index
