# DSA with C++ — Module 16 Notes

DYNAMIC MEMORY ALLOCATION -> a.cpp

we do not know the size at the compile time. size is alloted at the compile time

in static memory alocation , the memory is allocated at the compile time -> it happens in the stack
when the stack frame is removed then the memory frees up

b.cpp
in dynamic memory allocation, memory is allocated in the runtime dynamically -> it happens in heap
the pointer is created in the main which is pointing in the heap

memory inside the heap is not automatically allocated, this leads to memory leak problem.
we have to manually delete the memory from the heap

Static Memory Allocation
• allocation at compile time
• uses stack memory
• gets freed automatically

Dynamic Memory Allocation
• allocation at run time (new operator)
• uses heap memory
• needs to be freed explicitly (delete operator)

Memory Leak -> c.cpp
A memory leak occurs when programmers create a memory in a heap and forget to delete it.
Leads to reduced performance due to depletion of available memory.

CREATING 2D ARRAYS DYNAMICALLY -> d.cpp
A 2D array is basically an array of arrays (rows × columns).
In dynamic allocation, memory is created at runtime in the heap using new.
You typically use a pointer to pointer (int\*\*) to represent a 2D array.

STL
Standard Template Library of C++
It is a library (collection) of container classes, algorithms & iterators.
It contains the implementation of common data structures like vectors, stacks, maps stc.

in java the STL is called collection framework

VECTORS -> e.cpp

Like Dynamic arrays that can resize dynamically at runtime.
They are stored contiguously in memory.

1. vector<int> vec1;
2. vector<int> vec2 = {1, 2, 3, 4};
3. vector<int> vec3(5, -1); -> init a vector of size 5 and values -1

VECTOR IMPLEMENTATION IN MEMORY -> f.cpp

vectors have :
capacity -> this is the max no of elements that the vector can store
size -> no. of elements present in the vector

new element add -> O(1) constant
but in some operations -> O(n)

for this we calculate the amotized time (average time) -> O(1)

PAIR SUM -> Leetcode 167
Find if any pair in sorted vector has target sum

input : arr = [2,7,11,15], target = 9
output: [0,1] // vector of indices

1. brute force approach -> g.cpp
   this does not use the info that the array is sorted
   time complexity -> O(n^2)
2. two pointer approach -> h.cpp
   Start one pointer at the beginning (left = 0)
   Start another at the end (right = n - 1)
   Compute sum:
   If sum == target → return indices
   If sum < target → move left++
   If sum > target → move right--

the time complexity is O(n)

2D VECTORS
A 2D vector is basically a vector of vectors
Think of it like a matrix (rows × columns)
Each element is itself a vector<int>
vector<vector<int>> matrix;

Structure
matrix[i] → represents a row
matrix[i][j] → represents an element in row i, column j

Initialization Methods -> i.cpp

1. Empty matrix

vector<vector<int>> matrix;

2. Fixed size (n rows, m columns)

vector<vector<int>> matrix(n, vector<int>(m, 0));

3. With values

vector<vector<int>> matrix = {
{1, 2, 3},
{4, 5, 6}
};

traversing the 2d vectors -> j.cpp

we can have no of columns in 2d vectors different unline 2d arrays
