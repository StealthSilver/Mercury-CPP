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

VECTOR IMPLEMENTATION IN MEMORY
