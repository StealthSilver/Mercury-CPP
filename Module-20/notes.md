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

TILING PROBLEM -> l.cpp
count the total ways to tile a floor of size (2xn) with tiles of size (2x1). 

this can be done by recursion and DP  

for every level we have a choice to place the tile vertically or horizontally 

for [2 * n] floor 
if vertically placed -> 2 * (n-1)
if horizontally placed-> 2*(n-2)

recurrence relation -> f(n) = f(n-1) + f(n-2)

we will check for both of them

1. work -> t[2*(n-1)] + t[2*(n-2)]
2. recursive call -> vertical tp(n-1) , horizontal tp(n-2)
3. base case -> n=0 -> ways =1 (not tile is placed) , n=1 -> ways =1 (tile is vertically placed)