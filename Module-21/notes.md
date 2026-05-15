# DSA with C++ — Module 21 Notes

**Topic:** Divide and conquer — merge sort, quick sort, modified binary search, and practice problems (strings, majority element, inversion count).  
**Companion code:** Each section links to a runnable `.cpp` in this folder. These notes explain *what* and *why*; open the files to see the full implementation.

**Prerequisite:** Module 13 (bubble, selection, insertion, counting sort) and Module 20 (recursion, base case, call stack).

---

## Divide and conquer (big picture)

**Divide and conquer** is a problem-solving pattern that fits naturally with **recursion**:

1. **Divide** — break the problem into **smaller subproblems** of the **same type** (e.g. sort half an array).
2. **Conquer** — solve each subproblem by **recursing** until you hit a **base case** you can answer directly.
3. **Combine** — use the subproblem answers to build the answer for the original problem (merge two sorted halves, or rely on partitioning so no extra combine step is needed).

| Idea | Detail |
|------|--------|
| **Smaller input each time** | Each recursive call must work on a **strictly smaller** range (or otherwise progress toward the base case). |
| **Base case** | Stops recursion — often “0 or 1 element” for sorting. |
| **Work at each level** | Some linear or near-linear work happens at every call (merge, partition). |
| **Recursion tree** | Time complexity is often **(depth of tree) × (work per level)**. |

Both algorithms in this module sort in **ascending** order by default. They are **comparison-based**: order is decided by comparing pairs of elements.

---

## Merge sort

**Merge sort** always splits the array into two **equal-sized (or nearly equal)** halves, sorts each half recursively, then **merges** the two sorted halves into one sorted range.

**Reference:** [a.cpp](a.cpp) — `mergeSort`, `merge`, and `printArr`.

### Algorithm (three steps)

| Step | What happens |
|------|----------------|
| **Divide** | For range `[si, ei]`, compute `mid = si + (ei - si) / 2`. Left subproblem: `[si, mid]`. Right: `[mid + 1, ei]`. |
| **Conquer** | Recursively call merge sort on the left half, then on the right half. |
| **Combine** | Call `merge` to merge the two **already sorted** halves back into `arr[si .. ei]`. |

Using `si + (ei - si) / 2` instead of `(si + ei) / 2` avoids integer overflow on very large indices (same midpoint, safer formula).

### Base case

If `si >= ei`, the subarray has **0 or 1** element — it is already sorted. **Return** without further recursion.

### Merge step (combine) — intuition

Imagine two sorted piles of cards (left half and right half). To merge:

- Compare the **front** of each pile.
- Take the **smaller** value and place it in the output.
- When one pile is empty, copy the rest from the other pile.

The implementation uses a **temporary array** of size equal to the current subrange, then copies the merged result back into `arr`. See [a.cpp](a.cpp) for the two-pointer merge loop.

### Example trace (splitting then merging)

Array: `[38, 27, 43, 3, 9, 82, 10]`

**Divide (down to size 1):**

```
                    [38,27,43,3,9,82,10]
                   /                    \
          [38,27,43]                  [3,9,82,10]
          /        \                  /           \
    [38,27]      [43]            [3,9]        [82,10]
    /    \                      /   \         /    \
 [38]  [27]                   [3]  [9]     [82]  [10]
```

**Conquer (merge back up):**

```
 [38] [27]  →  [27,38]
 [27,38] + [43]  →  [27,38,43]
 [3] [9]  →  [3,9]
 [82] [10]  →  [10,82]
 [3,9] + [10,82]  →  [3,9,10,82]
 [27,38,43] + [3,9,10,82]  →  [3,9,10,27,38,43,82]
```

### Time complexity — why O(n log n)

Think in terms of the **recursion tree**:

| Quantity | Merge sort |
|----------|------------|
| **Depth** | About **log₂ n** — each level splits the range in **half**. |
| **Work per level** | Every `merge` over a subarray of total length `n` at that level costs **O(length)**. Across **all** merges at one tree level, each element is touched a constant number of times → **O(n)** per level. |
| **Total** | **O(n) × O(log n) = O(n log n)** |

| Case | Time | Why |
|------|------|-----|
| **Best** | O(n log n) | Always divides in half; always merges. |
| **Average** | O(n log n) | Same as best for merge sort. |
| **Worst** | O(n log n) | Same — split is always balanced regardless of input order. |

Merge sort does **not** degrade to O(n²) on already sorted or reverse-sorted input (unlike naive quick sort with a bad pivot).

### Space complexity

| Component | Cost |
|-----------|------|
| **Temporary merge array** | **O(n)** extra space for the merge of the full array (each merge allocates a temp buffer for that subrange; peak auxiliary space is **O(n)**). |
| **Recursion stack** | **O(log n)** — depth of recursion is about log n. |

**Total auxiliary space:** **O(n)** (dominated by the temp array).

### Properties

| Property | Merge sort |
|----------|------------|
| **Stable** | **Yes** — when merging, if `arr[i] == arr[j]`, take from the **left** half first (`<=` comparison). Equal elements keep their original relative order. |
| **In-place** | **No** — needs extra space for merging. |
| **Predictable** | Worst-case time is always O(n log n). |

### Compared to Module 13 sorts

Bubble, selection, and insertion sort are **O(n²)** in typical and worst cases. Merge sort is a standard **efficient** comparison sort when you need **guaranteed** O(n log n) time and can afford **O(n)** extra memory.

---

## Quick sort

**Quick sort** also uses divide and conquer, but the **combine** step is different: there is **no separate merge**. Instead, a **partition** rearranges the array so the **pivot** is in its final position, with smaller elements on the left and larger on the right; then you recurse on the two sides.

**Reference:** [b.cpp](b.cpp) — `quickSort` and `partition` (Lomuto scheme, pivot = last element `arr[ei]`).

### Algorithm (three steps)

| Step | What happens |
|------|----------------|
| **Choose pivot** | In [b.cpp](b.cpp), the pivot is **`arr[ei]`** (last element of the current range). |
| **Partition** | Rearrange `[si, ei]` so all elements **≤ pivot** are on the **left**, all **> pivot** on the **right**. Pivot ends at index `p` (its final sorted position). |
| **Conquer** | Recursively sort `[si, p - 1]` and `[p + 1, ei]`. |

### Base case

If `si >= ei`, the subarray has 0 or 1 element — already sorted. Return.

### Partition (Lomuto) — intuition

Maintain a region “**≤ pivot**” on the left:

- Index `i` marks the end of that region (starts before `si`).
- Scan `j` from `si` to `ei - 1`.
- Whenever `arr[j] <= pivot`, grow the region: move `i` forward and swap `arr[i]` with `arr[j]`.
- After the scan, place the pivot **just after** that region (swap with `arr[i + 1]`).

Resulting layout:

```
[  elements ≤ pivot  |  pivot  |  elements > pivot  ]
```

Then recurse only on the left and right parts; the pivot is **never moved again**.

### Example (high level)

Array: `[38, 27, 43, 3, 9, 82, 10]`, pivot = `10`.

After partition, `10` sits between smaller values (e.g. `3`, `9`) and larger ones (e.g. `38`, `27`, …). Recurse on the left and right subarrays until every range has size 0 or 1.

### Time complexity — average case O(n log n)

**Average case** assumes pivots usually **split the range roughly in half** (random or “typical” data).

| Quantity | Typical behavior |
|----------|------------------|
| **Recursion depth** | About **log n** when partitions are balanced. |
| **Work per level** | Each `partition` scans its subarray once → **O(size of subarray)**. Summed over all subarrays at one tree level: **O(n)**. |
| **Total** | **O(n log n)** — same reasoning as merge sort when splits are balanced. |

**Intuition:** If you get a 50–50 split most of the time, the recursion tree looks like merge sort’s tree, so you get O(n log n) **on average**.

### Time complexity — worst case O(n²)

**Worst case** happens when **every partition is maximally unbalanced**: the pivot is always the **smallest** or **largest** element in the current range.

| Situation | What goes wrong |
|-----------|-----------------|
| **Already sorted array** + pivot = **last** element | Pivot is the maximum; left part has **n − 1** elements, right part has **0**. |
| **Reverse sorted** + pivot = last | Pivot is the minimum; right part empty, left has **n − 1** elements. |
| **Many equal elements** (with naive Lomuto) | Can also produce very uneven splits if not handled carefully. |

Then:

| Quantity | Worst case |
|----------|------------|
| **Recursion depth** | **O(n)** — one side has `n-1` elements, the other `0`, every time. |
| **Work per level** | Partition on sizes `n, n-1, n-2, …` → about **n + (n-1) + … + 1 = O(n²)** total comparisons/swaps across all levels. |
| **Total** | **O(n²)** |

**Important:** Worst case is **input-dependent** and **pivot-choice-dependent**. Production libraries often use **random pivot**, **median-of-three**, or switch to insertion sort on small ranges to avoid pathological O(n²) behavior on common inputs.

### Best case

If every partition is **perfectly balanced** (pivot is always the median), depth is **log n** and work per level is **O(n)** → **O(n log n)** best case.

### Summary table — quick sort time

| Case | Time | When |
|------|------|------|
| **Best** | O(n log n) | Balanced partitions every time (rare in practice with fixed pivot rule). |
| **Average** | O(n log n) | Pivot usually splits range into reasonable parts (random data, good pivot rules). |
| **Worst** | O(n²) | Pivot always min or max of current range (e.g. sorted array + last-element pivot). |

### Space complexity

| Component | Cost |
|-----------|------|
| **Partitioning** | **O(1)** extra — only a few indices and swaps; **in-place** in the array. |
| **Recursion stack** | **O(log n)** average (balanced splits), **O(n)** worst (skewed splits). |

When course notes say quick sort uses **“constant space,”** they usually mean **O(1) auxiliary array space** (no temp array of size n like merge sort). Recursion still consumes **stack** space as above.

### Properties

| Property | Quick sort |
|----------|------------|
| **Stable** | **No** — swapping during partition can change the relative order of equal elements. |
| **In-place** | **Yes** (aside from recursion stack). |
| **Worst time** | Can be O(n²); average is O(n log n). |

---

## Merge sort vs quick sort

| | Merge sort | Quick sort |
|---|------------|------------|
| **Divide** | Always split at **middle** | **Partition** around a **pivot** |
| **Combine** | Explicit **merge** of two sorted halves | **No merge** — pivot already in place |
| **Extra array space** | **O(n)** for merging | **O(1)** for partition (in-place) |
| **Best / average / worst time** | **O(n log n)** for all | **O(n log n)** average · **O(n²)** worst |
| **Stability** | **Stable** (with `<=` in merge) | **Not stable** |
| **Typical use** | Linked lists, external sort, when stability matters | General in-memory sort when average speed matters |

Both are **O(n log n)** in typical practice; merge sort **guarantees** that bound; quick sort is often **faster in practice** on arrays (good cache behavior, less copying) but needs care for worst-case inputs.

---

## Search in a rotated sorted array

**Problem:** You are given an array that was **sorted in ascending order with all distinct values**, then **rotated** at some unknown pivot index (elements after the pivot move to the front). Given `target`, return its **index**, or **-1** if it is not present.

**Example:** Original `[0, 1, 2, 4, 5, 6, 7]` rotated at index 4 → `[5, 6, 7, 0, 1, 2, 4]`. Target `0` → index **3**.

| Approach | Time | Space |
|----------|------|-------|
| Linear scan | O(n) | O(1) |
| **Modified binary search** (this module) | **O(log n)** | **O(1)** iterative · **O(log n)** stack if recursive |

**Reference:** [c.cpp](c.cpp) — recursive divide-and-conquer search.

---

### What “rotated” looks like (graph view)

Plot **value** (y) vs **index** (x). A normal sorted array is one rising line. After rotation you get a **“mountain” with a cliff”**: one segment still rises left-to-right, then a **drop**, then another rising segment.

```
Value
  7 |           *
  6 |         *
  5 |       *              (right part — still sorted)
  4 |     *
  3 |   *
  2 | *
  1 |*____________________  (left part — still sorted)
  0 |        *
    +--+--+--+--+--+--+--→ Index
       0  1  2  3  4  5  6

Array: [5, 6, 7, 0, 1, 2, 4]
              ↑ pivot / “break” between index 2 and 3
```

**Key insight:** The array is **not** fully sorted, but **at least one of the two halves** `[si, mid]` and `[mid+1, ei]` is **always a normal sorted range**. Binary search can still work if you first ask: *which half is sorted?* then *is target inside that sorted half?*

---

### Divide and conquer formulation

| Step | Role |
|------|------|
| **Divide** | Pick `mid`. Split range into left `[si, mid]` and right `[mid+1, ei]`. |
| **Conquer** | Recurse on **only one** half — the half that can contain `target`. |
| **Combine** | No merge step; answer comes directly from the recursive call. |

| Step | Role |
|------|------|
| **Base case** | `si > ei` → not found → `-1`. |
| **Work** | If `arr[mid] == target` → return `mid`. Decide which half is sorted and whether `target` lies in that half’s value range. |
| **Recursive call** | Search either `[si, mid-1]` or `[mid+1, ei]`. |

This is **modified binary search**: same O(log n) halving as normal binary search, with extra checks for rotation.

---

### Decision graph (each recursive level)

At every call you are at node **“range [si, ei]”**. Compute `mid`, then follow one branch:

```mermaid
flowchart TD
    A["Range [si, ei], mid = (si+ei)/2"] --> B{arr[mid] == target?}
    B -->|yes| C["Return mid"]
    B -->|no| D{arr[si] <= arr[mid]?}
    D -->|yes| E["LEFT half [si..mid] is sorted"]
    D -->|no| F["RIGHT half [mid..ei] is sorted"]
    E --> G{target in [arr[si], arr[mid])?}
    G -->|yes| H["Search LEFT: [si, mid-1]"]
    G -->|no| I["Search RIGHT: [mid+1, ei]"]
    F --> J{target in (arr[mid], arr[ei]]?}
    J -->|yes| K["Search RIGHT: [mid+1, ei]"]
    J -->|no| L["Search LEFT: [si, mid-1]"]
```

**How to read the graph:**

1. **Found** — if `arr[mid] == target`, stop.
2. **Which half is sorted?**
   - If `arr[si] <= arr[mid]` → left half is sorted (no break inside left).
   - Else → right half is sorted (break is in the left part).
3. **Is target in the sorted half’s range?** If yes, discard the other half; if no, search the other half.

Distinct elements make the range checks unambiguous (`<` vs `<=` at boundaries still matters; see [c.cpp](c.cpp)).

---

### Walkthrough (graph + indices)

Array: `[4, 5, 6, 7, 0, 1, 2]`, target = **0**

```
Index:  0   1   2   3   4   5   6
Value:  4   5   6   7   0   1   2
        |------- sorted -------|
                        |-- sorted --|
```

| Step | si | ei | mid | arr[mid] | Sorted half | Target in sorted range? | Next range |
|------|----|----|-----|----------|-------------|-------------------------|------------|
| 1 | 0 | 6 | 3 | 7 | Left `[4..7]` | 0 ∉ [4, 7) | right `[4, 6]` |
| 2 | 4 | 6 | 5 | 1 | Right `[0, 1, 2]` | 0 ∈ (arr[4], arr[5]]? check: 0 ≤ 0 ≤ 2 → search left of mid in right part | `[4, 4]` |
| 3 | 4 | 4 | 4 | 0 | — | found | return **4** |

(Exact boundary comparisons match [c.cpp](c.cpp); the table shows the *idea* of halving toward the cliff where `0` lives.)

---

### Why this is O(log n)

Each recursive step cuts the search range **roughly in half**, same as standard binary search. At most **log₂ n** levels → **O(log n)** time. No extra array is needed.

| Case | Time |
|------|------|
| **Best / average / worst** | O(log n) — always halving one side |

---

### Relation to other modules

| Module | Connection |
|--------|------------|
| **Module 20** — [p.cpp](../Module-20/p.cpp) | Ordinary binary search on a **fully** sorted array; one comparison tells you left vs right. |
| **Module 12** — [h.cpp](../Module-12/h.cpp) | Same problem, often shown with an **iterative** while-loop version. |
| **This module** — [c.cpp](c.cpp) | Same logic as **divide and conquer** / recursive binary search. |

---

## Practice problems (divide and conquer)

---

### Problem 1 — Merge sort on strings → [d.cpp](d.cpp)

**Task:** Sort an array of **strings** in **ascending lexicographic (dictionary) order** using **merge sort**. All characters are lowercase, so normal string comparison is enough.

**Sample**

| Input | Output |
|-------|--------|
| `{ "sun", "earth", "mars", "mercury" }` | `{ "earth", "mars", "mercury", "sun" }` |

**Lexicographic order:** Compare character by character left to right (like dictionary order). Example: `"earth" < "mars"` because `'e' < 'm'`. `"mars" < "mercury"` because `'a'` at index 1 is less than `'e'`.

**Algorithm:** Same divide-and-conquer as integer merge sort from [a.cpp](a.cpp):

| Step | Role |
|------|------|
| **Divide** | `mid = si + (ei - si) / 2`; sort left and right halves recursively. |
| **Base case** | `si >= ei` → done. |
| **Combine** | `merge` two sorted string halves using `<=` on `string` (or `compare`). |

**Complexity**

| | |
|---|---|
| **Time** | O(n log n × L) — n strings, each comparison up to length L of strings; often written O(n log n) when string lengths are bounded. |
| **Space** | O(n) for temporary string array during merge (plus O(log n) recursion stack). |

**Reference:** [d.cpp](d.cpp)

---

### Problem 2 — Majority element → [e.cpp](e.cpp)

**Task:** Given an array `nums` of size `n`, return the **majority element** — the value that appears **more than ⌊n / 2⌋** times. You may assume the majority element **always exists**.

**Sample:** `nums = [3, 2, 3]` → answer **3** (appears 2 times; ⌊3/2⌋ = 1).

**Constraints (typical):**

- `1 <= n <= 5 × 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`

#### Brute force (for understanding)

For each distinct value, count occurrences — O(n²) if done naïvely, O(n) with a hash map and O(n) space.

#### Boyer–Moore voting algorithm (used in [e.cpp](e.cpp))

**Idea:** Pair up different elements and “cancel” them. The majority survives because it has more than half the array.

| Phase | What happens |
|-------|----------------|
| **Find candidate** | Walk the array. Keep `candidate` and `count`. Same as candidate → `count++`. Different → `count--`. If `count == 0`, set new `candidate` and `count = 1`. |
| **Why it works** | Majority count exceeds n/2, so after all cancellations it remains as candidate. |
| **Verify (optional)** | When majority is **guaranteed**, skip verification. Otherwise count occurrences of `candidate`. |

**Example trace:** `[3, 2, 3]`

| Step | Element | candidate | count |
|------|---------|-----------|-------|
| start | — | 3 | 1 |
| 2 | 2 | 3 | 0 (cancel) |
| reset | 2 | 2 | 1 |
| 3 | 3 | 3 | 1 |

Answer: **3**.

**Complexity**

| | |
|---|---|
| **Time** | O(n) — one pass (two if you verify). |
| **Space** | O(1) — only candidate and counter. |

**Note:** A divide-and-conquer solution also exists (majority in left or right half), but Boyer–Moore is the standard O(n) / O(1) approach for this problem.

**Reference:** [e.cpp](e.cpp)

---

### Problem 3 — Inversion count → [f.cpp](f.cpp)

**Task:** Count **inversions** in an integer array.

**Definition:** A pair `(i, j)` is an inversion if **`i < j`** and **`arr[i] > arr[j]`** (out-of-order pair).

**Meaning:** Inversion count measures how “far” the array is from sorted:

| Array | Inversions |
|-------|------------|
| Already sorted ascending | **0** |
| Reverse sorted | **Maximum** — n(n−1)/2 |

**Sample:** `arr = {2, 4, 1, 3, 5}` → **3** inversions: **(2, 1)**, **(4, 1)**, **(4, 3)**.

#### Brute force

Check every pair `(i, j)` with `i < j` — **O(n²)**.

#### Optimal: modified merge sort → [f.cpp](f.cpp)

Use **divide and conquer** like merge sort:

| Step | Role |
|------|------|
| **Divide** | Split `[si, ei]` at `mid`. |
| **Conquer** | Count inversions in left half and right half recursively. |
| **Combine** | While **merging** two sorted halves, count **cross-inversions**: pairs with left index in left half, right index in right half, and left value > right value. |

**Key merge insight:** When copying from the **right** half before the **left** pointer `i`, every remaining element in the left half from `i` to `mid` is greater than the current right element → add **`(mid - i + 1)`** to the count.

```
Left (sorted):  [2, 4]     i → 4
Right (sorted): [1, 3]     pick 1  →  4 > 1  →  add 2 inversions (2,1) and (4,1)
```

**Complexity**

| | |
|---|---|
| **Time** | **O(n log n)** — same structure as merge sort; O(n) work per level. |
| **Space** | **O(n)** for temporary array used in merge. |

**Reference:** [f.cpp](f.cpp)

---

## Quick reference (files in this module)

| File | Concept |
|------|---------|
| [a.cpp](a.cpp) | Merge sort — integers |
| [b.cpp](b.cpp) | Quick sort — Lomuto partition |
| [c.cpp](c.cpp) | Search in rotated sorted array |
| [d.cpp](d.cpp) | Merge sort — strings |
| [e.cpp](e.cpp) | Majority element |
| [f.cpp](f.cpp) | Inversion count |