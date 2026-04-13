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

ARRAYS ARE PASSED BY REFERENCE

in c++ the array name can be converted into a pointer

the name of the array is a pointer pointing at hte 0th index -> h.cpp

passing the array name is equivalent to passing the pointer -> i.cpp

void printArr(int arr[]){...}
void printArr(int \*arr){...}
both of the above syntax are same

pasing an array in a function -> j.cpp

in the function only the pointer is passed so there is no array in the other function.
we need to manually pass the size of array in teh other function as we cannot access the size of array from the other function in any possible way

LINEAR SEARCH -> k.cpp

we can apply linear search on \sorted or unsorted array. we traverse the array until we find the key.
if the key does not exist then -1 is returned

time complexity -> O(n)

space complexity -> O(1)

REVERSE AN ARRAY

l.cpp -> with extra space (we create a duplicate array and then reverse the array)

time complexity -> O(n)
space complexity -> O(n)

m.cpp -> without extra space

time complexity -> O(n)
space complexity -> O(1)

we use swap for this

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        or we use the inbuit swap function
        swap(start , end);

BINARY SEARCH

It works only for a sorted array or sorted values.

Sorted array is a prerequisite.

## Number of Iterations

If after each step the array size becomes half:

n / 2^x = 1

(when only one element remains)

n = 2^x

x = log₂(n)

So total iterations:

x + 1 = log₂(n) + 1

Ignoring constants, complexity is **log n**.

Complexities

Time Complexity: O(log n)

Space Complexity: O(1) for iterative binary search

Space Complexity: O(log n) for recursive binary search (due to recursion stack)

ARRAY POINTER

array pointer acts like a constant pointer

int arr[5];
cout<<arr<<endl;
int y = 25;
arr = &y;

this operation is not possible as we cannot change arr, it will always point to the 0th element of the array

POINTER ARITHMETIC

Increment & Decrement Operators -> o.cpp

ptr ++ or ++prt
ptr-- or --ptr

any of the increment and the decrement operations will make the pointer jump the addresses same as the memory occupied by the kind of pointer.

for int pointer - 4 bytes
for char pointer - 1 byte

Addition and Subtraction of constants -> p.cpp

ptr + 3
ptr - 3

this will skip the address ptr + 3 \* 4 bytes (size of integer)

this is mostly used in teh case of arrays -> q.cpp -> using pointer arethematics to access the integer values

Addition and Subtraction of Pointers -> r.cpp

ptr1 + ptr2 // invalid operation
ptr1 - ptr2 // both must be of same types (this will give the numebr of elements lying between the pointers)

s.cpp -> using the same for the arrays

comparision of two pointers
(== , < , <= ,> , >=)

we can compare two pointer values -> t.cpp
addresses will be compared
