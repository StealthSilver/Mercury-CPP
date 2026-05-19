# DSA with C++ — Module 24 Notes

**Topic:** Linked lists — definition, head/tail, `push_front` / `push_back`, `pop_front` / `pop_back`, `insert`, `removeAt`, destructor, and the `->` pointer operator.  
**Companion code:** [a.cpp](a.cpp) — custom `List` class · [b.cpp](b.cpp)–[f.cpp](f.cpp) — algorithms on simple lists · [g.cpp](g.cpp)–[h.cpp](h.cpp) — cycle detect/remove · [i.cpp](i.cpp)–[j.cpp](j.cpp) — `std::list` and iterators.

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
| `searchItr(key)` | Find key (iterative) | `O(n)` |
| `searchRec(key)` | Find key (recursive) | `O(n)` |
| `reverse()` | Reverse list in place | `O(n)` time, `O(1)` extra space |
| `display()` | Print from head | `O(n)` |

| Pair | Insert | Remove |
|------|--------|--------|
| **Front** | `push_front` — `O(1)` | `pop_front` — `O(1)` |
| **Back** | `push_back` — `O(1)` with `tail` | `pop_back` — `O(n)` without `prev` pointer |


## Iterative search — `searchItr`

**Call:** `linkedList.searchItr(key)` in [a.cpp](a.cpp) · `searchItr(head, key)` in [b.cpp](b.cpp)  
**Reference:** [b.cpp](b.cpp) (simple list in `main`) · [a.cpp](a.cpp) (full `List` class)  
**Time:** `O(n)` — worst case visit every node once.

### Idea

Walk the list **from `head`** using a **`while` loop** (not recursion). Compare each node’s `data` with `key`. If it matches, return that node’s **0-based index**. If the loop ends without a match, return **`-1`**.

| Step | Action |
|------|--------|
| 1 | `temp = head`, `index = 0` |
| 2 | While `temp != nullptr` |
| 3 | If `temp->data == key`, return `index` |
| 4 | Else `temp = temp->next`, `index++` |
| 5 | Return `-1` (not found) |

```
  list:  10 -> 20 -> 30 -> 40 -> NULL
  key:   30

  temp at index 0: 10  ≠ 30  → advance
  temp at index 1: 20  ≠ 30  → advance
  temp at index 2: 30  = 30  → return 2
```

### Return value

| Result | Meaning |
|--------|---------|
| `0, 1, 2, …` | **Found** — index of first node with `data == key` |
| `-1` | **Not found** — no node holds `key` |

### Example ([b.cpp](b.cpp))

List: `10 -> 20 -> 30 -> 40 -> NULL`

| Call | Output |
|------|--------|
| `searchItr(30)` | `2` → print `30 found at index 2` |
| `searchItr(99)` | `-1` → print `99 not found` |

### Why a separate [b.cpp](b.cpp)?

[b.cpp](b.cpp) builds a **simple linked list in `main`** (no `List` class) and uses a standalone function **`searchItr(head, key)`**. Same logic as the member function in [a.cpp](a.cpp), but easier to read when you are learning search first.

---

## `struct Node` in [b.cpp](b.cpp) / [c.cpp](c.cpp)

In the simple demos you use a **`struct Node`** — not a full **`class List`**:

```cpp
struct Node {
    int data;
    Node* next;
};
```

| Member | Role |
|--------|------|
| **`data`** | Value stored in this node |
| **`next`** | Pointer to the next node, or `nullptr` at the end |

### Why a `struct` here?

| Idea | Detail |
|------|--------|
| **Lightweight container** | Only holds **data** for one node — no `push_front`, `display`, etc. on the type itself |
| **List lives in `main`** | You wire nodes with `head->next = ...`; functions like `searchItr` / `searchRec` take `head` |
| **Same layout as `class Node` in [a.cpp](a.cpp)** | One node = value + link; [a.cpp](a.cpp) wraps many nodes inside a `List` class |

**One-line intuition:** `struct Node` is the **brick**; `class List` in [a.cpp](a.cpp) is the **wall** built from bricks plus rules for how to change it.

---

## `struct` vs `class` in C++

In C++, **`struct` and `class` are almost the same** — both can have data members, member functions, constructors, etc.

| | `struct` | `class` |
|---|----------|---------|
| **Default access** | Members are **`public`** | Members are **`private`** |
| **Typical use** | Plain data bundles (POD-style), simple nodes | Types with **invariants** and many operations (e.g. `List`) |
| **In this module** | `struct Node` in [b.cpp](b.cpp), [c.cpp](c.cpp) | `class Node`, `class List` in [a.cpp](a.cpp) |

### Example — same node, two keywords

```cpp
struct Node { int data; Node* next; };   // public by default
class Node  { int data; Node* next; };   // would need public: unless you only use inside List
```

For a **public** node used directly in `main`, **`struct`** is common because `data` and `next` are meant to be accessed freely.

### When to prefer which

| Prefer **`struct`** | Prefer **`class`** |
|---------------------|-------------------|
| Small type that mostly **stores fields** | Type that **hides** `head`/`tail` and exposes methods |
| Used like a C-style record | Enforces **encapsulation** (`private` head, public `push_back`) |

**Remember:** choosing `struct` vs `class` does **not** change how `next` pointers or `->` work — only default visibility and convention.

---

## Recursive search — `searchRec`

**Call:** `linkedList.searchRec(key)` in [a.cpp](a.cpp) · `searchRec(head, key)` in [c.cpp](c.cpp)  
**Reference:** [c.cpp](c.cpp) (simple list in `main`) · [a.cpp](a.cpp) (`searchRec` + private `searchRecHelper`)  
**Time:** `O(n)` — still visits up to `n` nodes (on the **call stack** instead of a loop).

### Iterative vs recursive

| | [b.cpp](b.cpp) `searchItr` | [c.cpp](c.cpp) `searchRec` |
|---|---------------------------|---------------------------|
| **Control** | `while (temp != nullptr)` loop | Function **calls itself** on `head->next` |
| **State** | `temp` and `index` in local variables | `head` and `index` passed into each call |
| **Base case** | Loop ends when `temp == nullptr` | `head == nullptr` → return `-1` |
| **Found** | Return `index` inside loop | `head->data == key` → return `index` |

### Idea

1. If `head == nullptr` → **not found** → return `-1`.
2. If `head->data == key` → **found** → return current `index`.
3. Otherwise → search the **rest** of the list: `searchRec(head->next, key, index + 1)`.

```
  searchRec(10→20→30→40, key=30, index=0)
    10 ≠ 30  →  searchRec(20→30→40, 30, 1)
                  20 ≠ 30  →  searchRec(30→40, 30, 2)
                                  30 = 30  →  return 2
```

### Code shape ([c.cpp](c.cpp))

| Case | Return |
|------|--------|
| `head == nullptr` | `-1` |
| `head->data == key` | `index` |
| else | `searchRec(head->next, key, index + 1)` |

### Example ([c.cpp](c.cpp))

Same list as [b.cpp](b.cpp): `10 -> 20 -> 30 -> 40 -> NULL`

| Call | Output |
|------|--------|
| `searchRec(head, 30)` | `30 found at index 2` |
| `searchRec(head, 99)` | `99 not found` |

### Stack note

Each recursive call waits for the next. For a list of length `n`, recursion depth is **`O(n)`** — fine for learning; for very long lists, **iterative** search ([b.cpp](b.cpp)) avoids deep call stacks.

---

## Search summary

| File | Function | Style |
|------|----------|--------|
| [b.cpp](b.cpp) | `searchItr(head, key)` | Loop |
| [c.cpp](c.cpp) | `searchRec(head, key, index)` | Recursion |
| [a.cpp](a.cpp) | `List::searchItr(key)` / `List::searchRec(key)` | Loop / recursion inside full class |


## Reverse a linked list in place

**Call:** `linkedList.reverse()` in [a.cpp](a.cpp) · `reverseList(head)` in [d.cpp](d.cpp)  
**Reference:** [d.cpp](d.cpp) (simple list in `main`) · [a.cpp](a.cpp) (updates `head` and `tail` on full `List`)

### What “reverse” means

Turn:

`10 -> 20 -> 30 -> 40 -> NULL`

into:

`40 -> 30 -> 20 -> 10 -> NULL`

Same **nodes** in memory — only **`next` pointers** change direction.

### In place

| In place? | Meaning |
|-----------|---------|
| **Yes (this algorithm)** | No extra linked list; **no new nodes** — only rewire existing links |
| **No (other approach)** | Copy values or nodes into a new list/array — uses **O(n)** extra space |

**In place** here means **constant extra space** for pointers (`prev`, `curr`, `next`), not “you cannot use a few variables.”

---

### Algorithm (iterative, three pointers)

Used in [d.cpp](d.cpp) and [a.cpp](a.cpp).

| Pointer | Role |
|---------|------|
| **`prev`** | Already reversed part (starts `nullptr`) |
| **`curr`** | Current node being fixed |
| **`next`** | Saves `curr->next` before we overwrite it |

**Per node:**

1. `next = curr->next` — save rest of list  
2. `curr->next = prev` — reverse link  
3. `prev = curr` — extend reversed segment  
4. `curr = next` — move forward  

**After loop:** `head = prev` (old tail becomes new head). In [a.cpp](a.cpp) also set **`tail = old head`** before the loop.

```
  step 0:  NULL  ←  10  →  20  →  30  →  40  →  NULL
           prev   curr

  step 1:  NULL  ←  10     20  →  30  →  40
           prev   curr

  ... after all steps:

           40  →  30  →  20  →  10  →  NULL
           head (prev)
```

### Walkthrough ([d.cpp](d.cpp))

| After processing | Reversed part (`prev`) | Remaining (`curr`) |
|------------------|------------------------|---------------------|
| Start | `NULL` | `10 → 20 → 30 → 40` |
| 1 | `10` | `20 → 30 → 40` |
| 2 | `20 → 10` | `30 → 40` |
| 3 | `30 → 20 → 10` | `40` |
| Done | `40 → 30 → 20 → 10` | `NULL` |

---

### Complexity (detailed)

Let **`n`** = number of nodes.

#### Time complexity — **`O(n)`**

| Reason | Detail |
|--------|--------|
| **One pass** | Each node visited **exactly once** in the `while (curr != nullptr)` loop |
| **Work per node** | Constant pointer assignments (save `next`, flip link, advance) |
| **Total** | `n` nodes × `O(1)` work = **`O(n)`** |

This is **optimal** for a singly linked list if you must touch every link to reverse — you cannot do better than linear time.

#### Space complexity — **`O(1)`** extra space

| Counts toward space? | In this algorithm |
|----------------------|-------------------|
| **`prev`, `curr`, `next`** | Yes — **3 pointers**, fixed count (does not grow with `n`) |
| **Recursion stack** | **No** — iterative version uses no recursive calls |
| **New nodes / copy array** | **No** — in-place rewire |

So **auxiliary space** = **`O(1)`**.  
The list itself still uses **`O(n)`** memory for `n` nodes — that is the input, not extra overhead from the algorithm.

#### Compare approaches

| Method | Time | Extra space | Notes |
|--------|------|-------------|--------|
| **Three-pointer reverse (this module)** | `O(n)` | `O(1)` | Standard interview / course solution |
| **Recursive reverse** | `O(n)` | `O(n)` stack | Same flip idea; call stack depth = `n` |
| **Copy values to array, reverse array, write back** | `O(n)` | `O(n)` array | Not pointer-based; wastes space |
| **Build new reversed list** | `O(n)` | `O(n)` new nodes | Not in place |

---

### [a.cpp](a.cpp) vs [d.cpp](d.cpp)

| | [d.cpp](d.cpp) | [a.cpp](a.cpp) `List::reverse()` |
|---|----------------|----------------------------------|
| **API** | `reverseList(head)` | `linkedList.reverse()` |
| **Head** | `head = prev` via reference | `head = prev` |
| **Tail** | Not tracked | `tail = old head` before loop |
| **Empty / one node** | Loop still OK | Early return if `head == nullptr` or `head == tail` |

### Example ([d.cpp](d.cpp))

```
Before: 10 -> 20 -> 30 -> 40 -> NULL
After:  40 -> 30 -> 20 -> 10 -> NULL
```

### Example ([a.cpp](a.cpp))

On `15 -> 30 -> 40`, after `reverse()` → `40 -> 30 -> 15 -> NULL`.

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Lose `curr->next` before saving it | Rest of list lost — always save in `next` first |
| Forget to update **`tail`** in [a.cpp](a.cpp) | `push_back` breaks after reverse |
| Reverse by only swapping **values** | Works for ints but wrong when nodes are moved/shared elsewhere — prefer pointer reverse |


## Remove the Nth node from the end

**Call:** `removeNthFromEnd(head, n)` in [e.cpp](e.cpp)  
**Reference:** [e.cpp](e.cpp) only (not added to [a.cpp](a.cpp))  
**Convention:** **`n` is 1-indexed from the end** — `n = 1` is the **last** node, `n = 2` is the second from last, etc.

### Problem

Given a singly linked list, **find and delete** the node that is **`n` positions from the end**, in **one pass** if possible.

Example list: `10 -> 20 -> 30 -> 40 -> NULL`

| `n` | Node removed | Result |
|-----|--------------|--------|
| `1` | `40` (last) | `10 -> 20 -> 30 -> NULL` |
| `2` | `30` | `10 -> 20 -> 40 -> NULL` |
| `4` | `10` (first) | `20 -> 30 -> 40 -> NULL` |

---

### Naive idea (two passes)

| Pass | Work |
|------|------|
| **1** | Count length `L` |
| **2** | Walk to position `L - n` and remove |

**Time:** `O(L)` · **Space:** `O(1)` — correct, but two traversals.

The **two-pointer** method below still **`O(L)`** time but uses **one** traversal after a short setup.

---

### Optimal idea: two pointers + dummy node

Use **`slow`** and **`fast`**, plus a **dummy** node before `head`.

| Pointer | Role |
|---------|------|
| **dummy** | Fake node with `next = head` — makes removing the **first** node easy when `n == L` |
| **slow** | Will end up **just before** the node to delete |
| **fast** | Leads `slow` by a fixed gap |

#### Step 1 — create a gap of `n + 1` steps

Start: `slow = fast = dummy`.

Move **`fast` forward `n + 1` times**.

For `n = 2` on four nodes:

```
  dummy -> 10 -> 20 -> 30 -> 40 -> NULL
  slow
  fast moves n+1 = 3 times → fast at 30
```

Now **`fast` is `n + 1` nodes ahead of `slow`**.

#### Step 2 — move both until `fast` hits the end

```
  while (fast != nullptr:
      slow = slow->next
      fast = fast->next
```

When `fast == nullptr`, **`slow` is the node before the target**.

```
  dummy -> 10 -> 20 -> 30 -> 40 -> NULL
                  slow          fast=NULL
```

Target to remove = `slow->next` (here `30`).

#### Step 3 — delete

```
  toDelete = slow->next
  slow->next = slow->next->next
  delete toDelete
  head = dummy.next
```

---

### Why `n + 1` steps (not `n`)?

We need `slow` **before** the victim so we can do `slow->next = slow->next->next`.

| Gap between slow and fast | Where slow lands when fast is past last |
|---------------------------|----------------------------------------|
| **`n` nodes apart** | On the node to delete (hard to unlink) |
| **`n + 1` apart** | On the **predecessor** of the node to delete |

So the first loop runs **`i = 0` to `n`** → **`n + 1`** advances of `fast`.

---

### Dummy node — why?

Without dummy, removing the **head** (when `n == L`) is a special case.

| With dummy | Effect |
|------------|--------|
| `dummy.next` is real `head` | `slow` can sit on `dummy`; deleting `slow->next` removes head uniformly |
| After delete | `head = dummy.next` updates head if first node was removed |

---

### Complexity (detailed)

Let **`L`** = number of nodes in the list.

#### Time — **`O(L)`**

| Phase | Work |
|-------|------|
| Move `fast` `n + 1` steps | At most `L + 1` — **`O(L)`** |
| Move both until end | `fast` walks remaining nodes — **`O(L)`** |
| Delete + update head | **`O(1)`** |
| **Total** | **`O(L)`** — **one logical pass** over the list |

You cannot do better than `O(L)` in the worst case: you must at least reach the node before the one you delete.

#### Space — **`O(1)`** extra

| Item | Space |
|------|--------|
| `slow`, `fast` pointers | `O(1)` |
| **`dummy` node** | `O(1)` — one extra node on stack, not proportional to `L` |
| Recursion | None |
| **Total auxiliary** | **`O(1)`** |

The **`L` nodes** already stored are input memory, not algorithm overhead.

#### Compare

| Approach | Time | Extra space | Passes |
|----------|------|-------------|--------|
| Count length, then remove | `O(L)` | `O(1)` | 2 |
| **Two-pointer + dummy ([e.cpp](e.cpp))** | `O(L)` | `O(1)` | 1 |
| Store all nodes in array | `O(L)` | `O(L)` | 1–2 |

---

### Example trace ([e.cpp](e.cpp))

List: `10 -> 20 -> 30 -> 40`, remove **`n = 2`** (node `30`).

| Step | `slow` at | `fast` at |
|------|-----------|-----------|
| After `n+1` advance | `dummy` | `30` |
| End of while | `20` | `nullptr` |
| Delete | unlink `30` | |

Output: `10 -> 20 -> 40 -> NULL`.

Second call in [e.cpp](e.cpp): `n = 1` removes `40` → `10 -> 20 -> NULL`.

---

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Only `n` steps ahead instead of `n + 1` | `slow` lands on victim — cannot unlink cleanly |
| No dummy when removing head | Extra branch for `head = head->next` |
| `n > L` | Guard: if `fast` becomes `nullptr` too early in first loop, invalid `n` |
| Forget `delete` | Memory leak |
| Off-by-one on indexing | Agree whether `n=1` means last — [e.cpp](e.cpp) uses **last = 1** |

---

### Module file map (search & modify)

| File | Topic |
|------|--------|
| [b.cpp](b.cpp) | Iterative search |
| [c.cpp](c.cpp) | Recursive search |
| [d.cpp](d.cpp) | Reverse in place |
| [e.cpp](e.cpp) | Remove Nth from end |
| [f.cpp](f.cpp) | Palindrome check |
| [g.cpp](g.cpp) | Cycle detection (Floyd) |

---

## Practice: Palindrome linked list

**Problem:** Given the head of a singly linked list, return **`true`** if it reads the same forward and backward, else **`false`**.

**Reference:** [f.cpp](f.cpp) — `isPalindrome(head)`  
**Not in [a.cpp](a.cpp)** — practice file only.

### Examples

| Input (list) | Output | Why |
|--------------|--------|-----|
| `1 -> 2 -> 2 -> 1` | `true` | Same as `1,2,2,1` reversed |
| `1 -> 2` | `false` | `1,2` ≠ `2,1` |
| `1` or empty | `true` | Single / empty palindrome |

---

### What “palindrome” means here

Compare **values in order**, not node addresses:

```
  1 -> 2 -> 2 -> 1   ✓  (reads 1,2,2,1 from both ends)
  1 -> 2             ✗  (reads 1,2 vs 2,1)
```

You cannot index from the end in `O(1)` on a singly linked list — you must **walk** or **rewrite links**.

---

### Approach 1 — copy to array (easy, extra space)

| Step | Action |
|------|--------|
| 1 | Traverse list, push each `data` into a vector/array |
| 2 | Two pointers: start and end of array, move inward |
| 3 | If all pairs match → `true` |

| Time | Space |
|------|--------|
| `O(n)` | `O(n)` for the array |

Good for understanding; not optimal for space.

---

### Approach 2 — middle + reverse second half ([f.cpp](f.cpp))

**Idea:** Split the list at the middle, **reverse** the second half, compare two front-to-front walks, then clean up.

Uses skills from [d.cpp](d.cpp) (reverse) and slow/fast pointers (like [e.cpp](e.cpp)).

#### Step 1 — find middle (slow / fast)

| Pointer | Moves |
|---------|--------|
| **slow** | `+1` per step |
| **fast** | `+2` per step |

Stop when `fast` cannot take two more steps. **`slow`** lands at the **end of the first half** (for even length).

```
  1 -> 2 -> 2 -> 1
  s    f
       s         f
       s              f (stop)
```

For `1 -> 2 -> 2 -> 1`, **`slow`** is the **first `2`**.

#### Step 2 — reverse second half

Reverse starting at **`slow->next`** (same three-pointer reverse as [d.cpp](d.cpp)).

```
  first half:  1 -> 2
  second half reversed: 1 -> 2   (from original 2 -> 1)
```

Temporarily set **`slow->next = nullptr`** to split halves.

#### Step 3 — compare

Walk **`p1`** from `head` and **`p2`** from reversed second head while **`p2 != nullptr`**.

| `p1` | `p2` | Match? |
|------|------|--------|
| 1 | 1 | yes |
| 2 | 2 | yes |
| done | | return `true` |

Only need to walk while **`p2`** runs — second half has the same or fewer nodes (odd length: middle node ignored).

#### Step 4 — cleanup ([f.cpp](f.cpp))

Free the reversed second-half nodes after the check (list was modified for the algorithm).

---

### Why this works (even vs odd length)

| Length | Middle behavior | Compare |
|--------|-----------------|--------|
| **Even** `1→2→2→1` | Two equal halves | All nodes in second half vs first |
| **Odd** `1→2→1` | Middle `2` not compared | Second half is `1`; first half `1→2` vs `1` only while `p2` moves |

The **middle node** of an odd palindrome does not need a pair — it matches itself.

---

### Complexity (detailed)

Let **`n`** = number of nodes.

#### Time — **`O(n)`**

| Phase | Cost |
|-------|------|
| Slow/fast to middle | ≤ `n/2` steps → **`O(n)`** |
| Reverse second half | ≤ `n/2` nodes → **`O(n)`** |
| Compare halves | ≤ `n/2` steps → **`O(n)`** |
| **Total** | **`O(n)`** — linear constant factors |

#### Space — **`O(1)`** extra (this approach)

| Item | Space |
|------|--------|
| `slow`, `fast`, `p1`, `p2`, reverse pointers | **`O(1)`** |
| No vector / recursion | |
| **Note** | Algorithm **modifies** links temporarily; still constant extra pointers |

| Approach | Time | Extra space |
|----------|------|-------------|
| Copy to array | `O(n)` | `O(n)` |
| **Middle + reverse ([f.cpp](f.cpp))** | `O(n)` | **`O(1)`** |

---

### Code map ([f.cpp](f.cpp))

| Function | Role |
|----------|------|
| `buildList` | Build list from array for tests |
| `reverseSegment` | Reverse from a given head (second half) |
| `isPalindrome` | Full palindrome check |
| `main` | Runs `1,2,2,1` → `true` and `1,2` → `false` |

### Output ([f.cpp](f.cpp))

```
List: 1 -> 2 -> 2 -> 1 -> NULL
Is palindrome? true

List: 1 -> 2 -> NULL
Is palindrome? false
```

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Compare without reversing second half | Cannot walk singly list backward |
| Wrong middle (off-by-one) | Wrong split → wrong answer |
| Forget odd-length middle | Comparing middle twice — use **`while (p2 != nullptr)`** |
| Lose nodes after reverse | Memory leak — free second half in [f.cpp](f.cpp) after check |

## Detect a cycle in a linked list (Floyd's algorithm)

**Problem:** Given the head of a linked list, determine if the list has a **cycle** — some node’s `next` points back to a previous node in the chain (infinite loop if you follow `next`).

**Call:** `hasCycle(head)` in [g.cpp](g.cpp)  
**Also called:** **Tortoise and Hare**, **Floyd's cycle-finding algorithm**.

### Example

| List | Has cycle? |
|------|------------|
| `1 -> 2 -> 3 -> NULL` | **No** — `next` eventually is `nullptr` |
| `1 -> 2 -> 3 -> 4 -> 2 -> ...` | **Yes** — tail links back into the list |

---

### Idea — two pointers

| Pointer | Move each step |
|---------|----------------|
| **slow** | `+1` (`slow = slow->next`) |
| **fast** | `+2` (`fast = fast->next->next`) |

Start both at **`head`**. Repeat until:

| Condition | Meaning |
|-----------|---------|
| **`fast == nullptr`** or **`fast->next == nullptr`** | Fast hit the end → **no cycle** |
| **`slow == fast`** | Pointers meet inside the structure → **cycle exists** |

```
  acyclic:  1 -> 2 -> 3 -> NULL
            s,f
                 s  f
                      s     f
                            f falls off → stop → no cycle

  cyclic:   1 -> 2 -> 3 -> 4
                 ^         |
                 +---------+
            slow +1, fast +2 each round → eventually same node
```

---

### Algorithm ([g.cpp](g.cpp))

| Step | Action |
|------|--------|
| 1 | If `head == nullptr` → `false` |
| 2 | `slow = fast = head` |
| 3 | While `fast` and `fast->next` are not null |
| 4 | Advance `slow` by 1, `fast` by 2 |
| 5 | If `slow == fast` → `true` |
| 6 | Loop ends without meeting → `false` |

---

### Mathematical proof (why slow and fast must meet if a cycle exists)

Label:

| Symbol | Meaning |
|--------|---------|
| **μ** | Number of nodes from **head** to the **cycle entrance** (first node that is part of the loop) |
| **λ** | **Cycle length** (number of nodes in the loop) |
| **n** | Total nodes reachable from head; if a cycle exists, after μ + k·λ steps you are still inside the structure |

#### Lemma 1 — If both pointers are inside the cycle, fast closes on slow

Once **slow** has entered the cycle, on each iteration:

- **slow** moves **1** step forward along `next`
- **fast** moves **2** steps forward

So **fast** gains **1** step relative to **slow** on the cycle each iteration (the gap along forward `next` links shrinks by 1, modulo λ).

The distance from **fast** to **slow** measured **forward** along the cycle decreases by **1** each step (wrap around λ). After at most **λ** iterations from any starting offset inside the cycle, that forward distance becomes **0** → **`slow == fast`**.

#### Lemma 2 — Both pointers eventually enter the cycle

- **slow** reaches the cycle entrance after **μ** steps.
- **fast** moves twice as fast, so after **μ** steps of **slow**, **fast** has taken **2μ** steps total.

Since **2μ ≥ μ**, **fast** is at least as far along the list as **slow** when **slow** enters the cycle. **Fast** is already inside the cycle (or enters at the same time). From that point onward, Lemma 1 applies.

#### Theorem — Floyd's detection is correct

**If there is a cycle:**  
After **slow** enters the cycle, within **λ** more slow-steps, **slow** and **fast** meet → algorithm returns **`true`**.

**If there is no cycle:**  
The list ends at `nullptr`. **fast** reaches the end in at most about **⌈L/2⌉** fast-moves (L = list length) because it moves twice as fast → loop condition fails → **`false`**.

**Conclusion:** The algorithm returns **`true` iff** the linked list contains a cycle.

#### Meeting time bound (optional)

Let **L** be the number of nodes from head to `nullptr` if acyclic, or **μ + λ** if cyclic.

| Case | Iterations (order) |
|------|-------------------|
| **No cycle** | `O(L)` — fast exits first |
| **Cycle** | `O(μ + λ) ≤ O(L)` — meet within λ steps after slow enters cycle |

Overall **time `O(n)`** where **n** is the number of nodes in the list.

---

### Complexity

| | Value | Reason |
|---|--------|--------|
| **Time** | **`O(n)`** | At most a constant × (μ + λ) pointer moves; μ + λ ≤ n |
| **Extra space** | **`O(1)`** | Only `slow` and `fast` pointers |

#### Compare to other methods

| Method | Time | Extra space |
|--------|------|-------------|
| **Hash set of visited addresses** | `O(n)` | `O(n)` |
| **Floyd ([g.cpp](g.cpp))** | `O(n)` | **`O(1)`** |

---

### Example ([g.cpp](g.cpp))

```
Acyclic list: 1 -> 2 -> 3 -> NULL
Has cycle? false

Cyclic list (1->2->3->4->2...): ...
Has cycle? true
```

---

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Same speed for both pointers | They never meet on a cycle unless they start together |
| Not checking `fast->next` before `fast->next->next` | Segfault when `fast` is last node |
| Compare before moving | Off-by-one; [g.cpp](g.cpp) moves then compares inside loop |
| Freeing a cyclic list without breaking the loop | Infinite loop in cleanup — break cycle first (see [g.cpp](g.cpp)) |

---

### Module file map (continued)

| File | Topic |
|------|--------|
| [g.cpp](g.cpp) | Cycle detection (Floyd) |
| [h.cpp](h.cpp) | Find cycle entrance and remove cycle |

---

## Remove a cycle in a linked list

**Problem:** A linked list has a cycle (some `next` points backward). **Break** the cycle so the list becomes a normal chain ending in `nullptr`.

**Reference:** [h.cpp](h.cpp) — `findCycleEntrance`, `removeCycle`  
**Builds on:** [g.cpp](g.cpp) (Floyd detection).

### Overview — two phases

| Phase | Goal | From [g.cpp](g.cpp)? |
|-------|------|----------------------|
| **1** | Detect that a cycle exists; get a meeting node inside the cycle | Yes — slow/fast until `slow == fast` |
| **2** | Find the **cycle entrance** (first node on the loop) | New — reset `slow = head`, move both +1 |
| **3** | **Remove** cycle — set `last->next = nullptr` where `last` is the node before entrance on the loop | Walk from entrance |

---

### Phase 1 — detect cycle (recap)

Same as [g.cpp](g.cpp):

- `slow` moves +1, `fast` moves +2
- If `fast` hits `nullptr` → **no cycle** → stop
- If `slow == fast` → **cycle exists** → keep `fast` at meeting point, go to Phase 2

---

### Phase 2 — find the cycle entrance

**Steps:**

| Step | Action |
|------|--------|
| 1 | After Phase 1, `slow` and `fast` meet somewhere **inside** the cycle |
| 2 | Set **`slow = head`** (start from list head again) |
| 3 | Leave **`fast`** at the meeting point |
| 4 | Move **`slow` and `fast` one step at a time** (`+1` each) until `slow == fast` |
| 5 | That node is the **cycle entrance** — first node that is part of the loop |

```
  list:  1 -> 2 -> 3 -> 4
              ^         |
              +---------+

  Phase 1 meet: somewhere inside {2,3,4}
  Phase 2: slow from head, fast from meet, both +1
           → both arrive at node 2 (entrance) together
```

**Why this is the “connection point”:** The entrance is where the list **first joins** the cycle — not necessarily where Phase 1 first collided.

---

### Phase 3 — remove the cycle

| Step | Action |
|------|--------|
| 1 | `entrance =` node from Phase 2 |
| 2 | Walk `curr` starting at `entrance` until `curr->next == entrance` |
| 3 | `curr` is the **last node on the cycle** (tail of the loop) |
| 4 | `curr->next = nullptr` — breaks the back-edge |

After removal, you can traverse from `head` and eventually reach `nullptr`.

---

### Mathematical proof — Phase 2 (entrance correctness)

Use the same labels as in [g.cpp](g.cpp):

| Symbol | Meaning |
|--------|---------|
| **μ** | Nodes from **head** to **cycle entrance** `E` |
| **λ** | Cycle length |
| **Meeting point** `M` | Where slow and fast first coincide (Phase 1) |

#### Distances at the moment of first meeting

When they first meet:

- **slow** has taken **`s`** steps from head: **`s = μ + k`** for some integer **`k ≥ 0`** (μ steps to `E`, then **k** more steps around the cycle to `M`).
- **fast** has taken **`2s`** steps.

So **`M`** is **k** steps **forward** from **`E`** along the cycle.

#### Key congruence

From Floyd’s algebra (same as CLRS / standard lecture notes):

\[
\mu \equiv -k \pmod{\lambda}
\]

Meaning: **`μ` steps from head** reaches **`E`**, and **`k` steps forward from `M`** also reaches **`E`**.

#### Phase 2 — why they meet at `E`

After Phase 1:

- **slow** at **head** (0 steps from head).
- **fast** at **`M`** (**μ + k** steps from head).

Each Phase 2 step adds **1** to both:

| After `t` steps | slow | fast |
|-----------------|------|------|
| `t` | `t` from head | `μ + k + t` from head |

They are equal first when **`t = μ`**:

- **slow** is at **`E`** (μ steps from head).
- **fast** started at **`M`** (k steps after **`E`** on the cycle) and also moves **μ** steps → **`k + μ`** steps from **`E`** along the cycle. Since **`μ ≡ -k (mod λ)`**, **`k + μ`** is a multiple of **λ**, so **fast** is back at **`E`** too.

So Phase 2’s meeting node is exactly the **cycle entrance** `E`.

---

### Mathematical proof — Phase 3 (removal is correct)

The cycle is all nodes from **`E`** following `next` until returning to **`E`**.

The unique node **`L`** with **`L->next == E`** is the **last node on the cycle**. Setting **`L->next = nullptr`** removes only the back-edge into the loop; everything before **`E`** stays a simple chain; **`E … L`** becomes a tail ending in `nullptr`.

The list is acyclic afterward.

---

### Complexity

Let **n** = number of nodes reachable from head.

| Phase | Time | Extra space |
|-------|------|-------------|
| **1 — detect** | `O(n)` | `O(1)` |
| **2 — find entrance** | `O(n)` | `O(1)` |
| **3 — find tail of loop & break** | `O(λ) ≤ O(n)` | `O(1)` |
| **Total** | **`O(n)`** | **`O(1)`** |

---

### Example ([h.cpp](h.cpp))

List: `1 -> 2 -> 3 -> 4 -> 2` (cycle back to node 2)

| Stage | Result |
|-------|--------|
| **Entrance** | node with value **2** |
| **After `removeCycle`** | `1 -> 2 -> 3 -> 4 -> NULL` |

```
Before remove (cycle): 1 -> 2 -> 3 -> 4 -> 2 -> ...
Cycle entrance data: 2
After remove (acyclic): 1 -> 2 -> 3 -> 4 -> NULL
Has cycle now? no
```

---

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Skip Phase 1 | Do not know if a cycle exists |
| Move fast by 2 in Phase 2 | Must move **both by 1** to find entrance |
| Set wrong `next` to null | Break edge where `curr->next == entrance` |
| Free list before breaking cycle | Infinite loop in cleanup |

---

### [g.cpp](g.cpp) vs [h.cpp](h.cpp)

| File | Returns / does |
|------|----------------|
| [g.cpp](g.cpp) | `true` / `false` — cycle exists? |
| [h.cpp](h.cpp) | Finds **entrance**, **removes** back-edge → acyclic list |

## `std::list` — linked list in the STL

**Reference:** [i.cpp](i.cpp)

C++ already provides a **linked-list container** in the Standard Template Library. You do not need to write `Node` / `List` from scratch for everyday use — but building [a.cpp](a.cpp) teaches how it works under the hood.

### Include and type

```cpp
#include <list>
using namespace std;

list<int> lst;   // doubly linked list of ints
```

| Note | Detail |
|------|--------|
| **Name** | `list` (lowercase) — it is a **class template**, not your custom `List` |
| **Header** | `#include <list>` |
| **Internal structure** | Usually a **doubly linked list** (each node has `prev` and `next`) |

So `push_front` / `push_back` / `pop_front` / `pop_back` can all be **`O(1)`** — unlike your singly linked [a.cpp](a.cpp) where `pop_back` was `O(n)`.

---

### Custom [a.cpp](a.cpp) vs `std::list`

| Feature | Your `List` ([a.cpp](a.cpp)) | `std::list` ([i.cpp](i.cpp)) |
|---------|------------------------------|------------------------------|
| **Links** | Singly linked (`next` only) | Doubly linked (typical) |
| **`push_front` / `push_back`** | `O(1)` with head + tail | `O(1)` |
| **`pop_front`** | `O(1)` | `O(1)` |
| **`pop_back`** | `O(n)` (walk to predecessor) | **`O(1)`** |
| **Memory** | You manage `new` / `delete` | Container manages nodes |
| **Learning** | Full control, interviews | Production / quick use |

---

### Common member functions

| Function | What it does | Notes |
|----------|--------------|--------|
| **`push_front(val)`** | Insert **before** first element | List becomes `val -> ...` |
| **`push_back(val)`** | Insert **after** last element | Append at tail |
| **`pop_front()`** | Remove first element | **Empty list → undefined behavior** — check `empty()` first |
| **`pop_back()`** | Remove last element | Same empty caveat |
| **`size()`** | Return number of elements | `O(1)` in C++11 and later |
| **`front()`** | Reference to **first** element | Read or modify; list must be non-empty |
| **`back()`** | Reference to **last** element | Read or modify; list must be non-empty |
| **`empty()`** | `true` if `size() == 0` | Use before `front()` / `back()` / pop |

---

### How each maps to ideas from this module

| STL call | Same idea as |
|----------|----------------|
| `push_front` | [a.cpp](a.cpp) `push_front` |
| `push_back` | [a.cpp](a.cpp) `push_back` |
| `pop_front` | [a.cpp](a.cpp) `pop_front` |
| `pop_back` | [a.cpp](a.cpp) `pop_back` (but STL is `O(1)`) |
| `front` / `back` | Like reading `head->data` / `tail->data` without removing |

There is **no** `operator[]` — you cannot write `lst[i]`. Traverse with a range-`for` loop or iterators (see [i.cpp](i.cpp)).

---

### Traverse and print ([i.cpp](i.cpp))

```cpp
for (int x : lst) {
    cout << x << " ";
}
```

Or:

```cpp
for (auto it = lst.begin(); it != lst.end(); ++it) {
    cout << *it << " ";
}
```

---

### Example walkthrough ([i.cpp](i.cpp))

| Step | `list` contents (conceptual) |
|------|------------------------------|
| `push_back(30)`, `push_back(40)` | `30 <-> 40` |
| `push_front(20)`, `push_front(10)` | `10 <-> 20 <-> 30 <-> 40` |
| `front()` | `10` |
| `back()` | `40` |
| `pop_front()` | `20 <-> 30 <-> 40` |
| `pop_back()` | `20 <-> 30` |
| `size()` | `2` |

### Output ([i.cpp](i.cpp))

```
After pushes (size=4): 10 <-> 20 <-> 30 <-> 40 <-> END
front() = 10
back()  = 40
After pop_front & pop_back (size=2): 20 <-> 30 <-> END
size() = 2
```

---

### Pitfalls

| Mistake | Problem |
|---------|---------|
| `pop_front` on empty list | Undefined behavior — call `empty()` first |
| `front()` on empty list | Undefined behavior |
| Confuse `list` with `vector` | `vector` is dynamic array; `list` is linked nodes |
| Expect `lst[i]` | No random access — use iterators |

---

### Module file map (STL)

| File | Topic |
|------|--------|
| [i.cpp](i.cpp) | `std::list` — push, pop, size, front, back |
| [j.cpp](j.cpp) | Iterators on `std::list` |

---

## Iterators in C++

**Reference:** [j.cpp](j.cpp)  
**Headers:** `#include <list>` (container) · `#include <iterator>` (utilities like `std::distance`)

### Definition

An **iterator** is an object that **points to one element** in a container and lets you **move** to the next (or previous) element in order — like a **`Node* temp`** walking a linked list in [a.cpp](a.cpp) `display()`, but in a **standard** form that works for `list`, `vector`, `set`, etc.

| Manual linked list ([a.cpp](a.cpp)) | Iterator ([j.cpp](j.cpp)) |
|-----------------------------------|---------------------------|
| `Node* temp = head` | `auto it = lst.begin()` |
| `temp != nullptr` | `it != lst.end()` |
| `temp->data` | `*it` |
| `temp = temp->next` | `++it` |

**One-line intuition:** An iterator is a **cursor** on the container — not the whole list, just “where you are” right now.

---

### `begin()` and `end()`

| Function | Points to |
|----------|-----------|
| **`begin()`** | **First** element in the container |
| **`end()`** | **One past the last** element — sentinel, **do not** dereference |

```
  list:  10 <-> 20 <-> 30 <-> 40
         ^                        ^
      begin()                   end()
      (*it works)            (stop here; no *end())
```

Loop pattern:

```cpp
for (auto it = lst.begin(); it != lst.end(); ++it) {
    cout << *it << " ";
}
```

Same logic as:

```cpp
for (int x : lst) {  // range-for uses iterators internally
    cout << x << " ";
}
```

---

### Core operations

| Operation | Meaning | Example |
|-----------|---------|---------|
| **`*it`** | Value at current position | `*it` → `20` |
| **`++it`** | Move to **next** element | Forward one node |
| **`--it`** | Move to **previous** (doubly linked `list`) | Back one node |
| **`it1 == it2`** | Same position? | Compare iterators |
| **`lst.insert(it, val)`** | Insert **before** `it` | [j.cpp](j.cpp) inserts `25` before `30` |
| **`lst.erase(it)`** | Remove element at `it`; returns **next** iterator | Safe to continue traversal |

---

### Iterator type for `std::list`

```cpp
list<int> lst;
list<int>::iterator it = lst.begin();
```

| Property | `list` iterator |
|----------|-----------------|
| **Category** | **Bidirectional** — `++` and `--` both work |
| **Random access?** | **No** — cannot write `it + 3` on `list` (unlike `vector`) |
| **Why** | Linked nodes — must follow links step by step |

| Container | Iterator strength | `it + k`? |
|-----------|-------------------|-----------|
| **`vector`** | Random access | Yes |
| **`list`** | Bidirectional | No — use `++it` k times or `advance(it, k)` |

---

### `#include <iterator>` utilities

Used in [j.cpp](j.cpp) for helpers that work on many container types:

| Function | Role on `list` |
|----------|----------------|
| **`std::distance(begin, it)`** | Count steps from `begin` to `it` — **`O(n)`** for `list` |
| **`std::advance(it, k)`** | Move `it` forward `k` steps — **`O(k)`** for `list` |
| **`std::next(it, k)`** | Return iterator `k` steps ahead (does not move `it` unless you assign) |

You do not need `<iterator>` for a simple `begin`/`end` loop — only for these utilities and generic algorithms.

---

### Example ([j.cpp](j.cpp))

Start: `10 <-> 20 <-> 30 <-> 40`

| Step | Effect |
|------|--------|
| `insert(it, 25)` before `30` | `10 <-> 20 <-> 25 <-> 30 <-> 40` |
| `erase(it)` at `20` | `10 <-> 25 <-> 30 <-> 40` |

### Sample output

```
First element: 10
Second element: 20
Forward traversal: 10 20 30 40
After insert(25) before 30: 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> END
After erase(20): 10 <-> 25 <-> 30 <-> 40 <-> END
Iterator now at: 25
distance(begin, it) = 1
```

---

### Complexity notes

| Action on `list` iterator | Time |
|---------------------------|------|
| `++it` / `--it` | `O(1)` |
| `*it` | `O(1)` |
| `insert` / `erase` at `it` | `O(1)` if you already have the iterator |
| `distance(begin, it)` | `O(n)` — must walk the links |

---

### Pitfalls

| Mistake | Problem |
|---------|---------|
| Dereference **`end()`** | Invalid — `end()` is not an element |
| Use **`it + 2`** on `list` | Compile error — not random access |
| Erase without using return value | Iterator may be invalid; `erase` returns next valid iterator |
| Invalidate iterator after container change | Save returned iterator from `erase` ([j.cpp](j.cpp)) |

---

### How this module fits together

| File | Idea |
|------|------|
| [a.cpp](a.cpp) | Manual `Node*`, `head`, `tail` |
| [i.cpp](i.cpp) | STL `list` with `push` / `pop` / `front` / `back` |
| [j.cpp](j.cpp) | STL **iterators** — standard way to walk and edit in the middle |

