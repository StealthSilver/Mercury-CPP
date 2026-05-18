# DSA with C++ — Module 24 Notes

**Topic:** Linked lists — definition, head/tail, `push_front` / `push_back`, `pop_front` / `pop_back`, `insert`, `removeAt`, destructor, and the `->` pointer operator.  
**Companion code:** [a.cpp](a.cpp) — **complete `Node` + `List` class** with all operations and comments. These notes explain *what* and *why*; open [a.cpp](a.cpp) for the full implementation.

**Prerequisite:** Module 11 (arrays as a linear, contiguous structure; indexing and traversal).

---

## MODULE 24 — LINKED LISTS

### Definition

A **linked list** is a **linear** data structure: elements appear in a **sequence**, one after another, like a **chain**. Unlike an array, the chain is built from **separate nodes** linked by **pointers** (addresses), not by sitting next to each other in one big block of memory.

| Idea | Detail |
|------|--------|
| **Linear** | There is a first element, a last element, and an order between them — same “in a line” idea as an array. |
| **Chain** | Each node knows **only** the address of the **next** node (in the basic singly linked form). Follow the links from start to end. |
| **Non-contiguous memory** | Nodes can live **anywhere** in memory; what keeps the list together is each node’s **pointer** to the next. |
| **Dynamic size** | You can add or remove nodes by rewiring pointers; you are not locked into one fixed block allocated up front (as with a classic fixed-size array). |

**One-line intuition:** An array is a **row of lockers in one hallway**; a linked list is a **treasure hunt** — each clue (pointer) tells you where the next clue is.

---

## Linear data structures: array and linked list

Both **arrays** and **linked lists** store elements in a **sequence** (linear order). They differ in **how** that sequence is represented in memory and **how** you reach a given position.

| Aspect | Array | Linked list |
|--------|--------|-------------|
| **Memory layout** | **Contiguous** — elements stored in adjacent slots | **Non-contiguous** — each node may be allocated separately |
| **Link between elements** | Implicit: index `i` and `i+1` are neighbors in memory | Explicit: each node holds a **pointer** to the next node |
| **Size** | Often fixed at creation (static array) or managed as one block (e.g. `vector`) | Grows by allocating **new nodes** and linking them in |
| **Access to k-th element** | **Direct** — `O(1)` with index (e.g. `arr[k]`) | **Sequential** — start at head and follow `k` links — `O(k)` |
| **Insert/delete in middle** | Shifting elements can be costly | Rewire pointers; no need to shift the whole block (details in later sections) |

You already know arrays from Module 11. This module adds the linked list as a second standard way to represent a **linear** collection when **contiguous memory** or **random access by index** is not the priority.

---

## Node structure

The **node** is the basic unit of a linked list. In the usual **singly linked** list, every node has **two parts**:

| Part | Role |
|------|------|
| **Data** | The value stored in this position (e.g. an integer, or a struct). |
| **Next pointer** | Holds the **address** of the next node in the list, or a special value (e.g. `NULL` / `nullptr`) if this node is the **last**. |

Conceptually:

```
  ┌─────────┬──────────┐     ┌─────────┬──────────┐     ┌─────────┬──────────┐
  │  data   │   next   │ ──► │  data   │   next   │ ──► │  data   │   next   │ ──► NULL
  └─────────┴──────────┘     └─────────┴──────────┘     └─────────┴──────────┘
       node 1                    node 2                    node 3 (tail)
```

The list is **not** one array name spanning all values; it is this **linked sequence** of nodes. The program typically keeps a **head** (and sometimes a **tail**) so it knows where the chain starts (and optionally where it ends).

---

## Head and tail pointers

You do not access “the list” as a single slab of memory. You access it through **pointers** that refer to particular nodes.

| Pointer | Meaning |
|---------|---------|
| **Head** | Points to the **first** node. If the list is empty, head is `NULL` / `nullptr` (no first node). |
| **Tail** (optional) | Points to the **last** node. Useful when you often append at the end so you do not walk the whole list each time. |

```
  head ──►  [ 10 | • ] ──►  [ 20 | • ] ──►  [ 30 | NULL ]
                                              ▲
  tail ───────────────────────────────────────┘
```

- **Head** is enough to traverse or modify the whole list (walk `next` until `NULL`).
- **Tail** is an optimization for operations at the **end** (e.g. append in `O(1)` when tail is maintained).

The **first node** is not a separate special object type — it is simply the node that **head** points to. “First node” and “head pointer” are related: head is the variable in your program; the first node is the actual list element in memory.

---

## Traversal and access

In a linked list you **cannot** jump to “the 4th element” in one step the way you do with `arr[3]`.

| Operation | Linked list behavior |
|-----------|----------------------|
| **Visit every element** | Start at **head**, follow **next** until `NULL` — **linear traversal** only. |
| **Reach i-th element** | Walk **i** links from the head — cost grows with **i**. |
| **Random access by index** | **Not supported** in the same sense as arrays; there is no index operator on the chain itself. |

So linked lists favor problems where you **walk the sequence** or **insert/delete by rewiring links**, not where you repeatedly need **arbitrary index access**.

**Contrast with arrays:**

| | Array | Linked list |
|---|--------|-------------|
| **Typical access pattern** | Index anywhere, often many times | Walk from head (or tail in doubly linked variants, later) |
| **Time to reach i-th element** | `O(1)` | `O(i)` from head |
| **Memory for “where is next?”** | Implicit (next index) | Explicit (pointer field per node) |

---

## Memory layout (why “not contiguous” matters)

**Array** — one block, indices map to offsets:

```
  arr:  [ 10 | 20 | 30 | 40 | 50 ]   ← one continuous block
         index 0   1   2   3   4
```

**Linked list** — nodes may be scattered; only pointers define order:

```
  heap (simplified):

  address 0x100:  [ 10 | 0x250 ]
  address 0x180:  [ 30 | NULL  ]
  address 0x250:  [ 20 | 0x180 ]

  head → 0x100 → 0x250 → 0x180 → end
```

The **logical** order is 10 → 20 → 30. The **physical** order in memory is not required to match. That flexibility is the main reason to use a linked list; the trade-off is **extra space per node** (for the pointer) and **no direct indexing**.

---

## What to remember (this section)

| Idea | Takeaway |
|------|----------|
| **Linear** | Same “sequence” idea as an array; different implementation. |
| **Node** | **Data** + **next** pointer (singly linked case). |
| **Head / tail** | Head = entry to the list; tail = optional shortcut to the last node. |
| **vs array** | Array: contiguous, index in `O(1)`. List: scattered nodes, reach i-th in `O(i)`. |
| **Traversal** | Only by following links — no `list[i]` in one step. |

Later topics in this module will cover **deletion**, **search**, and variants such as **doubly linked** lists — still using this node-and-pointer model.

---

## Building a linked list in C++ (OOP)

C++ already provides linked-list-style containers in the standard library (e.g. `std::list`). In this course you also build one **from scratch** with classes so you see exactly how **nodes** and **pointers** work.

**Reference:** [a.cpp](a.cpp) — full class: `Node`, `List`, `push_front`, `push_back`, `pop_front`, `pop_back`, `insert`, `removeAt`, `display`, `~List()`.

### Two classes

| Class | Role |
|-------|------|
| **`Node`** | Holds `data` (e.g. `int`) and `next` (`Node*`). Constructor sets `next` to `nullptr`. |
| **`List`** | Owns **`head`** and **`tail`** pointers and operations on the whole chain (insert, print, etc.). |

The **list object** is not the nodes themselves — it is the **manager** that remembers where the chain starts and ends.

### Creating an empty list

| Step | What happens |
|------|----------------|
| **Constructor `List()`** | Set `head = nullptr` and `tail = nullptr`. |
| **In `main`** | Write `List linkedList;` — **not** `List linkedList();`, which C++ parses as a **function declaration**, not an object. |

---

## `push_front` — insert at the beginning

**Call:** `linkedList.push_front(val)`  
**Time (with head pointer):** `O(1)` — no walk through the list.

### Case 1 — list is empty (`head == nullptr`)

| Step | Effect |
|------|--------|
| Allocate `newNode` with `val` | One node on the heap |
| `head = newNode`, `tail = newNode` | Single node is both first and last |

```
  before:  head ──► NULL    tail ──► NULL

  after:   head ──► [ val | NULL ] ◄── tail
```

### Case 2 — list has at least one node

| Step | Effect |
|------|--------|
| `newNode->next = head` | New node points to the old first node |
| `head = newNode` | Head moves to the new front |

```
  before:  head ──► [ 20 | • ] ──► [ 30 | NULL ] ◄── tail

  after:   head ──► [ 10 | • ] ──► [ 20 | • ] ──► [ 30 | NULL ] ◄── tail
                      new              old head
```

**Example in [a.cpp](a.cpp):** `push_front(30)`, then `20`, then `10` → display shows `10 -> 20 -> 30 -> NULL`.

---

## `push_back` — insert at the end

**Call:** `linkedList.push_back(val)`  
**Time (with tail pointer):** `O(1)` — append without walking from head to the last node.

Without a **tail** pointer, every `push_back` would be `O(n)` because you would have to traverse the whole list to find the last node.

### Case 1 — list is empty (`head == nullptr`)

Same as `push_front` on an empty list: `head` and `tail` both point to `newNode`.

```
  before:  head ──► NULL    tail ──► NULL

  after:   head ──► [ val | NULL ] ◄── tail
```

### Case 2 — list has at least one node

| Step | Effect |
|------|--------|
| `tail->next = newNode` | Old last node links forward to the new node |
| `tail = newNode` | Tail moves to the new last node (`newNode->next` stays `nullptr`) |

```
  before:  head ──► [ 10 | • ] ──► ... ──► [ 30 | NULL ] ◄── tail

  after:   head ──► [ 10 | • ] ──► ... ──► [ 30 | • ] ──► [ 40 | NULL ] ◄── tail
```

**Example in [a.cpp](a.cpp):** After the three `push_front` calls, `push_back(40)` and `push_back(50)` → `10 -> 20 -> 30 -> 40 -> 50 -> NULL`.

---

## `display` — traverse and print

| Step | Action |
|------|--------|
| Start | `temp = head` |
| Loop | While `temp != nullptr`, print `temp->data`, then `temp = temp->next` |
| End | Print `NULL` to show the chain ends |

This is the standard **linear traversal** pattern for a singly linked list.

---

## What to remember (implementation)

| Operation | Empty list | Non-empty list | Why keep `tail`? |
|-----------|------------|----------------|------------------|
| **`push_front`** | `head = tail = newNode` | `newNode->next = head`, `head = newNode` | Tail unchanged |
| **`push_back`** | `head = tail = newNode` | `tail->next = newNode`, `tail = newNode` | Avoid `O(n)` walk to the last node |

| Pitfall | Correct approach |
|---------|------------------|
| **`List linkedList();` in `main`** | Use `List linkedList;` — otherwise you declare a function, not a list |
| **Forgetting `tail` on append** | `push_back` needs `tail`; only updating `head` is not enough |
| **Lost `next` on insert** | Set new links **before** moving `head` or `tail` so you do not drop the rest of the list |

---

## The `->` operator (member access through a pointer)

Used everywhere in [a.cpp](a.cpp): `display`, `insert`, `removeAt`, `push_front`, `push_back`, destructor.

### Meaning

`temp->data` means: read **`data`** on the object **`temp` points to**. It is shorthand for:

`(*temp).data`

| In [a.cpp](a.cpp) | Detail |
|-------------------|--------|
| **`temp`** | Type `Node*` — pointer to a `Node` |
| **`data`** | Member of `class Node` |
| **`temp->data`** | Value in the current node while traversing |
| **`temp->next`** | Address of the next node (move `temp` forward in the loop) |

### `->` vs `.`

| Expression | Type of left side | Meaning |
|------------|-------------------|---------|
| `temp->data` | `Node*` (pointer) | Access member **through** the pointer |
| `node.data` | `Node` (object) | Access member on the **object itself** |

**Rule:** use **`->`** when you have a **pointer**; use **`.`** when you have the **object**.

---

## `insert` — insert at a given index

**Call:** `linkedList.insert(val, pos)`  
**Reference:** [a.cpp](a.cpp) — `List::insert`  
**Time:** `O(pos)` — walk from head to the node before the insertion point.

### Why linked lists can insert “in the middle” easily

In an **array** or **`vector`**, inserting in the middle often requires **shifting** every element after the gap. In a **linked list**, you only **rewire pointers** — no shifting of the rest of the data in memory.

### `pos` is a 0-based index

| `pos` | Behavior in [a.cpp](a.cpp) |
|-------|----------------------------|
| `0` | Delegates to `push_front` |
| `1 … size-1` | Insert **after** the node at index `pos - 1` |
| `size` (after last element) | `temp->next == nullptr` → `push_back` |

### Steps (middle insert)

| Step | Code idea in [a.cpp](a.cpp) |
|------|----------------------------|
| 1 | Create `newNode` with `val` |
| 2 | Walk `temp` to index **`pos - 1`** (`for (i = 0; i < pos - 1; i++) temp = temp->next`) |
| 3a | `newNode->next = temp->next` — new node points to old successor |
| 3b | `temp->next = newNode` — predecessor points to new node |

```
  before:  ... ──► [ temp | • ] ──► [ 30 | • ] ──► ...

  insert 15 at pos 1 (after node 10):

  after:   ... ──► [ temp | • ] ──► [ 15 | • ] ──► [ 30 | • ] ──► ...
                              newNode
```

**Example in [a.cpp](a.cpp):** After `10 -> 20 -> 30 -> 40 -> 50`, call `insert(15, 1)` → `10 -> 15 -> 20 -> 30 -> 40 -> 50 -> NULL`.

---

## `removeAt` — delete node at a given index

**Call:** `linkedList.removeAt(pos)`  
**Reference:** [a.cpp](a.cpp) — `List::removeAt` (not named `delete` — that is a C++ keyword)  
**Time:** `O(pos)`.

### Case 1 — remove front (`pos <= 0`)

| Step | Effect |
|------|--------|
| `toDelete = head` | Remember node to free |
| `head = head->next` | Second node becomes first |
| `delete toDelete` | Free heap memory |
| If list empty | `tail = nullptr` |

### Case 2 — remove in middle or at end

| Step | Effect |
|------|--------|
| Walk `temp` to index **`pos - 1`** | `temp` is node **before** the victim |
| `toDelete = temp->next` | Node to remove |
| `temp->next = toDelete->next` | Bypass `toDelete` |
| If `toDelete` was tail | `tail = temp` |
| `delete toDelete` | Free heap memory |

```
  before:  ... ──► [ temp | • ] ──► [ 20 | • ] ──► [ 30 | • ] ──► ...

  removeAt(2) — remove node at index 2 (value 20):

  after:   ... ──► [ temp | • ] ──► [ 30 | • ] ──► ...
```

**Example in [a.cpp](a.cpp):** After insert demo, `removeAt(2)` removes `20` → `10 -> 15 -> 30 -> 40 -> 50 -> NULL`.

---

## Deleting the entire linked list (destructor)

Every node is created with **`new`**, so memory must be freed with **`delete`**. If you only remove nodes one-by-one in `main` but never free the rest, you get a **memory leak**.

**Reference:** [a.cpp](a.cpp) — `~List()` destructor.

### When it runs

The **destructor** `~List()` runs automatically when a `List` object is **destroyed** — for example when `linkedList` goes out of scope at the end of `main`, or when a `List` local variable leaves a `{ }` block.

You do **not** call the destructor yourself; C++ calls it for you.

### What it does

| Step | Action |
|------|--------|
| 1 | While `head != nullptr` |
| 2 | Remember `head` in `toDelete` |
| 3 | Move `head` to `head->next` |
| 4 | `delete toDelete` |
| 5 | After the loop, set `tail = nullptr` |

Same idea as removing the front node repeatedly until the list is empty.

```
  before:  head ──► [10] ──► [20] ──► [30] ──► NULL ◄── tail

  loop:    delete front node each time until head is NULL

  after:   head ──► NULL    tail ──► NULL
```

### Why you need it

| Without destructor | With destructor |
|--------------------|-----------------|
| Nodes stay on the heap after program logic “finishes” with the list | All `new` nodes are matched with `delete` when the `List` dies |
| Memory leak (especially bad in long-running programs) | Clean shutdown of list memory |

`removeAt` deletes **one** node at any index; the destructor deletes **every** node still in the list.

---

## `pop_front` — remove the first node

**Call:** `linkedList.pop_front()`  
**Reference:** [a.cpp](a.cpp) — `List::pop_front`  
**Time:** `O(1)` — only `head` moves; no walk through the list.

Mirror of **`push_front`**: push adds at the front; pop removes the front.

### Steps

| Step | Code in [a.cpp](a.cpp) | Effect |
|------|------------------------|--------|
| 1 | If `head == nullptr`, return | Empty list — nothing to remove |
| 2 | `temp = head` | Remember the node to free |
| 3 | `head = head->next` | Second node becomes the new front |
| 4 | `temp->next = nullptr` | Detach old front (safe before `delete`) |
| 5 | `delete temp` | Free heap memory |
| 6 | If `head == nullptr`, `tail = nullptr` | List had only one node |

```
  before:  head ──► [ 10 | • ] ──► [ 15 | • ] ──► ... ◄── tail

  after:   head ──► [ 15 | • ] ──► ... ◄── tail
           (10 deleted)
```

**Relation to `removeAt`:** `removeAt(0)` calls `pop_front()` in [a.cpp](a.cpp).

**Example:** After `10 -> 15 -> 30 -> 40 -> 50`, `pop_front()` → `15 -> 30 -> 40 -> 50 -> NULL`.

---

## `pop_back` — remove the last node

**Call:** `linkedList.pop_back()`  
**Reference:** [a.cpp](a.cpp) — `List::pop_back`  
**Time:** `O(n)` — singly linked list must **walk from head** to find the node **before** `tail` (tail’s predecessor).

Mirror of **`push_back`**: push adds at the end; pop removes the end.

### Case 1 — only one node (`head == tail`)

| Step | Effect |
|------|--------|
| `delete tail` | Free the only node |
| `head = tail = nullptr` | List becomes empty |

### Case 2 — two or more nodes

| Step | Code idea in [a.cpp](a.cpp) | Effect |
|------|----------------------------|--------|
| 1 | `temp = head` | Start at front |
| 2 | Loop: `while (temp->next != tail)` | Walk until `temp` is **just before** tail |
| 3 | `delete tail` | Free old last node |
| 4 | `tail = temp`, `temp->next = nullptr` | New last node; chain ends cleanly |

```
  before:  head ──► ... ──► [ 40 | • ] ──► [ 50 | NULL ] ◄── tail
                                    temp              tail

  after:   head ──► ... ──► [ 40 | NULL ] ◄── tail
                                    (50 deleted)
```

**Why `O(n)`?** With only a **next** pointer per node, you cannot move `tail` backward in one step. You must find **tail’s predecessor** by scanning from `head`. (A **doubly linked** list can pop back in `O(1)` with a `prev` pointer.)

**Example:** After `pop_front` demo (`15 -> 30 -> 40 -> 50`), `pop_back()` → `15 -> 30 -> 40 -> NULL`.

---

## Complete `List` API ([a.cpp](a.cpp))

| Member | Purpose | Typical time |
|--------|---------|--------------|
| `List()` | Empty list | `O(1)` |
| `~List()` | Delete all nodes | `O(n)` |
| `push_front(val)` | Insert at front | `O(1)` |
| `push_back(val)` | Insert at end | `O(1)` |
| `pop_front()` | Remove first node | `O(1)` |
| `pop_back()` | Remove last node | `O(n)` |
| `insert(val, pos)` | Insert at index | `O(pos)` |
| `removeAt(pos)` | Remove at index | `O(pos)` |
| `display()` | Print from head | `O(n)` |

| Pair | Insert | Remove |
|------|--------|--------|
| **Front** | `push_front` — `O(1)` | `pop_front` — `O(1)` |
| **Back** | `push_back` — `O(1)` with `tail` | `pop_back` — `O(n)` without `prev` pointer |


ITIRATIVE SEARCH -> b.cpp

searchItr(key)

use a loop to search the element from the starting 