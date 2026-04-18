# DSA with C++ — Module 16 Notes

---

## 🔹 Introduction to Dynamic Memory Allocation

**Memory allocation** is crucial for managing data at runtime. C++ provides two primary approaches: static allocation (compile-time) and dynamic allocation (runtime).

### Static vs Dynamic Memory

```
┌────────────────────────────────────────────────────────┐
│           Memory Allocation Methods                    │
├────────────────────────────────────────────────────────┤
│ STATIC MEMORY ALLOCATION:                              │
│ • Allocation: Compile-time (size must be known)        │
│ • Location: Stack memory                               │
│ • Scope: Within function scope                         │
│ • Lifetime: Until function/block exits                 │
│ • Deallocation: Automatic                              │
│ • Example: int arr[10];  // Fixed size at compile      │
│ • Speed: Very fast allocation                          │
│ • Limitation: Fixed size, cannot change                │
│                                                        │
│ DYNAMIC MEMORY ALLOCATION:                             │
│ • Allocation: Runtime (size can be determined later)   │
│ • Location: Heap memory                                │
│ • Scope: Throughout program execution                  │
│ • Lifetime: Until explicitly deleted                   │
│ • Deallocation: Manual (using delete)                  │
│ • Example: int* arr = new int[size];  // Runtime size   │
│ • Speed: Slightly slower allocation                    │
│ • Flexibility: Size can vary based on need              │
│                                                        │
│ COMPARISON TABLE:                                      │
│ Feature          │ Static    │ Dynamic                  │
│ ─────────────────┼───────────┼──────────────            │
│ When allocated   │ Compile   │ Runtime                  │
│ Memory location  │ Stack     │ Heap                     │
│ Size known at    │ Compile   │ Runtime                  │
│ Deallocation     │ Automatic │ Manual                   │
│ Overhead         │ Low       │ Higher                   │
│ Flexiblity       │ Low       │ High                     │
└────────────────────────────────────────────────────────┘
```

### Stack vs Heap Memory

```
┌────────────────────────────────────────────────────────┐
│         Stack Memory vs Heap Memory                    │
├────────────────────────────────────────────────────────┤
│ STACK MEMORY:                                          │
│ • LIFO (Last In First Out) structure                   │
│ • Stores: Local variables, function parameters         │
│ • Automatic cleanup when scope ends                    │
│ • Limited size (typically 1-8 MB)                      │
│ • Very fast access                                     │
│ • No fragmentation                                     │
│ • Thread-safe per thread                               │
│                                                        │
│ HEAP MEMORY:                                           │
│ • Dynamic allocation managed by OS                     │
│ • Stores: Dynamically allocated data                   │
│ • Manual cleanup required                              │
│ • Large size (limited by total system RAM)             │
│ • Slower access than stack                             │
│ • Can become fragmented                                │
│ • Shared across all threads                            │
│                                                        │
│ VISUAL REPRESENTATION:                                 │
│                                                        │
│  Memory Layout:                                        │
│ ┌─────────────────────┐                                │
│ │   Heap (grows ↓)    │ ← Dynamic memory               │
│ │                     │                                │
│ ├─────────────────────┤                                │
│ │                     │                                │
│ │   Stack (grows ↑)   │ ← Static memory                │
│ └─────────────────────┘                                │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp) - Dynamic allocation basics, [b.cpp](b.cpp) - Heap vs stack demonstration

---

## 🔹 The new and delete Operators

**Dynamic memory allocation in C++** uses the `new` operator to allocate memory and the `delete` operator to deallocate it.

### Allocation and Deallocation

```
┌────────────────────────────────────────────────────────┐
│          new and delete Operators                      │
├────────────────────────────────────────────────────────┤
│ ALLOCATING SINGLE VARIABLE:                            │
│ Syntax: data_type* ptr = new data_type(value);         │
│ Example: int* p = new int(5);                          │
│ Returns: Pointer to allocated memory                   │
│ Initialize: new int(5) or just new int()              │
│                                                        │
│ ALLOCATING ARRAY:                                      │
│ Syntax: data_type* ptr = new data_type[size];          │
│ Example: int* arr = new int[10];                       │
│ Size: Can be variable (determined at runtime)          │
│ Initialization: Values are uninitialized               │
│                                                        │
│ DEALLOCATING SINGLE VARIABLE:                          │
│ Syntax: delete ptr;                                    │
│ After: ptr becomes invalid (dangling pointer)          │
│ Important: Set ptr = nullptr after delete              │
│                                                        │
│ DEALLOCATING ARRAY:                                    │
│ Syntax: delete[] arr;  // Note the []                  │
│ Difference: Must use delete[] for arrays               │
│ Why: Allocator tracks array size                       │
│                                                        │
│ COMPLETE EXAMPLE:                                      │
│ int* p = new int(42);   // Allocate                    │
│ cout << *p;              // Use (dereference)          │
│ delete p;                // Deallocate                 │
│ p = nullptr;             // Mark as invalid            │
│                                                        │
│ ARRAY EXAMPLE:                                         │
│ int* arr = new int[100]; // Allocate array             │
│ arr[0] = 5;              // Use like normal array       │
│ delete[] arr;            // Deallocate (use [])         │
│ arr = nullptr;           // Mark as invalid            │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Memory Leaks

**Memory leak**: When memory is allocated on the heap but never deallocated, wasting system resources.

### Understanding Memory Leaks

```
┌────────────────────────────────────────────────────────┐
│            Memory Leak Definition & Impact             │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Allocated heap memory that is no longer referenced     │
│ and cannot be freed. Typically caused by forgetting    │
│ to call delete on dynamically allocated memory.        │
│                                                        │
│ HOW IT HAPPENS:                                        │
│ 1. Allocate memory: ptr = new Type();                  │
│ 2. Lose reference: ptr reassigned or goes out of scope │
│ 3. Memory orphaned: Cannot access or deallocate        │
│ 4. Leak grows: Each iteration adds more memory         │
│                                                        │
│ EXAMPLE LEAK:                                          │
│ void leaky_function() {                                │
│   int* ptr = new int(5);   // Allocate                 │
│   // ... do something ...                              │
│   return;  // LEAK! Never called delete!               │
│ }                                                      │
│                                                        │
│ REPAIRED VERSION:                                      │
│ void fixed_function() {                                │
│   int* ptr = new int(5);   // Allocate                 │
│   // ... do something ...                              │
│   delete ptr;  // Free memory                          │
│   ptr = nullptr;  // Mark invalid                      │
│   return;                                              │
│ }                                                      │
│                                                        │
│ CONSEQUENCES:                                          │
│ • Program performance degrades over time                │
│ • RAM gradually gets depleted                          │
│ • System becomes sluggish                              │
│ • Long-running programs may crash                      │
│ • Server applications suffer most                      │
│ • Hard to detect and debug                             │
│                                                        │
│ PREVENTION STRATEGIES:                                 │
│ ✓ Always pair new with delete                          │
│ ✓ Use smart pointers (unique_ptr, shared_ptr)          │
│ ✓ Use RAII (Resource Acquisition Is Initialization)    │
│ ✓ Use modern containers (vector, string)               │
│ ✓ Enable memory leak detection tools                   │
└────────────────────────────────────────────────────────┘
```

Reference: [c.cpp](c.cpp) - Memory leak demonstration and detection

---

## 🔹 Dynamic 2D Arrays

Creating 2D arrays dynamically allows runtime determination of dimensions.

### 2D Dynamic Array Allocation

```
┌────────────────────────────────────────────────────────┐
│         Dynamic 2D Array Creation                      │
├────────────────────────────────────────────────────────┤
│ CONCEPT:                                               │
│ A 2D array is fundamentally an "array of arrays"       │
│ Each row is itself a dynamic array                     │
│ Use pointer-to-pointer: int** matrix                   │
│                                                        │
│ ALLOCATION STEPS:                                      │
│ 1. Create array of row pointers                        │
│ 2. For each row, allocate column array                 │
│ 3. Access like regular 2D array                        │
│                                                        │
│ CODE PATTERN:                                          │
│ int rows = 5, cols = 3;                                │
│ int** matrix = new int*[rows];                         │
│                                                        │
│ for (int i = 0; i < rows; i++)                         │
│   matrix[i] = new int[cols];                           │
│                                                        │
│ DEALLOCATION (IMPORTANT):                              │
│ Must delete in REVERSE order (rows first, then col)    │
│                                                        │
│ for (int i = 0; i < rows; i++)                         │
│   delete[] matrix[i];  // Delete each row              │
│ delete[] matrix;       // Delete array of pointers     │
│ matrix = nullptr;                                      │
│                                                        │
│ MEMORY LAYOUT:                                         │
│ matrix[0] ──→ [col0][col1][col2]  Row 0               │
│ matrix[1] ──→ [col0][col1][col2]  Row 1               │
│ matrix[2] ──→ [col0][col1][col2]  Row 2               │
│ ...                                                    │
│                                                        │
│ COMPLEXITY:                                            │
│ Allocation: O(rows × cols) - fill array                │
│ Deallocation: O(rows) + O(rows × cols) operations      │
│ Access: O(1) - direct pointer access                   │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp) - Dynamic 2D array implementation

---

## 🔹 Introduction to STL (Standard Template Library)

The **Standard Template Library** is C++'s comprehensive library of reusable data structures, algorithms, and utilities.

### STL Components

```
┌────────────────────────────────────────────────────────┐
│     Standard Template Library Overview                 │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Collection of software development tools provided      │
│ with C++ that implements common data structures        │
│ and algorithms.                                        │
│                                                        │
│ THREE MAIN COMPONENTS:                                 │
│                                                        │
│ 1. CONTAINERS:                                         │
│    • Store collections of objects                      │
│    • Examples: vector, list, map, set, queue, stack   │
│    • Each has specific performance characteristics     │
│                                                        │
│ 2. ALGORITHMS:                                         │
│    • Operate on container elements                     │
│    • Examples: sort, find, reverse, unique             │
│    • Generic and work with any container type          │
│                                                        │
│ 3. ITERATORS:                                          │
│    • Objects that point to container elements          │
│    • Allow traversal and modification                  │
│    • Similar to pointers but more flexible             │
│                                                        │
│ COMMON CONTAINERS:                                     │
│ • vector<T>: Dynamic array, fast access                │
│ • list<T>: Doubly-linked list, fast insertion          │
│ • map<K,V>: Key-value pairs, sorted by key             │
│ • set<T>: Unique elements, sorted order                │
│ • queue<T>: FIFO (First In First Out)                  │
│ • stack<T>: LIFO (Last In First Out)                   │
│ • priority_queue<T>: Sorted by priority                │
│                                                        │
│ ADVANTAGES:                                            │
│ ✓ Well-tested, production-ready code                   │
│ ✓ Significantly reduces development time               │
│ ✓ Highly optimized for performance                     │
│ ✓ Consistent interface across all containers           │
│ ✓ Extensive algorithm support                          │
│                                                        │
│ INCLUDES:                                              │
│ #include <vector>                                      │
│ #include <list>                                        │
│ #include <map>                                         │
│ #include <set>                                         │
│ #include <algorithm>                                   │
│ #include <queue>                                       │
│ #include <stack>                                       │
└────────────────────────────────────────────────────────┘
```

Reference: [STL official documentation](https://en.cppreference.com/w/cpp/container)

---

## 🔹 Vectors

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

PRACTICE QUESTION -> getting the size and capacity -> k.cpp
PRACTICE QUESTION -> l.cpp -> leetcode 645
You have a set of integers, which originally contains all the numbers
from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated
to another number in the set, which results in repetition of one number and loss of
another number.
You are given an integer array nums representing the data status of this set after the
error.
Find the number that occurs twice and the number that is missing and return them in
the form of an array.

PRACTICE QUESTION -> m.cpp -> leetcode 11
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

PRACTICE QUESTION -> n.cpp -> leetcode 15
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
