# DSA with C++ — Module 5 Notes

---

## 🔹 Introduction

This module covers **conditional statements**, **decision-making constructs**, and **type aliasing** in C++. These concepts are fundamental for controlling program flow and writing efficient, readable code that responds to different conditions at runtime.

---

## 🔹 Conditional Statements Overview

Conditional statements allow you to execute different code blocks based on different conditions. C++ provides four main ways to implement conditional logic:

```
┌────────────────────────────────────────────┐
│      Types of Conditional Statements       │
├────────────────────────────────────────────┤
│ 1. if - else                               │
│ 2. else - if                               │
│ 3. Ternary Operator (? :)                  │
│ 4. Switch - case                           │
└────────────────────────────────────────────┘
```

---

## 🔹 1. IF-ELSE Statement

The **if-else** statement is the most basic conditional construct. It allows you to execute one block of code if a condition is true, and another block if it's false.

### Basic Syntax

```cpp
if (condition) {
    // Executes if condition is true
}
else {
    // Executes if condition is false
}
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│              IF-ELSE Characteristics                   │
├────────────────────────────────────────────────────────┤
│ • Condition must evaluate to boolean (true/false)      │
│ • "else" block is optional                             │
│ • You can write multiple "if" statements independently │
│ • Only one "else" can follow an "if"                   │
│ • "else" must immediately follow the "if" block        │
│ • If condition is true, "else" block is skipped        │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- **Pass/Fail Check** - Determine if a score passes [b.cpp](b.cpp)
- **Maximum of Two Numbers** - Compare and find larger value [c.cpp](c.cpp)
- **Odd/Even Check** - Determine number properties [d.cpp](d.cpp)

### Important Notes

```cpp
// ✓ CORRECT: Multiple independent if statements
if (age >= 18)
    cout << "Adult" << endl;
if (hasLicense)
    cout << "Can drive" << endl;

// ❌ INCORRECT: Only one else per if
if (age < 18)
    cout << "Minor" << endl;
else
    cout << "Adult" << endl;
else                    // ERROR: Second else not allowed
    cout << "Senior" << endl;
```

---

## 🔹 2. ELSE-IF Statement

The **else-if** statement extends the if-else logic to handle multiple conditions. It allows you to check several different cases sequentially.

### Basic Syntax

```cpp
if (condition1) {
    // Executes if condition1 is true
}
else if (condition2) {
    // Executes if condition1 is false AND condition2 is true
}
else if (condition3) {
    // Executes if condition1 and condition2 are false AND condition3 is true
}
else {
    // Executes if all conditions above are false
}
```

### Execution Flow

```
┌──────────────────────────────────────────────────────┐
│ Check condition1 → TRUE  → Execute block 1, skip rest│
│        ↓                                              │
│      FALSE                                           │
│        ↓                                              │
│ Check condition2 → TRUE  → Execute block 2, skip rest│
│        ↓                                              │
│      FALSE                                           │
│        ↓                                              │
│ Check condition3 → TRUE  → Execute block 3, skip rest│
│        ↓                                              │
│      FALSE                                           │
│        ↓                                              │
│    Execute else block (if present)                   │
└──────────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│            ELSE-IF Characteristics                     │
├────────────────────────────────────────────────────────┤
│ • Conditions are checked sequentially from top to bottom
│ • Execution stops once ONE condition is found true     │
│ • Remaining conditions are NOT evaluated               │
│ • Final "else" block is optional                       │
│ • You can have unlimited else-if statements            │
│ • Useful for range checking and categorization         │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- **Income Tax Calculator** - Different tax brackets for income ranges [f.cpp](f.cpp)
- **Maximum of Three Numbers** - Find largest among three values [g.cpp](g.cpp)
- **Grade Assignment** - Assign grades based on score ranges
- **Age Categorization** - Classify by age groups

### Performance Tip

Since conditions are evaluated sequentially, place the most common conditions first for better performance:

```cpp
// More efficient (common case checked first)
if (age >= 18)           // Most people
    handleAdult();
else if (age >= 13)      // Some people
    handleTeen();
else                     // Fewer people
    handleChild();
```

---

## 🔹 3. Ternary Operator

The **ternary operator** is a concise way to write simple if-else statements in a single line. It's called "ternary" because it takes three operands.

### Syntax

```cpp
condition ? valueIfTrue : valueIfFalse
```

### How It Works

```
     condition
         ↓
       true? → return valueIfTrue
         ↓
       false? → return valueIfFalse
```

### When to Use

```
┌────────────────────────────────────────────────────────┐
│           Ternary Operator Usage Guide                 │
├────────────────────────────────────────────────────────┤
│ ✓ Use for simple, single-line decisions               │
│ ✓ Use for assigning values based on condition          │
│ ✓ Use when both branches are expressions (not complex) │
│ ✓ Makes code concise and readable                      │
│                                                        │
│ ✗ Avoid nesting multiple ternary operators             │
│ ✗ Avoid using for complex logic (use if-else instead) │
│ ✗ Avoid if branches contain multiple statements        │
└────────────────────────────────────────────────────────┘
```

### Comparison: Ternary vs If-Else

```cpp
// Using if-else (more verbose)
int max;
if (a > b)
    max = a;
else
    max = b;

// Using ternary (more concise)
int max = (a > b) ? a : b;

// Both produce the same result
```

### Illustration Files

- [h.cpp](h.cpp) - Basic ternary operator usage
- [i.cpp](i.cpp) - Ternary with multiple expressions
- [j.cpp](j.cpp) - Practical ternary applications

### Examples

```cpp
// Absolute value
int abs = (x < 0) ? -x : x;

// Larger of two numbers
int larger = (a > b) ? a : b;

// Check if even or odd
string type = (n % 2 == 0) ? "Even" : "Odd";

// Nested ternary (avoid this for readability)
int category = (score >= 80) ? "A" : (score >= 60) ? "B" : "C";
// Better written as else-if ↑
```

---

## 🔹 4. Switch Statement

The **switch statement** is used when you need to check a single variable against multiple possible values (cases). It's more efficient and readable than multiple else-if statements when comparing a single expression to many constants.

### Syntax

```cpp
switch (expression) {
    case value1:
        // Code if expression == value1
        break;
    case value2:
        // Code if expression == value2
        break;
    // ... more cases ...
    default:
        // Code if expression doesn't match any case
}
```

### How Switch Works

```
┌─────────────────────────────────────────────────────┐
│ Evaluate expression                                 │
│         ↓                                           │
│ Compare with case value1? → YES → Execute, break   │
│         ↓                                           │
│ Compare with case value2? → YES → Execute, break   │
│         ↓                                           │
│ Compare with case value3? → YES → Execute, break   │
│         ↓                                           │
│ No match found? → Execute default block            │
└─────────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│             Switch Statement Characteristics           │
├────────────────────────────────────────────────────────┤
│ • Expression can be int, char, or enum                 │
│ • Each case represents a specific constant value       │
│ • "break" stops execution and exits the switch         │
│ • Without "break", execution falls through to next case│
│ • "default" case is optional (like else in if-else)   │
│ • Multiple cases can share the same code block         │
│ • More efficient than multiple else-if for single var │
└────────────────────────────────────────────────────────┘
```

### Break Statement Importance

```cpp
switch (day) {
    case 1:
        cout << "Monday" << endl;
        break;  // ✓ REQUIRED: Exit switch

    case 2:
        cout << "Tuesday" << endl;
        break;  // ✓ REQUIRED: Exit switch

    default:
        cout << "Invalid day" << endl;
}

// Without break: Falls through to next case (usually a bug)
switch (choice) {
    case 1:
        cout << "Option 1" << endl;
        // ❌ NO BREAK: Falls through to case 2
    case 2:
        cout << "Option 2" << endl;
        // Both printed if choice == 1
        break;
}
```

### Common Use Cases

- **Calculator** - Different operations based on operator symbol [l.cpp](l.cpp)
- **Menu Selection** - Handle different user choices
- **Day of Week** - Map numbers to day names
- **Character/String Classification** - Check character types

### Switch vs If-Else Comparison

```
┌──────────────────┬────────────────────────┬──────────────────────┐
│ Aspect           │ Switch                 │ If-Else              │
├──────────────────┼────────────────────────┼──────────────────────┤
│ Condition Type   │ Single variable        │ Any expression       │
│ Comparison       │ Equality only (==)     │ Any relational (>,<) │
│ Value Types      │ Constants only         │ Any values           │
│ Readability      │ Better for many cases  │ Better for ranges    │
│ Performance      │ Faster for many cases  │ Sequential check     │
│ use case         │ Menu, day, choice      │ Range checking, logic│
└──────────────────┴────────────────────────┴──────────────────────┘
```

---

## 🔹 Practice Problems

The following programs demonstrate conditional statements in practical scenarios:

```
┌──────┬──────────────────────────────────┬─────────────────────────┐
│ File │ Problem                          │ Concepts Covered        │
├──────┼──────────────────────────────────┼─────────────────────────┤
│ m.cpp│ Positive, Negative, or Zero      │ Multiple if-else checks │
│ n.cpp│ Leap Year Checker                │ Multiple conditions     │
│ o.cpp│ Armstrong Number Checker         │ Digit extraction logic  │
│ p.cpp│ Perfect Number Checker           │ Loop + conditional      │
└──────┴──────────────────────────────────┴─────────────────────────┘
```

---

## 🔹 TYPEDEF - Type Aliasing

**typedef** is a keyword used to create an alias (alternative name) for existing data types. It makes code more readable by giving meaningful names to types and is especially useful for complex data types.

### Basic Syntax

```cpp
typedef existingType newName;
```

### Examples

```cpp
typedef int myInt;              // myInt is alias for int
typedef float myFloat;          // myFloat is alias for float
typedef double myDouble;        // myDouble is alias for double
typedef unsigned long ulong;    // ulong is alias for unsigned long
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│             TYPEDEF Characteristics                    │
├────────────────────────────────────────────────────────┤
│ • Creates an alias, not a new type                    │
│ • Both original and alias names can be used           │
│ • Improves code readability and maintainability       │
│ • Compiler still sees the original type               │
│ • No runtime overhead or memory cost                  │
│ • Particularly useful for complex types               │
└────────────────────────────────────────────────────────┘
```

### When to Use TYPEDEF

```
┌────────────────────────────────────────────────────────┐
│              TYPEDEF Use Cases                         │
├────────────────────────────────────────────────────────┤
│ ✓ Simplify complex pointer types                       │
│ ✓ Create platform-independent type names              │
│ ✓ Make code more self-documenting                      │
│ ✓ Facilitate future type changes                       │
│ ✓ Improve readability in large projects                │
│                                                        │
│ Example:                                               │
│ typedef unsigned long long uint64;                     │
│ uint64 largeNumber = 123456789;  // More readable      │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Macros vs Constants vs Typedef

C++ provides three ways to define fixed or aliased values. Understanding the differences is crucial for writing maintainable code.

### Detailed Comparison

```
┌─────────────────┬──────────────────────┬──────────────────┬──────────────────┐
│ Feature         │ Macros (#define)     │ Constants (const)│ Typedef          │
├─────────────────┼──────────────────────┼──────────────────┼──────────────────┤
│ Declaration     │ #define NAME value   │ const type VAR;  │ typedef type new │
│                 │                      │                  │                  │
│ Purpose         │ Text replacement     │ Fixed values     │ Type aliasing    │
│                 │                      │                  │                  │
│ Data Type       │ None (text)          │ Required         │ Required         │
│                 │                      │                  │                  │
│ Memory          │ Not allocated        │ Allocated        │ No extra memory  │
│                 │                      │                  │                  │
│ Scope           │ Global (always)      │ Respects scope   │ Scope aware      │
│                 │                      │                  │                  │
│ Type Checking   │ None (risky)         │ Full checking    │ Type safe        │
│                 │                      │                  │                  │
│ Runtime         │ Replaced at compile  │ Variable access  │ No overhead      │
│                 │                      │                  │                  │
│ Can be unset    │ Yes (#undef)         │ No (fixed)       │ No               │
│                 │                      │                  │                  │
│ Use For         │ Conditional compile  │ Constants        │ Aliases          │
└─────────────────┴──────────────────────┴──────────────────┴──────────────────┘
```

### When to Use Each

```
┌──────────────────────────────────────────────────────────┐
│ Use MACROS when:                                         │
├──────────────────────────────────────────────────────────┤
│ • Conditional compilation (#ifdef DEBUG, etc.)          │
│ • Defining platform-specific code                       │
│ • Need zero runtime overhead                            │
│ • Creating configurable build-time values               │
│ • Define function-like replacements                     │
└──────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────┐
│ Use CONSTANTS when:                                      │
├──────────────────────────────────────────────────────────┤
│ • Defining mathematical constants (PI, GRAVITY)         │
│ • Need type safety and compiler checking                │
│ • Want scoped constant values                           │
│ • Using in arrays or pointers                           │
│ • Need readable error messages                          │
└──────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────┐
│ Use TYPEDEF when:                                        │
├──────────────────────────────────────────────────────────┤
│ • Creating aliases for complex types                     │
│ • Improving code readability                             │
│ • Making type changes easier (single place)              │
│ • Simplifying function pointer declarations              │
│ • Creating platform-independent type names               │
└──────────────────────────────────────────────────────────┘
```

### Practical Example

```cpp
// MACRO: Used for configuration that changes at compile time
#define DEBUG_MODE 1
#define MAX_BUFFER_SIZE 1024

// CONSTANT: Used for fixed mathematical/logical values
const float PI = 3.14159;
const int MAX_USERS = 100;

// TYPEDEF: Used to simplify type declarations
typedef unsigned long long ulonglong;
typedef int* IntPointer;
```

---

## 🔹 Best Practices Summary

```
┌──────────────────────────────────────────────────────────┐
│         Conditional & Type Definition Best Practices    │
├──────────────────────────────────────────────────────────┤
│ CONDITIONALS:                                            │
│ ✓ Use if-else for simple binary decisions               │
│ ✓ Use else-if for multiple mutually exclusive conditions│
│ ✓ Use switch for single variable with many values       │
│ ✓ Use ternary only for simple, readability reasons      │
│ ✓ Add "break" statements in every case block            │
│ ✓ Place most common conditions first for performance    │
│ ✗ Don't nest too many conditions (use functions instead)│
│ ✗ Don't forget the "break" in switch statements         │
│                                                         │
│ TYPE ALIASING:                                           │
│ ✓ Use UPPERCASE for typedef names (e.g., INT64)        │
│ ✓ Document why a typedef exists                         │
│ ✓ Use typedef for complex types (pointers, structs)    │
│ ✓ Use const for values that shouldn't change            │
│ ✗ Don't overuse typedef; keep code obvious              │
│ ✗ Don't typedef fundamental types unnecessarily         │
└──────────────────────────────────────────────────────────┘
```
