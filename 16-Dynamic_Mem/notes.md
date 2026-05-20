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

## 🔹 Vectors

**Vectors** are dynamic arrays that automatically resize themselves as elements are added or removed. They are part of the STL and provide a powerful alternative to traditional arrays.

### Vector Declaration and Initialization

```
┌────────────────────────────────────────────────────────┐
│        Vector Declaration Methods                      │
├────────────────────────────────────────────────────────┤
│ BASIC DECLARATION:                                     │
│ #include <vector>                                      │
│ using namespace std;                                   │
│                                                        │
│ 1. Empty vector:                                       │
│    vector<int> vec;                                    │
│    // Size = 0, Capacity = 0                           │
│                                                        │
│ 2. Vector with size and default values:                │
│    vector<int> vec(5, 0);  // 5 elements, all 0        │
│    // Creates: [0, 0, 0, 0, 0]                         │
│                                                        │
│ 3. Vector with initializer list:                       │
│    vector<int> vec = {1, 2, 3, 4, 5};                  │
│    // Creates: [1, 2, 3, 4, 5]                         │
│                                                        │
│ 4. Copy constructor:                                   │
│    vector<int> vec1 = {1, 2, 3};                       │
│    vector<int> vec2 = vec1;  // Copy all elements      │
│                                                        │
│ DATA TYPES:                                            │
│ • vector<int> - integers                               │
│ • vector<double> - floating point                      │
│ • vector<string> - strings                             │
│ • vector<vector<int>> - 2D arrays                       │
│ • vector<pair<int,int>> - pairs                        │
│ • Any type that can be stored                          │
│                                                        │
│ MEMORY LAYOUT:                                         │
│ Vector stores all elements contiguously in memory      │
│ vec: [1] [2] [3] [4] [5]  ← All adjacent in heap      │
└────────────────────────────────────────────────────────┘
```

### Vector Member Functions

```
┌────────────────────────────────────────────────────────┐
│      Essential Vector Member Functions                 │
├────────────────────────────────────────────────────────┤
│ 1. push_back(value) - Add element at end               │
│    Syntax: vec.push_back(10);                          │
│    Time: O(1) amortized                                │
│    Resizes vector if necessary                         │
│                                                        │
│ 2. pop_back() - Remove element from end                │
│    Syntax: vec.pop_back();                             │
│    Time: O(1)                                          │
│    Doesn't return value; access before removing        │
│                                                        │
│ 3. size() - Get number of elements                     │
│    Syntax: int n = vec.size();                         │
│    Time: O(1)                                          │
│    Returns: Number of actual elements                  │
│                                                        │
│ 4. capacity() - Max elements before resize             │
│    Syntax: int c = vec.capacity();                     │
│    Time: O(1)                                          │
│    Returns: Total capacity (≥ size)                    │
│                                                        │
│ 5. at(index) - Access element with bounds check       │
│    Syntax: int val = vec.at(i);                        │
│    Time: O(1)                                          │
│    Throws: out_of_range if invalid index               │
│                                                        │
│ 6. operator[] - Direct access (no bounds check)        │
│    Syntax: int val = vec[i];                           │
│    Time: O(1)                                          │
│    Faster but unsafe                                   │
│                                                        │
│ 7. clear() - Remove all elements                       │
│    Syntax: vec.clear();                                │
│    Time: O(n)                                          │
│    Size becomes 0, capacity unchanged                  │
│                                                        │
│ 8. empty() - Check if vector is empty                  │
│    Syntax: if (vec.empty()) { ... }                    │
│    Time: O(1)                                          │
│    Returns: true if size == 0                          │
│                                                        │
│ 9. insert(position, value) - Insert at position        │
│    Syntax: vec.insert(vec.begin() + 2, 99);            │
│    Time: O(n) - elements shift                         │
│    Expensive operation for large vectors               │
│                                                        │
│ 10. erase(position) - Remove element at position       │
│     Syntax: vec.erase(vec.begin() + 2);                │
│     Time: O(n) - elements shift                        │
└────────────────────────────────────────────────────────┘
```

Reference: [e.cpp](e.cpp) - Vector basics and operations

---

## 🔹 Vector Internals: Capacity and Size

Understanding how vectors manage memory is crucial for writing efficient code.

### Capacity and Size Management

```
┌────────────────────────────────────────────────────────┐
│      Vector Size vs Capacity                           │
├────────────────────────────────────────────────────────┤
│ SIZE:                                                  │
│ • Number of actual elements currently in vector        │
│ • Changed by: push_back(), pop_back(), clear()         │
│ • Accessed by: vec.size()                              │
│ • Example: vec = {1, 2, 3} → size = 3                  │
│                                                        │
│ CAPACITY:                                              │
│ • Maximum number of elements vector can hold           │
│ • Before needing to reallocate memory                  │
│ • Always: capacity ≥ size                              │
│ • Accessed by: vec.capacity()                          │
│ • Example: vec = {1, 2, 3}, cap might be 4 or 8        │
│                                                        │
│ REALLOCATION STRATEGY:                                 │
│ • When size exceeds capacity, vector reallocates       │
│ • Typically doubles capacity (2x growth)               │
│ • Example growth:                                      │
│   Step 1: {1}       size=1, cap=1                      │
│   Step 2: {1,2}     size=2, cap=2 (doubled)            │
│   Step 3: {1,2,3}   size=3, cap=4 (doubled)            │
│   Step 4: {1,2,3,4} size=4, cap=4                      │
│   Step 5: Add 5th   size=5, cap=8 (doubled)            │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ • Typical push_back(): O(1) - constant                 │
│ • Occasional resize: O(n) - copy all elements          │
│ • Amortized: O(1) - averaged over many operations      │
│                                                        │
│ WHY AMORTIZED O(1)?                                    │
│ n operations cost n + 2n = 3n (worst case resize)     │
│ Divided by n operations = 3 per operation = O(1)       │
│                                                        │
│ MEMORY VISUALIZATION:                                  │
│ Vector after 5 push_backs with doubling:               │
│ ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐      │
│ │ 1   │ 2   │ 3   │ 4   │ 5   │ ??? │ ??? │ ??? │      │
│ └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘      │
│ Size = 5, Capacity = 8 (3 empty slots)                 │
└────────────────────────────────────────────────────────┘
```

Reference: [f.cpp](f.cpp) - Vector memory management demonstration

---

## 🔹 Two Pointer Approach: Pair Sum (LeetCode 1)

**Problem**: Given a sorted array and a target sum, find two numbers that add up to the target.

### Algorithm and Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│         Two Sum II (Sorted Array) - LeetCode 167      │
├────────────────────────────────────────────────────────┤
│ PROBLEM STATEMENT:                                     │
│ Input:  arr = [2, 7, 11, 15], target = 9              │
│ Output: [1, 2]  // 1-indexed (arr[0]+arr[1]=9)         │
│         or [0, 1] (0-indexed)                          │
│                                                        │
│ KEY INSIGHT:                                           │
│ Array is sorted! Use two pointers from opposite ends   │
│                                                        │
│ ALGORITHM (Two Pointer):                               │
│ 1. left = 0 (start), right = n-1 (end)                 │
│ 2. Calculate sum = arr[left] + arr[right]              │
│ 3. If sum == target: FOUND! Return indices             │
│ 4. If sum < target: Move left++ (need bigger sum)      │
│ 5. If sum > target: Move right-- (need smaller sum)    │
│ 6. Repeat until found or pointers meet                 │
│                                                        │
│ EXAMPLE WALKTHROUGH:                                   │
│ arr = [2, 7, 11, 15], target = 9                       │
│                                                        │
│ Iteration 1: left=0, right=3                           │
│   sum = 2 + 15 = 17 > 9 → move right--                 │
│                                                        │
│ Iteration 2: left=0, right=2                           │
│   sum = 2 + 11 = 13 > 9 → move right--                 │
│                                                        │
│ Iteration 3: left=0, right=1                           │
│   sum = 2 + 7 = 9 == 9 → FOUND!                        │
│   Return [0, 1] (0-indexed) or [1, 2] (1-indexed)      │
│                                                        │
│ COMPLEXITY ANALYSIS:                                   │
│ Time: O(n) - each pointer moves at most n steps        │
│ Space: O(1) - only two pointers, no extra space        │
│                                                        │
│ COMPARISON WITH BRUTE FORCE:                           │
│ Brute Force (nested loops): O(n²) - check all pairs    │
│ Two Pointer: O(n) - single pass with smart pointers    │
│ Improvement: 100x faster for large arrays!             │
└────────────────────────────────────────────────────────┘
```

Reference: [g.cpp](g.cpp) - Brute force O(n²) approach, [h.cpp](h.cpp) - Two pointer O(n) approach

---

## 🔹 2D Vectors

A **2D vector** is a vector of vectors, representing a dynamic matrix with potentially different row lengths.

### 2D Vector Basics

```
┌────────────────────────────────────────────────────────┐
│          2D Vector Fundamentals                        │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ vector<vector<int>> matrix;                            │
│ Each element is itself a vector                        │
│ Flexible row and column dimensions                     │
│                                                        │
│ STRUCTURE:                                             │
│ matrix[i] → represents row i (vector<int>)             │
│ matrix[i][j] → represents element at row i, col j      │
│                                                        │
│ ADVANTAGES OVER 2D ARRAYS:                             │
│ ✓ Dynamic row lengths (jagged arrays)                  │
│ ✓ Automatic memory management                         │
│ ✓ Easy resizing                                        │
│ ✓ No manual deallocation needed                        │
│ ✓ Compatible with STL algorithms                       │
│                                                        │
│ COMPARISON:                                            │
│ 2D Array:                                              │
│ int arr[3][3];  // Fixed 3×3                           │
│ Size known at compile time                             │
│                                                        │
│ 2D Vector:                                             │
│ vector<vector<int>> vec;  // Dynamic                   │
│ Size determined at runtime                             │
│ Can have different column counts per row               │
│                                                        │
│ COMMON USES:                                           │
│ • Image processing (pixel matrices)                    │
│ • Game grids (chess, sudoku, maze)                     │
│ • Graph adjacency matrices                             │
│ • Dynamic programming tables                          │
│ • Matrix operations (multiply, transpose)              │
└────────────────────────────────────────────────────────┘
```

### 2D Vector Initialization

```
┌────────────────────────────────────────────────────────┐
│      2D Vector Initialization Methods                  │
├────────────────────────────────────────────────────────┤
│ 1. EMPTY 2D VECTOR:                                    │
│    vector<vector<int>> matrix;                         │
│    // No rows or columns allocated                     │
│                                                        │
│ 2. FIXED SIZE WITH DEFAULTS:                           │
│    vector<vector<int>> mat(3, vector<int>(4, 0));      │
│    Creates 3 rows × 4 columns, all 0s                  │
│    └─ Outer vector: 3 rows                             │
│    └─ Inner vector: 4 columns, init to 0               │
│                                                        │
│    Result:                                             │
│    ┌─────┬─────┬─────┬─────┐                           │
│    │ 0   │ 0   │ 0   │ 0   │ Row 0                     │
│    ├─────┼─────┼─────┼─────┤                           │
│    │ 0   │ 0   │ 0   │ 0   │ Row 1                     │
│    ├─────┼─────┼─────┼─────┤                           │
│    │ 0   │ 0   │ 0   │ 0   │ Row 2                     │
│    └─────┴─────┴─────┴─────┘                           │
│                                                        │
│ 3. WITH INITIAL VALUES:                                │
│    vector<vector<int>> mat = {                         │
│      {1, 2, 3},                                        │
│      {4, 5, 6},                                        │
│      {7, 8, 9}                                         │
│    };                                                  │
│    Creates: 3×3 matrix with specified values           │
│                                                        │
│ 4. JAGGED ARRAY (Different row lengths):               │
│    vector<vector<int>> jagged;                         │
│    jagged.push_back({1, 2});                           │
│    jagged.push_back({3, 4, 5});                        │
│    jagged.push_back({6});                              │
│    Row 0: {1, 2} (2 elements)                          │
│    Row 1: {3, 4, 5} (3 elements)                       │
│    Row 2: {6} (1 element)                              │
│                                                        │
│ ACCESSING ELEMENTS:                                    │
│ mat[0][0]      // Element at row 0, col 0              │
│ mat[i][j]      // Element at row i, col j              │
│ mat[i].size()  // Number of columns in row i           │
│ mat.size()     // Number of rows                       │
└────────────────────────────────────────────────────────┘
```

### 2D Vector Traversal

```
┌────────────────────────────────────────────────────────┐
│      Traversing 2D Vectors                             │
├────────────────────────────────────────────────────────┤
│ NESTED LOOPS:                                          │
│ for (int i = 0; i < matrix.size(); i++)                │
│   for (int j = 0; j < matrix[i].size(); j++)           │
│     cout << matrix[i][j] << " ";                       │
│                                                        │
│ RANGE-BASED FOR LOOP (Modern C++):                     │
│ for (auto& row : matrix)                               │
│   for (int val : row)                                  │
│     cout << val << " ";                                │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(rows × cols) - visit each element              │
│ Space: O(1) - no extra space                           │
│                                                        │
│ NOTE: matrix[i].size() can differ for each row         │
└────────────────────────────────────────────────────────┘
```

Reference: [i.cpp](i.cpp) - 2D vector initialization, [j.cpp](j.cpp) - 2D vector traversal

---

## 🔹 Vector Practice Problems

### Problem 1: Find Duplicate (LeetCode 645)

**Problem**: You have a set of integers from 1 to n. One number got duplicated, causing one number to be missing. Find both the duplicate and missing number.

```
┌────────────────────────────────────────────────────────┐
│   Find the Duplicate and Missing Number - LeetCode 645 │
├────────────────────────────────────────────────────────┤
│ EXAMPLE:                                               │
│ Input: {1, 2, 2, 2}  (should have 1, 2, 3, 4)          │
│ Output: Duplicate = 2, Missing = 3                     │
│                                                        │
│ APPROACH 1: Frequency Array                            │
│ • Create array to track which numbers appear           │
│ • Mark each number as seen                             │
│ • Find duplicate (appears twice)                       │
│ • Find missing (never appeared)                        │
│ Time: O(n), Space: O(n)                                │
│                                                        │
│ APPROACH 2: Math using Formulas                        │
│ • Sum of 1 to n: n*(n+1)/2                             │
│ • Actual sum: sum of all array elements                │
│ • Difference: (sum of squares)                         │
│ • Solve two equations for the values                   │
│ Time: O(n), Space: O(1)                                │
│                                                        │
│ KEY INSIGHT:                                           │
│ Each number 1 to n should appear exactly once          │
│ Use mathematical property to identify mismatch         │
└────────────────────────────────────────────────────────┘
```

Reference: [k.cpp](k.cpp) - Size and capacity demonstration, [l.cpp](l.cpp) - Find duplicate solution

### Problem 2: Container With Most Water (LeetCode 11)

**Problem**: Given an array of heights, find two lines that form a container holding the maximum amount of water.

```
┌────────────────────────────────────────────────────────┐
│      Container With Most Water - LeetCode 11           │
├────────────────────────────────────────────────────────┤
│ CONCEPT:                                               │
│ • Two vertical lines at positions i and j              │
│ • Height of smaller line limits water level            │
│ • Width: distance between lines = j - i                │
│ • Area = min(height[i], height[j]) × (j - i)           │
│                                                        │
│ EXAMPLE:                                               │
│ heights = [1, 8, 6, 2, 5, 4, 8, 3, 7]                  │
│                ↑           ↑                            │
│ Maximum area with lines at index 1 and 8               │
│ Area = min(8, 7) × (8 - 1) = 7 × 7 = 49                │
│                                                        │
│ APPROACH: Two Pointer                                  │
│ 1. Start with leftmost and rightmost lines             │
│ 2. Calculate current area                              │
│ 3. Move the pointer pointing to shorter line inward    │
│   (to potentially find taller line)                    │
│ 4. Track maximum area seen                             │
│ 5. Stop when pointers meet                             │
│                                                        │
│ WHY THIS WORKS:                                        │
│ • Moving the taller pointer inward can only decrease   │
│  area (width decreases, height can't increase enough)  │
│ • Moving shorter pointer might find taller line        │
│  (could increase area despite smaller width)           │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n) - single pass with two pointers             │
│ Space: O(1) - only variables                           │
└────────────────────────────────────────────────────────┘
```

Reference: [m.cpp](m.cpp) - Container with most water solution

### Problem 3: 3Sum (LeetCode 15)

**Problem**: Find all unique triplets in array that sum to zero.

```
┌────────────────────────────────────────────────────────┐
│         3Sum - LeetCode 15                             │
├────────────────────────────────────────────────────────┤
│ PROBLEM:                                               │
│ Input: nums = [-1, 0, 1, 2, -1, -4]                    │
│ Output: [[-1, -1, 2], [-1, 0, 1]]                      │
│ Find all triplets that sum to 0 (no duplicates)        │
│                                                        │
│ APPROACH:                                              │
│ 1. SORT array first                                    │
│ 2. FIX first element                                   │
│ 3. Use two pointers on remaining elements              │
│ 4. Skip duplicates to avoid repeated triplets          │
│                                                        │
│ ALGORITHM:                                             │
│ • For each element i (fix it)                          │
│ • Find two elements in rest that sum to -nums[i]       │
│ • Use two pointers from i+1 and end                    │
│ • If sum too small: move left++                        │
│ • If sum too large: move right--                       │
│ • If sum correct: add to result, skip duplicates       │
│                                                        │
│ DUPLICATE HANDLING:                                    │
│ • Must skip same outer element to avoid triplet repeat │
│ • Must skip same left/right elements for pairs         │
│ • Sort helps: identical elements are adjacent          │
│                                                        │
│ EXAMPLE:                                               │
│ [-1, 0, 1, 2, -1, -4] → sorted → [-4, -1, -1, 0, 1, 2]│
│                                                        │
│ i=-4: Need two elements summing to 4 (no solution)     │
│ i=-1: Find 0 + 1 = 1, so -1+0+1=0 ✓                    │
│ i=0:  Find -1 + 1 = 0, so 0-1+1=0 ✓                    │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n²) - outer loop + inner two pointers          │
│ Space: O(1) or O(n) depending on sort implementation   │
│                                                        │
│ KEY INSIGHT:                                           │
│ Sorting enables efficient duplicate handling and       │
│ allows two-pointer optimization instead of brute force │
└────────────────────────────────────────────────────────┘
```

Reference: [n.cpp](n.cpp) - 3Sum solution

---

## 🔹 Best Practices and Summary

```
┌────────────────────────────────────────────────────────┐
│       Module 16 Key Takeaways                          │
├────────────────────────────────────────────────────────┤
│ MEMORY MANAGEMENT:                                     │
│ ✓ Always delete dynamically allocated memory           │
│ ✓ Use smart pointers (unique_ptr, shared_ptr)          │
│ ✓ Never trust manual memory management in large code   │
│ ✓ Modern C++ prefers containers over raw pointers      │
│                                                        │
│ VECTORS ARE SUPERIOR TO ARRAYS:                        │
│ ✓ Dynamic resizing                                     │
│ ✓ Automatic memory management                          │
│ ✓ Rich set of member functions                         │
│ ✓ Compatible with STL algorithms                       │
│ ✓ Type-safe operations                                 │
│                                                        │
│ TWO-POINTER TECHNIQUE:                                 │
│ ✓ Powerful for sorted arrays                           │
│ ✓ Converts O(n²) to O(n) solutions                     │
│ ✓ Works when moving one pointer eliminates cases       │
│ ✓ Think about invariants to maintain                   │
│                                                        │
│ VECTOR COMPLEXITY CHEAT SHEET:                         │
│ Operation      │ Time      │ Note                      │
│ ──────────────┼───────────┼─────────────────          │
│ push_back()    │ O(1)      │ Amortized                 │
│ pop_back()     │ O(1)      │ Always constant           │
│ access [i]     │ O(1)      │ Direct access             │
│ insert()       │ O(n)      │ Elements shift            │
│ erase()        │ O(n)      │ Elements shift            │
│ search         │ O(n)      │ Unsorted data             │
│ sort()         │ O(n log n)│ STL sort                  │
│                                                        │
│ STL MINDSET:                                           │
│ ✓ Use STL containers instead of manual management     │
│ ✓ Know time complexity of operations                   │
│ ✓ Leverage STL algorithms (sort, find, reverse, etc)   │
│ ✓ Use iterators for generic code                       │
│ ✓ Combine algorithms with lambda functions             │
└────────────────────────────────────────────────────────┘
```

---

**Module 16 Complete!** You now understand dynamic memory, vectors, and efficient array techniques essential for competitive programming and real-world applications.
