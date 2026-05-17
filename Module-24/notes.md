# DSA with C++ — Module 24 Notes

**Topic:** Linked lists — definition, node structure, head/tail pointers, memory layout, and how they compare to arrays.  
**Companion code:** [a.cpp](a.cpp) and later files in this folder. These notes give *definitions* and *mental models* only — no implementation snippets here.

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

Later topics in this module (and companion `.cpp` files) will cover **creating** lists, **insertion**, **deletion**, and variants such as **doubly linked** lists — still using this node-and-pointer model.


LINKED LIST IMPLEMENTATION

linked list is already there in C++ template library but you can also make it by your own

making a linked list using OOPS 

we will create a node class : it will have int data and Node* next

then we have to create a collection of nodes

Push Front -> LL.push_front(val)

this is the function on a linked list which creates a new node at the begining of the linked list : it works for two cases

1. ll is empty : a new node will initialize
2. ll has elements : new node will be created, then the pointer of new node will point the head of ll