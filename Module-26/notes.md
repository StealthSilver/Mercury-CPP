# MODULE 26 — Queue

**Illustration code:** `a.cpp`–`f.cpp` (queue basics) · `g.cpp` (first non-repeating in stream) · `h.cpp` (interleave queues / halves) · `i.cpp` (queue reversal) · `j.cpp` (`std::deque` — double-ended queue)

---

## What is a queue?

A **queue** is a linear data structure where you add elements at one end and remove them from the **other** end.

- **Enqueue** — insert at the **rear** (back of the line).
- **Dequeue** — remove from the **front** (front of the line).
- **Front** — look at the front element without removing it.

Think of a **line at a ticket counter** or a **printer job list**:

- The first person who joins the line is served **first**.
- New people always stand at the **rear**.

So a queue follows **FIFO** — **First In, First Out**: the oldest element leaves first.

---

## FIFO vs LIFO (stack)

| | **Stack** (Module 25) | **Queue** (Module 26) |
|--|----------------------|------------------------|
| Rule | **LIFO** — Last In, First Out | **FIFO** — First In, First Out |
| Add | **Push** on top | **Enqueue** at rear |
| Remove | **Pop** from top | **Dequeue** from front |
| Analogy | Stack of plates | Line at a counter |

```text
Enqueue 10, 20, 30  ->  front [ 10 | 20 | 30 ] rear
Dequeue             ->  removes 10 (first in)
```

---

## Array implementation (circular buffer)

In `a.cpp` we use a **fixed-size array** as a **circular queue**:

- **`front`** — index of the first element.
- **`rear`** — index where the **next** enqueue will write.
- **`count`** — how many elements are stored.

Enqueue writes at **`rear`**, then advances **`rear = (rear + 1) % CAPACITY`**.  
Dequeue reads at **`front`**, then advances **`front = (front + 1) % CAPACITY`**.

Wrapping lets us reuse slots at the start of the array after dequeues — no shifting of all elements.

```text
CAPACITY = 8

after enqueue 10, 20, 30:
  front -> [10][20][30][ _ ][ _ ]...
  rear points to next empty slot
```

---

## Main operations

| Operation | Meaning |
|-----------|---------|
| **Enqueue(x)** | Add `x` at the rear (if not full). |
| **Dequeue()** | Remove the front element (if not empty). |
| **Front()** | Read the front element without removing. |
| **Empty() / Full()** | Check state. |

With a circular array and fixed capacity, **enqueue**, **dequeue**, and **front** are **O(1)** time.

---

## When queues are useful

- **BFS** in graphs (process nodes in order discovered).
- **CPU / task scheduling**, print spoolers, message buffers.
- **Level-order** traversal in trees.
- Any problem that needs “handle the **oldest** waiting item first”.

Run `a.cpp` to see enqueue, front, and dequeue in FIFO order.

---

## Queue using a linked list

**Illustration code:** `b.cpp`

In `a.cpp` the queue lives in a **fixed array**. With a **singly linked list**, each value is a **node** (`data` + `next`). There is **no capacity limit** (until memory runs out).

### Two pointers: `front` and `rear`

| Pointer | Points to |
|---------|-----------|
| **`front`** | First node (next to **dequeue**) |
| **`rear`** | Last node (where we **enqueue**) |

```text
front                          rear
  |                              |
  v                              v
 [10] -> [20] -> [30] -> nullptr
```

- **Enqueue** — create a node, link **`rear->next = newNode`**, move **`rear`** forward. **O(1)** because we keep **`rear`**.
- **Dequeue** — remove **`front`**, advance **`front`**. If the list becomes empty, set **`rear = nullptr`** too. **O(1)**.
- **Front** — return **`front->data`**. **O(1)**.

```mermaid
flowchart LR
  subgraph enqueue["enqueue(40)"]
    A["rear->next = new 40"] --> B["rear = new node"]
  end
  subgraph dequeue["dequeue()"]
    C["delete front"] --> D["front = front->next"]
  end
```

**Important:** If you only stored **`front`** and enqueued by walking to the end of the list, each enqueue would be **O(n)**. Keeping **`rear`** makes enqueue **O(1)**.

### Operation names (same queue, two naming styles)

| Queue name | Same idea as | Where |
|------------|--------------|--------|
| **enqueue(x)** | **push(x)** (add at **rear**) | back of line |
| **dequeue()** | **pop()** (remove from **front**) | front of line |
| **front()** | peek first element | front of line |

Do **not** confuse with a **stack**: stack **push/pop** use one end only; queue **enqueue/dequeue** use **opposite** ends.

`b.cpp` implements **`enqueue` / `dequeue` / `front`** and aliases **`push` / `pop`** that call the same logic.

### Time complexity

| Operation | Time |
|-----------|------|
| **enqueue** / **push** | **O(1)** |
| **dequeue** / **pop** | **O(1)** |
| **front** | **O(1)** |
| **empty** / **size** | **O(1)** |

### Space complexity

- **O(n)** for **`n`** stored elements — one node per value, plus two pointers (`front`, `rear`).
- Each **`new`** on enqueue is matched with **`delete`** on dequeue; destructor frees any remaining nodes.

### vs array queue (`a.cpp`)

| | Array (`a.cpp`) | Linked list (`b.cpp`) |
|--|-----------------|------------------------|
| Capacity | Fixed **`CAPACITY`** | Grows with allocations |
| Enqueue / dequeue | **O(1)** | **O(1)** |
| Extra memory | No per-node pointer | Pointer per node |
| Locality | Contiguous (cache-friendly) | Nodes may be scattered |

Run `b.cpp` for a **`Queue`** class with linked-list **enqueue**, **dequeue**, and **front**.

---

## Circular queue (array implementation)

**Illustration code:** `c.cpp`

A **circular queue** stores elements in a **fixed-size array** but treats the array as a **ring**: after the last index, the next slot is index **0** again.

### Why circular?

A **naive array queue** might dequeue by shifting every element left — **O(n)** per dequeue.

With **two indices** — **`front`** (dequeue here) and **`rear`** (enqueue here) — and **modulo** wrap:

```text
index:   0    1    2    3    4
        [20][30][ _ ][ _ ][40]   <- logical: front=0, rear=3 after wrap
          ^front          ^rear (next write at index 3)
```

After dequeues free slots at the start, **enqueue** can reuse them without shifting.

```mermaid
flowchart LR
  subgraph ring["array as ring"]
    A0["0"] --> A1["1"] --> A2["2"] --> A3["3"] --> A0
  end
```

### Variables (`c.cpp`)

| Field | Role |
|-------|------|
| **`data[CAPACITY]`** | Storage |
| **`front`** | Index of first element |
| **`rear`** | Index where **next** enqueue writes |
| **`count`** | Number of elements (tells empty vs full) |

**Empty:** `count == 0`  
**Full:** `count == CAPACITY`

Using **`count`** avoids the “waste one slot” trick (`(rear+1)%CAP == front` means full).

### Operations (all **O(1)**)

| Operation | Action |
|-----------|--------|
| **enqueue(x)** | If not full: `data[rear]=x`, `rear=(rear+1)%CAPACITY`, `count++` |
| **dequeue()** | If not empty: `front=(front+1)%CAPACITY`, `count--` |
| **front()** | Return `data[front]` |
| **isEmpty() / isFull()** | Check `count` |

### Time and space

| | |
|--|--|
| **Time** | **O(1)** per enqueue, dequeue, front |
| **Space** | **O(CAPACITY)** — fixed array; at most **`CAPACITY`** elements |

### Wrap-around example

`CAPACITY = 5`, enqueue `1..5` (full), dequeue `1,2`, enqueue `6,7`:

```text
Physical array:  [6][7][3][4][5]
                  ^front=0  rear=2 (next slot)
Logical order:   3, 4, 5, 6, 7  (FIFO)
```

`c.cpp` defines class **`CircularQueue`** and **`main`** demonstrates fill → dequeue → enqueue with wrap.

Run `c.cpp` to see indices reuse after dequeue.

---

## Queue in the C++ standard library (`std::queue`)

**Illustration code:** `d.cpp`

Include the header:

```cpp
#include <queue>
```

**`std::queue<T, Container>`** is a **container adapter**: it wraps an underlying sequence container (default **`std::deque<T>`**) and only exposes **FIFO** queue operations.

### Map to our queue names

| Our queue (`a`–`c`) | `std::queue` |
|---------------------|--------------|
| enqueue | **`push(x)`** or **`emplace(...)`** |
| dequeue | **`pop()`** (returns **`void`**) |
| front | **`front()`** |
| peek rear | **`back()`** |
| empty / size | **`empty()`**, **`size()`** |

There is **no** **`clear()`** member. Empty the queue by looping **`pop()`** or **`swap`** with an empty queue (see `d.cpp`).

### Member functions (what `d.cpp` demonstrates)

| Category | Functions |
|----------|-----------|
| **Constructors** | default **`queue()`**, copy **`queue(const queue&)`**, move **`queue(queue&&)`**, from container **`queue(const Container& c)`** |
| **Assignment** | **`operator=`** (copy / move) |
| **Access** | **`front()`**, **`back()`** |
| **Capacity** | **`empty()`**, **`size()`** |
| **Modifiers** | **`push(x)`**, **`emplace(args...)`**, **`pop()`**, **`swap(other)`** |
| **Non-member** | **`swap(q1, q2)`**, **`==`**, **`!=`**, **`<`**, **`<=`**, **`>`**, **`>=`** |

**`pop()`** removes the front element but does **not** return it — read **`front()`** first if you need the value.

Default backing store is **`deque`** (good for growth at both ends internally). You can pass **`std::list<T>`** as the second template argument: **`queue<int, list<int>>`**.

### Complexity (typical)

| Operation | Time |
|-----------|------|
| **`push`**, **`pop`**, **`front`**, **`back`**, **`empty`**, **`size`** | **O(1)** amortized |
| **Copy / move** whole queue | **O(n)** |

### Space

**O(n)** for **`n`** elements stored in the underlying container.

`d.cpp` runs through **every** common **`std::queue`** member and helper in one program.

Run `d.cpp` to see all STL queue functions in action.

---

## Queue using two stacks

**Illustration code:** `e.cpp`

You can simulate a **FIFO queue** using only **two LIFO stacks** — often called **`inStack`** (incoming) and **`outStack`** (outgoing).

### Idea

| Operation | What to do |
|-----------|------------|
| **Enqueue** | **Push** onto **`inStack`** only. **O(1)**. |
| **Dequeue** | If **`outStack`** is empty, **pop** everything from **`inStack`** and **push** onto **`outStack`** (reverses order). Then **pop** from **`outStack`**. |
| **Front** | Same as dequeue, but **peek** **`outStack.top()`** without popping (after transfer if needed). |

```text
enqueue 1,2,3  ->  inStack:  bottom [1,2,3] top

dequeue:
  transfer inStack -> outStack
  inStack: empty    outStack: bottom [3,2,1] top
  pop outStack -> returns 1  (FIFO!)
```

```mermaid
flowchart LR
  subgraph enqueue["enqueue(x)"]
    E["push x on inStack"]
  end
  subgraph dequeue["dequeue()"]
    T["if outStack empty: pour inStack into outStack"]
    P["pop outStack"]
  end
  E --> T --> P
```

**Why it works:** Stack reverses order. Pushing `1,2,3` on `inStack` gives top `3`. Pouring into `outStack` makes top `1` — the **first** enqueued — so dequeue is FIFO.

### Amortized time

| Operation | Time |
|-----------|------|
| **Enqueue** | **O(1)** every time |
| **Dequeue** | **O(1) amortized** — each element moves from `inStack` to `outStack` **at most once** over its lifetime |
| **Dequeue (worst single call)** | **O(n)** when `outStack` is empty and you pour **`n`** elements |

So a long series of enqueues and dequeues costs **O(1)** per dequeue on average, like a normal queue.

### Space

**O(n)** — at most **`n`** elements split across the two stacks.

### When this pattern appears

- Interview classic: “implement queue using stacks.”
- Shows how **LIFO + LIFO** can mimic **FIFO** with careful transfer.
- Related: **stack using two queues** (opposite problem).

`e.cpp` defines **`QueueTwoStacks`** with **`enqueue`**, **`dequeue`**, **`front`**, and a demo trace.

Run `e.cpp` to compare FIFO order with the two-stack transfer step.

---

## Stack using two queues

**Illustration code:** `f.cpp`

The mirror of **`e.cpp`**: simulate a **LIFO stack** using only **two FIFO queues** — **`mainQ`** and **`helperQ`**.

### Idea (push costs more, pop is cheap)

| Operation | What to do |
|-----------|------------|
| **Push(x)** | Enqueue **`x`** on **`helperQ`**. Move every element from **`mainQ`** to **`helperQ`**. **Swap** the two queues. New top is at **`mainQ.front()`**. |
| **Pop** | Dequeue from **`mainQ.front()`**. **O(1)**. |
| **Top** | Return **`mainQ.front()`** (after pushes, the stack top is always at the front). **O(1)**. |

```text
push(1):  mainQ: [1]                    (front = top = 1)
push(2):  helper [2], pour 1 -> [2,1], swap -> mainQ [2,1]   top = 2
push(3):  helper [3], pour -> [3,2,1], swap -> mainQ [3,2,1] top = 3
pop():    dequeue front -> 3  (LIFO)
```

```mermaid
flowchart LR
  subgraph push["push(x)"]
    A["enqueue x on helperQ"] --> B["pour mainQ into helperQ"]
    B --> C["swap mainQ and helperQ"]
  end
  subgraph pop["pop()"]
    D["dequeue mainQ.front()"]
  end
```

**Why it works:** Each **push** rotates the queue so the **newest** element moves to the **front**. The **front** of the queue always holds the stack **top**; **pop** removes it in **O(1)**.

### Alternative (opposite costs)

You can instead **push in O(1)** and **pop in O(n)** by moving **`size - 1`** elements to the helper queue, popping the last one, then swapping — similar to **`e.cpp`**’s pour-on-dequeue style.

`f.cpp` uses **O(n) push / O(1) pop** so **`top()`** stays simple.

### Time complexity

| Operation | Time |
|-----------|------|
| **Push** | **O(n)** — pour all of **`mainQ`** into **`helperQ`** |
| **Pop** / **Top** | **O(1)** |

### Space

**O(n)** — elements live in the two queues combined.

### Pair with Module 25 / `e.cpp`

| Problem | Tools | Typical trick |
|---------|--------|----------------|
| Queue from 2 stacks (`e.cpp`) | LIFO + LIFO | Pour when dequeuing |
| Stack from 2 queues (`f.cpp`) | FIFO + FIFO | Pour when pushing |

`f.cpp` defines **`StackTwoQueues`** with **`push`**, **`pop`**, **`top`**.

Run `f.cpp` to see LIFO order with two `std::queue`s.

---

# Practice problems

---

## First non-repeating letter in a stream

**Code:** `g.cpp`

### Problem statement

Characters arrive **one at a time** (a stream). After **each** new character, output the **first** character (from the start of the stream until now) that has appeared **exactly once** so far.

If every character seen so far repeats at least twice, output **`'#'`** (or another sentinel your problem uses).

**Example:** stream `"aabc"` → output after each char: **`a`**, **`#`**, **`b`**, **`b`**

| Step | Stream so far | First unique |
|------|---------------|--------------|
| `a` | `a` | `a` |
| `a` | `aa` | none → `#` |
| `b` | `aab` | `b` |
| `c` | `aabc` | `b` (still oldest with count 1) |

### Approach

- **`freq[c]`** — how many times character **`c`** appeared.
- **`queue<char>`** — candidates in **order of first appearance** (FIFO).

On each new character **`c`**:

1. **`freq[c]++`**
2. **`enqueue c`**
3. **While** **`queue.front()`** has **`freq > 1`**, **dequeue** (no longer a unique candidate).

The **front** of the queue (if any) is the **oldest** character that is still unique.

```mermaid
flowchart TD
  A["read char c"] --> B["freq[c]++"]
  B --> C["enqueue c"]
  C --> D{"freq[front] > 1?"}
  D -->|yes| E["dequeue front"]
  E --> D
  D -->|no| F["answer = front or '#'"]
```

### Complexity

| | |
|--|--|
| **Time** | **O(1)** amortized per character — each char enqueued once and dequeued at most once |
| **Space** | **O(1)** if alphabet size is fixed (e.g. 26 letters); **O(k)** for **`k`** distinct chars in stream |

---

## Interleave two queues / two halves

**Code:** `h.cpp`

### Problem A — Interleave two queues

Given **`q1`** and **`q2`**, build a new sequence by taking elements **alternately**: first from **`q1`**, then from **`q2`**, until one is empty, then append the rest of the other.

**Example:** `q1 = [1,2,3]`, `q2 = [4,5,6]` → **`[1,4,2,5,3,6]`**

```text
q1: 1 2 3
q2: 4 5 6
     | | |
out: 1 4 2 5 3 6
```

### Problem B — Interleave two halves of one queue (even length)

Given a queue of **even** size, split into **first half** and **second half**, then interleave.

**Example:** `[11,12,13,14,15,16]` → halves `[11,12,13]` and `[14,15,16]` → **`[11,14,12,15,13,16]`**

```text
first:  11  12  13
second: 14  15  16
out:    11  14  12  15  13  16
```

### Approach

Use extra **`queue`**s (or indices): dequeue from each side in turn and push to result.

### Complexity

| | |
|--|--|
| **Time** | **O(n)** — each element moved a constant number of times |
| **Space** | **O(n)** — result / temporary queues |

---

## Queue reversal

**Code:** `i.cpp`

### Problem statement

Reverse the order of elements in a queue so **front** and **rear** swap roles (first becomes last).

**Example:** front → rear **`1,2,3,4,5`** becomes **`5,4,3,2,1`**.

### Approach (stack)

A **stack** reverses order (LIFO):

1. **Dequeue** all elements from the queue and **push** each onto a **stack**.
2. **Pop** the stack and **enqueue** back into the queue.

```text
queue: 1 2 3  -> stack: 3 2 1  -> queue: 3 2 1
```

```mermaid
flowchart LR
  Q1["queue"] --> S["stack push all"]
  S --> Q2["enqueue back"]
```

### Complexity

| | |
|--|--|
| **Time** | **O(n)** |
| **Space** | **O(n)** for the stack |

Run **`g.cpp`**, **`h.cpp`**, and **`i.cpp`** for full implementations and sample output.

Double Ended Queue -> j.cpp
Deque in C++
• push_back()
• push_front( )
• pop_ front()
• pop_back()
• front()
• back()

