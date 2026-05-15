# DSA with C++ — Module 20 Notes

**Topic:** Recursion — definition, recurrence relations, call stack, classic patterns, array problems, and time-complexity trade-offs.  
**Companion code:** Each section links to a runnable `.cpp` in this folder. These notes explain *what* and *why*; open the files to see behavior.

---

## What is recursion?

**Recursion** is when a function **calls itself** to solve a problem by breaking it into **smaller instances of the same problem**.

A useful formal view: recursion is a method where the solution at size `n` depends on solutions at smaller sizes (`n-1`, `n/2`, etc.) until you reach a size you can answer directly.

| Idea | Detail |
|------|--------|
| **Same problem, smaller input** | Each call works on a reduced version (e.g. `factorial(n-1)`, `fib(n-1)`). |
| **Loops are often equivalent** | Almost every recursive solution can be rewritten with iteration (`for` / `while`). Some problems feel more natural with recursion (trees, divide-and-conquer). |
| **Call chain** | `main` → `f` → `f` → … → **base case**, then each call **returns** to its caller in reverse order. |

### Three parts every recursive function needs

1. **Base case** — the smallest input you can answer **without** another recursive call (stops infinite recursion).
2. **Recursive call** — the function invokes itself on a **strictly smaller** or **progressing** subproblem.
3. **Work / combine step** — what you do at the current level (print, add, multiply, compare, etc.) and how you use the result from the deeper call.

If the base case is missing or never reached, recursion never stops.

**Reference:** [a.cpp](a.cpp) — introduction and simple recursive examples.

---

## Recursion and mathematics

### Composition of functions

If `f(x) = x²`, then `f(f(x)) = (x²)²`. Applying a function to the **result of the same function** is the same “use the answer to get the next answer” idea as recursion.

### Recurrence relations

A **recurrence relation** defines a sequence (or function) in terms of **previous values**.

**Factorial example:**

- `f(n) = n!`
- `f(n) = n × f(n-1)` for `n > 0`
- **Base case:** `f(0) = 1`

Expanding `f(5)`:

- `f(5) = 5 × f(4)`
- `f(4) = 4 × f(3)`
- … down to `f(0) = 1`, then values bubble back up: `f(1)=1`, `f(2)=2`, `f(3)=6`, `f(4)=24`, `f(5)=120`.

**Reference:** [b.cpp](b.cpp) — mathematical / recurrence view of recursion.

---

## Recursion and memory (the call stack)

Each recursive call gets a new **stack frame** on the **call stack**: space for parameters, local variables, and where to return when the call finishes.

**Example: `factorial(5)`**

| Phase | What happens |
|-------|----------------|
| **Going down** | Frames for `n=5,4,3,2,1` are pushed; each waits for the next call. |
| **Base hit** | `factorial(0)` returns `1`; its frame is popped. |
| **Coming back up** | `factorial(1)` returns `1×1`, `factorial(2)` returns `2×1`, … until `factorial(5)` returns `120`. |

So recursion uses **stack space** proportional to **recursion depth** (how many nested calls are active at once).

---

## Print numbers: decreasing vs ascending order

Both problems print `1` through `n`, but **when** you print relative to the recursive call changes the order.

| Order | Strategy | Intuition |
|-------|----------|-----------|
| **Decreasing** (`n, n-1, …, 1`) | **Work first**, then recurse on `n-1`. | Print current number, then trust `print(n-1)` for the rest. |
| **Ascending** (`1, 2, …, n`) | **Recurse first** on `n-1`, then **work** (print `n`). | Trust `print(n-1)` to finish the smaller range; print `n` on the way back up. |

**Base case (both):** `n == 0` → return (nothing left to print).

**References:** [c.cpp](c.cpp) — decreasing order · [d.cpp](d.cpp) — ascending order.

---

## Stack overflow

**Stack overflow** happens when the call stack runs out of space. In C++, this often shows up as a **segmentation fault** or abnormal termination.

Common causes:

1. **Missing or wrong base case** — recursion never stops; frames keep piling up until the stack is exhausted.
2. **Too much work per frame** — many large local variables or very deep recursion (e.g. `fib(n)` without optimization for large `n`).

Always ensure the recursive argument **moves toward** the base case every time.

---

## Sum of first n natural numbers

**Recurrence:** `sum(n) = n + sum(n-1)`  
**Base case:** `sum(0) = 0`

At each step you do a little **work** (`+ n`) and combine it with the result of the smaller subproblem.

**Reference:** [e.cpp](e.cpp)

---

## Nth Fibonacci number

**Sequence:** `0, 1, 1, 2, 3, 5, 8, 13, 21, …`

**Recurrence:** `fib(n) = fib(n-1) + fib(n-2)`  
**Base cases:** `fib(0) = 0`, `fib(1) = 1`

### Recursion tree for `fib(5)`

Each call splits into `fib(n-1)` (left) and `fib(n-2)` (right). Leaves are base cases returning `0` or `1`.

```
                              fib(5)
                             /      \
                        fib(4)      fib(3)
                       /    \       /    \
                  fib(3)  fib(2) fib(2) fib(1)→1
                 /   \   /   \   /   \
            fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
           /   \    →1     →1     →0     →1     →0
      fib(1) fib(0)
        →1     →0
```

**Bubble values up** (each parent = left child + right child):

- Every `fib(2)` subtree evaluates to `1 + 0 = 1`.
- `fib(3) = 2`, `fib(4) = 3`, **`fib(5) = 5`**.

**Why this matters:** The same subproblems (`fib(2)`, `fib(3)`, …) are solved **many times**. Naive recursion is **exponential** in `n`. **Memoization** (caching results) or an **iterative** loop reduces this to **O(n)** time.

**Reference:** [f.cpp](f.cpp)

---

## Check if an array is sorted

**Iterative idea:** For each adjacent pair, check `arr[i] <= arr[i+1]`.

**Recursive idea:** From index `i`, check the current pair; if OK, assume the suffix starting at `i+1` is sorted if the recursive call says so.

| Step | Role |
|------|------|
| **Base case** | `i == n-1` → only one element left in the suffix → **sorted** (`true`). |
| **Work** | If `arr[i] > arr[i+1]` → **not sorted** (`false`). |
| **Recursive call** | `isSorted(arr, n, i+1)` |

**Reference:** [g.cpp](g.cpp)

---

## First occurrence of an element

**Example:** In `[1, 2, 3, 4, 5, 6]`, first occurrence of `3` is index **2** (0-based).

Search **left to right**: at index `i`, if you find the target, return immediately; otherwise search the rest.

| Step | Role |
|------|------|
| **Base case** | `i == n` → element not found → return `-1`. |
| **Work** | If `arr[i] == target` → return `i`. |
| **Recursive call** | Search from `i+1`. |

**Reference:** [h.cpp](h.cpp)

---

## Last occurrence of an element

**Example:** In `[1, 2, 3, 2, 5, 6]`, last occurrence of `2` is index **3**.

Here you must prefer a match **to the right** of the current index. So you **do not** return as soon as you see `arr[i] == target` at the current index.

| Step | Role |
|------|------|
| **Base case** | `i == n` → not found → return `-1`. |
| **Recursive call first** | `ans = lastOccurrence(arr, n, i+1, target)`. |
| **Work** | If `ans != -1`, return `ans` (a later index already found). Else if `arr[i] == target`, return `i`; else return `-1`. |

**Key difference from first occurrence:** recurse on the **suffix first**, then decide whether the current index is the answer.

**Reference:** [i.cpp](i.cpp)

---

## Print x to the power n (xⁿ)

**Definition:** `x⁰ = 1`; for `n > 0`, `xⁿ = x × x × … × x` (`n` times).

The same problem can be solved in two time complexities:

| Approach | Idea | Time (typical) | File |
|----------|------|----------------|------|
| **Linear recursion** | `xⁿ = x × xⁿ⁻¹` — reduce `n` by 1 each call | **O(n)** recursive depth | [j.cpp](j.cpp) |
| **Binary / fast exponentiation** | If `n` is even: `xⁿ = (xⁿ/²)²`; if odd: `xⁿ = x × (xⁿ/²)²` — halve `n` each step | **O(log n)** recursive depth | [k.cpp](k.cpp) |

**Intuition for O(log n):** Each step cuts the exponent roughly in half (e.g. `10 → 5 → 2 → 1 → 0`), so the number of calls grows like **log₂ n**, not like `n`.

Both versions in this module use non-negative integer `n` as in the course examples.

---

## Tiling problem (2×n floor with 2×1 tiles)

**Problem:** Count how many ways you can tile a floor of size **2×n** using tiles of size **2×1** (no gaps, no overlap).

Think of the floor as **2 rows** and **n columns**. Each tile covers exactly **2 unit squares** (either stacked in one column or side by side across two columns).

### Two choices at each step

| Placement | What it looks like | Remaining floor |
|-----------|-------------------|-----------------|
| **Vertical** | One tile in a single column (covers both rows in that column) | **2×(n−1)** |
| **Horizontal** | Two tiles, each spanning one row, placed in **two adjacent columns** | **2×(n−2)** |

So the number of ways for width `n` depends on how you tile the rest after the first move:

**Recurrence:** `f(n) = f(n−1) + f(n−2)`

| Step | Role |
|------|------|
| **Base case** | `n = 0` → **1** way (empty floor, no tile placed). `n = 1` → **1** way (one vertical tile). |
| **Recursive calls** | Ways with first move vertical → `f(n−1)`; with first horizontal pair → `f(n−2)`. |
| **Work** | Add both counts: `f(n−1) + f(n−2)`. |

**Example:** `n = 4` → **5** ways (sequence 1, 2, 3, 5, … — same pattern as Fibonacci).

This problem can also be solved with **dynamic programming** (store `f(0)…f(n)` in a table) to avoid recomputing the same `n` many times, like naive `fib(n)`.

**Reference:** [l.cpp](l.cpp)

---

## Remove duplicates from a string

**Problem:** You are given a string made of lowercase letters (`a`–`z`). Some characters repeat. Build a new string that contains **each character at most once**, keeping the **first occurrence** of every letter and dropping later copies. **Order must stay the same** as in the original string.

**Example:** `"abbccd"` → `"abcd"` (second `b`, second `c`, and second `d` are removed).

### Recursive idea (process index `i` from left to right)

Trust that `removeDuplicates(s, i+1)` already returns the correct answer for the **suffix** starting at `i+1`. Then decide what to do with `s[i]`:

| Step | Role |
|------|------|
| **Base case** | `i == s.length()` → empty suffix → return `""`. |
| **Recursive call** | `rest = removeDuplicates(s, i+1)` — answer for `s[i+1 … n-1]`. |
| **Work** | If `s[i]` already appears in `rest`, it is a **duplicate** (a later copy was kept in the suffix step) → return `rest` only. Otherwise `s[i]` is the **first** time this letter appears → return `s[i] + rest`. |

**Why “check in `rest`” works:** `rest` is built only from characters to the **right** of `i`. If `s[i]` shows up there, a copy of that letter still exists later, so the first occurrence will be handled when that later position is processed—or `s[i]` is the first occurrence and `rest` does not contain it, so we prepend `s[i]`.

**Example trace (short):** `"aab"`  
- Suffix `"ab"` → `"ab"`.  
- At first `a`, `rest` is `"ab"` which contains `a` → skip this `a`.  
- At second `a`, `rest` is `"b"` → no `a` → `"a" + "b"` = `"ab"`.

Same problem can be solved with a loop and a `bool seen[26]` array; recursion here matches the module’s pattern.

**Reference:** [m.cpp](m.cpp)

---

## Friends pairing problem

**Problem:** There are **n** friends labelled `1 … n`. Each friend is either **alone** or forms **exactly one pair** with another friend (no one is in more than one pair). Count the **total number of valid arrangements**.

### Small examples

**n = 2** (`A`, `B`):

1. `A` alone, `B` alone  
2. `(A, B)` paired  

→ **2** ways.

**n = 3** (`A`, `B`, `C`):

1. `A`, `B`, `C` — all alone  
2. `A` alone, `(B, C)` paired  
3. `(A, B)` paired, `C` alone  
4. `(A, C)` paired, `B` alone  

→ **4** ways.

### Recursive idea (focus on friend 1)

Fix what happens to the **first** friend:

| Choice | What happens | Remaining friends | Ways from rest |
|--------|----------------|-------------------|----------------|
| **Alone** | Friend 1 stays single | `n − 1` | `f(n − 1)` |
| **Paired** | Friend 1 pairs with one of the other `n − 1` friends | `n − 2` | `(n − 1) × f(n − 2)` |

**Recurrence:** `f(n) = f(n − 1) + (n − 1) × f(n − 2)`

| Step | Role |
|------|------|
| **Base case** | `n = 0` → **1** way (no friends, empty arrangement). `n = 1` → **1** way (that friend stays alone). |
| **Recursive calls** | `f(n − 1)` when friend 1 is alone; `f(n − 2)` after pairing (multiply by `n − 1` for the choice of partner). |
| **Work** | Add both counts. |

**More values:** `f(2) = 2`, `f(3) = 4`, `f(4) = 10`.

This is **not** the same as Fibonacci: the `(n − 1)` factor in the pairing branch makes the sequence grow faster.

**Reference:** [n.cpp](n.cpp)

---

## Binary strings without consecutive 1s

**Problem:** Print **all** binary strings of length **n** (only `0` and `1`) such that **no two `1`s appear next to each other**.

**Example (n = 3):** `000`, `001`, `010`, `100`, `101` — **5** strings. Invalid examples: `011`, `110`, `111` (have `11`).

### Recursive idea (build left to right)

Maintain the string built so far and how many positions are left (`n`). Also track whether the **last placed** character was `1` or not:

| Last character | Can append `0`? | Can append `1`? |
|----------------|-----------------|-----------------|
| `0` (or empty start) | Yes | Yes |
| `1` | Yes | **No** (would create consecutive 1s) |

| Step | Role |
|------|------|
| **Base case** | `n == 0` → string is complete → print it. |
| **Recursive call (always)** | Append `'0'` → `printBinary(n−1, 0, s + "0")`. |
| **Work / second branch** | If last was not `1` (`lastPlace == 0`), append `'1'` → `printBinary(n−1, 1, s + "1")`. |

`lastPlace` is a flag: `0` means the last character was `0` (or we have not placed any yet), so `1` is allowed; `1` means the last character was `1`, so only `0` is allowed next.

**Count growth (optional):** Number of valid strings of length `n` follows a pattern related to Fibonacci (e.g. `n=1` → 2, `n=2` → 3, `n=3` → 5, `n=4` → 8).

**Reference:** [o.cpp](o.cpp)

---

## Practice problems (recursion)

### Problem 1 — Recursive binary search

**Task:** In a **sorted** array, find the **index** of `key` using recursion. Return `-1` if not found.

**Idea:** Use a search range `[s, e]` (start and end indices), same as rotated-sorted-array style problems.

| Step | Role |
|------|------|
| **Base case** | `s > e` → key not in range → `-1`. |
| **Work** | `mid = s + (e - s) / 2`. If `arr[mid] == key` → return `mid`. If `arr[mid] > key` → search left `[s, mid-1]`; else search right `[mid+1, e]`. |
| **Recursive call** | `binarySearch(arr, s, mid-1, key)` or `binarySearch(arr, mid+1, e, key)`. |

**Example:** `{1,2,3,4,5,6,7}`, `key = 5` → index **4**.

**Reference:** [p.cpp](p.cpp)

---

### Problem 2 — All occurrences of an element

**Task:** Print **all indices** where `key` appears in an array (left to right).

| Step | Role |
|------|------|
| **Base case** | `i == n` → stop. |
| **Work** | If `arr[i] == key` → print index `i`. |
| **Recursive call** | `findAllOccurrences(arr, n, i+1, key)`. |

**Example:** `{3,2,4,5,6,2,7,2,2}`, `key = 2` → **1 5 7 8**.

**Reference:** [q.cpp](q.cpp)

---

### Problem 3 — Substrings with same first and last character

**Task:** Count **contiguous** substrings whose **first and last character are equal**.

**Example:** `"abcab"` → **7** (`a`, `abca`, `b`, `bcab`, `c`, `a`, `b`). `"aba"` → **4** (`a`, `b`, `a`, `aba`).

**Idea:** Fix a **start index** `i`, try every **end index** `j ≥ i`. If `s[i] == s[j]`, the substring `s[i..j]` counts. Move to the next start when `j` reaches the end of the string.

| Step | Role |
|------|------|
| **Base case** | `i >= length` → `0`. If `j >= length` → next start: `count(s, i+1, i+1)`. |
| **Work** | If `s[i] == s[j]` → add `1`. |
| **Recursive call** | Extend end: `count(s, i, j+1)`. |

**Reference:** [r.cpp](r.cpp)

---

### Problem 4 — Tower of Hanoi

**Task:** Move **n** disks from source tower **A** to destination **C** using helper **B**.

**Rules:**

1. Move only **one** disk at a time.
2. Only the **top** disk of a tower can be moved.
3. Never place a larger disk on a smaller disk.

**Idea:** To move `n` disks from A → C:

1. Move top `n−1` disks from **A → B** (using C as helper).
2. Move largest disk from **A → C**.
3. Move `n−1` disks from **B → C** (using A as helper).

| Step | Role |
|------|------|
| **Base case** | `n == 0` → nothing to do. |
| **Recursive calls** | `towerOfHanoi(n-1, src, dest, helper)` then `towerOfHanoi(n-1, helper, src, dest)`. |
| **Work** | Print move of disk `n` from `src` to `dest`. |

**Moves:** `2^n − 1` for `n` disks.

**Reference:** [s.cpp](s.cpp)

---

### Problem 5 — Count good digit strings

**Task:** Count digit strings of length **n** such that:

- Digits at **even indices** (0, 2, 4, …) are **even** → `{0, 2, 4, 6, 8}` → **5** choices per even position.
- Digits at **odd indices** (1, 3, 5, …) are **prime** → `{2, 3, 5, 7}` → **4** choices per odd position.

Leading zeros are allowed. Return the count **modulo 10⁹ + 7**.

**Examples:** `"2582"` is good; `"3245"` is not (3 at index 0 is odd, not even).

**Recursive idea:** Build position by position from index `pos`:

| Step | Role |
|------|------|
| **Base case** | `pos == n` → one complete string → return `1`. |
| **Work** | Even `pos` → multiply by `5`; odd `pos` → multiply by `4`. |
| **Recursive call** | `countGoodStrings(n, pos+1)`. |

**Closed form:** `5^⌈n/2⌉ × 4^⌊n/2⌋` (same as multiplying choices at each index).

**Reference:** [t.cpp](t.cpp)

---

## Quick reference (files in this module)

| File | Concept |
|------|---------|
| [a.cpp](a.cpp) | Introduction to recursion |
| [b.cpp](b.cpp) | Recursion and recurrence relations |
| [c.cpp](c.cpp) | Print numbers in decreasing order |
| [d.cpp](d.cpp) | Print numbers in ascending order |
| [e.cpp](e.cpp) | Sum of first n natural numbers |
| [f.cpp](f.cpp) | Nth Fibonacci number |
| [g.cpp](g.cpp) | Check if array is sorted |
| [h.cpp](h.cpp) | First occurrence in array |
| [i.cpp](i.cpp) | Last occurrence in array |
| [j.cpp](j.cpp) | xⁿ — O(n) |
| [k.cpp](k.cpp) | xⁿ — O(log n) |
| [l.cpp](l.cpp) | Tiling 2×n floor with 2×1 tiles |
| [m.cpp](m.cpp) | Remove duplicates from string |
| [n.cpp](n.cpp) | Friends pairing problem |
| [o.cpp](o.cpp) | Binary strings without consecutive 1s |
| [p.cpp](p.cpp) | Recursive binary search |
| [q.cpp](q.cpp) | All occurrences of key |
| [r.cpp](r.cpp) | Substrings with same start/end char |
| [s.cpp](s.cpp) | Tower of Hanoi |
| [t.cpp](t.cpp) | Count good digit strings |