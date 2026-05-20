# DSA with C++ — Module 18 Notes

**Topic:** Object-Oriented Programming (OOP) part 1 in C++  
**Companion code:** See the linked `.cpp` files in this folder for runnable examples. These notes focus on concepts and wording; the programs demonstrate behavior.

---

## 🔹 What Is Object-Oriented Programming?

**Object-oriented programming** is a way of structuring programs around **objects** and **classes** instead of scattering data and logic without clear boundaries.

- A **class** is a user-defined type: it describes what data the type holds and which operations (member functions) apply to that data.
- An **object** is a concrete instance of a class in memory—one “thing” created from the blueprint.

You still write algorithms and logic; OOP helps you **group related data and behavior**, **hide internal details**, and **reuse** designs through inheritance and composition.

**Reference:** [a.cpp](a.cpp), [b.cpp](b.cpp) — classes as blueprints and creating objects.

---

## 🔹 The Four Pillars of OOP (Overview)

Most OOP courses organize ideas around four themes. This module goes deep on several of them in C++; the list below is the full map.

| Pillar | Idea in one line | Where this module focuses |
|--------|------------------|-----------------------------|
| **Encapsulation** | Bundle data + methods; control visibility from outside. | Access modifiers, getters/setters, constructors — [c.cpp](c.cpp), [d.cpp](d.cpp), [e.cpp](e.cpp) |
| **Inheritance** | Derive a new type from an existing one to reuse and extend behavior. | [l.cpp](l.cpp), [m.cpp](m.cpp), [n.cpp](n.cpp) |
| **Abstraction** | Expose *what* an object does, hide *how* it does it (interfaces, meaningful public API). | Reinforced whenever you design a small, clear public surface for a class. |
| **Polymorphism** | Same interface, different behaviors (e.g. virtual functions in a later topic). | Named here for completeness; virtual tables / overrides are typically a follow-up lesson. |

Encapsulation and inheritance are the main technical threads in the files listed above.

---

## 🔹 Classes and Objects

- **Class:** A named pattern (template) for objects: member variables (**data members**, **attributes**, **fields**) and **member functions** (**methods**).
- **Object:** A region of storage that follows that pattern; each object has its **own** copies of non-static data members (unless the design shares data on purpose).

**Analogy:** The class is the blueprint; each object is one house built from it.

**Reference:** [a.cpp](a.cpp), [b.cpp](b.cpp).

---

## 🔹 Access Modifiers (`private`, `protected`, `public`)

C++ lets you mark members with an **access level**. That level controls **who can use the name** of a member from outside (or in derived classes).

| Modifier | Who can access |
|----------|----------------|
| **`private`** | Only inside the same class (and **friends**, an advanced feature). Use this for internal state you do not want arbitrary outside code to touch. |
| **`protected`** | Inside the same class **and** inside **derived** classes. Common when subclasses need to cooperate with the base implementation. |
| **`public`** | Any code that has an object of the type can access these members. |

**Default for `class`:** If you omit an access label, members are **`private` until you write `public:` / `protected:` / `private:` again.**  
**Default for `struct`:** Members are **`public`** until you change the access section.

**Reference:** [c.cpp](c.cpp).

---

## 🔹 Getters and Setters

When important data is **`private`**, outside code cannot read or change it directly. **Getters** (read accessors) and **setters** (write mutators) are ordinary member functions that expose **controlled** access—for example, validating input before storing a value.

They are not magic keywords; they are a **discipline** for keeping invariants (rules your object must always satisfy).

**Reference:** [d.cpp](d.cpp).

---

## 🔹 Encapsulation

**Encapsulation** means two related things:

1. **Grouping:** Data and the functions that operate on that data live together in one type.
2. **Information hiding:** You choose a **public API** (what callers may use) and keep the rest **`private`** (or `protected` for inheritance), so internal details can change without breaking every caller—as long as the public contract stays stable.

Access modifiers and getters/setters are the usual tools for encapsulation in C++.

**Reference:** [d.cpp](d.cpp) (together with getters/setters).

---

## 🔹 Constructors

A **constructor** is a special member function used to **initialize** an object right after storage for the object exists.

**Facts that matter in C++:**

- The constructor has the **same name** as the class.
- It has **no return type** (not even `void`).
- It runs **automatically** when an object is created (automatic storage, `new`, container insertion, etc.).
- You can have **no-parameter** (“default”) constructors and **parameterized** constructors; the compiler may also generate some special members unless you restrict them (modern C++ has `= delete` / `= default` for fine control—see advanced material when needed).

**Reference:** [e.cpp](e.cpp).

---

## 🔹 The `this` Pointer

Inside a non-static member function, **`this`** is a pointer to **the object on which the function was called**. Writing `this->member` is equivalent to accessing the same object’s `member` for that call. It is useful when parameter names shadow member names, or when you must pass the current object’s address to another function.

**Reference:** [f.cpp](f.cpp).

---

## 🔹 Constructor Overloading

You may define **several constructors** in one class as long as their **parameter lists differ** (overload resolution). The compiler picks which constructor matches the arguments used at the creation site.

**Reference:** [g.cpp](g.cpp).

---

## 🔹 Practice Problem (Specification)

Design a **`User`** class with:

- `id` — **private**, initialized via a **parameterized** constructor  
- `username` — **public**  
- `password` — **private**, with a **getter** and **setter**

**Reference:** [h.cpp](h.cpp).

---

## 🔹 Copy Constructor

A **copy constructor** builds a new object as a **copy** of an existing object of the same type. Its typical form is `T(const T&)` (possibly with other parameters defaulted). If you do not write one, the compiler may **generate** a copy constructor for you—but generated copying is not always correct when the class owns **raw pointers to dynamic memory** or other non-copy-trivial resources.

**Note:** Other languages handle copying and references differently (for example Java’s reference model). C++ makes **value semantics** and **custom copying** explicit responsibilities of the class author when needed.

**Reference:** [i.cpp](i.cpp).

---

## 🔹 Shallow Copy vs Deep Copy

- **Shallow copy:** Member-wise copy where **pointer members copy the address**, not a new allocation. Multiple objects can end up **pointing at the same heap storage**. That is fine only if you **design** for shared ownership and lifetime rules carefully.
- **Deep copy:** For owned dynamic data, you **allocate new storage** and copy the **contents**, so each object has its **own** independent copy.

The compiler-generated copy constructor often behaves like a **shallow** copy for pointer members. If your class **owns** memory (`new` / `new[]`), you usually need a **user-defined copy constructor** (and often copy assignment, destructor, and move operations—see the **Rule of Three / Five** in advanced C++ material).

**Reference:** [j.cpp](j.cpp).

---

## 🔹 Destructor

A **destructor** is a special member `~ClassName` that runs when an object’s lifetime **ends** (scope exit, `delete`, destruction of a containing object, etc.). Use it to **release resources** the object acquired—especially memory that will not be freed automatically (for example memory from `new` that the destructor should pair with `delete`).

The destructor has **no parameters** and **no return type**. For simple classes with only automatic members, the compiler-generated destructor is often enough.

**Reference:** [k.cpp](k.cpp).

---

## 🔹 Inheritance

**Inheritance** lets you define a **derived** (**child**) class that **extends** or **specializes** a **base** (**parent**) class. The derived type **inherits** members from the base according to access rules and the **inheritance mode** (`public`, `protected`, or `private` inheritance).

**Terminology:** base / super / parent ↔ derived / sub / child.

**Purpose:** Reuse common behavior and data models, express **“is-a”** or **“kind-of”** relationships clearly, and build hierarchies (see [n.cpp](n.cpp)).

**Correction from informal notes:** Inheritance is used to **increase code reuse** and structure—not “reduce reusability.”

**Default inheritance kind:** For `class Derived : Base`, inheritance is **`private`** if you omit the keyword. For `struct Derived : Base`, the default is **`public` inheritance**. Being explicit (`public Base`) is recommended for readability.

**Reference:** [l.cpp](l.cpp).

---

## 🔹 Modes of Inheritance (How Base Members “Arrive” in the Derived Type)

The keyword on the inheritance line (`public`, `protected`, `private`) sets the **mode of inheritance**. It adjusts how **accessible** inherited members are **when seen through the derived class**—especially from **outside** code.

**Summary table** (base member’s access in the base class → resulting notion in the derived class for each mode):

| Base member was… | `class D : public B` | `class D : protected B` | `class D : private B` |
|------------------|------------------------|-------------------------|------------------------|
| `public` in `B` | `public` in `D` | `protected` in `D` | `private` in `D` |
| `protected` in `B` | `protected` in `D` | `protected` in `D` | `private` in `D` |
| `private` in `B` | **Not accessible** in `D` | **Not accessible** in `D` | **Not accessible** in `D` |

`private` members of the base remain **implementation details of the base**; the derived class does not get direct access to them (only through base-provided `public`/`protected` interface).

**Reference:** [m.cpp](m.cpp).

---

## 🔹 Structural Patterns: Types of Inheritance

These names describe **shapes of inheritance graphs**, not C++ syntax keywords.

1. **Single inheritance** — One base class, one derived class (one direct parent).
2. **Multilevel inheritance** — A chain: base → derived → further derived (each step has one direct base).
3. **Multiple inheritance** — One **derived** class has **two or more direct** base classes. (Informal notes sometimes mis-state this as “single base”; the correct idea is **one derived, multiple bases**.)
4. **Hierarchical inheritance** — **One** base class, **several** different derived classes that do not inherit from each other (sibling branches from the same root).
5. **Hybrid inheritance** — A **mix** of the above patterns in one design (for example a multilevel branch **plus** multiple inheritance). Real systems often combine patterns; multiple inheritance also introduces design questions (e.g. **diamond** inheritance), which advanced courses address with **virtual inheritance** and interface discipline.

**Reference:** [n.cpp](n.cpp).

---

## 🔹 Quick Module Map

| File | Topic |
|------|--------|
| [a.cpp](a.cpp), [b.cpp](b.cpp) | Classes and objects |
| [c.cpp](c.cpp) | Access modifiers |
| [d.cpp](d.cpp) | Getters, setters, encapsulation |
| [e.cpp](e.cpp) | Constructors |
| [f.cpp](f.cpp) | `this` pointer |
| [g.cpp](g.cpp) | Constructor overloading |
| [h.cpp](h.cpp) | Practice: `User` class |
| [i.cpp](i.cpp) | Copy constructor |
| [j.cpp](j.cpp) | Shallow vs deep copy |
| [k.cpp](k.cpp) | Destructor |
| [l.cpp](l.cpp) | Inheritance basics |
| [m.cpp](m.cpp) | Modes of inheritance |
| [n.cpp](n.cpp) | Structural inheritance patterns |

---

_End of Module 18 notes._
