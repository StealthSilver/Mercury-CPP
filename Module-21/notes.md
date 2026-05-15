MODULE 21 NOTES

DIVIDE AND CONQUER

This is a recursive algorithm: we split a big problem into smaller problems, solve each smaller one, then combine those answers into the answer for the original problem.

---

## Merge Sort → [a.cpp](a.cpp)

**Goal:** Sort an array in **ascending** order.

**Time complexity:** O(n log n) — we split the array in half each level (log n levels) and merge two halves in O(n) work per level.

**Space complexity:** O(n) extra space for the temporary merge array (plus O(log n) recursion stack depth).

### Idea (divide and conquer)

| Step | What happens |
|------|----------------|
| **Divide** | Split the range `[si, ei]` into a **left** half `[si, mid]` and **right** half `[mid+1, ei]`, where `mid = si + (ei - si) / 2`. |
| **Conquer** | Recursively sort the left half and the right half. |
| **Combine** | **Merge** the two sorted halves into one sorted range using a helper function. |

### Base case

If `si >= ei`, the subarray has 0 or 1 element — it is already sorted. Return without doing more work.

### Why recursion works here

- Sorting `[si, ei]` only needs correctly sorted `[si, mid]` and `[mid+1, ei]`.
- Each recursive call uses a **smaller** range, so we eventually hit the base case.
- After both halves return, we **merge** them in linear time.

### Merge step (combine)

Given two **already sorted** subarrays:

- Left: `arr[si .. mid]`
- Right: `arr[mid+1 .. ei]`

Use two pointers `i` (left) and `j` (right). At each step, copy the smaller of `arr[i]` and `arr[j]` into a temporary array, then advance that pointer. When one side is finished, copy the rest from the other side. Finally copy the temp array back into `arr[si .. ei]`.

### Example trace

Array: `[38, 27, 43, 3, 9, 82, 10]`

```
                    [38,27,43,3,9,82,10]
                   /                    \
          [38,27,43]                  [3,9,82,10]
          /        \                  /           \
    [38,27]      [43]            [3,9]        [82,10]
    /    \                      /   \         /    \
 [38]  [27]                   [3]  [9]     [82]  [10]
   \    /                       \  /         \    /
  [27,38]                      [3,9]      [10,82]
      \                          /            /
    [27,38,43]              [3,9,10,82]
            \                /
         [3,9,10,27,38,43,82]
```

### Complexity intuition

- **Height of recursion tree:** about log₂ n (keep halving the array).
- **Work per level:** merging all subarrays at that level touches every element once → O(n).
- **Total:** O(n) × O(log n) = **O(n log n)**.

### Compared to Module 13 sorts

Bubble, selection, and insertion sort are O(n²). Merge sort is one of the standard **efficient** comparison sorts and is stable (equal elements keep their relative order) when implemented as above.

**Reference:** [a.cpp](a.cpp) — full merge sort with `mergeSort` and `merge`.

---

## Quick Sort → [b.cpp](b.cpp)

**Goal:** Sort an array in **ascending** order using divide and conquer, but **without** a temporary merge array.

**Space complexity:** **O(1) extra space** (in-place partitioning). Recursion still uses **O(log n)** stack space on average, **O(n)** in the worst case — but we do **not** allocate another array of size n like merge sort.

| Case | Time complexity | When |
|------|-----------------|------|
| **Average** | O(n log n) | Pivot splits the range roughly in half |
| **Worst** | O(n²) | Pivot is always the smallest or largest (e.g. already sorted array with last-element pivot) |

### Idea (divide and conquer)

| Step | What happens |
|------|----------------|
| **Choose pivot** | Pick one element (here: **last** element `arr[ei]`). |
| **Partition** | Rearrange `[si, ei]` so elements **≤ pivot** are on the **left**, and elements **> pivot** are on the **right**. Pivot ends at its final sorted position `p`. |
| **Conquer** | Recursively sort `[si, p-1]` and `[p+1, ei]`. No separate **combine** step — partitioning already places the pivot correctly. |

### Base case

If `si >= ei`, the subarray has 0 or 1 element — already sorted.

### Partition (Lomuto, pivot = `arr[ei]`)

Use index `i` for the boundary of the “≤ pivot” region (starts at `si - 1`). Scan `j` from `si` to `ei - 1`:

- If `arr[j] <= pivot`, increment `i` and swap `arr[i]` with `arr[j]`.
- After the loop, swap `arr[i+1]` with `arr[ei]` so the pivot sits between the two parts.
- Return `p = i + 1` (pivot’s final index).

After partition:

```
[  elements ≤ pivot  | pivot |  elements > pivot  ]
```

### Example

Array: `[38, 27, 43, 3, 9, 82, 10]`, pivot = `10` (last)

After partition (one possible outcome): smaller values left of `10`, larger right — then recurse on each side.

### Merge sort vs quick sort

| | Merge sort | Quick sort |
|---|------------|------------|
| **Extra array** | Yes, O(n) for merge | No, in-place partition |
| **Combine step** | Explicit merge | Done during partition |
| **Average time** | O(n log n) | O(n log n) |
| **Worst time** | O(n log n) | O(n²) |
| **Stability** | Stable (with `<=` in merge) | Not stable (swaps) |

### Why worst case is O(n²)

If every partition is **unbalanced** (e.g. pivot is always min or max), one side has `n-1` elements and the other has `0`. You get **n** levels of recursion and **O(n)** work per level → **O(n²)**.

**Reference:** [b.cpp](b.cpp) — `quickSort` and `partition`.