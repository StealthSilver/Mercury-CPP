# MODULE 25 — Stack

**Illustration code:** `a.cpp` (stack + bucket model) · `b.cpp` (LIFO order trace) · `c.cpp` (stack with `std::vector`) · `d.cpp` (templated `Stack<T>`)

---

## What is a stack?

A **stack** is a linear data structure where you only add or remove elements from **one end**. That end is usually called the **top** of the stack.

Think of it like a **bucket** or a **stack of plates** in the kitchen:

- You always put a new plate on **top** of the pile.
- You always take the next plate from the **top** as well.
- You do **not** pull a plate from the middle without lifting everything above it first.

So the stack follows **LIFO** (Last In, First Out): the last thing you pushed is the first one you pop.

---

## “Static” picture in memory

In code, a stack is often built on a **fixed block of memory** (for example, a C-style array of fixed size). You can imagine that block as a **bucket** with a fixed number of slots:

- Memory is laid out in a row: index `0`, `1`, `2`, … up to `capacity - 1`.
- A variable (often called `top` or `sp` for “stack pointer”) remembers **how full** the bucket is: it points at the position **above** the last stored element, or at the index where the **next** push will go.

Nothing “allocates” a new cell for each push in the simple array version: you reuse the same bucket and only move the logical “top” index. That is the sense in which it feels **static**—one pre-sized region of memory, used in a disciplined way.

---

## Three main operations

| Operation | Meaning |
|-----------|---------|
| **Push(x)** | Put `x` on top of the stack (if there is room). |
| **Pop()** | Remove the element on top (if the stack is not empty). |
| **Top()** | Read the element on top **without** removing it (if not empty). |

In a correct implementation with a fixed-size array backing:

- **Push** writes at the current top index and advances the top.
- **Pop** moves the top back by one (the old value may still sit in memory but is no longer “in” the stack).
- **Top** returns the value at the last pushed position.

---

## Time complexity

**Push**, **Pop**, and **Top** each do a **constant** amount of work: a few index updates and maybe one assignment or read. So each operation runs in **O(1)** time—**constant time**—as long as you do not count growing the underlying storage (in `a.cpp` we use a fixed capacity, so every operation is truly O(1)).

---

## When stacks are useful

- Undo/redo, parsing expressions, matching brackets.
- Depth-first traversal, function call stack (the language runtime uses a stack for calls and locals).
- Converting recursion to iteration by explicitly storing “where to continue” on a stack.

Run `a.cpp` and follow the printed steps to see push, top, and pop in order.

---

## LIFO — Last In, First Out

**Illustration code:** `b.cpp`

**LIFO** is the ordering rule behind a stack (and behind anything that behaves like a one-ended pile).

- **Last in** — the item you most recently **pushed** sits at the **top**.
- **First out** — when you **pop**, that newest item leaves **before** anything that arrived earlier.

So removal order is the **reverse** of insertion order:

| Push order (in) | Pop order (out) |
|-----------------|-----------------|
| 1st → A | Last popped |
| 2nd → B | Middle |
| 3rd → C | **First** popped |

If you push `A`, then `B`, then `C`, the first `pop` gives `C`, then `B`, then `A`. The **last** pushed (`C`) is the **first** removed — hence **LIFO**.

Contrast with **FIFO** (First In, First Out), used by a **queue**: a line at a counter where the person who arrived first is served first.

Stacks are not “unfair”; they are defined to behave this way so algorithms can rely on **nested** or **nested-and-unwind** structure (e.g. matching brackets, undo, returning from the most recent function call first).

Run `b.cpp` to print a step-by-step trace of pushes and pops so you can read the order of values leaving the stack.

---

## Implementing a stack with `std::vector`

**Illustration code:** `c.cpp`

Instead of a **fixed-size array**, you can back the stack with a **`std::vector`**. The vector still stores elements in a contiguous row; the stack still only uses **one end** as the top.

| Stack idea | `std::vector` member / idiom |
|------------|------------------------------|
| Push on top | `push_back(x)` — append at the back |
| Pop from top | `pop_back()` — remove the last element |
| Read top | `back()` — reference to the last element |
| Empty? | `empty()` |
| How many? | `size()` |

**Why use a vector?** The stack **grows** as needed (until memory runs out). You do not pick `CAPACITY` up front. The trade-off is that `push_back` may occasionally **reallocate** when capacity is full; each push is still **amortized O(1)** time in typical use, which is good enough for the same stack algorithms.

**Class design in `c.cpp`:** A small `Stack` class wraps a private `vector` and exposes **`push`**, **`pop`**, **`top`**, **`empty`**, **`size`**, and **`clear`** so the outside world only talks in stack terms (no random access to the middle). `main` pushes and pops integers and prints state so you can follow the behavior.

Run `c.cpp` to see the same LIFO behavior with a dynamic backing store.

---

## Stack as a class template (`Stack<T>`)

**Illustration code:** `d.cpp`

In `c.cpp`, the stack is hard-coded to **`int`**. Often you want **one implementation** that works for **`double`**, **`string`**, **`char`**, or your own **`struct`**.

A **class template** lets you name a **placeholder type** (usually written **`T`**) and write the class once:

```cpp
template <typename T>
class Stack {
    std::vector<T> data;
    // ...
};
```

When you write **`Stack<int>`** or **`Stack<std::string>`**, the compiler **generates** a concrete class by substituting `T` with that type. The stored type is not a “runtime variable”; it is fixed **per instantiation** at compile time.

**Backing store:** Same as `c.cpp` — a **`std::vector<T>`** with **`push_back`** / **`pop_back`** / **`back`**.

**Requirements:** Any type `T` you store must be **assignable** and **copyable or movable** in the ways your `Stack` uses (here: default constructible for the empty-`top()` demo path, and streamable with **`<<`** if you use `print()`). `int`, `double`, `std::string`, etc. satisfy this.

`d.cpp` defines **`template <typename T> class Stack`** and in **`main`** uses **`Stack<int>`** and **`Stack<std::string>`** so you can see the same API with different element types.

Run `d.cpp` to compare stacks of integers and strings built from one template.

STACK USING THE LINKED LIST -> E.CPP