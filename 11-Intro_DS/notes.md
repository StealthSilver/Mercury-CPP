# DSA with C++ — Module 11 Notes

---

## 🔹 Introduction to Data Structures

**Data structures** are systematic ways of organizing and storing data to enable efficient access, modification, and analysis. The choice of data structure directly impacts the performance and scalability of your program.

---

## 🔹 Arrays: The Foundation

An **array** is a linear data structure that stores a fixed-size collection of elements of the **same data type** in **contiguous memory locations**. This contiguous arrangement allows for efficient access and traversal.

### Key Concepts

```
┌────────────────────────────────────────────────────────┐
│              Array Fundamentals                        │
├────────────────────────────────────────────────────────┤
│ • Linear data structure (elements in sequence)         │
│ • Homogeneous elements (same data type)                │
│ • Fixed size (determined at compile or runtime)        │
│ • Zero-indexed (first element at index 0)              │
│ • Contiguous memory allocation                         │
│ • Direct access to any element via index               │
└────────────────────────────────────────────────────────┘
```

### Memory Organization

For an array of 7 elements with indices 0-6:

```
Index:    0    1    2    3    4    5    6
        ┌────┬────┬────┬────┬────┬────┬────┐
Array:  │ 10 │ 20 │ 30 │ 40 │ 50 │ 60 │ 70 │
        └────┴────┴────┴────┴────┴────┴────┘
Contiguous Memory
```

---

## 🔹 Creating Arrays

Arrays in C++ can be initialized in multiple ways. The method you choose depends on how much you know about the data at compile time.

### Initialization Methods

```
┌──────┬────────────────────────────────┬──────────────────────────────┐
│ Type │ Declaration                    │ Initial Values               │
├──────┼────────────────────────────────┼──────────────────────────────┤
│  1   │ int marks[50];                 │ Garbage values               │
│      │                                │ (uninitialized memory)       │
│  2   │ int marks[50] = {1,2,3};       │ 1, 2, 3, then 0s             │
│  3   │ int marks[] = {1,2,3,4};       │ Auto-sized: 1, 2, 3, 4       │
└──────┴────────────────────────────────┴──────────────────────────────┘
```

### Memory Allocation

```
┌────────────────────────────────────────────────────────┐
│           Memory Allocation in C++                     │
├────────────────────────────────────────────────────────┤
│ • Static Allocation: int marks[50];                    │
│   - Size determined at COMPILE TIME                    │
│   - Memory allocated on STACK                          │
│   - Limited to compile-time constants                  │
│                                                        │
│ • Dynamic Allocation: int *arr = new int[n];           │
│   - Size determined at RUNTIME                         │
│   - Memory allocated on HEAP                           │
│   - Better for variable-sized arrays                   │
└────────────────────────────────────────────────────────┘
```

### Finding Array Size

To determine the number of elements in an array:

```cpp
int arr[50];
int size = sizeof(arr) / sizeof(int);  // Returns 50
```

This works only for static arrays. For dynamic arrays, you must track the size manually.

Reference: [a.cpp](a.cpp) - Basic array creation, [b.cpp](b.cpp) - Initialization with values, [c.cpp](c.cpp) - Auto-sized arrays

---

## 🔹 Array Input and Output

Working with array elements requires iteration to input values from users and display results.

### Common Operations

```
┌──────┬─────────────────────────────────────────┬────────────────┐
│ File │ Operation                               │ Key Concept    │
├──────┼─────────────────────────────────────────┼────────────────┤
│ d.cpp│ Output array elements                   │ Iteration      │
│ e.cpp│ Input array elements                    │ User input     │
│ f.cpp│ Dynamic array creation (runtime size)   │ Dynamic arrays │
│ g.cpp│ Find max and min in array               │ Traversal      │
└──────┴─────────────────────────────────────────┴────────────────┘
```

---

## 🔹 Arrays Are Passed by Reference

This is a critical distinction in C++: when you pass an array to a function, you're not passing a copy of the array. Instead, you're passing a **pointer to the first element**.

### Why This Matters

```
┌────────────────────────────────────────────────────────┐
│              Array Passing Mechanism                   │
├────────────────────────────────────────────────────────┤
│ Array Name → Pointer to First Element (Index 0)        │
│                                                        │
│ int arr[5] = {1, 2, 3, 4, 5};                          │
│ arr ≡ &arr[0]  (they are equivalent)                   │
│                                                        │
│ When passed to function:                               │
│ • Only the pointer is copied (not the array)           │
│ • Changes inside function AFFECT original array        │
│ • Size information is NOT passed                       │
└────────────────────────────────────────────────────────┘
```

### Function Declaration Equivalence

```cpp
// All three declarations are IDENTICAL:
void printArr(int arr[]);      // Array syntax
void printArr(int *arr);       // Pointer syntax
void printArr(int *arr);       // Clearly a pointer
```

### Important Note

When an array is passed to a function, the called function receives **only a pointer**, not the actual array. Therefore, you must **pass the array size separately** to the function, as there's no way to determine the size inside the function.

Reference: [h.cpp](h.cpp) - Array name as pointer, [i.cpp](i.cpp) - Array passing mechanism, [j.cpp](j.cpp) - Function with array parameter

---

## 🔹 Linear Search

**Linear search** (also called sequential search) is the simplest searching algorithm. It examines each element sequentially until the target value is found or the array is exhausted.

### Algorithm Overview

```
┌─────────────────────────────────────────────────────────┐
│ 1. Start from index 0                                   │
│ 2. Compare target with current element                  │
│ 3. If match → Return index                              │
│ 4. If no match → Move to next element                   │
│ 5. Repeat until end of array                            │
│ 6. If not found → Return -1                             │
└─────────────────────────────────────────────────────────┘
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│         Linear Search Characteristics                  │
├────────────────────────────────────────────────────────┤
│ • Works on SORTED or UNSORTED arrays                   │
│ • Checks elements one by one                           │
│ • Returns first occurrence of key                       │
│ • Returns -1 if key not found                           │
│ • Simple to implement and understand                    │
│ • Inefficient for large datasets                        │
│                                                        │
│ Time Complexity:  O(n)                                 │
│ Space Complexity: O(1)                                 │
└────────────────────────────────────────────────────────┘
```

Reference: [k.cpp](k.cpp)

---

## 🔹 Reversing an Array

Array reversal rearranges elements so the last element becomes first, second-last becomes second, and so on.

### Method 1: With Extra Space (Naive Approach)

```
┌────────────────────────────────────────────────────────┐
│            With Extra Space (Copy)                     │
├────────────────────────────────────────────────────────┤
│ • Create a duplicate array                             │
│ • Copy elements in reverse order                       │
│ • Can then replace original array                      │
│                                                        │
│ Time Complexity:  O(n)                                 │
│ Space Complexity: O(n)  (duplicate array needed)       │
└────────────────────────────────────────────────────────┘
```

Reference: [l.cpp](l.cpp)

### Method 2: Without Extra Space (Optimal)

```
┌────────────────────────────────────────────────────────┐
│          Without Extra Space (In-Place)                │
├────────────────────────────────────────────────────────┤
│ • Use two pointers (start and end)                     │
│ • Swap elements at both ends                           │
│ • Move pointers toward center                          │
│ • Stop when pointers meet or cross                     │
│                                                        │
│ Time Complexity:  O(n)                                 │
│ Space Complexity: O(1)  (only swap space)              │
└────────────────────────────────────────────────────────┘
```

### Swap Mechanism

```cpp
// Method 1: Manual swap
int temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;

// Method 2: Standard Library swap
swap(arr[start], arr[end]);
```

Reference: [m.cpp](m.cpp)

---

## 🔹 Binary Search

**Binary search** is a highly efficient searching algorithm that works only on **sorted arrays**. It repeatedly divides the search space in half, eliminating half of the remaining elements with each comparison.

### Prerequisites

```
┌────────────────────────────────────────────────────────┐
│              For Binary Search to Work:                │
├────────────────────────────────────────────────────────┤
│ ✓ Array MUST be sorted (ascending or descending)       │
│ ✓ Contiguous elements or known indices                 │
│ ✓ Random access to elements (array-like)               │
└────────────────────────────────────────────────────────┘
```

### How It Works

```
Original array (sorted): [2, 5, 8, 12, 15, 20, 26, 31, 39]
Target: 20

Step 1: mid = (0+8)/2 = 4 → arr[4] = 15
        Since 20 > 15, search right half

Step 2: mid = (5+8)/2 = 6 → arr[6] = 26
        Since 20 < 26, search left half

Step 3: mid = (5+5)/2 = 5 → arr[5] = 20
        Found! Return index 5
```

### Number of Iterations

Mathematical analysis of binary search complexity:

$$n / 2^x = 1$$

When only one element remains: $ n = 2^x $

Therefore: $ x = \log_2(n) $

Total iterations: $ x + 1 = \log_2(n) + 1 $

Ignoring constants, time complexity is **O(log n)**.

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│           Binary Search Complexity                     │
├────────────────────────────────────────────────────────┤
│ Time Complexity:                                       │
│   • Iterative: O(log n)                                │
│   • Recursive: O(log n)                                │
│                                                        │
│ Space Complexity:                                      │
│   • Iterative: O(1)     (no extra space)               │
│   • Recursive: O(log n) (recursion stack)              │
│                                                        │
│ Example: Searching in 1,000,000 elements               │
│   Linear search:  ~500,000 comparisons                 │
│   Binary search:  ~20 comparisons                      │
│   Speedup: 25,000x faster!                             │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Array Pointers

Arrays have a special relationship with pointers in C++. The array name itself is a pointer constant to the first element.

### Array as Pointer

```
┌────────────────────────────────────────────────────────┐
│            Array Name = Pointer                        │
├────────────────────────────────────────────────────────┤
│ int arr[5] = {10, 20, 30, 40, 50};                     │
│                                                        │
│ arr      ≡ &arr[0]  (same address)                     │
│ arr[i]   ≡ *(arr+i) (same element)                    │
│                                                        │
│ cout << arr;      // Prints base address               │
│ cout << &arr[0];  // Same address                      │
│                                                        │
│ arr is a POINTER CONSTANT:                             │
│ • Cannot be reassigned: arr = &y;  ✗ ERROR             │
│ • Always points to arr[0]                              │
│ • Similar to const int *p                              │
└────────────────────────────────────────────────────────┘
```

Reference: [h.cpp](h.cpp)

---

## 🔹 Pointer Arithmetic

Pointers support arithmetic operations that are adjusted based on the size of the data type being pointed to.

### Increment and Decrement Operators

```
┌────────────────────────────────────────────────────────┐
│          Increment/Decrement on Pointers               │
├────────────────────────────────────────────────────────┤
│ ptr++  or  ++ptr  → Move to NEXT element               │
│ ptr--  or  --ptr  → Move to PREVIOUS element           │
│                                                        │
│ Memory Jump = Size of Data Type                        │
│                                                        │
│ For int pointer:   ++ptr jumps 4 bytes                 │
│ For char pointer:  ++ptr jumps 1 byte                  │
│ For double pointer: ++ptr jumps 8 bytes                │
└────────────────────────────────────────────────────────┘
```

Reference: [n.cpp](n.cpp)

### Addition and Subtraction with Constants

```
┌────────────────────────────────────────────────────────┐
│   Adding/Subtracting Constants to Pointers             │
├────────────────────────────────────────────────────────┤
│ ptr + 3  → Points 3 elements AFTER ptr                 │
│ ptr - 2  → Points 2 elements BEFORE ptr                │
│                                                        │
│ Memory jump = constant × sizeof(data type)             │
│                                                        │
│ For int array:                                         │
│ ptr + 3  → actual address: ptr + 3×4 bytes             │
│ ptr - 1  → actual address: ptr - 1×4 bytes             │
│                                                        │
│ Commonly used with arrays:                             │
│ int *p = arr;   // Points to arr[0]                    │
│ *(p + 3);       // Accesses arr[3]                     │
│ *(p + i);       // Accesses arr[i]                     │
└────────────────────────────────────────────────────────┘
```

Reference: [n.cpp](n.cpp) - Increment/Decrement, [o.cpp](o.cpp) - Addition/Subtraction, [p.cpp](p.cpp) - Array access via pointers

### Pointer-to-Pointer Subtraction

```
┌────────────────────────────────────────────────────────┐
│         Subtracting Two Pointers                       │
├────────────────────────────────────────────────────────┤
│ ptr1 + ptr2  → INVALID (cannot add pointers)           │
│ ptr1 - ptr2  → VALID (both must be same type)          │
│                                                        │
│ Result = Number of ELEMENTS between pointers           │
│                                                        │
│ Example:                                               │
│ int *p1 = &arr[2];                                     │
│ int *p2 = &arr[5];                                     │
│ p2 - p1 = 3  (3 elements between them)                 │
│                                                        │
│ int arr[5];                                            │
│ &arr[4] - &arr[0] = 4  (4 elements between)            │
└────────────────────────────────────────────────────────┘
```

Reference: [q.cpp](q.cpp) - Pointer subtraction, [r.cpp](r.cpp) - Pointer arithmetic with arrays

---

## 🔹 Comparing Pointers

Two pointers can be compared to determine their relative positions in memory. The comparison operators work with pointer addresses.

### Valid Comparisons

```
┌────────────────────────────────────────────────────────┐
│          Pointer Comparison Operators                  │
├────────────────────────────────────────────────────────┤
│ ptr1 == ptr2  → Same address?                          │
│ ptr1 != ptr2  → Different addresses?                   │
│ ptr1 < ptr2   → ptr1 before ptr2 in memory?            │
│ ptr1 <= ptr2  → ptr1 at or before ptr2?                │
│ ptr1 > ptr2   → ptr1 after ptr2 in memory?             │
│ ptr1 >= ptr2  → ptr1 at or after ptr2?                 │
│                                                        │
│ Note: Comparisons are based on ADDRESS VALUES,         │
│       not the data they point to                       │
└────────────────────────────────────────────────────────┘
```

### Practical Use Cases

```
┌────────────────────────────────────────────────────────┐
│          Common Pointer Comparison Uses                │
├────────────────────────────────────────────────────────┤
│ while (ptr < end)      // Iterate until end of array   │
│ if (ptr == NULL)       // Check if uninitialized       │
│ if (ptr1 != ptr2)      // Compare different points     │
└────────────────────────────────────────────────────────┘
```

Reference: [s.cpp](s.cpp)

---

## 🔹 Best Practices with Arrays

```
┌────────────────────────────────────────────────────────┐
│            Array Best Practices                        │
├────────────────────────────────────────────────────────┤
│ INITIALIZATION:                                        │
│ ✓ Always initialize arrays to avoid garbage values     │
│ ✓ Use = {0} to initialize all elements to 0            │
│ ✓ For dynamic arrays, use new and delete pairs         │
│                                                        │
│ BOUNDS CHECKING:                                       │
│ ✓ Validate array indices before access                 │
│ ✓ Prevent out-of-bounds access                         │
│ ✓ Use dynamic arrays when size is unknown at compile   │
│                                                        │
│ FUNCTION PARAMETERS:                                   │
│ ✓ Always pass array size to functions                  │
│ ✓ Document whether function modifies the array         │
│ ✓ Consider using pointers or references               │
│                                                        │
│ POINTER ARITHMETIC:                                    │
│ ✓ Keep track of pointer boundaries                     │
│ ✓ Avoid pointer arithmetic beyond array bounds         │
│ ✗ Don't forget that arrays decay to pointers           │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Summary Table

```
┌─────┬────────────────────────┬──────────────┬────────────────────┐
│File │ Concept                │ Difficulty   │ Key Learning Point │
├─────┼────────────────────────┼──────────────┼────────────────────┤
│a.cpp│ Basic array creation   │ Easy         │ Initialization     │
│b.cpp│ Array with values      │ Easy         │ Value initialization│
│c.cpp│ Auto-sized array       │ Easy         │ Implicit sizing    │
│d.cpp│ Output elements        │ Easy         │ Iteration          │
│e.cpp│ Input elements         │ Easy         │ User input         │
│f.cpp│ Dynamic array size     │ Medium       │ Runtime sizing     │
│g.cpp│ Find max/min           │ Medium       │ Traversal logic    │
│h.cpp│ Array as pointer       │ Medium       │ Pointer relation   │
│i.cpp│ Array passing          │ Medium       │ Reference passing  │
│j.cpp│ Function parameters    │ Medium       │ Size needed        │
│k.cpp│ Linear search          │ Medium       │ Sequential search  │
│l.cpp│ Reverse (with space)   │ Medium       │ Copy approach      │
│m.cpp│ Reverse (in-place)     │ Medium       │ Swap technique     │
│n.cpp│ Pointer increment      │ Medium       │ Pointer arithmetic │
│o.cpp│ Addition/subtraction   │ Medium       │ Offset operations  │
│p.cpp│ Pointer addition       │ Medium       │ Address calculation│
│q.cpp│ Pointer array access   │ Medium       │ Pointer indexing   │
│r.cpp│ Pointer subtraction    │ Hard         │ Distance between   │
│s.cpp│ Pointer with arrays    │ Hard         │ Combined concepts  │
│t.cpp│ Pointer comparison     │ Hard         │ Address comparison │
└─────┴────────────────────────┴──────────────┴────────────────────┘
```
