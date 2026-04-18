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
