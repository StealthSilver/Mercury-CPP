# DSA with C++ — Module 12 Notes

---

## 🔹 Introduction to Advanced Array Problems

This module covers advanced array manipulation techniques and classic algorithmic problems. These problems require understanding compound data structures and optimized solution strategies using dynamic programming and greedy approaches.

---

## 🔹 Subarrays and Subsequences

**Fundamental distinction**: Understanding the difference between subarrays and subsequences is crucial for many array problems.

### Definitions

```
┌────────────────────────────────────────────────────────┐
│          Subarrays vs Subsequences                     │
├────────────────────────────────────────────────────────┤
│ SUBARRAY:                                              │
│ • Contiguous elements in the original order            │
│ • Must be consecutive indices                          │
│ • Example: [1,2,3,4,5]                                 │
│   Valid subarrays: [2,3], [3,4,5], [1]                 │
│   Invalid: [1,3,5] (not contiguous)                     │
│                                                        │
│ SUBSEQUENCE:                                           │
│ • Elements follow original order but NOT contiguous    │
│ • Indices don't need to be consecutive                 │
│ • Example: [1,2,3,4,5]                                 │
│   Valid subsequences: [1,3,5], [2,4], [1,2,5]         │
│   Invalid: [5,3,1] (order breaks)                      │
└────────────────────────────────────────────────────────┘
```

### Counting Subarrays

For an array of size **n**, the total number of possible subarrays is:

$$\text{Total Subarrays} = n + (n-1) + (n-2) + \ldots + 1 = \frac{n(n+1)}{2}$$

**Intuition**: Each element can be a starting point, and from each start, multiple subarrays are possible.

### Print All Subarrays

```
┌────────────────────────────────────────────────────────┐
│         Brute Force Approach (3 Nested Loops)          │
├────────────────────────────────────────────────────────┤
│ for i = 0 to n-1              (starting index)         │
│   for j = i to n-1            (ending index)           │
│     for k = i to j            (print elements)         │
│       print arr[k]                                     │
│                                                        │
│ This generates:                                        │
│ [1], [1,2], [1,2,3], ...                               │
│      [2], [2,3], ...                                   │
│           [3], ...                                     │
└────────────────────────────────────────────────────────┘
```

### Complexity Analysis

```
┌─────────────────────────────────────┬──────────────────┐
│ Approach                            │ Complexity       │
├─────────────────────────────────────┼──────────────────┤
│ Nested loops (printing all)         │ O(n³)            │
│ Optimized with string accumulation  │ O(n²)            │
│ Space required                      │ O(1)             │
└─────────────────────────────────────┴──────────────────┘
```

Reference: [a.cpp](a.cpp)

---

## 🔹 Maximum Subarray Sum

**Problem Statement**: Given an array of integers, find the contiguous subarray with the largest sum and return that sum.

**Core Challenge**: The array may contain negative numbers, making it non-trivial to find the optimal subarray.

### Approach 1: Brute Force (Exhaustive Search)

```
┌────────────────────────────────────────────────────────┐
│              Brute Force Algorithm                     │
├────────────────────────────────────────────────────────┤
│ 1. Generate all possible subarrays                     │
│ 2. For each subarray, calculate the sum               │
│ 3. Track the maximum sum encountered                   │
│ 4. Return maximum sum                                  │
│                                                        │
│ Time: Check all n(n+1)/2 subarrays                    │
│ Space: O(1) - only storing max value                  │
└────────────────────────────────────────────────────────┘
```

### Approach 2: Prefix Sum Optimization

```
┌────────────────────────────────────────────────────────┐
│          Prefix Sum Optimization                       │
├────────────────────────────────────────────────────────┤
│ Key Insight: No need to recalculate sums from scratch  │
│                                                        │
│ For subarray [i, j]:                                   │
│ sum = prefixSum[j+1] - prefixSum[i]                    │
│                                                        │
│ This eliminates the innermost loop needed for summing │
│ Still need 2 loops for start and end positions         │
│                                                        │
│ Time: O(n²) - one loop saved                          │
│ Space: O(n) - auxiliary array needed                   │
└────────────────────────────────────────────────────────┘
```

### Approach 3: Kadane's Algorithm (Optimal - Dynamic Programming)

```
┌────────────────────────────────────────────────────────┐
│            Kadane's Algorithm (DP Approach)            │
├────────────────────────────────────────────────────────┤
│ Key Insight: Make locally optimal choices at each step │
│                                                        │
│ at each position i, decide:                            │
│ • Continue current subarray by adding arr[i]          │
│ • OR start fresh from arr[i]                           │
│                                                        │
│ Decision: maxSum = max(arr[i], maxSum + arr[i])       │
│                                                        │
│ Logic:                                                 │
│ • If previous sum + current element > current element │
│   then include current element in subarray             │
│ • Otherwise, start a new subarray from current element │
│ • Track maximum sum at each step                       │
│                                                        │
│ Time: O(n) - single pass                              │
│ Space: O(1) - only two variables needed                │
└────────────────────────────────────────────────────────┘
```

### Comparison

```
┌─────────────────┬──────────────┬──────────────┬─────────────────┐
│ Approach        │ Time Comp.   │ Space Comp.  │ When to Use     │
├─────────────────┼──────────────┼──────────────┼─────────────────┤
│ Brute Force     │ O(n³)        │ O(1)         │ Small arrays    │
│ Prefix Sum      │ O(n²)        │ O(n)         │ Medium arrays   │
│ Kadane (DP)     │ O(n)         │ O(1)         │ Production code │
└─────────────────┴──────────────┴──────────────┴─────────────────┘
```

Reference: [b.cpp](b.cpp) - Brute force, [c.cpp](c.cpp) - Prefix sum optimization, [d.cpp](d.cpp) - Kadane's algorithm

---

## 🔹 Best Time to Buy and Sell Stock

**Problem Statement**: Given an array of stock prices for consecutive days, find the maximum profit you can achieve by buying on one day and selling on a later day. You must sell after you buy.

**Constraint**: You can only complete one transaction (buy once, sell once).

### Problem Analysis

```
┌────────────────────────────────────────────────────────┐
│         Key Insights                                   │
├────────────────────────────────────────────────────────┤
│ • Selling price must be AFTER buying price             │
│ • Maximum profit = max(sellPrice - buyPrice)           │
│   across all valid pairs                               │
│ • Negative profit means no transaction is good         │
│ • We want minimum buy price up to current day          │
│ • We want maximum sell price from current day onward   │
└────────────────────────────────────────────────────────┘
```

### Optimal Solution: Track Minimum Buy Price

```
┌────────────────────────────────────────────────────────┐
│         Single Pass Algorithm                          │
├────────────────────────────────────────────────────────┤
│ 1. Keep track of minimum price seen so far             │
│ 2. For each day, calculate profit if selling today:    │
│    profit = currentPrice - minPriceSoFar              │
│ 3. Update maximum profit                               │
│ 4. Update minimum price if current price is lower     │
│                                                        │
│ Variables needed:                                      │
│ • minPrice: Lowest price encountered                   │
│ • maxProfit: Best profit found                         │
│                                                        │
│ Time: O(n) - single pass through array                │
│ Space: O(1) - only two variables                       │
└────────────────────────────────────────────────────────┘
```

### Example Walkthrough

```
Prices: [7, 1, 5, 3, 6, 4]

Day 0: price=7   minPrice=7, maxProfit=0
Day 1: price=1   profit=1-7=-6, minPrice=1, maxProfit=0
Day 2: price=5   profit=5-1=4,  minPrice=1, maxProfit=4
Day 3: price=3   profit=3-1=2,  minPrice=1, maxProfit=4
Day 4: price=6   profit=6-1=5,  minPrice=1, maxProfit=5
Day 5: price=4   profit=4-1=3,  minPrice=1, maxProfit=5

Answer: 5 (buy at 1, sell at 6)
```

Reference: [e.cpp](e.cpp)

---

## 🔹 Trapping Rainwater

**Problem Statement**: Given an array representing elevation heights, calculate how much rainwater can be trapped after it rains.

**Visualization**:

```
Height array: [0,1,0,2,1,0,1,3,2,1,2,1]

                    |
      |  _  |       |
  | _| | | | | _| | | | _|
  0 1 0 2 1 0 1 3 2 1 2 1
```

### Core Concept

```
┌────────────────────────────────────────────────────────┐
│            How Water Traps                             │
├────────────────────────────────────────────────────────┤
│ At each position i:                                    │
│                                                        │
│ Water level = min(leftMax[i], rightMax[i])             │
│   where leftMax = tallest bar to the LEFT             │
│   where rightMax = tallest bar to the RIGHT           │
│                                                        │
│ Water trapped at i = water level - height[i]          │
│   (if water level > height[i], otherwise 0)           │
│                                                        │
│ Constraints:                                           │
│ • Minimum size: n ≥ 3                                  │
│ • No water traps in purely ascending/descending order  │
│ • Each bar needs higher bars on both sides             │
└────────────────────────────────────────────────────────┘
```

### Optimal Solution: Precompute Max Arrays

```
┌────────────────────────────────────────────────────────┐
│         Two-Pass Algorithm with Helper Arrays          │
├────────────────────────────────────────────────────────┤
│ STEP 1: Build leftMax array                            │
│ For each index i: leftMax[i] = max height up to i     │
│ Initialize: leftMax[0] = height[0]                    │
│                                                        │
│ STEP 2: Build rightMax array                           │
│ For each index i: rightMax[i] = max height from i     │
│ Initialize: rightMax[n-1] = height[n-1]               │
│                                                        │
│ STEP 3: Calculate water at each position              │
│ For each i:                                            │
│   waterLevel = min(leftMax[i], rightMax[i])            │
│   water[i] = max(0, waterLevel - height[i])            │
│                                                        │
│ STEP 4: Sum all water amounts                          │
│                                                        │
│ Time: O(n) - three separate passes                     │
│ Space: O(n) - two auxiliary arrays                     │
└────────────────────────────────────────────────────────┘
```

### Important Implementation Details

```
┌────────────────────────────────────────────────────────┐
│            Common Pitfalls                             │
├────────────────────────────────────────────────────────┤
│ ❌ DON'T initialize with INT_MAX or INT_MIN            │
│    Reason: Addition/subtraction causes overflow       │
│    and circular integer wraparound                     │
│                                                        │
│ ✓ DO initialize properly:                              │
│   leftMax[0] = height[0]                               │
│   rightMax[n-1] = height[n-1]                          │
│                                                        │
│ ✓ DO set negative water amounts to 0                   │
│   This handles bars shorter than water level          │
└────────────────────────────────────────────────────────┘
```

### Complexity Analysis

```
┌──────────────────────────┬──────────┬──────────┐
│ Approach                 │ Time     │ Space    │
├──────────────────────────┼──────────┼──────────┤
│ Precomputed (optimal)    │ O(n)     │ O(n)     │
│ Stack-based (advanced)   │ O(n)     │ O(n)     │
│ Two-pointer technique    │ O(n)     │ O(1)     │
└──────────────────────────┴──────────┴──────────┘
```

Reference: [f.cpp](f.cpp)

---

## 🔹 Problem 1: Contains Duplicate

**Problem Statement**: Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

### Solution Approaches

```
┌──────────────────────────────────────────────────────────┐
│           Approach 1: Brute Force (Comparison)           │
├──────────────────────────────────────────────────────────┤
│ Algorithm:                                               │
│ • For each element at index i                            │
│ • Compare with all elements at index j (j > i)          │
│ • If any match found, return true                        │
│ • If no duplicates after checking all, return false      │
│                                                          │
│ Time Complexity:  O(n²)                                  │
│ Space Complexity: O(1)                                   │
│ When to Use: Educational purposes, very small arrays    │
└──────────────────────────────────────────────────────────┘
```

```
┌──────────────────────────────────────────────────────────┐
│           Approach 2: Sorting                            │
├──────────────────────────────────────────────────────────┤
│ Algorithm:                                               │
│ 1. Sort the array                                        │
│ 2. Iterate through and check if arr[i] == arr[i+1]      │
│ 3. If duplicate found, return true                       │
│ 4. If no duplicate after iteration, return false         │
│                                                          │
│ Time Complexity:  O(n log n)  (sorting dominates)        │
│ Space Complexity: O(1) or O(n) (depends on sort method) │
│ When to Use: Medium arrays, space-constrained systems   │
└──────────────────────────────────────────────────────────┘
```

```
┌──────────────────────────────────────────────────────────┐
│        Approach 3: HashSet (Optimal)                     │
├──────────────────────────────────────────────────────────┤
│ Algorithm:                                               │
│ 1. Create an empty unordered_set                         │
│ 2. For each element in array:                            │
│    • If element exists in set, return true (duplicate)   │
│    • Otherwise, insert element into set                  │
│ 3. If loop completes, return false (all distinct)        │
│                                                          │
│ Time Complexity:  O(n)      (average case)               │
│ Space Complexity: O(n)      (set storage)                │
│ When to Use: Production code, prioritize speed          │
└──────────────────────────────────────────────────────────┘
```

### Recommendation

**Use HashSet approach** for optimal performance in most scenarios. It provides linear time complexity and is straightforward to implement.

Reference: [g.cpp](g.cpp)

---

## 🔹 Problem 2: Search in Rotated Sorted Array

**Problem Statement**: A sorted array has been rotated at an unknown pivot index. Given the rotated array and a target value, find the index of the target or return -1 if not found. **Constraint**: Must achieve O(log n) time complexity (binary search required).

### Problem Visualization

```
Original sorted:    [0, 1, 2, 4, 5, 6, 7]
Rotated at index 3: [4, 5, 6, 7, 0, 1, 2]
                     ↑ pivot point
```

### Key Insights

```
┌────────────────────────────────────────────────────────┐
│          Binary Search on Rotated Array                 │
├────────────────────────────────────────────────────────┤
│ 1. At least one half is ALWAYS sorted                  │
│                                                        │
│ 2. Compare middle element with both ends to identify   │
│    which half is sorted                                 │
│                                                        │
│ 3. Check if target is in the sorted half               │
│    • If YES: search that half                          │
│    • If NO: search the other half                      │
│                                                        │
│ 4. Repeat until target found or search space exhausted │
└────────────────────────────────────────────────────────┘
```

### Algorithm Steps

```
┌────────────────────────────────────────────────────────┐
│          Rotated Array Binary Search                    │
├────────────────────────────────────────────────────────┤
│ 1. Initialize: left = 0, right = n-1                   │
│                                                        │
│ 2. While left <= right:                                │
│                                                        │
│    a) mid = (left + right) / 2                         │
│                                                        │
│    b) If arr[mid] == target: return mid                │
│                                                        │
│    c) Determine which half is sorted:                  │
│       • arr[left] <= arr[mid]?  LEFT half sorted       │
│       • Otherwise: RIGHT half sorted                   │
│                                                        │
│    d) Check if target is in sorted half:               │
│       • If in range: search that half                  │
│       • Else: search other half                        │
│                                                        │
│ 3. If not found: return -1                             │
│                                                        │
│ Time: O(log n) - binary search                         │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

### Hint for Implementation

When determining which half to search, compare `target` with the range boundaries of the sorted half:

```cpp
if (arr[left] <= arr[mid])  // LEFT half is sorted
{
    if (arr[left] <= target && target <= arr[mid])
        right = mid - 1;    // target in left half
    else
        left = mid + 1;     // target in right half
}
else                        // RIGHT half is sorted
{
    if (arr[mid] <= target && target <= arr[right])
        left = mid + 1;     // target in right half
    else
        right = mid - 1;    // target in left half
}
```

Reference: [h.cpp](h.cpp)

---

## 🔹 Problem 3: Maximum Product Subarray

**Problem Statement**: Given an array of integers, find the contiguous subarray with the largest product and return that product value.

**Challenge**: Array can contain negative numbers, zeros, and mixed values making it complex.

### Why This is Tricky

```
┌────────────────────────────────────────────────────────┐
│         Complexity Factors                              │
├────────────────────────────────────────────────────────┤
│ • Negative × Negative = Positive (can create max)       │
│ • Negative × Positive = Negative (can destroy product)  │
│ • Zero resets the product to zero                       │
│ • Must track BOTH max AND min products                  │
│   (minimum negative can become maximum with next neg)   │
│                                                        │
│ Example: [2, 3, -2, 4]                                 │
│ • [2] → max = 2                                         │
│ • [2,3] → max = 6                                       │
│ • [2,3,-2] → max = 6 BUT min = -6 (important!)         │
│ • [2,3,-2,4] → min×4 = -6×4 = -24, but we still have 6 │
│                                                        │
│ Without tracking min, we'd miss the true maximum!      │
└────────────────────────────────────────────────────────┘
```

### Optimal Solution: Dynamic Programming (Track Min & Max)

```
┌────────────────────────────────────────────────────────┐
│         DP Approach (Track Both Extremes)              │
├────────────────────────────────────────────────────────┤
│ Key: At each position, maintain:                       │
│ • maxProduct: maximum product ending at i              │
│ • minProduct: minimum product ending at i              │
│                                                        │
│ For each element:                                      │
│ temp = maxProduct                                      │
│ maxProduct = max(arr[i],                               │
│               maxProduct × arr[i],                     │
│               minProduct × arr[i])                     │
│ minProduct = min(arr[i],                               │
│               temp × arr[i],                           │
│               minProduct × arr[i])                     │
│                                                        │
│ Track global maximum seen so far                       │
│                                                        │
│ Time: O(n) - single pass                               │
│ Space: O(1) - only a few variables                     │
└────────────────────────────────────────────────────────┘
```

### Example Walkthrough

```
Array: [-2, 3, -4]

Index 0: arr[0] = -2
  maxProduct = -2, minProduct = -2, result = -2

Index 1: arr[1] = 3
  maxProduct = max(3, -2×3, -2×3) = max(3, -6, -6) = 3
  minProduct = min(3, -2×3, -2×3) = min(3, -6, -6) = -6
  result = 3

Index 2: arr[2] = -4
  maxProduct = max(-4, 3×(-4), -6×(-4)) = max(-4, -12, 24) = 24
  minProduct = min(-4, 3×(-4), -6×(-4)) = min(-4, -12, 24) = -12
  result = 24

Answer: 24 (subarray [-4] with min product -6 multiplied by -4 gives 24)
```

### Why We Track Minimum

The minimum (most negative) product can become the maximum when multiplied by the next negative number. Discarding it would cause us to miss valid maximum products.

Reference: [i.cpp](i.cpp)

---

## 🔹 Summary Table

```
┌────┬──────────────────────────┬──────────┬─────────────┬──────────────┐
│ # │ Problem                  │ File     │ Difficulty  │ Core Concept │
├────┼──────────────────────────┼──────────┼─────────────┼──────────────┤
│ 1  │ Print All Subarrays      │ a.cpp    │ Easy        │ Nested loops │
│ 2  │ Max Subarray Sum         │ b.cpp    │ Medium      │ Brute force  │
│ 3  │ Max Subarray (Optimized) │ c.cpp    │ Medium      │ Prefix sums  │
│ 4  │ Max Subarray (Kadane)    │ d.cpp    │ Hard        │ DP approach  │
│ 5  │ Buy & Sell Stock         │ e.cpp    │ Hard        │ Greedy + DP  │
│ 6  │ Trapping Rainwater       │ f.cpp    │ Hard        │ Aux arrays   │
│ 7  │ Contains Duplicate       │ g.cpp    │ Easy        │ HashSet      │
│ 8  │ Search Rotated Array     │ h.cpp    │ Hard        │ Bin search   │
│ 9  │ Max Product Subarray     │ i.cpp    │ Hard        │ Min/Max DP   │
└────┴──────────────────────────┴──────────┴─────────────┴──────────────┘
```

---

## 🔹 Best Practices for Array Problems

```
┌────────────────────────────────────────────────────────┐
│           Problem-Solving Strategy                     │
├────────────────────────────────────────────────────────┤
│ ANALYSIS PHASE:                                        │
│ ✓ Understand what's being asked clearly                │
│ ✓ Identify constraints (time, space, etc.)            │
│ ✓ Work through small examples manually                 │
│ ✓ Identify patterns                                    │
│                                                        │
│ SOLUTION DESIGN:                                       │
│ ✓ Start with brute force if unsure                     │
│ ✓ Identify inefficiencies                              │
│ ✓ Look for optimization opportunities                  │
│ ✓ Consider data structures that help                   │
│                                                        │
│ EDGE CASES:                                            │
│ ✓ Test with empty arrays                               │
│ ✓ Test with single element                             │
│ ✓ Test with negative numbers                           │
│ ✓ Test with duplicates                                 │
│ ✓ Test with sorted/unsorted input                      │
│                                                        │
│ OPTIMIZATION:                                          │
│ ✗ Don't prematurely optimize                           │
│ ✓ Profile and identify bottlenecks first               │
│ ✓ Balance time vs space tradeoffs                      │
│ ✓ Document your approach clearly                       │
└────────────────────────────────────────────────────────┘
```
