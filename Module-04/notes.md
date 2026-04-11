# DSA with C++ — Module 4 Notes

---

## 🔹 Introduction

This module covers **constants**, **macros**, **typecasting**, and **type conversions** in C++. These concepts are essential for writing safe, efficient, and maintainable code that handles different data types correctly.

---

## 🔹 Constants in C++

**Constants** are variables whose value cannot be changed after initialization. They provide a way to define fixed values that should remain unchanged throughout program execution.

### Basic Syntax

```cpp
const dataType constantName = value;  // Must be initialized
```

**Key Characteristics:**

```
┌─────────────────────────────────────────────────────────┐
│            Constants in C++                             │
├─────────────────────────────────────────────────────────┤
│ ✓ Must be initialized at declaration                    │
│ ✓ Value cannot be modified after initialization         │
│ ✓ Occupies memory space (unlike macros)                 │
│ ✓ Has a defined data type                               │
│ ✓ Scope follows normal variable rules                   │
│ ✓ Type-checked by compiler                              │
└─────────────────────────────────────────────────────────┘
```

### Constant Declaration Rules

```cpp
const int n = 25;              // ✓ Valid - initialized
const float PI = 3.14159;      // ✓ Valid

const int x;                   // ✗ Invalid - not initialized
x = 25;                        // ✗ Invalid - cannot be modified

const int year = 2025;
year = 2026;                   // Compiler Error: assignment of read-only variable
```

### Naming Convention

```
┌────────────────────────────────────────────────────────┐
│          Constant Naming Best Practice                 │
├────────────────────────────────────────────────────────┤
│ Use UPPERCASE with underscores for constants           │
│                                                        │
│ Examples:                                              │
│ const int MAX_SIZE = 100;                             │
│ const float GRAVITY = 9.8;                            │
│ const string DATABASE_URL = "localhost:5432";         │
│                                                        │
│ Benefits:                                              │
│ • Makes constants easily distinguishable               │
│ • Improves code readability                           │
│ • Follows industry standards                           │
└────────────────────────────────────────────────────────┘
```

### Advantages of Using Constants

```cpp
// Without constants - harder to maintain
int radius = 5;
double area = 3.14159 * radius * radius;

// With constants - clearer and maintainable
const float PI = 3.14159;
int radius = 5;
double area = PI * radius * radius;
```

**Benefits:**

- Makes code self-documenting
- Prevents accidental modification
- Easy to update values in one place
- Compiler can optimize better

**Illustration file:** [a.cpp](a.cpp)

---

## 🔹 Constants vs Macros

Both constants and macros store fixed values, but they work fundamentally differently. Understanding the difference is crucial for writing efficient code.

### Detailed Comparison

```
┌──────────────────┬──────────────────────────┬──────────────────────────┐
│ Feature          │ Constants                │ Macros                   │
├──────────────────┼──────────────────────────┼──────────────────────────┤
│ Declaration      │ const dataType VAR;      │ #define NAME value       │
│                  │                          │                          │
│ Data Type        │ Required (int, float)    │ None (text replacement)  │
│                  │                          │                          │
│ Memory           │ Occupies memory          │ No memory allocated      │
│                  │                          │                          │
│ Scope            │ Follows variable scope   │ Global scope always      │
│                  │ (block, function, etc.)  │                          │
│                  │                          │                          │
│ Compiler Checks  │ Type-checked             │ No type checking         │
│                  │ Compile time errors      │ Simple text replacement  │
│                  │                          │                          │
│ Runtime          │ Real variable            │ Replaced before compile  │
│                  │                          │                          │
│ Performance      │ Slight overhead          │ Zero overhead            │
│                  │                          │                          │
│ Usage            │ Declare constants        │ Define macros for        │
│                  │                          │ conditional compilation  │
└──────────────────┴──────────────────────────┴──────────────────────────┘
```

### Code Comparison

**Using Constants:**

```cpp
#include <iostream>
using namespace std;

int main() {
    const int MAX_USERS = 100;
    const float DISCOUNT = 0.10;

    cout << MAX_USERS << " " << DISCOUNT << endl;
    // MAX_USERS = 200;  // ✗ Error: cannot be modified

    return 0;
}
```

**Using Macros:**

```cpp
#include <iostream>
#define MAX_USERS 100
#define DISCOUNT 0.10
using namespace std;

int main() {
    cout << MAX_USERS << " " << DISCOUNT << endl;
    // Note: MAX_USERS is replaced with 100 during preprocessing

    return 0;
}
```

### When to Use Each

```
┌──────────────────────────────────────────────────────────────┐
│ Use CONSTANTS when:                                          │
├──────────────────────────────────────────────────────────────┤
│ • Storing mathematical constants (PI, GRAVITY, etc.)         │
│ • Defining limits within a scope (MAX_SIZE in a function)    │
│ • Need type safety and compiler error checking               │
│ • Need scoped constants (different values per scope)         │
│ • Using in arrays or with pointers                           │
│ • Want readable error messages                               │
└──────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────┐
│ Use MACROS when:                                             │
├──────────────────────────────────────────────────────────────┤
│ • Conditional compilation (#ifdef/#ifndef/#endif)           │
│ • Debug mode vs Release mode toggling                        │
│ • Platform-specific code                                     │
│ • Need zero runtime overhead                                 │
│ • Define function-like macros                                │
└──────────────────────────────────────────────────────────────┘
```

**Illustration file:** [b.cpp](b.cpp) - Advanced constant examples

---

## 🔹 Type Casting in C++

**Type casting** (or type conversion) is the process of converting a value from one data type to another.

### Two Types of Type Casting

```
                    Type Casting
                        │
            ┌───────────┴───────────┐
            │                       │
      Implicit Casting        Explicit Casting
    (Automatic/Promotion)   (Manual/Forced)
```

---

## 🔹 1. Implicit Type Casting (Automatic)

The compiler **automatically** converts one data type to another to prevent data loss. This is also called **type promotion**.

### Type Promotion Hierarchy

```
┌──────────────────────────────────────────────────────┐
│  Type Promotion Order (Smallest → Largest)           │
├──────────────────────────────────────────────────────┤
│                                                      │
│  bool  →  char  →  int  →  long  →  float  →  double
│                                                      │
│  (1 byte) (1 byte) (4 bytes) (8 bytes) ... (8 bytes)│
└──────────────────────────────────────────────────────┘
```

### How Implicit Casting Works

**Rule:** When mixing different data types in an operation, the smaller type is promoted to the larger type to avoid data loss.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Example 1: char + int = int
    char c = 'A';           // ASCII value: 65
    int num = 5;
    int result = c + num;   // 'A' is promoted to int
    cout << result << endl; // Output: 70

    // Example 2: int + float = float
    int x = 10;
    float y = 3.5;
    float answer = x + y;   // 10 is promoted to 10.0
    cout << answer << endl; // Output: 13.5

    // Example 3: bool + int = int
    bool flag = true;       // true = 1
    int value = 5;
    int sum = flag + value; // true promoted to 1
    cout << sum << endl;    // Output: 6

    return 0;
}
```

### Implicit Conversion Rules

```
┌──────────────────────────────────────────────────────────┐
│              Implicit Conversion Rules                   │
├──────────────────────────────────────────────────────────┤
│ 1. bool → char (false=0, true=1)                        │
│ 2. char → int (ASCII value)                             │
│ 3. int → float (10 becomes 10.0)                        │
│ 4. float → double (increases precision)                 │
│ 5. int → double (combines 3 & 4)                        │
│                                                         │
│ No data loss in these promotions                        │
│ (Direction is always: smaller → larger data type)       │
└──────────────────────────────────────────────────────────┘
```

**Illustration file:** [c.cpp](c.cpp) - Implicit casting examples

---

## 🔹 2. Explicit Type Casting (Manual)

The programmer **forcefully** converts one data type to another using explicit syntax. This is also called **type coercion**.

### Syntax

```cpp
(desiredType)value                    // C-style casting
staticCast<desiredType>(value)        // C++ style (recommended)
```

### Explicit Casting Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    // Example 1: double to int (loses decimal part)
    double pi = 3.14159;
    int result = (int)pi;           // Truncates to 3
    cout << result << endl;         // Output: 3

    // Example 2: int to char (gets ASCII character)
    int ascii_value = 65;
    char letter = (char)ascii_value; // Converts to 'A'
    cout << letter << endl;         // Output: A

    // Example 3: char to int (gets ASCII value)
    char ch = 'A';
    int value = (int)ch;            // Converts to 65
    cout << value << endl;          // Output: 65

    // Example 4: float to int (loses decimal)
    float height = 5.7;
    int feet = (int)height;         // Becomes 5
    cout << feet << endl;           // Output: 5

    return 0;
}
```

### Data Loss Warning

```
⚠️  IMPORTANT: Explicit casting can cause DATA LOSS
┌──────────────────────────────────────────────────────┐
│                                                      │
│ Larger Data Type  →  Smaller Data Type = DATA LOSS  │
│                                                      │
│ Examples:                                            │
│ • double 3.9  → (int) = 3      (loses .9)           │
│ • long 65000  → (short) = ?    (overflow)           │
│ • float 12.5  → (int) = 12     (loses .5)           │
│                                                      │
│ Always be careful with explicit casting!            │
└──────────────────────────────────────────────────────┘
```

**Illustration file:** [d.cpp](d.cpp) - Explicit casting examples

---

## 🔹 Boolean Type Conversion

Converting values to boolean type follows a specific rule:

### Conversion Rules

```
┌──────────────────────────────────────────────────────┐
│         Non-Boolean → Boolean Conversion             │
├──────────────────────────────────────────────────────┤
│ bool(0)              → false                         │
│ bool(any other value)→ true                          │
│ bool(-5)             → true                          │
│ bool(1)              → true                          │
│ bool(100)            → true                          │
│ bool("")             → false (empty string)          │
│ bool("text")         → true  (non-empty string)      │
└──────────────────────────────────────────────────────┘
```

### Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << boolalpha; // Display bools as true/false instead of 1/0

    cout << bool(0) << endl;      // Output: false
    cout << bool(1) << endl;      // Output: true
    cout << bool(5) << endl;      // Output: true
    cout << bool(-10) << endl;    // Output: true
    cout << bool(NULL) << endl;   // Output: false

    return 0;
}
```

---

## 🔹 ASCII Values and Character Conversion

**ASCII (American Standard Code for Information Interchange)** assigns numerical values to characters.

### Common ASCII Values

```
┌──────────────┬──────────────┬──────────────┐
│ Character    │ ASCII Value  │ Character    │
├──────────────┼──────────────┼──────────────┤
│ Space        │ 32           │ '0'-'9'      │
│ '0'          │ 48           │ 48-57        │
│ '9'          │ 57           │ '0'-'9'      │
│ 'A'          │ 65           │ 'A'-'Z'      │
│ 'Z'          │ 90           │ Uppercase    │
│ 'a'          │ 97           │ 'a'-'z'      │
│ 'z'          │ 122          │ Lowercase    │
└──────────────┴──────────────┴──────────────┘

Quick Reference:
• Uppercase letters:  'A' = 65,  'B' = 66,  ... 'Z' = 90
• Lowercase letters:  'a' = 97,  'b' = 98,  ... 'z' = 122
• Digits:            '0' = 48,  '1' = 49,  ... '9' = 57
```

### ASCII Character Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    // Char to ASCII value
    char ch1 = 'A';
    cout << (int)ch1 << endl;   // Output: 65

    char ch2 = 'a';
    cout << (int)ch2 << endl;   // Output: 97

    char ch3 = '5';
    cout << (int)ch3 << endl;   // Output: 53 (NOT 5)

    // ASCII value to Char
    int ascii = 66;
    cout << (char)ascii << endl; // Output: B

    ascii = 122;
    cout << (char)ascii << endl; // Output: z

    // Difference between characters
    cout << (int)'B' - (int)'A' << endl;  // Output: 1
    cout << (int)'z' - (int)'a' << endl;  // Output: 0

    return 0;
}
```

### Useful ASCII Tricks

```cpp
// Convert lowercase to uppercase
char lower = 'c';
char upper = (char)((int)lower - 32);  // or lower - 'a' + 'A'
cout << upper << endl; // Output: C

// Convert uppercase to lowercase
char up = 'C';
char low = (char)((int)up + 32);
cout << low << endl; // Output: c

// Check if character is digit (without using isdigit())
char digit = '5';
if ((int)digit >= 48 && (int)digit <= 57)
    cout << "Is a digit" << endl;

// Check if character is uppercase
char letter = 'A';
if ((int)letter >= 65 && (int)letter <= 90)
    cout << "Is uppercase" << endl;
```

---

## 🔹 Common Type Conversion Scenarios

```
┌────────────────────────────────────────────────────────┐
│           Type Conversion Reference Guide              │
├──────────┬──────────────┬────────────────────────────┤
│ From     │ To           │ Method & Example           │
├──────────┼──────────────┼────────────────────────────┤
│ int      │ float        │ (float)num or num * 1.0    │
│          │              │ (int)10 → 10.0             │
├──────────┼──────────────┼────────────────────────────┤
│ float    │ int          │ (int)num                   │
│          │              │ (int)3.9 → 3 (truncates)  │
├──────────┼──────────────┼────────────────────────────┤
│ char     │ int          │ (int)ch                    │
│          │              │ (int)'A' → 65              │
├──────────┼──────────────┼────────────────────────────┤
│ int      │ char         │ (char)num                  │
│          │              │ (char)65 → 'A'             │
├──────────┼──────────────┼────────────────────────────┤
│ bool     │ int          │ (int)flag                  │
│          │              │ (int)true → 1              │
├──────────┼──────────────┼────────────────────────────┤
│ int      │ bool         │ (bool)num                  │
│          │              │ (bool)0 → false            │
│          │              │ (bool)5 → true             │
└──────────┴──────────────┴────────────────────────────┘
```

**Practice Illustration file:** [e.cpp](e.cpp) - Mixed typecasting scenarios

---

## 🔹 Best Practices for Constants and Type Casting

```
┌──────────────────────────────────────────────────────────┐
│             Constants & Type Casting Best Practices      │
├──────────────────────────────────────────────────────────┤
│ CONSTANTS:                                               │
│ ✓ Use const for values that shouldn't change             │
│ ✓ Use UPPERCASE naming for constants                     │
│ ✓ Initialize all constants at declaration                │
│ ✗ Don't use #define for simple constants                 │
│ ✗ Don't modify constants (compiler prevents this)        │
│                                                          │
│ TYPE CASTING:                                            │
│ ✓ Prefer implicit casting when possible (no data loss)  │
│ ✓ Use explicit casting only when necessary               │
│ ✓ Be aware of data loss when downcasting                 │
│ ✓ Use boolalpha to display bools as true/false           │
│ ✗ Don't cast without understanding the consequences      │
│ ✗ Don't assume results; verify type conversions          │
└──────────────────────────────────────────────────────────┘
```

---

## 🔹 Key Takeaways

**Constants:**

- Declared with `const` keyword, value cannot be changed
- Must be initialized at declaration
- Use UPPERCASE naming convention
- Type-safe, occupies memory

**Constants vs Macros:**

- Constants: typed, scoped, compiler-checked
- Macros: text replacement, global scope, no type

**Implicit Type Casting:**

- Automatic promotion by compiler
- Prevents data loss (always to larger type)
- Order: bool → char → int → float → double

**Explicit Type Casting:**

- Forced conversion by programmer
- Syntax: `(type)value`
- Can cause data loss when downcasting

**Boolean Conversion:**

- 0 → false, anything else → true
- Use `boolalpha` for readable boolean output

**ASCII Values:**

- A-Z: 65-90, a-z: 97-122, 0-9: 48-57
- Convert between char and ASCII value using casting

**Golden Rule:** Prefer constants over macros and implicit over explicit casting unless you have specific reasons otherwise.

---
