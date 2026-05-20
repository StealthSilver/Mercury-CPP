# DSA with C++ — Module 13 Notes

---

## 🔹 Introduction to Sorting

**Sorting** is the process of arranging elements in a specific order, typically ascending (smallest to largest) or descending (largest to smallest). Efficient sorting is fundamental to many algorithms and applications.

### Definition

```
┌────────────────────────────────────────────────────────┐
│                 Sorting Definition                     │
├────────────────────────────────────────────────────────┤
│ Given an array of comparable elements,                 │
│ rearrange them into a specified order:                 │
│                                                        │
│ Example Array: [2, 3, 1, 4, 5]                         │
│                                                        │
│ Ascending Order:  [1, 2, 3, 4, 5]  (↑)                 │
│ Descending Order: [5, 4, 3, 2, 1]  (↓)                 │
│                                                        │
│ Key Properties:                                        │
│ • Stable: Equal elements maintain relative order       │
│ • In-place: Doesn't require extra space                │
│ • Comparison-based or Non-comparison-based             │
└────────────────────────────────────────────────────────┘
```

### Sorting Algorithms Covered

This module covers **four fundamental sorting algorithms** and their practical applications:

```
┌────────┬──────────────────┬──────────────┬──────────────┐
│ Name   │ Best for         │ Time Comp.   │ Space Comp.  │
├────────┼──────────────────┼──────────────┼──────────────┤
│ Bubble │ Educational      │ O(n²)        │ O(1)         │
│ Select │ Educational      │ O(n²)        │ O(1)         │
│ Insert │ Nearly sorted    │ O(n²) avg    │ O(1)         │
│ Count  │ Bounded range    │ O(n+k)       │ O(k)         │
└────────┴──────────────────┴──────────────┴──────────────┘
```

**Note**: These basic algorithms have O(n²) complexity. More efficient algorithms like Merge Sort and Quick Sort use recursion and will be covered later.

---

## 🔹 Bubble Sort

**Bubble sort** is the simplest sorting algorithm. It repeatedly steps through the array, compares adjacent elements, and swaps them if they're in the wrong order. Larger elements "bubble" to the end with each pass.

### How It Works

```
┌────────────────────────────────────────────────────────┐
│              Bubble Sort Algorithm                     │
├────────────────────────────────────────────────────────┤
│ for i = 0 to n-1                                       │
│   for j = 0 to n-2-i                                   │
│     if arr[j] > arr[j+1]                               │
│       swap(arr[j], arr[j+1])                           │
│                                                        │
│ Key Insight:                                           │
│ • After each pass, one more element is in final place  │
│ • Largest element moves to end in first pass          │
│ • Number of passes needed: n-1                         │
│ • Each pass compares one fewer pair (n-1-i)            │
└────────────────────────────────────────────────────────┘
```

### Visualization

```
Initial:      [5, 3, 8, 4, 2]

Pass 1:
  5>3→swap:   [3, 5, 8, 4, 2]
  5<8→no:     [3, 5, 8, 4, 2]
  8>4→swap:   [3, 5, 4, 8, 2]
  8>2→swap:   [3, 5, 4, 2, 8]  → 8 in place

Pass 2:
  3<5→no:     [3, 5, 4, 2, 8]
  5>4→swap:   [3, 4, 5, 2, 8]
  5>2→swap:   [3, 4, 2, 5, 8]  → 5 in place

Pass 3:
  3<4→no:     [3, 4, 2, 5, 8]
  4>2→swap:   [3, 2, 4, 5, 8]  → 4 in place

Pass 4:
  3>2→swap:   [2, 3, 4, 5, 8]  → Done!
```

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│         Bubble Sort Complexity                         │
├────────────────────────────────────────────────────────┤
│ Time Complexity:  O(n²)                                │
│   Calculation: (n-1) + (n-2) + ... + 1 = n(n-1)/2      │
│                                                        │
│ Space Complexity: O(1)                                 │
│   Only swapping in-place, no extra array needed        │
│                                                        │
│ Stable: YES (equal elements maintain order)            │
│ In-place: YES (no extra space)                         │
└────────────────────────────────────────────────────────┘
```

### Optimization: Early Termination

```
┌────────────────────────────────────────────────────────┐
│      Boolean Flag Optimization                         │
├────────────────────────────────────────────────────────┤
│ Problem: Already sorted arrays still take O(n²) time  │
│                                                        │
│ Solution: Track if any swap occurred                   │
│                                                        │
│ for i = 0 to n-1                                       │
│   swapped = false                                      │
│   for j = 0 to n-2-i                                   │
│     if arr[j] > arr[j+1]                               │
│       swap(arr[j], arr[j+1])                           │
│       swapped = true                                   │
│   if !swapped: return  (early exit)                    │
│                                                        │
│ Best Case: O(n)   (already sorted)                     │
│ Worst Case: O(n²) (reverse sorted)                     │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp) - Basic bubble sort, [b.cpp](b.cpp) - Optimized with boolean flag

---

## 🔹 Selection Sort

**Selection sort** divides the array into two parts: sorted and unsorted. It repeatedly finds the minimum element from the unsorted portion and places it at the beginning of the unsorted subarray.

### How It Works

```
┌────────────────────────────────────────────────────────┐
│            Selection Sort Algorithm                    │
├────────────────────────────────────────────────────────┤
│ for i = 0 to n-1                                       │
│   min_index = i                                        │
│   for j = i+1 to n-1                                   │
│     if arr[j] < arr[min_index]                         │
│       min_index = j                                    │
│   swap(arr[i], arr[min_index])                         │
│                                                        │
│ Process:                                               │
│ 1. Find minimum in unsorted part                       │
│ 2. Place it at start of unsorted part                  │
│ 3. Shrink unsorted part and repeat                     │
└────────────────────────────────────────────────────────┘
```

### Visualization

```
Initial:      [5, 3, 8, 4, 2]

Pass 1:
  Find min:   2 at index 4
  Swap:       [2, 3, 8, 4, 5]

Pass 2:
  Find min:   3 at index 1 (already there)
  Swap:       [2, 3, 8, 4, 5]

Pass 3:
  Find min:   4 at index 3
  Swap:       [2, 3, 4, 8, 5]

Pass 4:
  Find min:   5 at index 4
  Swap:       [2, 3, 4, 5, 8]

Result:       [2, 3, 4, 5, 8]
```

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│       Selection Sort Complexity                        │
├────────────────────────────────────────────────────────┤
│ Time Complexity:  O(n²)  (always)                      │
│   Best, Average, Worst: all O(n²)                      │
│   Always n(n-1)/2 comparisons                          │
│                                                        │
│ Space Complexity: O(1)                                 │
│   Only one temporary variable for swapping             │
│                                                        │
│ Stable: NO (may reorder equal elements)                │
│ In-place: YES                                          │
│                                                        │
│ Advantage: Minimizes number of swaps (O(n))            │
└────────────────────────────────────────────────────────┘
```

Reference: [c.cpp](c.cpp)

---

## 🔹 Insertion Sort

**Insertion sort** builds a sorted array one item at a time. It takes elements from the unsorted portion and inserts them into their correct position in the sorted portion.

### How It Works

```
┌────────────────────────────────────────────────────────┐
│           Insertion Sort Algorithm                     │
├────────────────────────────────────────────────────────┤
│ for i = 1 to n-1                              (start at 1, not 0)
│   key = arr[i]                                │
│   j = i - 1                                   │
│   while j >= 0 and arr[j] > key               │
│     arr[j+1] = arr[j]                         │ (shift)
│     j--                                       │
│   arr[j+1] = key                              │ (insert)
│                                                        │
│ Process:                                               │
│ 1. Start with second element                          │
│ 2. Compare with sorted portion                        │
│ 3. Shift larger elements right                        │
│ 4. Insert element in correct position                 │
└────────────────────────────────────────────────────────┘
```

### Visualization

```
Initial:      [5, 3, 8, 4, 2]
Sorted: [5]   Unsorted: [3, 8, 4, 2]

Step 1: Insert 3
  3 < 5: shift 5 right
  Result: [3, 5, 8, 4, 2]

Step 2: Insert 8
  8 > 5: no shift needed
  Result: [3, 5, 8, 4, 2]

Step 3: Insert 4
  4 < 8: shift 8 right          [3, 5, _, 4, 2]
  4 < 5: shift 5 right          [3, _, 5, 8, 2]
  4 > 3: insert at position 1
  Result: [3, 4, 5, 8, 2]

Step 4: Insert 2
  Shift 8, 5, 4, 3 all right
  Result: [2, 3, 4, 5, 8]
```

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│       Insertion Sort Complexity                        │
├────────────────────────────────────────────────────────┤
│ Time Complexity:                                       │
│   Best:    O(n)    (already sorted, 1 comparison each)│
│   Average: O(n²)                                       │
│   Worst:   O(n²)   (reverse sorted)                    │
│                                                        │
│ Space Complexity: O(1)                                 │
│   Only key and j variables needed                      │
│                                                        │
│ Stable: YES (equal elements maintain order)            │
│ In-place: YES                                          │
│                                                        │
│ Advantage: Efficient for nearly sorted arrays          │
│ Very efficient for small arrays (< 50 elements)        │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp)

---

## 🔹 Counting Sort

**Counting sort** is a non-comparison sorting algorithm. It counts the frequency of each distinct element and reconstructs the sorted array. It's highly efficient when the range of elements is small.

### Prerequisites and Use Cases

```
┌────────────────────────────────────────────────────────┐
│       When to Use Counting Sort                        │
├────────────────────────────────────────────────────────┤
│ ✓ Use when: Elements are in a bounded range           │
│ ✓ Examples: Ages (0-120), Grades (0-100), Colors      │
│ ✗ Don't use when: Range is very large (1-10^9)        │
│                                                        │
│ Input: arr[] = {4, 2, 3, 1, 2, 3}                     │
│ Range: min=1, max=4, k=4                              │
│                                                        │
│ Time: O(n + k) - efficient when k << n²               │
│ Space: O(k) - frequency array needed                   │
└────────────────────────────────────────────────────────┘
```

### How It Works

```
┌────────────────────────────────────────────────────────┐
│           Counting Sort Algorithm                      │
├────────────────────────────────────────────────────────┤
│ STEP 1: Create frequency count array                   │
│ for each element in arr:                               │
│   count[element]++                                     │
│                                                        │
│ STEP 2: Reconstruct sorted array                       │
│ for each element in range [min, max]:                  │
│   for i = 0 to count[element]-1:                      │
│     add element to output array                        │
│                                                        │
│ Alternative: Calculate cumulative counts for stability │
└────────────────────────────────────────────────────────┘
```

### Visualization

```
Input array:  [4, 2, 3, 1, 2, 3]

Step 1: Count frequencies
  count[1] = 1
  count[2] = 2
  count[3] = 2
  count[4] = 1

Step 2: Reconstruct
  Add 1 once:    [1]
  Add 2 twice:   [1, 2, 2]
  Add 3 twice:   [1, 2, 2, 3, 3]
  Add 4 once:    [1, 2, 2, 3, 3, 4]

Output array: [1, 2, 2, 3, 3, 4]
```

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│       Counting Sort Complexity                         │
├────────────────────────────────────────────────────────┤
│ Time Complexity:  O(n + k)                             │
│   where n = number of elements                        │
│   where k = range of input (max - min + 1)             │
│                                                        │
│ Space Complexity: O(k)                                 │
│   Frequency array size = k                             │
│                                                        │
│ Stable: YES (maintains order of equal elements)        │
│ In-place: NO (requires auxiliary arrays)               │
│                                                        │
│ Performance:                                           │
│   Better than O(n log n) when k = O(n)                │
│   Worse when k >> n (large range)                      │
└────────────────────────────────────────────────────────┘
```

Reference: [e.cpp](e.cpp)

---

## 🔹 Built-in Sort Function

C++ Standard Library provides an optimized sorting function through the `<algorithm>` header with O(n log n) time complexity.

### Syntax and Usage

```
┌────────────────────────────────────────────────────────┐
│           Built-in sort() Function                     │
├────────────────────────────────────────────────────────┤
│ #include <algorithm>                                   │
│                                                        │
│ ASCENDING ORDER (default):                             │
│ sort(arr.begin(), arr.end());                          │
│ or for C-style arrays:                                 │
│ sort(arr, arr + size);                                 │
│                                                        │
│ DESCENDING ORDER:                                      │
│ sort(arr.begin(), arr.end(), greater<int>());          │
│ or for C-style arrays:                                 │
│ sort(arr, arr + size, greater<int>());                 │
│                                                        │
│ Time Complexity: O(n log n)  (average & worst case)   │
│ Algorithm Used: Hybrid (IntroSort)                     │
│ Stable: NO (not necessarily)                           │
│ In-place: YES                                          │
└────────────────────────────────────────────────────────┘
```

### Why Use Built-in Sort?

```
┌────────────────────────────────────────────────────────┐
│        Advantages of Built-in Sort                     │
├────────────────────────────────────────────────────────┤
│ ✓ O(n log n) complexity - much faster on large arrays  │
│ ✓ Highly optimized implementation                      │
│ ✓ Uses hybrid algorithm (IntroSort):                  │
│   - QuickSort for larger arrays                        │
│   - HeapSort if recursion too deep                     │
│   - InsertionSort for small subarrays                  │
│ ✓ Less error-prone than custom implementation          │
│ ✓ Industry standard for production code                │
│                                                        │
│ In production: ALWAYS use built-in sort()             │
│ In interviews: Implement basic sorts to show          │
│   understanding, but use built-in in production       │
└────────────────────────────────────────────────────────┘
```

Reference: [f.cpp](f.cpp)

---

## 🔹 Problem: Sort Character Array

**Problem Statement**: Sort an array of characters using insertion sort algorithm in descending order.

**Input**: `char ch[] = {'f', 'b', 'a', 'c', 'd'};`

**Expected Output**: `{'f', 'd', 'c', 'b', 'a'}`

### Solution Approach

```
┌────────────────────────────────────────────────────────┐
│       Insertion Sort for Characters                    │
├────────────────────────────────────────────────────────┤
│ Modification from ascending to descending:             │
│                                                        │
│ Standard comparison:  if (arr[j] > key)               │
│ For descending:       if (arr[j] < key)               │
│   (shift elements smaller than key to the right)       │
│                                                        │
│ Algorithm:                                             │
│ 1. Start from second character (index 1)              │
│ 2. Compare with sorted portion (before it)            │
│ 3. Shift characters SMALLER than current right        │
│ 4. Insert current character in correct spot           │
│ 5. Repeat for all characters                          │
│                                                        │
│ Time: O(n²)     (same as regular insertion sort)       │
│ Space: O(1)     (in-place sorting)                     │
└────────────────────────────────────────────────────────┘
```

### Step-by-Step Walkthrough

```
Initial:       ['f', 'b', 'a', 'c', 'd']

Start: Sorted=['f']  Unsorted=['b', 'a', 'c', 'd']

Step 1: Insert 'b'
  'b' < 'f': shift 'f' right
  Result:    ['b', 'f', 'a', 'c', 'd']

Step 2: Insert 'a'
  'a' < 'f': shift 'f' right
  'a' < 'b': shift 'b' right
  Result:    ['a', 'b', 'f', 'c', 'd']

Step 3: Insert 'c'
  'c' < 'f': shift 'f' right
  'c' > 'b': insert at position 1
  Result:    ['b', 'c', 'f', 'a', 'd'] -- Wait, need to recalculate

Let me redo for DESCENDING properly:
Step 3: Insert 'c' in descending
  'c' < 'f': need to shift 'f' left? No, for DESCENDING
  We want larger chars at front
  'c' < 'f': 'f' stays at front
  'c' > 'b': insert 'c' after 'f'
  Result:    ['f', 'c', 'b', 'a', 'd']

Step 4: Insert 'd' in descending
  'd' < 'f': stays
  'd' > 'c': shifts left
  'd' > 'b': shifts left
  'd' > 'a': shifts left
  Result:    ['f', 'd', 'c', 'b', 'a']

Final:        ['f', 'd', 'c', 'b', 'a']
```

### Key Implementation Details

```
┌────────────────────────────────────────────────────────┐
│         Important Considerations                       │
├────────────────────────────────────────────────────────┤
│ • Use char data type for elements                      │
│ • Change comparison operator for descending:           │
│   From: arr[j] > key  (ascending)                     │
│   To:   arr[j] < key  (descending)                    │
│ • String of characters can be sorted same way         │
│ • Works identically to numeric insertion sort         │
│   just using character comparison                     │
└────────────────────────────────────────────────────────┘
```

Reference: [g.cpp](g.cpp)

---

## 🔹 Comparison of Basic Sorting Algorithms

```
┌────────┬──────────┬──────────┬──────────┬─────────┬──────────┐
│ Sort   │ Best     │ Average  │ Worst    │ Space   │ Stable   │
├────────┼──────────┼──────────┼──────────┼─────────┼──────────┤
│ Bubble │ O(n)     │ O(n²)    │ O(n²)    │ O(1)    │ Yes      │
│ Select │ O(n²)    │ O(n²)    │ O(n²)    │ O(1)    │ No       │
│ Insert │ O(n)     │ O(n²)    │ O(n²)    │ O(1)    │ Yes      │
│ Count  │ O(n+k)   │ O(n+k)   │ O(n+k)   │ O(k)    │ Yes      │
│ Built-in│ O(nlogn)│ O(nlogn) │ O(nlogn) │ O(logn) │ No*      │
└────────┴──────────┴──────────┴──────────┴─────────┴──────────┘

* Some implementations use stable sort; std::stable_sort is guaranteed stable
```

---

## 🔹 When to Use Each Algorithm

```
┌────────────────────────────────────────────────────────┐
│           Algorithm Selection Guide                    │
├────────────────────────────────────────────────────────┤
│ BUBBLE SORT:                                           │
│ • Learning purposes only                               │
│ • Understanding sorting concepts                       │
│ ✗ Never in production code                             │
│                                                        │
│ SELECTION SORT:                                        │
│ • Educational demonstrations                          │
│ • When minimizing memory writes is critical            │
│ ✗ Rarely in production                                 │
│                                                        │
│ INSERTION SORT:                                        │
│ • Nearly sorted data (nearly O(n) time)                │
│ • Small arrays (< 50 elements)                         │
│ • Online sorting (elements arrive one-by-one)          │
│ • Good performance with partially sorted data          │
│                                                        │
│ COUNTING SORT:                                         │
│ • Fixed bounded range (ages, grades, test scores)      │
│ • When k = O(n) for O(n) performance                   │
│ ✗ Not suitable for large ranges (1 to 10^9)           │
│                                                        │
│ BUILT-IN SORT:                                         │
│ ✓ USE IN PRODUCTION for general-purpose sorting       │
│ ✓ Provides O(n log n) guarantees                       │
│ ✓ Highly optimized and well-tested                     │
│ ✓ Handles all data types and custom comparators       │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Advanced Sorting Algorithms (Coming Later)

For larger arrays and production environments, more advanced algorithms provide better performance:

```
┌────────────────────────────────────────────────────────┐
│         Advanced Sorting Algorithms                    │
├────────────────────────────────────────────────────────┤
│ MERGE SORT:                                            │
│ • Divide-and-conquer approach using recursion          │
│ • Time: O(n log n) (always)                            │
│ • Space: O(n) (requires auxiliary space)               │
│ • Stable: YES                                          │
│ • Preferred when stability is required                 │
│                                                        │
│ QUICK SORT:                                            │
│ • Divide-and-conquer with pivot partitioning           │
│ • Time: O(n log n) average, O(n²) worst                │
│ • Space: O(log n) (recursion stack)                    │
│ • Stable: NO (standard implementation)                 │
│ • Fastest in practice for most scenarios               │
│                                                        │
│ HEAP SORT:                                             │
│ • Uses binary heap data structure                      │
│ • Time: O(n log n) (always)                            │
│ • Space: O(1)                                          │
│ • Used in hybrid algorithms                            │
│                                                        │
│ These will be studied when we cover recursion!         │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Best Practices for Sorting

```
┌────────────────────────────────────────────────────────┐
│           Sorting Best Practices                       │
├────────────────────────────────────────────────────────┤
│ ANALYSIS PHASE:                                        │
│ ✓ Understand data characteristics                      │
│ ✓ Determine range and size of input                    │
│ ✓ Check if stability is required                       │
│ ✓ Measure importance of space complexity               │
│                                                        │
│ ALGORITHM SELECTION:                                   │
│ ✓ Use built-in sort() for production                   │
│ ✓ Consider insertion sort for small/nearly sorted data │
│ ✓ Use counting sort only for bounded ranges             │
│ ✓ Learn basic algorithms for interview preparation     │
│                                                        │
│ IMPLEMENTATION:                                        │
│ ✓ Test with edge cases (empty, single element)        │
│ ✓ Test with duplicates                                 │
│ ✓ Verify ascending and descending order                │
│ ✓ Profile performance on large datasets                │
│                                                        │
│ OPTIMIZATION:                                          │
│ ✓ Profile first, optimize later                        │
│ ✓ Avoid unnecessary comparisons                        │
│ ✓ Consider hybrid approaches (IntroSort)               │
│ ✗ Don't reinvent the wheel (use standard library)      │
└────────────────────────────────────────────────────────┘
```
