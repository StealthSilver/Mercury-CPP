# DSA with C++ — Module 23 Notes

**Topic:** Backtracking — definition, relation to recursion, the explore–choose–unchoose pattern, and three problem families (decision, optimization, enumeration).  
**Companion code:** [a.cpp](a.cpp) (array backtracking demo), [b.cpp](b.cpp) (subsets), [c.cpp](c.cpp) (permutations), [d.cpp](d.cpp) (N-Queens). These notes give *definitions* and *worked examples in words* only — no implementation snippets here.

**Prerequisite:** Module 20 (recursion, base case, call stack, recursion tree) and Module 16 (2D grids / matrices). Module 21 (divide and conquer) is separate: it always breaks into fixed subproblems; backtracking **tries choices** and **undoes** them when a path fails.

---

## MODULE 23 — BACKTRACKING

### Definition

**Backtracking** is a problem-solving technique built on **recursion**. You build a solution **step by step** (one decision at a time). When a choice leads to a dead end, you **undo** that choice and return to an earlier state — you literally **track back** along the recursion call stack.

| Idea | Detail |
|------|--------|
| **Same engine as recursion** | Each call explores one level of decisions; when the call returns, control goes back to the parent — that return path is the “back” in backtracking. |
| **State** | What you have chosen so far (path in a grid, queens placed so far, digits picked for a subset, etc.). |
| **Explore** | Try a valid next option. |
| **Choose** | Commit to that option (update state). |
| **Recurse** | Solve the rest of the problem from the new state. |
| **Unchoose (backtrack)** | If the deeper call did not lead to success, **reverse** the choice so the parent can try something else. |
| **Base case** | Either a complete valid solution is found, or no more valid moves exist from the current state. |

**One-line intuition:** Recursion walks **down** the decision tree; backtracking walks **back up** when a branch cannot work, erasing the last choice so another branch can be tried.

This is the process in which we are **returning from the call stack** while implementing recursion — not only to combine answers (like merge sort), but to **undo partial solutions** and search elsewhere.

---

## Backtracking in arrays

**Reference:** [a.cpp](a.cpp) — first illustration of **choose → recurse → unchoose** on a 1D array.

This program does not solve a puzzle; it shows **how the array looks on the way down**, at the **deepest call**, and **after undoing** each assignment on the way back up. The same array is shared across all calls (pointer), so every change in a deeper call is visible to shallower calls until it is reversed.

### Setup

| Item | Value |
|------|--------|
| **Array (start)** | `{1, 2, 3, 4, 5}` — five integers |
| **`n`** | `5` |
| **Entry** | `changeArray(arr, n, 0)` from `main` |
| **`printArray`** | Prints all `n` elements on one line (used at base case and again in `main`) |

### `changeArray` — what each part does

| Step | Condition / action | Role |
|------|-------------------|------|
| **Base case** | `i == n` | All indices `0 .. n-1` have been processed; print the array once, then `return`. |
| **Choose** | `arr[i] = i + 1` | Commit a value at index `i` before going deeper. |
| **Recurse** | `changeArray(arr, n, i + 1)` | Process index `i + 1`, then `i + 2`, … until `i == n`. |
| **Unchoose (backtrack)** | `arr[i] -= 2` | After the recursive call returns, **undo** the effect at `i` by subtracting `2` from whatever `arr[i]` is at that moment. |

So for index `i`, the forward pass sets `arr[i]` to **`i + 1`**. The backward pass does **`arr[i] -= 2`**, which turns that into **`(i + 1) - 2 = i - 1`** before control returns to the parent at `i - 1`.

### Trace: going down (choose + recurse)

Start: `arr = [1, 2, 3, 4, 5]`, call `changeArray(..., i = 0)`.

| Call (`i`) | Action before recurse | `arr` after choose |
|------------|------------------------|---------------------|
| `i = 0` | `arr[0] = 1` | `[1, 2, 3, 4, 5]` |
| `i = 1` | `arr[1] = 2` | `[1, 2, 3, 4, 5]` |
| `i = 2` | `arr[2] = 3` | `[1, 2, 3, 4, 5]` |
| `i = 3` | `arr[3] = 4` | `[1, 2, 3, 4, 5]` |
| `i = 4` | `arr[4] = 5` | `[1, 2, 3, 4, 5]` |
| `i = 5` | base case → **print** | `1 2 3 4 5` (first line of output) |

At the deepest level every index holds **`index + 1`**. That snapshot is the “full depth” state of the shared array.

### Trace: coming back up (unchoose)

After the base case returns, each frame runs `arr[i] -= 2` in order from `i = 4` down to `i = 0`:

| After return from | `arr[i] -= 2` | `arr` |
|-------------------|---------------|--------|
| `i = 5` | `arr[4]`: 5 → 3 | `[1, 2, 3, 4, 3]` |
| `i = 4` | `arr[3]`: 4 → 2 | `[1, 2, 3, 2, 3]` |
| `i = 3` | `arr[2]`: 3 → 1 | `[1, 2, 1, 2, 3]` |
| `i = 2` | `arr[1]`: 2 → 0 | `[1, 0, 1, 2, 3]` |
| `i = 1` | `arr[0]`: 1 → −1 | `[-1, 0, 1, 2, 3]` |

When `changeArray` finishes, `main` calls `printArray` again → second line of output.

### Program output

```
1 2 3 4 5 
-1 0 1 2 3 
```

| Line | When | Meaning |
|------|------|---------|
| **First** | Base case (`i == n`) | Array at **maximum recursion depth** — all chooses applied, no unchooses yet. |
| **Second** | After `changeArray` returns to `main` | Array after **every** `arr[i] -= 2` on the unwind — shared state restored to the post-backtrack values. |

### Call stack picture

```
changeArray(i=0)  arr[0]=1
  changeArray(i=1)  arr[1]=2
    changeArray(i=2)  arr[2]=3
      changeArray(i=3)  arr[3]=4
        changeArray(i=4)  arr[4]=5
          changeArray(i=5)  → print 1 2 3 4 5
        arr[4] -= 2
      arr[3] -= 2
    arr[2] -= 2
  arr[1] -= 2
arr[0] -= 2
main → print -1 0 1 2 3
```

Going **down**, the stack grows and each index is set to `i + 1`. Going **up**, each frame undoes its index before the parent continues — that is backtracking on an array.

### What to remember

| Idea | In this file |
|------|----------------|
| **Shared array** | One `arr` in memory; all recursive calls read/write the same elements. |
| **Choose / unchoose** | `arr[i] = i + 1` then later `arr[i] -= 2` — the second line only runs **after** the subtree returns. |
| **Base case = “done with path”** | Here, `i == n` means “all positions filled for this demo”; print and return. |
| **Final array ≠ printed snapshot** | The first print shows the “forward” configuration; after full unwind, values are **`i - 1`** at each index. |

Real backtracking problems use the same pattern with richer chooses (place queen, mark visited, include element) and matching unchooses (remove queen, unmark, exclude). [a.cpp](a.cpp) keeps the logic minimal so the **call stack and array updates** are easy to see.

---

## How backtracking differs from other recursion you have seen

| Pattern | Typical use (modules so far) | Tries many paths? | Undoes choices? |
|---------|------------------------------|-------------------|-----------------|
| **Linear recursion** | Factorial, sum, print 1…n (Module 20) | No — one chain of calls | No |
| **Tree recursion** | Fibonacci (Module 20) | Yes — but overlapping subproblems | No explicit undo |
| **Divide and conquer** | Merge sort, quick sort, binary search (Module 21) | No — fixed split (half array, one mid) | No |
| **Backtracking** | Subsets, mazes, puzzles (this module) | Yes — **explicit** branches | **Yes** — unchoose after failed subtree |

---

## The decision tree (mental model)

Think of every sequence of choices as a **tree**:

- **Root** — empty partial solution.
- **Edge** — one decision (move right, place a queen, include an element, etc.).
- **Leaf** — either a **complete solution** or a **failure** (no valid move left).

Backtracking is **depth-first search** on this tree: go deep on one path; if it fails, pop back and try the next sibling.

**Tiny example (include / skip three items {A, B, C}):**

```
                        []
           /            |            \
        [A]           [B]            [C]
       /   \           |
    [A,B] [A,C]      [B,C]
      |
   [A,B,C]
```

Each path from root to a node is one **partial** subset; leaves are **full** subsets. Backtracking visits each path by choosing “take” or “skip” and undoing when exploring the other branch.

---

## Three types of backtracking

Most backtracking problems fall into one of three families. The **same skeleton** (explore → choose → recurse → unchoose) applies; only the **question you ask at the end** changes.

| Type | Question you answer | Output |
|------|---------------------|--------|
| **1. Decision** | Does **any** valid solution exist? (yes / no) | Boolean — existence |
| **2. Optimization** | Among all valid solutions, which is **best** by some measure? | One best solution (min cost, max profit, shortest length, etc.) |
| **3. Enumeration** | How many valid solutions are there, or **list them all**? | Count and/or full list |

---

## Running example: grid from (0,0) to (n−1, n−1)

You are on an **n × n** matrix. Start at cell **(0, 0)**. Goal: reach **(n−1, n−1)**. From each cell you may move only **right** or **down** (unless the problem states otherwise). Some cells may be **blocked**.

This single setup illustrates all three types:

| Type | Question on this grid |
|------|------------------------|
| **Decision** | Is there **any** path from start to destination without hitting a blocked cell? |
| **Optimization** | If each cell has a **cost**, what is the **minimum total cost** along a valid path? |
| **Enumeration** | How many **distinct** valid paths exist from start to destination? (Or: list every path.) |

**Decision — worked example (4×4, no blocks):**  
From (0,0) you can go right to (0,1) or down to (1,0). If every unblocked path eventually reaches (3,3), the answer is **yes**. If a wall surrounds the destination, every branch dies before (3,3) — after exploring, backtracking concludes **no**.

**Optimization — worked example:**  
Suppose costs are:

```
(0,0)=1  (0,1)=4  ...
(1,0)=2  ...
```

One path: right, right, down, down might cost 1+4+…+…. Another path: down, down, right, right might be cheaper. Backtracking explores paths; whenever you reach (3,3), compare total cost to the best seen so far and **prune** branches that already exceed the best cost (optional but common).

**Enumeration — worked example (3×3, only right/down, no blocks):**  
From (0,0) to (2,2) you need **2 rights** and **2 downs** in any order — that is **C(4,2) = 6** paths. Enumeration backtracking counts each complete path once by trying all orderings of moves and recording each time the destination is reached.

---

## Type 1 — Decision problems

**Definition:** Find whether **at least one** valid configuration or path exists. You can stop as soon as you find one solution (early exit).

| Example problem | What you decide | Yes means… |
|-----------------|-----------------|------------|
| **Grid path existence** | Move right/down into unblocked cells | Start can reach end |
| **Rat in a maze** | Move in four directions in a 0/1 maze | A route exists from source to destination |
| **N-Queens (existence)** | Place queens row by row with no attacks | Some placement works for given N |
| **Sudoku (solvability)** | Fill empty cells with digits 1–9 | Puzzle has a valid completion |
| **Subset sum (decision)** | Include or exclude each number | Some subset sums to target T |
| **Word search on board** | Walk adjacent cells to spell a word | Word can be formed along a path |

**Example (subset sum, decision):**  
Array {3, 5, 2}, target **7**.  
Try including 3 → need 4 from {5,2}; include 5 → need −1 → fail, backtrack; try 2 with 3 → 3+2=5; include 5 → 7 → **yes**, a subset exists.

**Example (N-Queens, N = 4, decision only):**  
Place queen row 0 in column 0; row 1 cannot use column 0 or 1; try column 2; continue. If row 3 has no safe column, **backtrack** to row 2 and try another column. If eventually all four rows are filled legally, answer is **yes**.

---

## Type 2 — Optimization problems

**Definition:** Among **all** valid solutions, find one that **minimizes** or **maximizes** an objective (cost, length, value, count of something, etc.). You often explore many complete solutions (or prune aggressively) and keep the **best so far**.

| Example problem | What you optimize |
|-----------------|-------------------|
| **Minimum-cost grid path** | Sum of cell costs along path |
| **Shortest path in maze** | Number of steps (unweighted) or total weight |
| **0/1 Knapsack (max value)** | Total value ≤ capacity, maximize value |
| **Job assignment** | Minimize maximum time or total cost |
| **Graph coloring (min colors)** | Fewest colors so no adjacent vertices share a color |
| **Traveling Salesman (small n)** | Minimum tour length visiting all cities |

**Example (minimum-cost path on a tiny grid):**  

```
1   3   1
2   5   1
4   2   1
```

Start (0,0), end (2,2), moves right/down.  
Path A: down, down, right → cost 1+2+1+1 = 5 (example arithmetic along cells).  
Path B: right, right, down → cost 1+3+1+1 = 6.  
Backtracking (with pruning) records **5** as the best complete path cost.

**Example (0/1 knapsack, maximize value):**  
Weights {2, 3, 4}, values {3, 4, 5}, capacity **5**.  
Try taking item 1 and 2: weight 5, value 7.  
Try taking item 3 only: weight 4, value 5.  
Best value found: **7**. Optimization backtracking tracks the maximum value over all valid subsets.

---

## Type 3 — Enumeration problems

**Definition:** Count **all** valid solutions, or **produce every** valid solution (not just one, not just the best). Often you visit every leaf of the decision tree that satisfies constraints.

| Example problem | What you enumerate |
|-----------------|-------------------|
| **All paths in a grid** | Every distinct right/down sequence from start to end |
| **All subsets** | Every subsequence / subset of a set |
| **All permutations** | Every ordering of n distinct elements |
| **All combinations** | Every k-element subset of n items |
| **N-Queens (all solutions)** | Every distinct board placement |
| **Parentheses** | All valid strings of n pairs of brackets |
| **Letter combinations of phone number** | All strings from digit-to-letter mapping |
| **Partition equal subset (count)** | Sometimes count partitions; variant of subset exploration |

**Example (all subsets of {1, 2, 3}):**  
{}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3} — **8** subsets.  
At each index: **include** the element and recurse, then **exclude** it and recurse. Backtracking ensures each branch is explored exactly once.

**Example (permutations of {A, B, C}):**  
Fix A at front → permute {B,C} → ABC, ACB.  
Fix B at front → BAC, BCA.  
Fix C at front → CAB, CBA.  
**6** orderings total. When you swap choices at level 1, earlier choices are undone (unchoose) before trying the next root letter.

**Example (grid path count, 2×2):**  
Need one right and one down from (0,0) to (1,1):  
R then D, or D then R → **2** paths.

---

## Standard backtracking template (in words)

For any problem in this module, the flow is:

1. **Check base case** — solution complete? target reached? report success / update best / add to list.
2. **Check failure** — invalid state or no moves left? return failure.
3. **For each possible choice** at this step:
   - If choice is **valid** under constraints,
   - **Apply** choice (choose),
   - **Recurse** on the rest,
   - If recursion found what you need (decision: true; optimization: better answer; enumeration: more solutions), optionally record or return,
   - **Undo** choice (unchoose) before trying the next option.
4. Return aggregated result to parent (exists? best so far? count?).

**Maze example in words:**  
At (r,c), try up, down, left, right. Mark cell visited (choose), recurse from new cell. If recursion finds exit, bubble success up. If not, unmark cell (unchoose) and try next direction. This is why visited cells must be cleared on the way back — otherwise other paths cannot reuse that cell when allowed.

---

## Constraints and pruning (making search faster)

| Technique | When it helps |
|-----------|----------------|
| **Validity check before recurse** | N-Queens: no two queens attack; Sudoku: no duplicate in row/col/box |
| **Early exit (decision)** | Stop when first solution is found |
| **Bound / prune (optimization)** | If partial cost already ≥ best complete cost, stop that branch |
| **Symmetry breaking** | e.g. fix first queen in first half of columns to avoid mirror duplicates when enumerating |
| **Sorted input** | Subset sum: if remaining numbers cannot reach target, stop branch |

Pruning does not change **what** backtracking is; it skips subtrees that cannot improve the answer.

---

## Complexity intuition (no code)

| Situation | Rough behavior |
|-----------|----------------|
| **Many binary choices** (include/skip n items) | Often **O(2ⁿ)** leaves in the worst case |
| **Permutations of n** | **n!** leaves |
| **Grid paths (right/down only)** | **C(2n−2, n−1)** for n×n without obstacles — grows quickly with n |
| **With strong pruning** | Much better in practice; worst case may still be exponential |

Space is usually **O(depth)** for the recursion stack plus whatever you store for the current path (path array, board copy, subset buffer).

---

## Quick reference — map problem to type

| If the problem asks… | Type |
|------------------------|------|
| “Can we…?” / “Is it possible…?” | **Decision** |
| “Minimum / maximum / shortest / best…” | **Optimization** |
| “How many…?” / “Print all…” / “List every…” | **Enumeration** |

| Same skeleton | Different stopping rule |
|---------------|-------------------------|
| Explore → choose → recurse → unchoose | Decision: stop at first success · Optimization: track best · Enumeration: collect all or count all |

---

## Find all subsets of a string

**Reference:** [b.cpp](b.cpp) — **enumeration** (Type 3): print every subset.

### Question

Given a string (e.g. `"abc"`), find and print **all subsets** — every way to keep some characters and drop others. Order of characters in a subset follows the original string; we do not reorder.

| String | Example subsets |
|--------|-----------------|
| `"abc"` | `""` (empty / null set), `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"` |

For a string of length **n**, each character is either **in** or **out** → **2ⁿ** subsets total.

### Idea (include / skip)

Walk the string index by index (`i = 0, 1, …, n-1`). At each index:

| Choice | Meaning |
|--------|---------|
| **Skip** `s[i]` | Do not add this character; move to `i + 1` |
| **Take** `s[i]` | Append to current subset, move to `i + 1`, then **remove** it after exploring (backtrack) |

When `i == n`, the current subset is complete → print it.

This is the same **take / skip** tree as “all subsets of {A, B, C}” in the decision-tree section above, applied to string characters.

### Recursion tree for `"abc"` (skip first, then take — matches [b.cpp](b.cpp))

Each node shows the **subset built so far** and which index `i` we are deciding next.

```
                         ""  (i=0, decide 'a')
                skip /                    \ take
               ""  (i=1)                  "a"  (i=1)
          skip/    \take              skip/    \take
         ""        "b"               "a"        "ab"
       skip/\take skip/\take      skip/\take  skip/\take
      ""   "c"   "b"  "bc"       "a"  "ac"  "ab" "abc"
       |    |     |     |          |     |     |     |
     PRINT all 8 leaves when i reaches 3
```

**How backtracking shows up:** On the **take** branch you `push_back` before the recursive call and `pop_back` after it returns. That undo step lets the same `subset` string try the **skip** branch at the same level with a clean state.

### Small trace (first few calls)

| Step | Action | `subset` after |
|------|--------|----------------|
| Start | `i = 0`, skip `'a'` | `""` |
| | `i = 1`, skip `'b'` | `""` |
| | `i = 2`, skip `'c'` | `""` → **print** `""` |
| | `i = 2`, take `'c'` | `"c"` → **print** `"c"` → pop → `""` |
| | `i = 1`, take `'b'` | … continues for `"b"`, `"bc"`, then back to try `'a'` … |

Program output order (depth-first, skip before take):  
`""`, `"c"`, `"b"`, `"bc"`, `"a"`, `"ac"`, `"ab"`, `"abc"`.

### What [b.cpp](b.cpp) does

| Piece | Role |
|-------|------|
| `findSubsets(s, subset, i)` | Recursive worker; `i` is the next index to decide |
| Base case `i == s.size()` | One full subset → `printSubset` |
| Skip branch | `findSubsets(s, subset, i + 1)` — no change to `subset` |
| Take branch | `push_back` → recurse → `pop_back` (backtrack) |

### Complexity

| | |
|--|--|
| **Time** | **O(2ⁿ × n)** — there are **2ⁿ** subsets; printing each can take up to **n** characters. Often written simply as **O(2ⁿ)** when we count “work per leaf” as O(1) aside from output. |
| **Space** | **O(n)** — recursion depth is **n**; the `subset` buffer holds at most **n** characters. |

**Problem type:** Enumeration — list every valid subset.

---

## Find all permutations of a string

**Reference:** [c.cpp](c.cpp) — **enumeration** (Type 3): print every arrangement.

### Question

Given a string of **n unique** characters (e.g. `"abc"`), print **every ordering** (permutation) of those characters.

| Input | All 6 permutations (3! = 6) |
|-------|-------------------------------|
| `"abc"` | `"abc"`, `"acb"`, `"bac"`, `"bca"`, `"cab"`, `"cba"` |

A **permutation** uses each character **exactly once**; only the **order** changes.

### Idea (fix position `i`, try each unused letter)

Treat the string as slots `0 … n-1`. At index **`i`**, try every character from position **`j = i … n-1`** in the **suffix** by swapping `s[i]` and `s[j]`, then fill slot `i + 1` recursively. After the subtree returns, **swap back** (backtrack) and try the next `j`.

| Step | Action |
|------|--------|
| **Choose** | `swap(s[i], s[j])` — put the `j`-th character in position `i` |
| **Recurse** | `findPermutations(s, i + 1)` |
| **Unchoose** | `swap(s[i], s[j])` again |

Base case: `i == n` → entire string is one permutation → print.

### Recursion tree for `"abc"` (matches [c.cpp](c.cpp))

Root: string `"abc"`, fix position `i = 0`.

```
                         "abc"  (i=0)
            j=0          j=1 swap      j=2 swap
           /              |              \
        "abc"           "bac"           "cba"
       (i=1)            (i=1)            (i=1)
      j=0 j=1          j=0 j=1          j=0 j=1
       |    |           |    |           |    |
     abc  acb         bac  bca         cba  cab
     PRINT at i=3 (leaves)
```

- Left branch under `i=0`: keep `'a'` at front → permutations of `"bc"` → **abc**, **acb**
- Middle: `'b'` at front → **bac**, **bca**
- Right: `'c'` at front → **cba**, **cab**

**6 leaves** = **3!** — one leaf per permutation.

### How backtracking works here

Without the second `swap`, the string would stay permuted and the next `j` at the same level would start from the wrong arrangement. The undo restores `"abc"` (at that level) so the next sibling branch is correct.

### What [c.cpp](c.cpp) does

| Piece | Role |
|-------|------|
| `findPermutations(s, i)` | `i` = next index to fix |
| Loop `j` from `i` to `n-1` | Try each character in the suffix at position `i` |
| `swap` twice | Choose and unchoose |
| Base case `i == s.size()` | Print current arrangement |

**Note:** This version assumes **all characters are distinct**. Repeated letters (e.g. `"aab"`) need extra rules to avoid duplicate permutations.

### Complexity

| | |
|--|--|
| **Time** | **O(n! × n)** — **n!** permutations; each print is **O(n)**. Often summarized as **O(n!)**. |
| **Space** | **O(n)** recursion stack depth; the string is rearranged **in place** (no extra array of size n for the path). Auxiliary storage aside from the call stack: **O(1)**. |

**Problem type:** Enumeration — list every ordering.

---

## N-Queens problem

**Reference:** [d.cpp](d.cpp) — places queens on an **N×N** board; prints **all** solutions and the total count.

### Question

Place **N queens** on an **N×N** chessboard so that **no two queens attack each other**.

A queen attacks along:

- the same **row**
- the same **column**
- both **diagonals** (↘ and ↙ through her cell)

```
        col 0   1   2   3
      +---+---+---+---+
row 0 |   | Q |   |   |     Q attacks whole row 0, column 1,
      +---+---+---+---+     and both diagonals through (0,1).
row 1 |   |   |   | Q |
      +---+---+---+---+
row 2 | Q |   |   |   |
      +---+---+---+---+
row 3 |   |   | Q |   |
      +---+---+---+---+
```

**Key rules we use:**

| Rule | Why |
|------|-----|
| **One queen per row** | Two queens in the same row always attack each other |
| **One queen per column** | Two in the same column always attack |
| When placing row `r`, only check **rows above** for column / diagonal conflicts | Queens below are not placed yet |

So we build the board **row by row**: row `0`, then row `1`, …, row `N-1`. At each row, try each column; if safe, place queen and recurse to the next row.

### Example board size N = 4

You must place **4 queens** on **4×4**. There are exactly **2** solutions (mirror images of each other).

**Solution 1** (from [d.cpp](d.cpp)):

```
. Q . .
. . . Q
Q . . .
. . Q .
```

**Solution 2:**

```
. . Q .
Q . . .
. . . Q
. Q . .
```

(`.` = empty, `Q` = queen.)

### Three variations (same backtracking skeleton)

| # | Question | What you do at base case / on success |
|---|----------|--------------------------------------|
| **1. Decision** | Does **any** valid placement exist? | Return `true` as soon as `row == N`; stop searching |
| **2. Enumeration (print all)** | List **every** valid board | **Print** each board when `row == N` — **[d.cpp](d.cpp) does this** |
| **3. Count** | How many solutions? | Increment a counter at base case; **no** print |

Variations 1 and 3 are subsets of the same pattern as 2: only the **reporting** step changes.

### Partial recursion tree (N = 4, row-by-row)

Each level = **which column** gets the queen in that row. `×` = dead end (not safe); leaves at row 4 = full solution.

```
row 0:  try col 0,1,2,3
          |
row 1:  from (0,0): col 2 ok → ...
        from (0,0): col 1,3 often × quickly
          |
row 2:  only safe columns continue
          |
row 3:  if no safe col → backtrack to row 2
          |
row 4:  all rows filled → PRINT solution 1 or 2
```

Example failure (conceptual): place row 0 at col 0, row 1 at col 2, row 2 at col 1 — then row 3 may have **no** safe column. Backtrack: remove queen from row 2, try next column, and so on.

### `isSafe(row, col)` (in words)

Before placing at `(row, col)`, check all rows `0 … row-1`:

| Check | Condition |
|-------|-----------|
| **Column** | Any queen in same column? |
| **Diagonal ↖** | Walk up-left; any queen? |
| **Diagonal ↗** | Walk up-right; any queen? |

If all clear → safe to place `board[row][col] = 1`, recurse, then set back to `0`.

### What [d.cpp](d.cpp) does

| Piece | Role |
|-------|------|
| `solveNQueens(board, row, solutionCount)` | Try every column in current `row` |
| `isSafe(board, row, col)` | Validity check before choose |
| Choose | `board[row][col] = 1` |
| Recurse | `solveNQueens(board, row + 1, …)` |
| Unchoose | `board[row][col] = 0` |
| Base `row == N` | `printBoard` + increment `solutionCount` |

Change `const int N = 4` at the top to experiment (e.g. **N = 8** has **92** solutions).

### Complexity

| | |
|--|--|
| **Time** | Worst case explores many column choices per row; with pruning, practical bound is often stated as **O(N!)**-style growth. Naive upper bound **O(N^N)** if we tried every cell — we do not; one queen per row cuts the search heavily. |
| **Space** | **O(N²)** for the board array + **O(N)** recursion stack → **O(N²)** overall. |

**Problem type:** Enumeration in [d.cpp](d.cpp); decision / count are the same search with a different **stop / report** rule.

---

## Summary

- **Backtracking** = recursion + **systematic trial** of choices + **undo** when a path fails.
- It fits **configuration**, **path-finding**, and **combinatorial search** problems where the answer is built incrementally.
- **Decision**, **optimization**, and **enumeration** share the same process; they differ in what you report when a full or partial exploration finishes.
- The **grid from (0,0) to (n−1,n−1)** example unifies the three types: existence of a path, minimum total cost, and total number of paths (or listing them).
- Until now you used recursion for **single chains** (factorial), **repeated merging** (sorting), or **one narrowed search** (binary search). Backtracking adds **exploring a space of choices** and **restoring state** on the way back up the call stack — that restore step is the heart of this module.
- **Practice files:** [b.cpp](b.cpp) (subsets, **2ⁿ**, take/skip tree), [c.cpp](c.cpp) (permutations, **n!**, swap tree), [d.cpp](d.cpp) (N-Queens, row-by-row placement, print all + count).