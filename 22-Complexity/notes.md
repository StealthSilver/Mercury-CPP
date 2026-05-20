# DSA with C++ — Module 22 Notes

**Topic:** Time and space complexity — asymptotic analysis, **Big O**, **Big Ω (Omega)**, and **Big Θ (Theta)**, standard growth classes, recursion & **Master’s theorem**, best/average/worst case, and complexity graphs.  
These notes explain *definitions*, *worked examples*, and *practice problems* with full solutions.

**Prerequisite:** Comfortable with loops, arrays, and basic algorithms from earlier modules (e.g. linear scan, binary search, sorting from Modules 11–13 and 21).

---

## Why complexity matters

When you compare two ways to solve the same problem, **wall-clock time** on one machine is misleading: CPU speed, compiler, and load all change the number. What stays useful is **how cost grows when input size grows**.

| Goal | What we measure |
|------|-----------------|
| **Time** | How the **number of elementary steps** (comparisons, assignments, loop iterations) grows with input size. |
| **Space** | How much **extra memory** the algorithm needs as input size grows. |

An algorithm is **more efficient** than another if, for large enough inputs, it uses **less time** and/or **less space** in this asymptotic sense — not because it happened to run faster once on a small test case.

Throughout this module, **`n`** denotes **input size**: length of an array, number of nodes in a list, number of digits in a number, number of edges in a graph, etc. We usually assume **`n` is large** when we ask “which algorithm scales better?”

---

## Order complexity analysis (asymptotic analysis)

**Order complexity analysis** (also called **asymptotic analysis**) describes efficiency **in terms of growth rate** as `n → ∞`.

| Measure | Name | Question it answers |
|---------|------|---------------------|
| **Time** | **Time complexity** | As `n` increases, how does the **work** (operations) increase? |
| **Space** | **Space complexity** | As `n` increases, how does **memory usage** increase? |

We express answers using three related notations: **Big O**, **Big Ω (Omega)**, and **Big Θ (Theta)**. In practice, **Big O** is used most often in courses and interviews; Ω and Θ make the meaning of “bound” precise.

**Important:** Time complexity is **not** “3 seconds on my laptop.” It is a **function of `n`** (e.g. proportional to `n`, `n²`, `log n`) that describes **scaling behavior**.

```mermaid
flowchart LR
  A[Input size n] --> B[Algorithm]
  B --> C[Count operations / memory]
  C --> D[Express growth rate]
  D --> E["O, Ω, or Θ e.g. O(n), Θ(n log n)"]
```

---

## Time complexity — definition

**Time complexity** is the amount of work an algorithm performs, expressed as a function of input size `n`, in the **asymptotic** sense.

| Idea | Detail |
|------|--------|
| **Input grows** | Double the array length, add more graph nodes, etc. |
| **Work responds** | Count how comparisons, loop iterations, or recursive calls grow. |
| **Ignore machine details** | Same algorithm is O(n) on any reasonable machine; constant factors differ. |

**Example (conceptual):** Scanning an array once to find a maximum touches each element about once → work grows **linearly** with `n` → **O(n)** time.

---

## Space complexity — definition

**Space complexity** is how much **memory** an algorithm needs as a function of `n`.

| Type | Meaning |
|------|---------|
| **Auxiliary space** | **Extra** memory beyond the input (new arrays, recursion stack, hash table). This is what people usually mean by “space complexity” of the algorithm. |
| **Total space** | Input storage **plus** auxiliary space. Sometimes written separately: “O(n) input, O(1) auxiliary.” |

| Idea | Detail |
|------|--------|
| **In-place** | Uses **O(1)** auxiliary space (only a few variables); may still reorder the **input** array. |
| **Recursion** | Each call uses stack space; depth `d` often adds **O(d)** auxiliary space. |

**Example:** Merge sort needs a temporary array of size about `n` → **O(n)** auxiliary space. Quick sort’s partition step uses **O(1)** extra variables, but recursion stack can be **O(log n)** or **O(n)** depending on splits (see Module 21).

**More detail:** [Space complexity in practice](#space-complexity-in-practice) (heap vs stack, input vs auxiliary, merge sort trade-off).

---

## Asymptotic notation: Big O, Big Ω, and Big Θ

Three symbols describe how a function `f(n)` (actual work or space) relates to a growth function `g(n)` as **`n` becomes very large**. Constants and lower-order terms are ignored — same rules as in the Big O section below.

Let `f(n)` be the **exact** operation count (or a close model) for input size `n`.

### Overview — three ways to bound growth

| Notation | Name | Type of bound | Plain English |
|----------|------|---------------|---------------|
| **O(g(n))** | **Big O** | **Upper bound** (loose ceiling) | `f(n)` grows **no faster than** `g(n)` — “**at most**” |
| **Ω(g(n))** | **Big Omega** | **Lower bound** (loose floor) | `f(n)` grows **at least as fast as** `g(n)` — “**at least**” |
| **Θ(g(n))** | **Big Theta** | **Tight bound** | `f(n)` same order as `g(n)` — **both** O and Ω with same `g` |
| **o(g(n))** | **Little-o** | **Strict upper** | `f(n)` grows **strictly slower** than `g(n)` |
| **ω(g(n))** | **Little-omega** | **Strict lower** | `f(n)` grows **strictly faster** than `g(n)` |

```mermaid
flowchart TB
  subgraph bounds [How f(n) relates to g(n) for large n]
    O["O(g) — upper cap\nf does not grow faster than g"]
    Omega["Ω(g) — lower floor\nf does not grow slower than g"]
    Theta["Θ(g) — tight fit\nf and g same order"]
  end
  Theta --> O
  Theta --> Omega
```

**Visual intuition** (one algorithm, one `n`):

```
operations
  |     ..........  O(g)  — "won't do worse than this rate" (upper)
  |    *
  |   * *     actual f(n) might wiggle but stays between bounds
  |  *   *
  | *     *
  |*_______*____  Ω(g)  — "won't do better than this rate" (lower)
  +------------------------> n
              Θ(g) when upper and lower are the same order
```

---

### Big O notation (upper bound)

**Big O** states that an algorithm’s cost **`f(n)` is bounded above** by some multiple of `g(n)` for all sufficiently large `n`.

#### Time complexity as a function

Treat **time complexity** as a function **`T(n)`** (or **`f(n)`** in textbooks): for each input size `n`, `T(n)` is the number of elementary operations in the case you are analyzing (often **worst case**).

| Symbol | Meaning |
|--------|---------|
| **`T(n)`** | Running time as a function of input size `n` |
| **`g(n)`** | A simple reference growth function (e.g. `n`, `n²`, `n log n`) |
| **`T(n) = O(g(n))`** | “`T(n)` grows **no faster than** `g(n)`” (asymptotic upper bound) |

---

#### Formal definition — *Introduction to Algorithms* (CLRS, Cormen et al.)

The standard treatment is in **Cormen, Leiserson, Rivest, and Stein**, *Introduction to Algorithms* (often called **CLRS**). There, **`O(g(n))`** is a **set of functions**:

> **`f(n) = O(g(n))`** if there exist **positive constants** `c` and `n₀` such that  
> **`0 ≤ f(n) ≤ c · g(n)`** for all **`n ≥ n₀`**.

So Big O is not “equals” — it means: **from `n₀` onward, `f` stays at or below a fixed multiple of `g`.**

**Requirements (as in the book):**

- Usually assume **`f(n) ≥ 0`** and **`g(n) ≥ 0`** for large `n`.
- **`g(n)`** should be **asymptotically positive** (nonzero for all large `n`) so the bound is meaningful.

**Limit form (equivalent intuition when the limit exists):**

If `g(n) > 0` for large `n` and the limit below exists (or you use **lim sup** in general),

$$\lim_{n \to \infty} \frac{|f(n)|}{g(n)} < \infty$$

then **`f(n) = O(g(n))`**. The ratio **does not blow up** — `f` cannot grow faster than `g` up to a constant factor.

| Limit of &#124;f(n)&#124; / g(n) | Meaning |
|----------------------------------|---------|
| **0** | `f` grows **strictly slower** than `g` (also written **little-o**: `f(n) = o(g(n))`) |
| **Finite constant** `L > 0` | `f` and `g` same order → **`f(n) = Θ(g(n))`** |
| **∞** | `f` grows **faster** than `g` → `f` is **not** `O(g)` |

**Worst-case time complexity:** Let **`T_worst(n)`** be the **maximum** number of steps over **all** inputs of size `n`. Saying the algorithm’s worst-case time is **`O(g(n))`** means:

$$T_{\text{worst}}(n) = O(g(n))$$

i.e. for large `n`, the **worst** input never needs more than a constant times `g(n)` operations. That is why course problems often report **Big O of worst case** — it is a **guarantee**.

```mermaid
flowchart LR
  subgraph clrs [CLRS view]
    A["f(n) = actual work e.g. T_worst(n)"]
    B["g(n) = reference e.g. n²"]
    C["∃ c, n₀: f(n) ≤ c·g(n) for n ≥ n₀"]
    D["f(n) ∈ O(g(n))"]
  end
  A --> C
  B --> C
  C --> D
```

**Example (formal check):** `f(n) = 3n² + 5n + 6`, `g(n) = n²`.  
Pick `c = 4` and `n₀ = 10`. For `n ≥ 10`, `3n² + 5n + 6 ≤ 4n²`. So **`f(n) = O(n²)`** by definition.

---

#### Informal summary (same idea, less notation)

| Idea | Detail |
|------|--------|
| **Upper bound** | You are saying the algorithm takes **at most** on the order of `g(n)` steps. |
| **Worst case in practice** | When people say “the complexity is **O(n)**,” they usually mean **`T_worst(n) = O(n)`** (or a safe upper bound). |
| **Not “equals”** | `O(n²)` does **not** mean the algorithm always does exactly `n²` work; it might do less on some inputs. |
| **Link to simplification** | Dropping constants and lower terms in `T(n)` finds a simple **`g(n)`** that satisfies the CLRS inequality. |

**Examples:**

| Actual work `f(n)` | Valid Big O statements | Note |
|--------------------|------------------------|------|
| `3n + 10` | **O(n)**, also O(n log n), O(n²) | We give the **tightest usual** answer: O(n) |
| `n² + 5n` | **O(n²)** | Lower-order `5n` is dropped |
| `100` (fixed) | **O(1)** | Does not depend on `n` |

#### Rules and common mistakes (Big O)

| Rule | Example |
|------|---------|
| **Drop constant multipliers** | `3n + 100` → **O(n)** |
| **Drop lower-order terms** | `n² + 5n + 20` → **O(n²)** |
| **Keep the dominant term** | The term that grows fastest as `n` → ∞ |

| Wrong habit | Correct statement |
|-------------|-------------------|
| “This is O(3)” or “O(100)” | **O(1)** — constant time |
| “O(5n)” vs “O(n)” | Both are **O(n)**; the `5` is ignored |

Work that does **not** depend on `n` is always written **O(1)**, not O(3) or O(100).

#### Multiple inputs

If two sizes matter (e.g. `n` rows and `m` columns), complexity may be **O(n·m)**, **O(n + m)**, etc. State what each symbol means.

---

### Big Ω (Omega) notation (lower bound)

**Big Omega** states that an algorithm’s cost **`f(n)` is bounded below** by some multiple of `g(n)` for large `n`.

#### Formal definition (CLRS)

> **`f(n) = Ω(g(n))`** if there exist positive constants **`c`** and **`n₀`** such that  
> **`0 ≤ c · g(n) ≤ f(n)`** for all **`n ≥ n₀`**.

**Limit form (when the limit exists, `g(n) > 0`):**

$$\lim_{n \to \infty} \frac{|f(n)|}{g(n)} > 0 \quad \text{(and finite, or } \to \infty \text{)}$$

For a **tight** lower bound matching `g`, one often has **`lim |f(n)| / g(n) = L`** with **`L` a positive constant**.

**Best-case connection:** If **`T_best(n)`** is the **minimum** work over inputs of size `n`, then **`T_best(n) = Ω(g(n))`** means even the **easiest** input of that size still needs at least on the order of `g(n)` work.

| Idea | Detail |
|------|--------|
| **Lower bound** | The algorithm needs **at least** on the order of `g(n)` work — it cannot be asymptotically faster than that. |
| **Best case connection** | Sometimes Ω is used with **best-case** analysis: “you must do at least this much work even in the best situation.” |
| **Pair with O** | If you prove both `f(n) = O(g(n))` and `f(n) = Ω(g(n))`, you get `f(n) = Θ(g(n))`. |

**Examples:**

| Algorithm / problem | Lower bound intuition | Big Ω |
|---------------------|----------------------|-------|
| Print every element of an array of size `n` | Must touch each element at least once | **Ω(n)** |
| Comparison sort (general) | Must distinguish orderings | **Ω(n log n)** (standard result) |
| Binary search on sorted array | Each step eliminates half | **Ω(log n)** in the worst case for finding one element |

**Example:** If an algorithm always performs at least `n/2` comparisons for inputs of size `n`, then `f(n) ≥ n/2` → **Ω(n)**.

---

### Big Θ (Theta) notation (tight bound)

**Big Theta** means `f(n)` is **sandwiched** between constant multiples of `g(n)` — same growth order from above and below.

#### Formal definition (CLRS)

> **`f(n) = Θ(g(n))`** if there exist positive constants **`c₁`**, **`c₂`**, and **`n₀`** such that  
> **`0 ≤ c₁ · g(n) ≤ f(n) ≤ c₂ · g(n)`** for all **`n ≥ n₀`**.

Equivalently: **`f(n) = O(g(n))`** and **`f(n) = Ω(g(n))`** with the **same** **`g(n)`**.

**Limit form (when the limit exists, `g(n) > 0`):**

$$\lim_{n \to \infty} \frac{|f(n)|}{g(n)} = L \quad \text{where } L \text{ is a positive constant}$$

Then **`f(n) = Θ(g(n))`** — the ratio tends to a **fixed** constant, not 0 and not ∞.

| Idea | Detail |
|------|--------|
| **Tight / exact order** | “The algorithm grows **like** `g(n)`,” not just “at most” or “at least.” |
| **When to use** | When best and worst case are the **same order**, or when average case is proven to match (e.g. merge sort time is **Θ(n log n)** in all cases). |
| **Stronger than O alone** | Saying **Θ(n)** promises you cannot claim O(n) while secretly doing only O(log n) on every input — both upper and lower match. |

**Examples:**

| Situation | Statement |
|-----------|-----------|
| Merge sort time (always divides in half, always merges) | **Θ(n log n)** — best, average, and worst are the same order |
| Single loop `for (i = 0; i < n; i++)` body O(1) | **Θ(n)** — exactly `n` iterations |
| Linear search **worst** case only | **O(n)** is enough; worst is Θ(n), best is Θ(1) — whole algorithm is **not** Θ(n) |

---

### O vs Ω vs Θ — quick comparison

| Question | Use |
|----------|-----|
| “Will it ever need more than ~`g(n)` work?” | **O(g(n))** — upper / safe guarantee |
| “Must it always need at least ~`g(n)` work?” | **Ω(g(n))** — lower |
| “Does it grow **exactly** like `g(n)` (up to constants)?” | **Θ(g(n))** — tight |

| Relation | Meaning |
|----------|---------|
| `f(n) = Θ(g(n))` | Implies `f(n) = O(g(n))` **and** `f(n) = Ω(g(n))` |
| `f(n) = O(n)` only | Allows `f(n) = log n` or `f(n) = n` — only a ceiling |
| `f(n) = Ω(n²)` only | Allows `f(n) = n³` — only a floor |

**Course habit:** Problems often ask for **Big O** of **worst-case** time. Use **Θ** when the bound is tight in all cases (or you state which case). Use **Ω** when discussing **lower limits** (e.g. “any comparison sort needs Ω(n log n)”).

---

### Big O, Big Ω, Big Θ — links to best, average, and worst case

Many courses (including Mercury-style problem sets) **pair** each “Big” symbol with a **case** of running time. That is a **mnemonic**, not the full CLRS definition — but it is useful if you remember what each symbol **really** means.

| Notation | Bound type (CLRS) | Often used with… | Function | Meaning |
|----------|-------------------|------------------|----------|---------|
| **O(g(n))** | Upper (ceiling) | **Worst-case** time | **`T_worst(n)`** | Even the **hardest** input of size `n` needs **at most** ~`g(n)` work |
| **Ω(g(n))** | Lower (floor) | **Best-case** time | **`T_best(n)`** | Even the **easiest** input of size `n` needs **at least** ~`g(n)` work |
| **Θ(g(n))** | Tight (sandwich) | **Average-case** (when tight) | **`T_avg(n)`** | **Typical / expected** work grows **like** `g(n)` — **if** you proved upper and lower match for that case |

**Important corrections (CLRS vs classroom shorthand):**

| Shorthand you may hear | Precise truth |
|------------------------|---------------|
| “**Θ = average case only**” | **Θ** means **tight** for **whatever** `f(n)` you chose — worst, best, or average. Merge sort is **Θ(n log n)** for **worst** case too, not only average. |
| “**Ω = best case only**” | **Ω** is any **lower bound** on the function you analyze. Worst-case binary search is **Ω(log n)** (you still do at least ~log n work in the worst case). |
| “**O = worst case only**” | **O** is any **upper bound**. Best-case linear search is **O(1)**. |

**When the shorthand works well:**

| Algorithm | Best | Average | Worst | Usual report |
|-----------|------|---------|-------|--------------|
| Linear search | **Ω(1)** | **Θ(n)** if uniform random target | **O(n)** | Worst **O(n)** |
| Merge sort | **Θ(n log n)** | **Θ(n log n)** | **Θ(n log n)** | **Θ(n log n)** (all cases same order) |
| Quick sort (naive pivot) | **Ω(n log n)** possible | often **Θ(n log n)** | **O(n²)** | Worst **O(n²)**, average often **Θ(n log n)** |

```mermaid
flowchart TB
  subgraph cases [Running-time functions for input size n]
    W["T_worst(n) — maximum work"]
    B["T_best(n) — minimum work"]
    A["T_avg(n) — expected work"]
  end
  W --> OW["O(g) — upper on worst"]
  B --> OB["Ω(g) — lower on best"]
  A --> OT["Θ(g) — tight on average when proven"]
```

---

### Little-o and little-omega — strict (non-tight) bounds

CLRS also defines **little-o** and **little-omega**. They are **not** “small theta” — there is **no standard little-Θ** in CLRS. These notations mean the bound is **strict**: growth is **strictly** below or above `g(n)`, not just “up to a constant.”

| Notation | Name | CLRS-style definition (idea) | Limit (when it exists) |
|----------|------|------------------------------|-------------------------|
| **`f(n) = o(g(n))`** | Little-o | For **every** constant `c > 0`, `f(n) < c·g(n)` for all large `n` | \(\displaystyle \lim_{n \to \infty} \frac{f(n)}{g(n)} = 0\) |
| **`f(n) = ω(g(n))`** | Little-omega | For **every** constant `c > 0`, `f(n) > c·g(n)` for all large `n` | \(\displaystyle \lim_{n \to \infty} \frac{f(n)}{g(n)} = \infty\) |

**Loose vs tight vs strict:**

| Kind | Symbol | How tight? |
|------|--------|------------|
| **Loose upper** | **O(g)** | `f` may be **much smaller** than `g` (e.g. `f = n`, `g = n²`) |
| **Strict upper** | **o(g)** | `f` must be **strictly smaller order** than `g` (e.g. `f = n`, `g = n²` → `n = o(n²)`) |
| **Loose lower** | **Ω(g)** | `f` may be **much larger** than `g` |
| **Strict lower** | **ω(g)** | `f` must be **strictly larger order** than `g` |
| **Tight both sides** | **Θ(g)** | `f` is **sandwiched** between constant multiples of `g` |

So “**loosely bounded**” in practice usually means **Big O** or **Big Ω** alone (you only proved a **ceiling** or **floor**). **Little-o** / **little-omega** are **stricter**, not looser: they forbid `f` and `g` from being the **same** order.

**Relationships:**

| If true | Then also true | But not necessarily |
|---------|----------------|---------------------|
| `f(n) = o(g(n))` | `f(n) = O(g(n))` | `f(n) = Θ(g(n))` |
| `f(n) = ω(g(n))` | `f(n) = Ω(g(n))` | `f(n) = Θ(g(n))` |
| `f(n) = Θ(g(n))` | `f(n) = O(g(n))` and `f(n) = Ω(g(n))` | `f(n) = o(g(n))` or `ω(g(n))` |

**Examples:**

| `f(n)` | `g(n)` | Statement |
|--------|--------|-----------|
| `n` | `n²` | `f = o(g)` and `f = O(g)` — strict and loose upper |
| `n²` | `n` | `f = ω(g)` — `n²` grows strictly faster than `n` |
| `3n` | `n` | `f = Θ(g)` — same order; **not** `o(n)` or `ω(n)` |
| `100` | `n` | `f = o(n)` — constant is strictly less than linear |

**When courses mention “small o / small omega”:** They mean **`o`** and **`ω`** (lowercase). Use them when you want to say one function grows **strictly slower** or **strictly faster** than another, not merely “at most” or “at least.”

---

### Best, average, and worst case (with notation)

| Case | Meaning | Typical notation |
|------|---------|------------------|
| **Best case** | Minimum work over **all** inputs of size `n` | Often **Ω(...)** for lower bound on that case |
| **Worst case** | Maximum work over **all** inputs of size `n` | Usually stated as **O(...)** (upper bound) |
| **Average case** | Expected work over a **distribution** of inputs | **O(...)** or **Θ(...)** if proven tight |

**Example — linear search for a target in an array of size `n`:**

| Case | When | Bound |
|------|------|-------|
| Best | Target at index 0 | **O(1)**, **Ω(1)**, **Θ(1)** |
| Worst | Target absent or at last index | **O(n)**, **Ω(n)**, **Θ(n)** |
| Whole algorithm (mixed cases) | Not one fixed order | **O(n)** worst-case; **Ω(1)** best-case — **not** **Θ(n)** overall |

For interviews and design, **worst-case O(...)** is cited most often unless the problem specifies otherwise.

---

## Standard time complexity classes (with graphs)

Below: **horizontal axis** = input size `n`, **vertical axis** = work or memory (relative units). Curves show **shape of growth**, not exact constants.

### Growth comparison (overview)

For large `n`, from **slowest growing** to **fastest growing** among common classes:

```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

```mermaid
xychart-beta
    title "Relative growth (conceptual, n up to 20)"
    x-axis "n" [1, 5, 10, 15, 20]
    y-axis "operations (scaled)" 0 --> 400
    line "O(log n)" [0, 2.3, 3.3, 3.9, 4.3]
    line "O(n)" [1, 5, 10, 15, 20]
    line "O(n log n)" [0, 11.6, 33.2, 58.5, 86.4]
    line "O(n²)" [1, 25, 100, 225, 400]
```

*(For very large `n`, exponential and factorial curves dwarf everything else; they are omitted from the chart above so smaller classes remain visible.)*

---

### 1. Constant time — **O(1)**

**Definition:** The number of operations is **bounded by a fixed constant** that does **not** grow with `n`.

| Property | Detail |
|----------|--------|
| **As `n` increases** | Work stays (asymptotically) the same. |
| **Typical operations** | Access `arr[i]`, push/pop at end of vector (amortized O(1) for dynamic array), arithmetic on a few variables. |

**Examples:**

- Read the first or last element of an array.
- Find the **minimum of a sorted array** → always `arr[0]` → **one** access, **O(1)** (the fact that the array is long does not change the number of steps).
- Swap two variables, update a counter, hash table lookup **average** case (treated as O(1) in standard models).

**Graph — work vs `n`:**

```
work
  |     ___________________________  O(1)
  |
  +-----------------------------------> n
```

---

### 2. Logarithmic time — **O(log n)**

**Definition:** Each step **reduces** the problem size by a **constant factor** (often half), so the number of steps grows like **log₂ n** (base is omitted in Big O).

| Property | Detail |
|----------|--------|
| **Doubling `n`** | Adds only **one** more step (e.g. one more halving). |
| **Typical pattern** | Binary search, balanced tree height, exponentiation by squaring. |

**Example:** Binary search on a sorted array of size `n` — halve the search range each time → about **log₂ n** iterations → **O(log n)**. (Module 11.)

**Full derivation:** [Deriving O(log n) — binary search walkthrough](#deriving-olog-n--binary-search-walkthrough).

**Graph:**

```
work
  |              ****
  |          ****
  |      ****
  |  ****
  +-----------------------------------> n
        (slow increase — logarithmic)
```

**Intuition table:**

| n | ≈ log₂ n (halving steps) |
|---|--------------------------|
| 8 | 3 |
| 1,024 | 10 |
| 1,000,000 | ~20 |

---

### 3. Linear time — **O(n)**

**Definition:** Work grows **in proportion to `n`** — roughly a **constant amount of work per element**.

| Property | Detail |
|----------|--------|
| **Doubling `n`** | About **doubles** the work. |
| **Typical pattern** | Single loop over all `n` elements, linear scan, one pass merge of two lists totaling `n`. |

**Examples:** Find max/min in unsorted array, count frequencies in one pass, print all elements.

**Graph:**

```
work
  |                        /
  |                      /
  |                    /
  |                  /
  +-----------------------------------> n
              straight line — O(n)
```

---

### 4. Linearithmic time — **O(n log n)**

**Definition:** Work is **O(n)** times an **O(log n)** factor — very common in efficient comparison sorts and divide-and-conquer.

| Property | Detail |
|----------|--------|
| **Typical pattern** | **log n** levels of recursion, **O(n)** work per level (merge sort, heap sort, average quick sort). |
| **Comparison** | Much better than **O(n²)** for large `n`; slightly worse than **O(n)**. |

**Examples:** Merge sort, heap sort; `std::sort` is typically **O(n log n)** average.

**Graph:**

```
work
  |                    ****
  |                ****
  |            ****
  |        ****
  +-----------------------------------> n
        between linear and quadratic
```

---

### 5. Quadratic time — **O(n²)**

**Definition:** Work grows like **n²** — often **nested loops** each running about `n` times.

| Property | Detail |
|----------|--------|
| **Doubling `n`** | Roughly **quadruples** the work. |
| **Typical pattern** | All pairs `(i, j)`, simple comparison sorts (bubble, selection, insertion in worst/average). |

**Examples:** Bubble sort, selection sort, insertion sort (worst case), print all pairs in an array.

**Graph:**

```
work
  |                          *
  |                        *
  |                      *
  |                    *
  |                  *
  +-----------------------------------> n
              parabola — O(n²)
```

---

### 6. Cubic time — **O(n³)**

**Definition:** Work grows like **n³** — often **three nested loops** over `n`.

**Examples:** Naive matrix multiplication of two `n×n` matrices with three nested loops; checking all triples `(i, j, k)`.

**Graph:** Steeper than quadratic; becomes impractical for large `n` quickly.

```
work
  |                              *
  |                            *
  |                          *
  |                        *
  +-----------------------------------> n
```

---

### 7. Exponential time — **O(2ⁿ)** (and similar bases)

**Definition:** Work **doubles** (or multiplies by a constant base) when `n` increases by 1 — common in **brute-force** subsets and naive recursion without memoization.

**Examples:** Generate all subsets (2ⁿ choices), naive Fibonacci recursion tree size ~ O(2ⁿ) without caching.

**Graph:**

```
work
  |                                    *
  |                                  *
  |                                *
  |                              *
  |                            *
  +-----------------------------------> n
        explosive — unusable for large n
```

---

### 8. Factorial time — **O(n!)**

**Definition:** Work grows faster than any exponential with base 2 — common in **all permutations** brute force.

**Example:** Traveling salesman by trying every permutation of cities (~ **n!** orderings).

**Use:** Only tiny `n` (e.g. `n ≤ 10–12` in practice for naive approaches).

---

## Master comparison table

| Complexity | Name | Doubling `n` (rough effect) | Typical use |
|------------|------|-----------------------------|-------------|
| **O(1)** | Constant | Same order of work | Index access, fixed updates |
| **O(log n)** | Logarithmic | +constant steps | Binary search, balanced trees |
| **O(n)** | Linear | ~2× work | Single pass, linear search |
| **O(n log n)** | Linearithmic | ~2× × log factor | Efficient sorting |
| **O(n²)** | Quadratic | ~4× work | Nested loops, simple sorts |
| **O(n³)** | Cubic | ~8× work | Triple nested loops |
| **O(2ⁿ)** | Exponential | Work × ~2 | Subsets, naive recursion |
| **O(n!)** | Factorial | Explodes | Permutations brute force |

### “Which is better?” for large `n`

```
Faster (preferred)  ──────────────────────────────────────►  Slower (avoid for large n)

O(1) → O(log n) → O(n) → O(n log n) → O(n²) → O(n³) → O(2ⁿ) → O(n!)
```

**Numeric intuition** (same `n`, relative scale only):

| n | O(log n) | O(n) | O(n log n) | O(n²) |
|---|----------|------|------------|-------|
| 10 | ~3 | 10 | ~33 | 100 |
| 1,000 | ~10 | 1,000 | ~10,000 | 1,000,000 |
| 1,000,000 | ~20 | 1,000,000 | ~20,000,000 | 10¹² |

---

## Space complexity classes (summary)

Space uses the **same Big O classes** as time, but counts **memory locations** (or stack frames), not comparisons.

| Class | Example |
|-------|---------|
| **O(1)** | A few variables; in-place swap; iterative binary search. |
| **O(log n)** | Recursion depth `log n` (balanced binary search recursion). |
| **O(n)** | Copy of array, frequency table of size `n`, merge sort temp buffer. |
| **O(n²)** | 2D `n×n` table built by the algorithm (e.g. DP table). |

**Time–space trade-off:** Sometimes you use **extra O(n) memory** (hash set, prefix array) to reduce time from **O(n²)** to **O(n)**.

```mermaid
flowchart TB
  subgraph time_vs_space [Design trade-off]
    A[More memory] --> B[Faster lookup / fewer repeated passes]
    C[Less memory] --> D[May need slower nested loops]
  end
```

---

## Finding time complexity — three approaches

You can arrive at the same Big O class in different ways. All three are valid; use whichever fits the problem.

| Approach | When it helps |
|----------|----------------|
| **1. Graph** | Compare **shape** of growth (flat, line, parabola, explosion). |
| **2. Function (mathematical)** | You have a formula for operation count `T(n)` after counting steps. |
| **3. Intuition** | Recognize **loop patterns**, recursion depth, or “one pass / nested passes” without full algebra. |

```mermaid
flowchart TB
  Q[Need time complexity?]
  Q --> G["Graph: shape vs n"]
  Q --> F["Function: simplify T(n)"]
  Q --> I["Intuition: loops / recursion"]
  G --> R["Big O e.g. O(n²)"]
  F --> R
  I --> R
```

---

### 1. From graphs

Plot **work** (or relative work) on the **y-axis** and **input size `n`** on the **x-axis**. The **curve shape** tells you the class (see [Standard time complexity classes](#standard-time-complexity-classes-with-graphs) above).

| Shape of curve | Likely complexity |
|----------------|-------------------|
| Flat horizontal line | **O(1)** |
| Slow rise, doubles slowly when `n` doubles | **O(log n)** |
| Straight diagonal | **O(n)** |
| Between line and steep curve | **O(n log n)** |
| Parabola-like | **O(n²)** |
| Steeper than parabola, polynomial | **O(n³)**, etc. |
| Shoots up vertically for modest `n` | **O(2ⁿ)**, **O(n!)** |

**Example:** If doubling `n` roughly **quadruples** the operation count, the graph looks quadratic → **O(n²)**.

---

### 2. From functions (mathematical method)

First, express the total work as a function **`T(n)`** (number of operations in terms of `n`). Then convert **`T(n)`** to **Big O** using two simplification steps.

#### Step A — ignore constant multipliers (coefficients)

Drop leading constants on each term. Constants with **no** `n` are also dropped for the final class.

| Before | After (keep structure) |
|--------|-------------------------|
| `3n² + 5n + 6` | `n² + n + 1` |
| `10n + 50` | `n + 1` |
| `4n log n + 3n` | `n log n + n` |

#### Step B — remove lower-order (smaller) terms

Keep only the **term that grows fastest** as `n → ∞`.

| After step A | Dominant term | Big O |
|--------------|---------------|-------|
| `n² + n + 1` | `n²` | **O(n²)** |
| `n + 1` | `n` | **O(n)** |
| `n log n + n` | `n log n` | **O(n log n)** |
| `2ⁿ + n³ + n` | `2ⁿ` | **O(2ⁿ)** |

**Growth order reminder** (fastest at the end wins):

```
1 < log n < n < n log n < n² < n³ < … < 2ⁿ < n!
```

#### Worked example 1 (your course pattern)

```
T(n) = 3n² + 5n + 6

Step A (ignore constant multipliers):  n² + n + 1
Step B (drop smaller terms):           n²

Time complexity: O(n²)
```

#### Worked example 2 — linear

```
T(n) = 10n + 50

Step A:  n + 1
Step B:  n

Time complexity: O(n)
```

#### Worked example 3 — linearithmic

```
T(n) = 4n log₂ n + 3n + 100

Step A:  n log n + n + 1
Step B:  n log n          (n log n grows faster than n)

Time complexity: O(n log n)
```

#### Worked example 4 — exponential beats polynomial

```
T(n) = 2ⁿ + n³ + n

Step A:  2ⁿ + n³ + n      (coefficients already 1)
Step B:  2ⁿ               (2ⁿ dominates n³ and n)

Time complexity: O(2ⁿ)
```

#### Worked example 5 — constant

```
T(n) = 100

Step A/B:  no term in n

Time complexity: O(1)
```

#### Worked example 6 — cubic with extra terms

```
T(n) = 5n³ + 2n² log n + 8n + 20

Step A:  n³ + n² log n + n + 1
Step B:  n³               (n³ beats n² log n, n, and 1)

Time complexity: O(n³)
```

**Optional check:** If both a simplified upper bound and lower bound match, you can say **Θ(dominant term)** — e.g. `T(n) = 3n² + 5n + 6` is **Θ(n²)** when the algorithm always does that order of work in the case you analyzed.

---

### 3. From intuition

Use **structure of the code** without writing the full polynomial.

| What you see | Usual time |
|--------------|------------|
| Single loop over `n`, O(1) body | **O(n)** |
| Two nested loops, each `0 .. n-1` | **O(n²)** |
| Loop on `n`, inner loop halves index | **O(n log n)** |
| Loop `i *= 2` until `n` | **O(log n)** |
| Binary search, halving range | **O(log n)** |
| Merge sort–style: log levels, O(n) per level | **O(n log n)** |
| Recursion that splits in half + O(n) combine | Often **O(n log n)** |
| Try all subsets / permutations | **O(2ⁿ)** / **O(n!)** |

**Example (intuition):** Bubble sort — outer `n`, inner up to `n` → “about `n × n`” → **O(n²)** without expanding `n²/2 + n/2`. See [Practice 4 — bubble sort](#practice-4--bubble-sort) for the full sum.

**Example (intuition):** One `for` reading every array element once → **O(n)**.

When intuition and math disagree, **count more carefully** or write **`T(n)`** and simplify. More loop examples: [Practice problems](#practice-problems--loop-and-sort-analysis).

---

### Code analysis checklist

Apply this when reading any program (combine with graph or function method above).

| Step | Action |
|------|--------|
| 1 | Identify **input size** `n` (and `m` if multiple dimensions). |
| 2 | Count **loops**: single loop over `n` → often **O(n)**; nested `k` loops each `n` → often **O(nᵏ)**. |
| 3 | **Divide and conquer**: depth × work per level (Module 21 merge/quick sort). |
| 4 | **Recursion**: tree depth and work per node — see [Recursion — time and space complexity](#recursion--time-and-space-complexity). |
| 5 | Write **`T(n)`** if helpful, then **drop constants** and **lower-order terms**. |
| 6 | State **best / worst / average** if they differ. |
| 7 | For space, count **extra** structures and **recursion stack depth**. |

### Quick loop patterns

| Pattern | Time (typical) |
|---------|----------------|
| One loop `i = 0 .. n-1` | O(n) |
| Two nested loops, each `n` | O(n²) |
| Outer `n`, inner halving `j` | O(n log n) |
| Loop `i = 1; i < n; i *= 2` | O(log n) |

---

## Diagram: one picture for time classes

```
relative work (log scale feeling)
  |
  |                                              n!  *
  |                                            2^n *
  |                                         n³ *
  |                                    n² *
  |                              n log n *
  |                         n *
  |                    log n *
  |  1  __________________________________________________
  +--------------------------------------------------------> n
```

---

## Space complexity in practice

**Space complexity** is the amount of **extra** memory an algorithm uses as a function of input size **`n`**. (The formal definition is in [Space complexity — definition](#space-complexity--definition) above.)

### Where memory lives

| Region | What it holds | Examples |
|--------|----------------|----------|
| **Stack** | Local variables, function call frames (recursion depth) | `int mid` in binary search; each recursive call frame |
| **Heap** | Dynamically allocated data | `new int[n]`, `vector` growth, hash tables, merge-sort buffer |

### Input space vs auxiliary space

| Kind | Counted toward “algorithm space”? | Example |
|------|-----------------------------------|---------|
| **Input space** | The problem **gives** you the array — usually **not** blamed on the algorithm | Array of `n` integers passed in |
| **Auxiliary space** | **Yes** — extra structures the algorithm allocates | Temp array in merge sort, recursion stack |

**Rule of thumb:** When we say “space complexity **O(n)**,” we almost always mean **auxiliary** space unless the problem says “total space including input.”

| What increases auxiliary space | Typical result |
|--------------------------------|----------------|
| Allocate an array / vector of size `n` | **O(n)** |
| Recursion depth `d` | **O(d)** stack |
| 2D table `n × n` for DP | **O(n²)** |

### Example — merge sort (Module 21)

Merge sort **divides** the array and **merges** with a temporary buffer:

| Measure | Complexity | Why |
|---------|------------|-----|
| **Time** | **O(n log n)** | `log n` levels, **O(n)** merge work per level |
| **Auxiliary space** | **O(n)** | Temporary array (or similar) holding a copy during merge |

So merge sort is a classic **time–space trade-off**: you pay **O(n)** extra memory to get **O(n log n)** time instead of **O(n²)** in-place simple sorts.

### Time vs space — which matters more?

| Situation | Usual priority |
|-----------|----------------|
| Competitive programming, interviews, large datasets | **Lower time** first — a slow algorithm often fails before memory does |
| Embedded / huge data / memory limits | **Space** may dominate — then prefer in-place **O(1)** auxiliary algorithms |

**Practical note:** **O(n)** auxiliary for merge sort is usually acceptable because **O(n log n)** time is so much better than **O(n²)** for large `n`. You optimize space only when constraints require it.

---

## Comparing growth rates (with graphs)

For large `n`, small differences in Big O class dominate constant tweaks. Two comparisons that come up constantly:

### **O(log n)** vs **O(n)**

**O(log n)** grows **much slower** than **O(n)**. Doubling `n` adds **one** halving step for log; it **doubles** the work for linear.

| Input size `n` | ≈ **O(log n)** steps (log₂) | ≈ **O(n)** steps |
|----------------|----------------------------|------------------|
| 1,000 | ~10 | 1,000 |
| 100,000 | ~17 | 100,000 |
| 1,000,000,000 | ~30 | 1,000,000,000 |

So at **n = 10⁹**, logarithmic work is on the order of **tens** of steps; linear is **billions**.

```mermaid
xychart-beta
    title "O(log n) vs O(n) (conceptual)"
    x-axis "n" [10, 100, 1000, 10000]
    y-axis "steps (scaled)" 0 --> 10000
    line "O(log n)" [3.3, 6.6, 10, 13.3]
    line "O(n)" [10, 100, 1000, 10000]
```

**Takeaway:** Binary search **O(log n)** on a sorted array is vastly better than linear scan **O(n)** when you only need to search repeatedly on the same data.

---

### **O(n log n)** vs **O(n²)**

| Input size `n` | ≈ **n log₂ n** | ≈ **n²** |
|----------------|----------------|----------|
| 1,000 | ~10,000 | 1,000,000 |
| 10,000 | ~130,000 | 100,000,000 |

**O(n log n)** (merge sort, heap sort, efficient `std::sort`) scales to large inputs; **O(n²)** (bubble, insertion, selection in the usual nested-loop form) becomes slow quickly.

```mermaid
xychart-beta
    title "O(n log n) vs O(n²) (conceptual)"
    x-axis "n" [10, 50, 100, 200]
    y-axis "work (scaled)" 0 --> 50000
    line "O(n log n)" [33, 282, 664, 1520]
    line "O(n²)" [100, 2500, 10000, 40000]
```

---

## Deriving **O(log n)** — binary search walkthrough

Binary search on a **sorted** array of size `n` halves the search range each iteration.

```cpp
int binSearch(int *arr, int n, int key) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key > arr[mid]) {
            start = mid + 1;   // search right half
        } else {
            end = mid - 1;     // search left half
        }
    }
    return -1;
}
```

### Counting iterations

After each failed comparison, the remaining segment length is at most:

| Step | Remaining size (worst case) |
|------|-----------------------------|
| Start | `n` |
| After 1 | ≤ `n/2` |
| After 2 | ≤ `n/4` |
| After `k` | ≤ `n / 2^k` |

Stop when the segment has size **1** (or zero elements left):

```
n / 2^k = 1
n = 2^k
k = log₂ n
```

So the loop runs **at most** about **log₂ n** times → **O(log n)** time. Iterative version uses **O(1)** auxiliary space (only `start`, `end`, `mid`).

**Why log is “good”:** For **n = 10⁶**, **log₂ n ≈ 20** — that is why **O(log n)** is considered excellent for search and balanced-tree height.

---

## Common classes — quick examples (cheat sheet)

| Class | Name | Typical sources | Example |
|-------|------|-----------------|--------|
| **O(1)** | Constant | Fixed number of steps | First element `arr[0]` |
| **O(log n)** | Logarithmic | Halving each step | Binary search, balanced BST height |
| **O(n)** | Linear | One full pass | Linear search, find max in one loop |
| **O(n log n)** | Linearithmic | `log n` levels × `n` work/level | Merge sort, heap sort |
| **O(n²)** | Quadratic | Nested loops over `n` | Bubble/insertion/selection sort, naive pair loops |
| **O(2ⁿ)** | Exponential | Branching recursion, all subsets | Naive Fibonacci recursion; brute subsets |

**Exponential and DP:** Many naive recursive solutions are **O(2ⁿ)** (or similar) because they **recompute** the same subproblems. **Dynamic programming** / **memoization** removes repeated work and often drops time to **polynomial** (e.g. **O(n)** or **O(n²)**) at the cost of **extra O(n)** or **O(n²)** space.

---

## Practice problems — loop and sort analysis

Work through each problem by (1) counting inner iterations for a typical `i`, (2) summing over `i`, (3) simplifying to Big O. Assume the inner body does **Θ(1)** work (**k** operations = constant).

---

### Practice 1 — upper triangle of pairs

**Code:**

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        // constant work
    }
}
```

**Question:** What is the time complexity?

**Solution:**

| Outer `i` | Inner `j` runs from `i+1` to `n-1` | Inner iterations |
|-----------|--------------------------------------|------------------|
| `0` | `1 .. n-1` | `n - 1` |
| `1` | `2 .. n-1` | `n - 2` |
| … | … | … |
| `n - 2` | `n-1` only | `1` |
| `n - 1` | (empty) | `0` |

Total iterations:

```
(n - 1) + (n - 2) + … + 1 + 0 = n(n - 1) / 2 = (n² - n) / 2
```

Drop constants and lower terms → **O(n²)**.

**Intuition:** You touch about **half** of all ordered pairs `(i, j)` with `i < j` — still quadratic in `n`.

---

### Practice 2 — inner loop depends on `i`

**Code:**

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        // constant work
    }
}
```

**Question:** What is the time complexity?

**Solution:**

| Outer `i` | Inner `j` runs `0 .. i-1` | Inner iterations |
|-----------|---------------------------|------------------|
| `0` | (none) | `0` |
| `1` | `0` | `1` |
| `2` | `0, 1` | `2` |
| … | … | … |
| `n - 1` | `0 .. n-2` | `n - 1` |

Total:

```
0 + 1 + 2 + … + (n - 1) = n(n - 1) / 2
```

→ **O(n²)**.

**Note:** This is the **same order** as Practice 1 (only a constant factor differs: half the pairs vs all pairs above the diagonal).

---

### Practice 3 — stride `K` on the outer loop

**Code** (fixed integer **`K`** with `1 ≤ K < n`):

```cpp
for (int i = 0; i < n; i += K) {
    for (int j = 0; j <= K; j++) {
        // constant work
    }
}
```

**Question:** What is the time complexity in terms of `n` and `K`?

**Solution:**

| Part | Count |
|------|--------|
| Outer loop | `i = 0, K, 2K, …` → about **⌈n / K⌉** iterations |
| Inner loop | `j = 0 .. K` → **K + 1** iterations each time |

Total work:

```
Θ((n / K) · (K + 1)) = Θ(n + n/K) = Θ(n)   when K is a fixed constant
```

→ **O(n)**.

**Intuition:** The outer loop runs **fewer** times when `K` is large, but the inner loop runs **more** — the product stays **linear in `n`**.

If **`K` is not constant** (e.g. `K = n/2`), analyze separately; the table above assumes **fixed** `K` independent of `n`.

---

### Practice 4 — bubble sort

**Code:**

```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

**Question:** Worst-case time complexity?

**Solution:**

| Pass `i` | Inner limit `j < n - i - 1` | Comparisons (worst case) |
|----------|-------------------------------|---------------------------|
| `0` | `n - 1` | `n - 1` |
| `1` | `n - 2` | `n - 2` |
| … | … | … |
| `n - 2` | `1` | `1` |

Total comparisons:

```
(n - 1) + (n - 2) + … + 1 = n(n - 1) / 2
```

→ **O(n²)** time. Auxiliary space → **O(1)** (only a few variables if `swap` is in-place).

**Graph link:** Nested passes over a shrinking range → parabola-shaped growth → same class as [Quadratic time — O(n²)](#5-quadratic-time--on²).

---

## Recursion — time and space complexity

Recursive algorithms are analyzed with the same Big O tools as loops, but you count **recursive calls**, **work per call**, and **call-stack depth**.

### Two approaches

| Approach | Idea | When to use |
|----------|------|-------------|
| **1. Recursion tree / call count** | **Total work** ≈ (number of calls) × (work per call), or **sum work at each tree level** | Quick estimate; drawing the tree helps |
| **2. Recurrence relation** | Write **`T(n)`** from the code, then solve (expand, tree levels, or **Master’s theorem**) | Divide-and-conquer, formal proof |

```mermaid
flowchart LR
  R[Recursive code] --> A["Approach 1: tree / #calls × work"]
  R --> B["Approach 2: T(n) recurrence"]
  B --> M["Master theorem if aT(n/b) + f(n)"]
  A --> O["Big O answer"]
  M --> O
  B --> O
```

### Space complexity in recursion

| Formula (intuition) | Meaning |
|---------------------|---------|
| **Auxiliary stack space** ≈ **maximum depth of recursion tree** × **memory per stack frame** | Each active call holds local variables on the **call stack** |

| Pattern | Typical stack depth | Typical auxiliary space |
|---------|---------------------|-------------------------|
| **Linear recursion** (`f(n-1)`) | **O(n)** | **O(n)** stack |
| **Divide & conquer** (halve `n`, two calls) | **O(log n)** if balanced | **O(log n)** stack + sometimes **O(n)** heap (merge buffer) |

**Important:** Stack space is **auxiliary**. Extra arrays allocated in recursion (merge buffer) add to space separately.

### Linear vs divide-and-conquer recurrences

| Type | Code shape | Recurrence (time) | Tree shape |
|------|------------|-------------------|------------|
| **Linear** | One smaller subproblem `f(n-1)` | `T(n) = T(n-1) + Θ(1)` | **Chain** — depth `n` |
| **Divide & conquer** | Two (or `a`) subproblems of half size + combine | `T(n) = a·T(n/b) + f(n)` | **Branching** — depth **log_b n** |

---

### Example 1 — sum of numbers `1 + 2 + … + n`

**Code:**

```cpp
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}
```

#### Recurrence (approach 2)

```
T(n) = T(n - 1) + k        // k = Θ(1) work per call (compare, add, return)
T(n - 1) = T(n - 2) + k
   ⋮
T(0) = k

T(n) = (n + 1) · k  →  O(n)
```

#### Recursion tree (approach 1)

A **single chain** — no branching. Depth = **`n + 1`** nodes from `sum(n)` down to `sum(0)`.

```mermaid
flowchart TB
  S5["sum(5)"] --> S4["sum(4)"]
  S4 --> S3["sum(3)"]
  S3 --> S2["sum(2)"]
  S2 --> S1["sum(1)"]
  S1 --> S0["sum(0) base"]
```

| Measure | Calculation | Result |
|---------|-------------|--------|
| **Time** | `(n + 1)` calls × `Θ(1)` each | **O(n)** |
| **Space (stack)** | max depth × frame size | **(n + 1) × Θ(1) = O(n)** |

#### Call stack snapshot (`sum(3)`)

Stack grows on the way **down**; unwinds on **return** (values accumulate: `0 → 1 → 3 → 6`).

| Step | Call stack (bottom → top) | Action |
|------|---------------------------|--------|
| 1 | `sum(3)` | call `sum(2)` |
| 2 | `sum(3)`, `sum(2)` | call `sum(1)` |
| 3 | `sum(3)`, `sum(2)`, `sum(1)` | call `sum(0)` |
| 4 | `sum(3)`, `sum(2)`, `sum(1)`, `sum(0)` | base → return `0` |
| 5 | `sum(3)`, `sum(2)`, `sum(1)` | return `1 + 0 = 1` |
| 6 | `sum(3)`, `sum(2)` | return `2 + 1 = 3` |
| 7 | `sum(3)` | return `3 + 3 = 6` |

**Max frames alive at once:** **4** = **O(n)** for general `n`.

---

### Example 2 — factorial of `n`

**Code:**

```cpp
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
```

**Note:** The **value** satisfies `fact(n) = n · fact(n-1)` (factorial growth), but **time** recurrence is still **`T(n) = T(n-1) + Θ(1)`** — one recursive call and constant work per level.

#### Recursion tree

Same **linear chain** as `sum`, depth **`n + 1`**.

```mermaid
flowchart TB
  F4["fact(4)"] --> F3["fact(3)"]
  F3 --> F2["fact(2)"]
  F2 --> F1["fact(1)"]
  F1 --> F0["fact(0) → 1"]
```

| Measure | Result |
|---------|--------|
| **Time** | **O(n)** — `n` calls, `Θ(1)` each |
| **Space (stack)** | **O(n)** — depth `n + 1` |

#### Call stack (`factorial(3)`)

| Max stack | Frames |
|-----------|--------|
| Deepest | `fact(3) → fact(2) → fact(1) → fact(0)` |

Returns unwind: `1 → 1·1 → 2·1 → 3·2 = 6`.

---

### Example 3 — naive Fibonacci

**Code:**

```cpp
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
```

#### Recurrence

```
T(n) = T(n - 1) + T(n - 2) + Θ(1)
```

This is **not** Master-theorem form (two subproblems of sizes `n-1` and `n-2`, not `n/b`).

#### Recursion tree (`n = 5`)

Each internal node **branches twice** — many **repeated** subproblems.

```mermaid
flowchart TB
  F5["fib(5)"] --> F4["fib(4)"]
  F5 --> F3a["fib(3)"]
  F4 --> F3b["fib(3)"]
  F4 --> F2a["fib(2)"]
  F3a --> F2b["fib(2)"]
  F3a --> F1a["fib(1)"]
```

`fib(3)`, `fib(2)`, etc. appear **multiple times** — that is why work explodes.

**ASCII tree (small `n = 4`):**

```
                    fib(4)
                   /      \
              fib(3)        fib(2)
             /     \        /     \
        fib(2)   fib(1) fib(1)  fib(0)
        /    \
   fib(1) fib(0)
```

| Measure | Calculation | Result |
|---------|-------------|--------|
| **Time** | Roughly **~2ⁿ** calls (each call spawns two until base) | **O(2ⁿ)** — **exponential** |
| **Space (stack)** | Longest root-to-leaf path has length **`n`** | **O(n)** |

**Why it is bad:** For `n = 40`, about **10⁹** calls is already impractical.

#### Optimizing with DP (memoization)

Store `fib(k)` after computing once:

| Version | Time | Extra space |
|---------|------|-------------|
| Naive recursion | **O(2ⁿ)** | **O(n)** stack |
| Top-down memo / bottom-up DP | **O(n)** | **O(n)** table + **O(n)** stack (or **O(1)** space iterative) |

Recurrence becomes **`T(n) = T(n-1) + Θ(1)`** when each `fib(k)` computed once → **linear** time.

```mermaid
xychart-beta
    title "Naive fib vs DP (call count, conceptual)"
    x-axis "n" [5, 10, 15, 20]
    y-axis "relative work" 0 --> 25000
    line "naive ~2^n" [32, 1024, 8192, 21845]
    line "DP O(n)" [5, 10, 15, 20]
```

---

### Master’s theorem (divide-and-conquer recurrences)

**Applies when:**

```
T(n) = a · T(n/b) + f(n)     with a ≥ 1, b > 1
```

Compare **`f(n)`** to **`n^(log_b a)`** (work at the “leaf” level of the recursion tree).

Let **`c = log_b a`**.

| Case | Condition on `f(n)` | Result |
|------|---------------------|--------|
| **1** | `f(n) = O(n^d)` with **`d < c`** | **`T(n) = Θ(n^c) = Θ(n^(log_b a))`** |
| **2** | `f(n) = Θ(n^c log^k n)` for some **`k ≥ 0`** | **`T(n) = Θ(n^c log^(k+1) n)`** |
| **3** | `f(n) = Ω(n^d)` with **`d > c`** (+ regularity condition) | **`T(n) = Θ(f(n))`** |

**Intuition (recursion tree):**

| Case | Dominant work at |
|------|------------------|
| 1 | **Leaves** (many cheap leaves) |
| 2 | **Every level** (balanced — multiply levels × work/level) |
| 3 | **Root** (expensive combine step) |

#### Standard examples

| Algorithm | Recurrence | `a`, `b` | `log_b a` | `f(n)` | Case | Time |
|-----------|------------|----------|-----------|--------|------|------|
| **Binary search** | `T(n/2) + Θ(1)` | 1, 2 | 0 | `Θ(1) = Θ(n⁰)` | 2 (`c = 0`) | **Θ(log n)** |
| **Merge sort** | `2T(n/2) + Θ(n)` | 2, 2 | 1 | `Θ(n) = Θ(n¹)` | 2 (`c = 1`) | **Θ(n log n)** |
| **Fast power** | `T(n/2) + Θ(1)` | 1, 2 | 0 | `Θ(1)` | 2 | **Θ(log n)** |

---

### Example 4 — merge sort

**Code:**

```cpp
void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);   // Θ(ei - si + 1) work
}
```

#### Recurrence

For segment length **`n = ei - si + 1`:**

```
T(n) = 2 · T(n/2) + Θ(n)
```

**Master’s theorem:** `a = 2`, `b = 2`, `log₂ 2 = 1`, `f(n) = Θ(n)` → **case 2** → **`T(n) = Θ(n log n)`**.

#### Recursion tree (time) — work per level

For `n = 8`:

```
Level 0:          [ mergeSort n=8 ]     work Θ(8)
                 /                    \
Level 1:   [ n=4 ]                  [ n=4 ]     total Θ(8)
           /      \                /      \
Level 2: [4][4]  [4][4]  ...                 total Θ(8)
Level 3: 8 leaves (size 1)                   total Θ(8)

Depth = log₂ n  levels
Work per level = Θ(n)
Total = Θ(n log n)
```

```mermaid
flowchart TB
  L0["n=8 merge Θ(8)"] --> L1a["n=4"]
  L0 --> L1b["n=4"]
  L1a --> L2a["n=2"]
  L1a --> L2b["n=2"]
  L1b --> L2c["n=2"]
  L1b --> L2d["n=2"]
```

| Measure | Result | Notes |
|---------|--------|-------|
| **Time** | **O(n log n)** | `log n` levels × `Θ(n)` merge work per level |
| **Stack space** | **O(log n)** | Recursion depth on a balanced split |
| **Auxiliary heap** | **O(n)** | Temporary buffer in `merge` (see [Space complexity in practice](#space-complexity-in-practice)) |
| **Total auxiliary** | **O(n)** | Dominated by merge buffer |

#### Call stack (`mergeSort` on `[0..3]`, `n = 4`)

| Order | Stack (bottom → top) | Event |
|-------|----------------------|-------|
| 1 | `(0,3)` | call left `(0,1)` |
| 2 | `(0,3), (0,1)` | call left `(0,0)` |
| 3 | `(0,3), (0,1), (0,0)` | base return |
| 4 | `(0,3), (0,1)` | call right `(1,1)` → return, **merge** `(0,1)` |
| 5 | `(0,3)` | call right `(2,3)` → … same pattern |
| 6 | `(0,3)` | **merge** `(0,3)` |

**Max depth:** about **`log₂ n + 1`** frames → **O(log n)** stack.

---

### Example 5 — fast power `x^n` (binary exponentiation)

**Code:**

```cpp
int power(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int halfPow = power(x, n / 2);
    int sq = halfPow * halfPow;
    if (n % 2 != 0) {   // odd exponent
        sq *= x;
    }
    return sq;
}
```

**Idea:** Each step halves **`n`** → only **one** recursive call (not two like merge sort).

#### Recurrence

```
T(n) = T(n/2) + Θ(1)
```

**Master:** `a = 1`, `b = 2`, `log₂ 1 = 0`, `f(n) = Θ(1)` → **case 2** → **`T(n) = Θ(log n)`**.

#### Recursion tree

**Single chain** of depth **`log₂ n + 1`** (like binary search on `n`).

```mermaid
flowchart TB
  P16["power(n=16)"] --> P8["n=8"]
  P8 --> P4["n=4"]
  P4 --> P2["n=2"]
  P2 --> P1["n=1"]
  P1 --> P0["n=0 base"]
```

| `n` | Recursive calls (worst) | Time | Stack |
|-----|-------------------------|------|-------|
| 16 | ~5 (`16→8→4→2→1→0`) | **O(log n)** | **O(log n)** |

**Compare:** Naive loop multiplying `n` times → **O(n)** time.

#### Call stack (`power(x, 8)`)

| Step | Stack |
|------|-------|
| Deepest | `power(8) → power(4) → power(2) → power(1) → power(0)` |

Unwind: square at each level; multiply extra `x` when `n` was odd.

---

### Recursion examples — summary table

| Problem | Recurrence | Time | Stack space | Extra notes |
|---------|------------|------|-------------|-------------|
| `sum(n)` | `T(n-1) + Θ(1)` | **O(n)** | **O(n)** | Linear chain |
| `factorial(n)` | `T(n-1) + Θ(1)` | **O(n)** | **O(n)** | Linear chain |
| `fib(n)` naive | `T(n-1) + T(n-2) + Θ(1)` | **O(2ⁿ)** | **O(n)** | Use DP → **O(n)** time |
| **Merge sort** | `2T(n/2) + Θ(n)` | **O(n log n)** | **O(log n)** | + **O(n)** merge buffer |
| **`x^n` fast** | `T(n/2) + Θ(1)` | **O(log n)** | **O(log n)** | Halve exponent each step |
| **Binary search** | `T(n/2) + Θ(1)` | **O(log n)** | **O(1)** iterative / **O(log n)** recursive |

---

## Connecting to earlier modules

| Topic | Module | Typical complexity |
|-------|--------|-------------------|
| Linear search | Earlier arrays | Time **O(n)**, space **O(1)** |
| Binary search | 11 | Time **O(log n)**, iterative space **O(1)** |
| Bubble / selection / insertion sort | 13 | Time **O(n²)**, space **O(1)** |
| Merge sort | 21 | Time **O(n log n)**, space **O(n)** |
| Quick sort | 21 | Time **O(n log n)** average, **O(n²)** worst; partition space **O(1)** |

Complexity analysis is the language you use to **justify** these choices and to predict behavior on **large** inputs.

---

## Review & challenge problems

Short conceptual questions plus code analysis. Try each yourself before reading the solution.

---

### Problem 1 — **O(2ⁿ)** vs **O(n!)**

**Question:** Which is a **better** (faster-growing-slower) time complexity: **O(2ⁿ)** or **O(n!)**?

**Answer:** **O(2ⁿ)** is better (i.e. grows more slowly for large `n`).

**Why:** Among common classes, **n!** grows faster than **2ⁿ**:

```
… < O(2ⁿ) < O(n!) < …
```

| n | 2ⁿ | n! |
|---|-----|-----|
| 10 | 1,024 | 3,628,800 |
| 20 | ~10⁶ | ~2.4×10¹⁸ |

For large `n`, an **O(n!)** algorithm is unusable long before **O(2ⁿ)** becomes impractical.

---

### Problem 2 — **O(2ⁿ)** vs **O(nⁿ)**

**Question:** Which is better: **O(2ⁿ)** or **O(nⁿ)**?

**Answer:** **O(2ⁿ)** is better.

**Why:** Compare logs (same base):

```
log(2ⁿ) = n
log(nⁿ) = n · log n
```

For large `n`, **`n · log n > n`**, so **nⁿ** grows faster than **2ⁿ**.

**Note:** **O(nⁿ)** is **not** the same as **O(n!)** — factorial is even worse than **nⁿ** for large `n`.

---

### Problem 3 — nested loops (`i` linear, `j` doubles)

**Code:**

```cpp
int i, j, k = 0;
for (i = n / 2; i <= n; i++) {
    for (j = 2; j <= n; j = j * 2) {
        k = k + n / 2;
    }
}
```

**Question:** Find the time complexity (input size = `n`).

**Solution:**

| Loop | How many iterations? |
|------|----------------------|
| **Outer** `i` from `n/2` to `n` | About **`n/2 + 1` = Θ(n)** |
| **Inner** `j = 2, 4, 8, …` while `j ≤ n` | **`j` doubles** each time → **Θ(log n)** (same as `j *= 2`) |
| **Body** | `k = k + n/2` → **Θ(1)** per inner iteration |

Total:

```
Θ(n) × Θ(log n) × Θ(1) = O(n log n)
```

**Answer:** **O(n log n)** time, **O(1)** extra space (`i`, `j`, `k`).

---

### Problem 4 — `for (int i = 0; i < n; i++) i *= k;`

**Code (as written):**

```cpp
for (int i = 0; i < n; i++) {
    i *= k;
}
```

**Question:** What is the time complexity?

**Solution:** As written, this is **not a valid analysis problem** for typical `k`:

| `k` | What happens |
|-----|----------------|
| `k = 0` | `i` stays `0` → **infinite loop** |
| `k = 1` | `i` stays `0` → **infinite loop** |
| `k > 1` | `0 * k = 0` → `i` never advances → **infinite loop** |

So the snippet is almost certainly a **typo**. Common intended versions:

| Intended code | Iterations | Complexity |
|---------------|------------|------------|
| `i++` (normal loop) | `n` | **O(n)** |
| `i += k` (fixed step `k ≥ 1`) | about `n/k` | **O(n)** |
| `i *= 2` (separate loop, `i` starts at 1) | **Θ(log n)** | **O(log n)** |

**Answer to submit in class:** Point out the **bug**; if they meant **`i++`**, answer is **O(n)**; if they meant **`i *= 2`** with `i` starting at 1, answer is **O(log n)**.

---

### Problem 5 — “B is O(log n) so B always beats A which is O(n)”

**Statement:** Algorithm **A** has worst-case **O(n)** and **B** has worst-case **O(log n)**. Therefore **B always runs faster than A**.

**Answer:** **False.**

**Why Big O does not mean “always faster”:**

| Reason | Example |
|--------|---------|
| **Hidden constants** | `A` does `0.001n` ops; `B` does `1000 log n` ops → for small/medium `n`, **A** can be faster |
| **Only asymptotic for large `n`** | O(log n) wins **eventually**; not for every `n` |
| **O is an upper bound** | “O(n)” allows **Θ(1)** on some inputs; “O(log n)” allows **Θ(n)** on worst inputs if not tight |

**Correct statement:** For **sufficiently large** `n`, an algorithm with **Θ(log n)** worst case is faster than one with **Θ(n)** worst case **if** leading constants are comparable — not “always” for all `n`.

---

### Problem 6 — `floorSqrt` (integer square root)

**Code:**

```cpp
int floorSqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    int i = 1, result = 1;
    while (result <= x) {
        i++;
        result = i * i;
    }
    return i - 1;
}
```

**Question:** Time and space complexity? (Treat input size as **`n = x`**.)

**Solution:**

The loop increases **`i`** until **`i² > x`**. Smallest such **`i`** is about **`⌊√x⌋ + 1`**.

| Measure | Analysis | Result |
|---------|----------|--------|
| **Time** | Loop runs **Θ(√x)** times; each iteration **Θ(1)** | **O(√n)** if `n = x` |
| **Space** | Only `i`, `result` | **O(1)** |

**Recurrence view:** `T(x) = T(x-1) + O(1)` in a loose sense as `i` marches up — linear in **`√x`**, not in `x`.

**Answer:** **Time O(√n)**, **space O(1)** (auxiliary).

**Note:** A binary-search style sqrt can do **O(log n)** time; this brute-force version is **simpler but slower**.

---

### Problem 7 — nested loops, `j` decreases

**Code:**

```cpp
int a = 0;
for (int i = 0; i < n; ++i) {
    for (int j = n; j > i; --j) {
        a = a + i + j;
    }
}
```

**Question:** Time and space complexity?

**Solution:**

For each fixed **`i`**, **`j`** runs: `n, n-1, …, i+1` → **`(n - i)`** iterations.

| `i` | Inner iterations |
|-----|------------------|
| `0` | `n` |
| `1` | `n - 1` |
| … | … |
| `n - 1` | `1` |

Total:

```
n + (n - 1) + … + 1 = n(n + 1) / 2 = Θ(n²)
```

**Answer:** **Time O(n²)**, **space O(1)**.

**Link:** Same triangular sum as [Practice 1](#practice-1--upper-triangle-of-pairs) (pairs with `j > i`).

---

## Key takeaways

| # | Point |
|---|--------|
| 1 | **`n` is input size**; complexity describes **growth**, not seconds on one machine. |
| 2 | **Time** = how operations grow; **space** = how **auxiliary** memory grows. |
| 3 | **CLRS:** `f(n) = O(g(n))` ⇔ `f(n) ≤ c·g(n)` for large `n`; limit &#124;f/g&#124; &lt; ∞ (when defined). |
| 4 | **O** → worst-case ceiling; **Ω** → best-case floor; **Θ** → tight (often average when proven). |
| 5 | **o** / **ω** = strict upper/lower; no standard little-Θ. |
| 6 | **Big O** drops constants and lower terms; **O(1)** means constant, not “O(3)”. |
| 7 | Know the **ordering** of common classes and **best / average / worst** when they differ. |
| 8 | Use **graphs** to remember shape: flat (O(1)), slow rise (log), line (n), between line and parabola (n log n), parabola (n²), explosion (2ⁿ, n!). |
| 9 | Find complexity via **graph**, **function** (`T(n)` → simplify), or **intuition** (loops/recursion). |
| 10 | Analyze by **loops**, **recursion depth**, and **extra arrays**; redo [review problems](#review--challenge-problems). |
| 11 | **Heap vs stack**, **input vs auxiliary** space; merge sort = **O(n)** extra for **O(n log n)** time. |
| 12 | **O(log n) ≪ O(n)** and **O(n log n) ≪ O(n²)** for large `n` — use comparison tables and graphs. |
| 13 | Practice: triangle loops → **O(n²)**; stride-`K` outer + fixed inner → **O(n)**; bubble sort → **O(n²)**. |
| 14 | Recursion: **tree / #calls × work** or **recurrence**; stack space ≈ **depth × frame**. |
| 15 | Linear recursion → **O(n)** time & stack; naive **fib** → **O(2ⁿ)** time, **O(n)** stack; **DP** fixes time. |
| 16 | **Master’s theorem** for `a·T(n/b) + f(n)` → merge sort **Θ(n log n)**, binary search / fast pow **Θ(log n)**. |
| 17 | Draw **recursion tree** + **call stack** to avoid confusing depth with total calls (e.g. fib). |
| 18 | **O(2ⁿ)** beats **O(nⁿ)** and **O(n!)**; **O** ≠ “always faster”; know **`i *= k`** typos. |

---

**Next steps:** Define `T(n)` for each loop and recurrence, simplify to Big O, and check best vs worst case. Redo [loop practice](#practice-problems--loop-and-sort-analysis), [review problems](#review--challenge-problems), and sketch trees for [sum](#example-1--sum-of-numbers-1--2--n), [fib](#example-3--naive-fibonacci), and [merge sort](#example-4--merge-sort) without looking. In later modules, the same formal bounds apply to trees, graphs, and dynamic programming.

**Further reading:** Cormen, Leiserson, Rivest, and Stein — *Introduction to Algorithms* (CLRS), chapter on asymptotic notation (Big O, Ω, Θ, little-o, little-ω) and recurrence / Master theorem.
