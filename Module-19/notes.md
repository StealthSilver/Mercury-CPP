# DSA with C++ — Module 19 Notes

**Topic:** Object-Oriented Programming (OOP) part 2 — polymorphism, virtual dispatch, abstraction with abstract classes, `static`, `friend`, and practice problems.  
**Companion code:** Each idea below points to a runnable `.cpp` in this folder. These notes explain *what* and *why*; open the files to see behavior.

---

## Polymorphism (big picture)

**Polymorphism** means “many shapes”: the **same interface** (same function name, same operator symbol, or same base-class pointer) can **mean different things** depending on **context**—either resolved at **compile time** or at **run time**.

| Kind | When the decision is made | Typical mechanisms in C++ |
|------|---------------------------|---------------------------|
| **Compile-time polymorphism** | While compiling | Function overloading, operator overloading, templates |
| **Runtime polymorphism** | While the program runs | **Virtual functions**, **overriding**, pointers/references to base |

**Constructor overloading** (many constructors, different parameter lists) is an example of **compile-time** polymorphism: the compiler picks which constructor matches the arguments at the place the object is created.

---

## Compile-time polymorphism

The compiler **already knows** which function or operator implementation to use before the program runs. No “lookup” through a base pointer is involved.

### 1. Function overloading

**Definition:** Several functions in the **same scope** may share the **same name** if their **parameter lists differ** (number and/or types of parameters). The compiler chooses the best match at each **call site** based on the arguments.

This is **not** inheritance; it is simply **overload resolution** in one scope (often inside a class or at namespace scope).

**Reference:** [a.cpp](a.cpp)

---

### 2. Operator overloading

**Definition:** For a class type, you define special member functions (or sometimes non-member functions) named **`operator`** followed by a symbol (`+`, `-`, `<<`, etc.). The **symbol stays familiar** to readers, but **your** type defines what the operation **does**.

Useful for mathematical types (e.g. complex numbers), smart wrappers, or anything that reads more clearly with familiar syntax. The compiler still picks the right overload at **compile time** from the operand types.

**Reference:** [b.cpp](b.cpp)

---

## Runtime polymorphism

Here the **correct function** is often chosen using the **actual type of the object** in memory, even when the code only names a **base** class pointer or reference. That needs a **virtual** function in the base and an **override** in the derived class with the **same signature**.

### 1. Function overriding

**Definition:** A **derived** class provides a **member function with the same name and same parameter list** as a **base** class member. When the base version is **`virtual`**, the derived version **replaces** it for calls made through **`Base*`** / **`Base&`** to a **derived** object. The base function is then said to be **overridden**.

If the base function is **not** `virtual`, the derived function can still **hide** the base name for direct calls on the derived type, but calls through **`Base&`** will **not** automatically run the derived implementation.

**Reference:** [c.cpp](c.cpp)

---

### 2. Virtual functions

**Definition:** A **virtual** member function in the base class is one you **expect derived classes to replace**. Mark it with the keyword **`virtual`** in the base. Calls through a **base pointer or reference** use **dynamic dispatch** (run-time binding): the program follows the object’s **dynamic type** to find the final override.

**Properties (useful checklist):**

- **Dynamic:** With `virtual`, the **which implementation** question can be answered at **run time** (for example, iterating over different shapes stored as `Shape*`).
- **Declared in base, refined in derived:** The base declares the contract; derived classes supply (or further override) behavior.
- **Override, not overload:** Same **name and parameter list** as the base virtual; use the **`override`** keyword on the derived function to catch signature mistakes early.

**Relationship to inheritance:** Virtual functions are **meaningful only in an inheritance hierarchy**. Inheritance gives you the “is-a” layout; `virtual` gives you **substitutability** (treat a `Dog` as an `Animal` and still get dog behavior when you call `speak()`).

**Reference:** [d.cpp](d.cpp)

---

## Abstraction

**Abstraction** means exposing **what** a type does (meaningful operations and data at the boundary) while **hiding** **how** it works inside and hiding details callers do not need.

You implement abstraction with:

- **Access specifiers** (`private`, `protected`, `public`) to narrow the public surface.
- **Abstract classes** and **pure virtual** functions to describe **capabilities** without committing to one concrete implementation in the base.

Abstract classes and pure virtuals are **one** way to express abstraction; they are not the only tool (interfaces can also be small concrete classes with good encapsulation).

---

## Abstract classes

**Definition:** A class that **cannot be instantiated** on its own because it is **incomplete** as a concrete type—usually because it has at least one **pure virtual** function. It acts as a **blueprint** or **interface**: derived classes are expected to fill in behavior.

**Typical roles:**

- Provide a **common base type** for pointers/references (`Shape*`, `Logger&`, …).
- **Force** derived types to implement certain operations.
- **Cannot** create `AbstractType x;` until every pure virtual has been implemented down some inheritance chain.

**Reference:** [e.cpp](e.cpp)

---

## Pure virtual functions

**Definition:** A **pure virtual** function is a virtual function **without an implementation in that class’s declaration**, marked by **`= 0`** (read as “no implementation here”). The base class only **declares** the operation.

Syntax pattern (spelling details in [f.cpp](f.cpp)): a virtual function with **`= 0`** and **no body** in the class declaration, e.g. `virtual ReturnType name(ParameterList) = 0;`.

Until a **derived** class provides a **definition** for every inherited pure virtual, that derived class is still **abstract** and cannot be instantiated either.

**Note:** In advanced C++, a pure virtual may technically have an **out-of-class definition** for rare cases; in introductory courses, treat **`= 0`** as “no body in the class; derived must implement.”

**Reference:** [f.cpp](f.cpp)

---

## The `static` keyword (variables and objects)

### Static local variables (inside a function)

A **`static`** local variable has **one storage location** for the **entire program**. It is **initialized once** (the first time control reaches its declaration) and **keeps its value** across subsequent calls to that function.

**Reference:** [g.cpp](g.cpp)

---

### Static data members (inside a class)

A **`static`** data member belongs to the **class**, not to each object. There is **one shared variable** for all instances (unless you use `thread_local` or other advanced variants). You define it **once** in a `.cpp` file (or use `inline static` in C++17 inside the class).

**Reference:** [g.cpp](g.cpp)

---

### Static objects (storage duration)

A **`static`** object (e.g. `static MyClass instance;` at namespace scope, or `static MyClass instance;` inside a function) has **static storage duration**: lifetime is essentially **from before/throughout `main` until program teardown**, with destruction order rules relative to other static objects.

- **Namespace / file scope:** constructed before `main` runs (for this translation unit’s dynamic initialization order).
- **Block scope inside a function:** constructed the **first** time execution passes the declaration; destroyed at program exit in a defined order relative to other statics.

**Reference:** [h.cpp](h.cpp)

---

## `friend` classes and `friend` functions

**Definition:** A **`friend`** declaration inside class `X` grants **named** non-members or **another class** the right to access **`private`** and **`protected`** members of `X` as if they were part of `X`.

**Important facts:**

- Friendship is **not symmetric** (`X` friending `Y` does not let `X` into `Y`’s privates).
- Friendship is **not inherited** (a derived class does not automatically gain friends of the base).

**Reference:** [i.cpp](i.cpp)

---

## Practice questions (specifications)

Work these in order; each has a matching solution file.

| File | Goal |
|------|------|
| [j.cpp](j.cpp) | Predict **constructor/destructor order** for `class B : public A` when you create a `B` (inheritance construction/destruction rules). |
| [k.cpp](k.cpp) | Predict output for **`Base* b = new Derived(); b->print(); delete b;`** with **`virtual`** `print` (and why **`virtual ~Base()`** matters). |
| [l.cpp](l.cpp) | **`Complex`** subtraction with **`operator-`**. Conventionally **`z1 - z2`** uses **real minus real** and **imaginary minus imaginary** (left-hand side minus right-hand side). If a problem statement phrases “first subtracted from second” ambiguously, match the assignment’s intended order to **`z1 - z2`** or **`z2 - z1`** explicitly. |
| [m.cpp](m.cpp) | **`BankAccount`**: private **`accountNumber`** and **`balance`**; public **`deposit`**, **`withdraw`**, **`getBalance`**. |
| [n.cpp](n.cpp) | **`Person`** (name, age); **`Student`** adds **`studentID`**; **`displayStudentInfo()`**; construct with `Student student("Alice", 20, "S12345");`. |

---

## Quick glossary

| Term | One-line meaning |
|------|------------------|
| **Overload** | Same name, **different parameters**; compile-time choice. |
| **Override** | Same name, **same parameters** in derived class; replaces `virtual` base behavior when called through base ref/ptr. |
| **Virtual** | Enables run-time choice of override through base pointer/reference. |
| **Pure virtual (`= 0`)** | No implementation in this class; makes class abstract until derived defines it. |
| **Abstract class** | Has at least one pure virtual; cannot instantiate directly. |
| **Static (local)** | One variable for all calls to that function. |
| **Static (member)** | One variable shared by all objects of the class. |
| **Friend** | Explicit permission to bypass `private`/`protected` for listed code. |

---

*End of Module 19 notes.*
