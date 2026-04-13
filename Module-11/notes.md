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
