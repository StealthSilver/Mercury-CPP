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

## 🔹 Operators in C++

**Operators** are symbols that perform operations on variables and values. C++ provides various types of operators to manipulate data and make logical decisions.

```
┌─────────────────────────────────────┐
│      Types of Operators in C++       │
├─────────────────────────────────────┤
│ 1. Arithmetic Operators             │
│ 2. Assignment Operators             │
│ 3. Relational Operators             │
│ 4. Logical Operators                │
│ 5. Bitwise Operators                │
└─────────────────────────────────────┘
```

---

## 🔹 1. Arithmetic Operators

**Arithmetic operators** perform mathematical calculations on numeric values. They are divided into two categories: **binary** (require 2 operands) and **unary** (require 1 operand).

### Binary Arithmetic Operators

These operators work on two operands.

```
┌─────────────────────────────────────────────────────────┐
│         Binary Arithmetic Operators                     │
├──────────┬─────────────┬──────────────────────────────┤
│ Operator │ Name        │ Description & Example        │
├──────────┼─────────────┼──────────────────────────────┤
│ +        │ Addition    │ Adds two operands            │
│          │             │ 10 + 5 = 15                  │
├──────────┼─────────────┼──────────────────────────────┤
│ -        │ Subtraction │ Subtracts second from first  │
│          │             │ 10 - 5 = 5                   │
├──────────┼─────────────┼──────────────────────────────┤
│ *        │ Multiply    │ Multiplies two operands      │
│          │             │ 10 * 5 = 50                  │
├──────────┼─────────────┼──────────────────────────────┤
│ /        │ Division    │ Divides first by second      │
│          │             │ 10 / 5 = 2                   │
│          │             │ Note: 10 / 3 = 3 (int div)   │
├──────────┼─────────────┼──────────────────────────────┤
│ %        │ Modulus     │ Remainder after division     │
│          │             │ 10 % 3 = 1                   │
│          │             │ Only works with integers     │
└──────────┴─────────────┴──────────────────────────────┘
```

### Binary Arithmetic Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 20, b = 8;

    cout << "a + b = " << a + b << endl;  // 28
    cout << "a - b = " << a - b << endl;  // 12
    cout << "a * b = " << a * b << endl;  // 160
    cout << "a / b = " << a / b << endl;  // 2 (integer division)
    cout << "a % b = " << a % b << endl;  // 4

    return 0;
}
```

**Important Notes on Division:**

- Integer division truncates (removes) the decimal part
- `10 / 3 = 3` (not 3.33)
- For floating-point division, use: `10.0 / 3 = 3.333...`
- Modulus (%) only works with integers

**Illustration file:** [f.cpp](f.cpp) - Binary arithmetic operators

---

### Unary Arithmetic Operators

These operators work on a single operand: **increment (++)** and **decrement (--)**.

```
┌──────────────────────────────────────────────────────┐
│         Unary Arithmetic Operators                   │
├────────────┬──────────────────────────────────────┤
│ Operator   │ Name                                 │
├────────────┼──────────────────────────────────────┤
│ ++         │ Increment (increases by 1)           │
│ --         │ Decrement (decreases by 1)           │
└────────────┴──────────────────────────────────────┘
```

### Pre-increment vs Post-increment

The order matters! There are TWO ways to use increment/decrement:

```
┌─────────────────────────────────────────────────────────┐
│         Pre-increment vs Post-increment                 │
├────────────────┬────────────────────────────────────────┤
│ Pre-increment  │ ++a (Update FIRST, then use)           │
│ (prefix)       │ Updates value, then returns new value  │
├────────────────┼────────────────────────────────────────┤
│ Post-increment │ a++ (Use FIRST, then update)           │
│ (postfix)      │ Returns old value, then updates        │
└────────────────┴────────────────────────────────────────┘
```

### Pre-increment vs Post-increment Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;

    // Pre-increment: ++a
    int result1 = ++a;  // a becomes 6, then result1 = 6
    cout << "++a: a = " << a << ", result = " << result1 << endl;
    // Output: ++a: a = 6, result = 6

    // Reset for comparison
    a = 5;

    // Post-increment: a++
    int result2 = a++;  // result2 = 5, then a becomes 6
    cout << "a++: a = " << a << ", result = " << result2 << endl;
    // Output: a++: a = 6, result = 5

    // Pre-decrement: --a
    int b = 10;
    int result3 = --b;  // b becomes 9, then result3 = 9
    cout << "--b: b = " << b << ", result = " << result3 << endl;
    // Output: --b: b = 9, result = 9

    // Post-decrement: b--
    b = 10;
    int result4 = b--;  // result4 = 10, then b becomes 9
    cout << "b--: b = " << b << ", result = " << result4 << endl;
    // Output: b--: b = 9, result = 10

    return 0;
}
```

### Key Difference Summary

```cpp
int x = 5;
cout << ++x << endl;  // Output: 6  (x is incremented first)
cout << x << endl;    // Output: 6

int y = 5;
cout << y++ << endl;  // Output: 5  (uses old value first)
cout << y << endl;    // Output: 6  (now it's incremented)
```

**Performance Note:** In loops, prefer `++i` over `i++` as post-increment creates a temporary copy:

```cpp
// Preferred (slightly faster)
for (int i = 0; i < 10; ++i) { }

// Less efficient (creates temporary)
for (int i = 0; i < 10; i++) { }
```

**Illustration files:** [g.cpp](g.cpp) - Basic unary operators | [h.cpp](h.cpp) - Pre vs Post increment/decrement

---

## 🔹 2. Assignment Operators

**Assignment operators** assign values to variables. The basic assignment operator is `=`, and there are compound assignment operators that combine assignment with other operations.

### Assignment Operators Table

```
┌────────────┬──────────────────┬──────────────────────────┐
│ Operator   │ Equivalent To     │ Example                  │
├────────────┼──────────────────┼──────────────────────────┤
│ =          │ Assign directly   │ a = 10;  // a = 10       │
├────────────┼──────────────────┼──────────────────────────┤
│ +=         │ a = a + b         │ a += 5;  // a = a + 5    │
├────────────┼──────────────────┼──────────────────────────┤
│ -=         │ a = a - b         │ a -= 5;  // a = a - 5    │
├────────────┼──────────────────┼──────────────────────────┤
│ *=         │ a = a * b         │ a *= 5;  // a = a * 5    │
├────────────┼──────────────────┼──────────────────────────┤
│ /=         │ a = a / b         │ a /= 5;  // a = a / 5    │
├────────────┼──────────────────┼──────────────────────────┤
│ %=         │ a = a % b         │ a %= 5;  // a = a % 5    │
└────────────┴──────────────────┴──────────────────────────┘
```

### Assignment Operators Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    // Simple assignment
    a = 5;
    cout << "a = 5; // a = " << a << endl;  // 5

    // Compound addition
    a += 3;              // a = a + 3
    cout << "a += 3; // a = " << a << endl;  // 8

    // Compound subtraction
    a -= 2;              // a = a - 2
    cout << "a -= 2; // a = " << a << endl;  // 6

    // Compound multiplication
    a *= 2;              // a = a * 2
    cout << "a *= 2; // a = " << a << endl;  // 12

    // Compound division
    a /= 3;              // a = a / 3
    cout << "a /= 3; // a = " << a << endl;  // 4

    // Compound modulus
    a %= 3;              // a = a % 3
    cout << "a %= 3; // a = " << a << endl;  // 1

    return 0;
}
```

### Advantages of Compound Assignment

```cpp
// Less efficient (longer to write)
count = count + 1;
total = total + amount;
product = product * factor;

// More efficient (cleaner and faster to write)
count += 1;
total += amount;
product *= factor;
```

**Illustration file:** [i.cpp](i.cpp) - Assignment operators

---

## 🔹 3. Relational Operators

**Relational operators** compare two values and return a **boolean result** (true or false, represented as 1 or 0 in C++).

### Relational Operators Table

```
┌────────────┬────────────────────────┬──────────────────────┐
│ Operator   │ Name                   │ Example              │
├────────────┼────────────────────────┼──────────────────────┤
│ >          │ Greater than           │ a > b                │
├────────────┼────────────────────────┼──────────────────────┤
│ <          │ Less than              │ a < b                │
├────────────┼────────────────────────┼──────────────────────┤
│ >=         │ Greater than or equal  │ a >= b               │
├────────────┼────────────────────────┼──────────────────────┤
│ <=         │ Less than or equal     │ a <= b               │
├────────────┼────────────────────────┼──────────────────────┤
│ ==         │ Equal to               │ a == b               │
├────────────┼────────────────────────┼──────────────────────┤
│ !=         │ Not equal to           │ a != b               │
└────────────┴────────────────────────┴──────────────────────┘
```

### Relational Operators Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 5;

    cout << boolalpha;  // Display true/false instead of 1/0

    cout << "a > b:  " << (a > b) << endl;   // true
    cout << "a < b:  " << (a < b) << endl;   // false
    cout << "a >= 10: " << (a >= 10) << endl; // true
    cout << "a <= b:  " << (a <= b) << endl;  // false
    cout << "a == 10: " << (a == 10) << endl; // true
    cout << "a != b:  " << (a != b) << endl;  // true

    return 0;
}
```

### Important Note: == vs =

```cpp
❌ COMMON MISTAKE:
if (a = 5)      // This ASSIGNS 5 to a, doesn't compare!
{
    cout << "This will always execute";
}

✓ CORRECT:
if (a == 5)     // This COMPARES a with 5
{
    cout << "Executes only if a equals 5";
}
```

**Key Rules:**

- Single `=` is assignment (changes value)
- Double `==` is comparison (checks if values are equal)
- Relational operators always return boolean (0 for false, 1 for true)
- Use `boolalpha` to display true/false instead of 1/0

**Illustration file:** [j.cpp](j.cpp) - Relational operators

---

## 🔹 4. Logical Operators

**Logical operators** combine boolean expressions and create more complex conditions. They return a **boolean result** (true or false).

### Logical Operators Table

```
┌────────────┬─────────────┬────────────────┬────────────────────┐
│ Operator   │ Name        │ Type           │ Description        │
├────────────┼─────────────┼────────────────┼────────────────────┤
│ &&         │ AND         │ Binary         │ ALL conditions     │
│            │             │ (2 operands)   │ must be true       │
├────────────┼─────────────┼────────────────┼────────────────────┤
│ ||         │ OR          │ Binary         │ At least ONE       │
│            │             │ (2 operands)   │ condition must     │
│            │             │                │ be true            │
├────────────┼─────────────┼────────────────┼────────────────────┤
│ !          │ NOT         │ Unary          │ Reverses the       │
│            │             │ (1 operand)    │ boolean value      │
└────────────┴─────────────┴────────────────┴────────────────────┘
```

### Logical AND (&&)

Returns **true** only if BOTH conditions are true.

```
┌──────────┬──────────┬─────────────┐
│ Cond 1   │ Cond 2   │ Cond1 && Cond2 │
├──────────┼──────────┼─────────────┤
│ true     │ true     │ true            │
│ true     │ false    │ false           │
│ false    │ true     │ false           │
│ false    │ false    │ false           │
└──────────┴──────────┴─────────────┘
```

**Example:**

```cpp
int age = 25;
bool hasLicense = true;

if (age >= 18 && hasLicense) {
    cout << "Can drive" << endl;  // Executes: both true
}

if (age >= 30 && hasLicense) {
    cout << "Can rent a car" << endl;  // Doesn't execute: first false
}
```

### Logical OR (||)

Returns **true** if AT LEAST ONE condition is true.

```
┌──────────┬──────────┬─────────────┐
│ Cond 1   │ Cond 2   │ Cond1 || Cond2 │
├──────────┼──────────┼─────────────┤
│ true     │ true     │ true            │
│ true     │ false    │ true            │
│ false    │ true     │ true            │
│ false    │ false    │ false           │
└──────────┴──────────┴─────────────┘
```

**Example:**

```cpp
int marks = 45;
bool isDisabled = true;

if (marks >= 40 || isDisabled) {
    cout << "Pass" << endl;  // Executes: second condition true
}

if (marks >= 90 || marks >= 80) {
    cout << "Grade A or B" << endl;  // Doesn't execute: both false
}
```

### Logical NOT (!)

Reverses the boolean value.

```
┌──────────┬────────────┐
│ Condition│ !Condition │
├──────────┼────────────┤
│ true     │ false      │
│ false    │ true       │
└──────────┴────────────┘
```

**Example:**

```cpp
bool flag = true;
cout << !flag << endl;  // Output: false

int x = 5;
if (!(x > 10)) {
    cout << "x is not greater than 10" << endl;  // Executes
}

bool isEmpty = false;
if (!isEmpty) {
    cout << "Container has items" << endl;  // Executes
}
```

### Logical Operators Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 75;
    int attendance = 85;

    cout << boolalpha;

    // AND - both conditions must be true
    cout << (marks >= 50 && attendance >= 75) << endl;  // true
    cout << (marks >= 50 && attendance >= 90) << endl;  // false

    // OR - at least one condition must be true
    cout << (marks >= 90 || attendance >= 75) << endl;  // true
    cout << (marks >= 90 || attendance >= 90) << endl;  // false

    // NOT - reverses the condition
    cout << !(marks < 50) << endl;   // true
    cout << !(marks > 100) << endl;  // true

    // Complex expression
    if ((marks >= 60 && attendance >= 75) || marks >= 90) {
        cout << "Student passes" << endl;  // Executes
    }

    return 0;
}
```

**Short-circuit Evaluation:**

```cpp
// AND (&&): Stops evaluating if first condition is false
if (false && expensiveFunction()) {
    // expensiveFunction() is NOT called (short-circuit)
}

// OR (||): Stops evaluating if first condition is true
if (true || expensiveFunction()) {
    // expensiveFunction() is NOT called (short-circuit)
}
```

**Illustration file:** [k.cpp](k.cpp) - Logical operators

---

## 🔹 5. Bitwise Operators

**Bitwise operators** perform operations on individual bits of integers. They work at the binary level and are useful for optimization and low-level programming.

### Bitwise Operators Table

```
┌──────────┬──────────────────┬────────────────┬─────────────────┐
│ Operator │ Name             │ Type           │ Description     │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ &        │ AND              │ Binary         │ Both bits = 1   │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ |        │ OR               │ Binary         │ Any bit = 1     │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ ^        │ XOR              │ Binary         │ Different bits  │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ ~        │ NOT              │ Unary          │ Flip all bits   │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ <<       │ Left shift       │ Binary         │ Shift bits left │
├──────────┼──────────────────┼────────────────┼─────────────────┤
│ >>       │ Right shift      │ Binary         │ Shift bits right│
└──────────┴──────────────────┴────────────────┴─────────────────┘
```

### Bitwise AND (&)

Compares each bit; result is 1 only if BOTH bits are 1.

```cpp
  5:     0101
  3:     0011
     -------
   &:     0001   (= 1)
```

### Bitwise OR (|)

Compares each bit; result is 1 if ANY bit is 1.

```cpp
  5:     0101
  3:     0011
     -------
   |:     0111   (= 7)
```

### Bitwise XOR (^)

Compares each bit; result is 1 if bits are DIFFERENT.

```cpp
  5:     0101
  3:     0011
     -------
   ^:     0110   (= 6)
```

### Bitwise NOT (~)

Flips all bits (1 becomes 0, 0 becomes 1).

```cpp
  5:     00000101
     -----------
  ~:     11111010   (for 8-bit: = 250 or -6 in signed)
```

### Bitwise Shift Operators

**Left Shift (<<):** Shifts bits left, fills right with 0s. Each shift multiplies by 2.

```cpp
  5:         00000101
  5 << 1:    00001010   (= 10)
  5 << 2:    00010100   (= 20)
```

**Right Shift (>>):** Shifts bits right, fills left with 0s or sign bit. Each shift divides by 2.

```cpp
  5:         00000101
  5 >> 1:    00000010   (= 2)
  5 >> 2:    00000001   (= 1)
```

### Bitwise Operators Examples

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;      // 0101 in binary
    int b = 3;      // 0011 in binary

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;   // 0001 = 1
    cout << "a | b = " << (a | b) << endl;   // 0111 = 7
    cout << "a ^ b = " << (a ^ b) << endl;   // 0110 = 6
    cout << "~a = " << (~a) << endl;         // Flips all bits
    cout << "a << 1 = " << (a << 1) << endl; // 1010 = 10
    cout << "a >> 1 = " << (a >> 1) << endl; // 0010 = 2

    return 0;
}
```

### Common Bitwise Use Cases

```cpp
// Check if a number is power of 2
bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Check if bit at position i is set
bool isBitSet(int num, int i) {
    return (num & (1 << i)) != 0;
}

// Set bit at position i
int setBit(int num, int i) {
    return num | (1 << i);
}

// Clear bit at position i
int clearBit(int num, int i) {
    return num & ~(1 << i);
}

// Toggle bit at position i
int toggleBit(int num, int i) {
    return num ^ (1 << i);
}
```

**Note:** Bitwise operators are primarily used in:

- Low-level system programming
- Competitive programming optimization
- Graphics and game development
- Set operations and flags
- Performance-critical code

---

## 🔹 Operator Precedence and Associativity

**Operator precedence** determines the order in which operators are evaluated in an expression. **Associativity** determines the direction of evaluation when operators have the same precedence (left-to-right or right-to-left).

### Complete Operator Precedence Table

```
┌─────┬──────────────────────────┬────────────────┬────────────────────────┐
│ Lvl │ Operators                │ Type           │ Associativity          │
├─────┼──────────────────────────┼────────────────┼────────────────────────┤
│  1  │ :: (scope resolution)    │ Left-to-Right  │ Not used in basics      │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  2  │ ()  [] . -> ++ --        │ Left-to-Right  │ Parentheses, brackets, │
│     │ (Parentheses, Brackets)  │                │ postfix ++/--          │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  3  │ ! ~ + - ++ -- (unary)    │ Right-to-Left  │ NOT, Bitwise NOT,      │
│     │ & * (unary) sizeof       │                │ unary +/-, prefix ++/--│
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  4  │ * / %                    │ Left-to-Right  │ Multiply, Divide,      │
│     │ (Multiply, Divide, Mod)  │                │ Modulus                │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  5  │ + -                      │ Left-to-Right  │ Addition, Subtraction  │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  6  │ << >>                    │ Left-to-Right  │ Bitwise Left/Right     │
│     │ (Bitwise shifts)         │                │ Shift                  │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  7  │ < <= > >=                │ Left-to-Right  │ Relational operators   │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  8  │ == !=                    │ Left-to-Right  │ Equality operators     │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│  9  │ &                        │ Left-to-Right  │ Bitwise AND            │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 10  │ ^                        │ Left-to-Right  │ Bitwise XOR            │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 11  │ |                        │ Left-to-Right  │ Bitwise OR             │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 12  │ &&                       │ Left-to-Right  │ Logical AND            │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 13  │ ||                       │ Left-to-Right  │ Logical OR             │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 14  │ ?:                       │ Right-to-Left  │ Ternary conditional    │
│ ────┼──────────────────────────┼────────────────┼────────────────────────┤
│ 15  │ = += -= *= /= %=         │ Right-to-Left  │ Assignment operators   │
│     │ &= ^= |= <<= >>=         │                │ (lowest priority)      │
└─────┴──────────────────────────┴────────────────┴────────────────────────┘
```

**Legend:** Level 1 = Highest Priority | Level 15 = Lowest Priority

### Understanding Associativity

**Left-to-Right Associativity** (most operators):

```cpp
// Evaluated LEFT to RIGHT
int a = 10 - 5 - 2;
// (10 - 5) - 2 = 5 - 2 = 3 ✓ Correct
// NOT: 10 - (5 - 2) = 10 - 3 = 7 ✗ Wrong
```

**Right-to-Left Associativity** (assignment, unary, ternary):

```cpp
// Evaluated RIGHT to LEFT
int a = 5, b = 3, c = 1;
a = b = c;
// Evaluated as: a = (b = c)
// First: b = 1
// Then: a = 1
// Result: a = 1, b = 1, c = 1 ✓ Correct
```

### Comprehensive Precedence Examples

**Example 1: Arithmetic Operators**

```cpp
int result = 5 + 3 * 2 - 8 / 4;
//            5 + (3*2) - (8/4)   [* and / first, left-to-right]
//            5 + 6 - 2            [+ and - next, left-to-right]
//            11 - 2
//            = 9
```

**Example 2: Relational and Logical**

```cpp
bool check = 5 > 3 && 2 < 4 || 1 == 1;
//           (5 > 3) && (2 < 4) || (1 == 1)   [relational first]
//           true && true || true              [&& before ||]
//           true || true
//           = true
```

**Example 3: Bitwise vs Logical**

```cpp
int a = 5 | 3 ^ 2 & 1;
//       5 | (3 ^ (2 & 1))   [& has higher precedence than ^ and |]
//       5 | (3 ^ 0)
//       5 | 3
//       = 7
```

**Example 4: Assignment Associativity**

```cpp
int x, y, z;
x = y = z = 10;  // Right-to-Left
// Evaluated as: x = (y = (z = 10))
// z = 10
// y = 10
// x = 10
// All three variables are now 10
```

**Example 5: Mix of Operators**

```cpp
int result = 2 + 3 * 4 - 5 / 2 % 3;
//            2 + (3*4) - ((5/2)%3)  [*,/,% first]
//            2 + 12 - (2%3)
//            2 + 12 - 2
//            14 - 2
//            = 12
```

### Operator Precedence Quick Reference

```
┌─────────────────────────────────────────────────────────────┐
│              Operator Precedence Shortcuts                  │
├─────────────────────────────────────────────────────────────┤
│ 1. Parentheses: () always evaluated first                  │
│ 2. Unary: ! ~ + - ++ -- (right-to-left)                   │
│ 3. Multiply/Divide: * / % (left-to-right)                 │
│ 4. Add/Subtract: + - (left-to-right)                      │
│ 5. Bitwise Shifts: << >> (left-to-right)                  │
│ 6. Relational: < <= > >= (left-to-right)                  │
│ 7. Equality: == != (left-to-right)                        │
│ 8. Bitwise: & then ^ then | (left-to-right)               │
│ 9. Logical: && then || (left-to-right)                    │
│ 10. Ternary: ?: (right-to-left)                           │
│ 11. Assignment: = += -= etc (right-to-left)               │
└─────────────────────────────────────────────────────────────┘
```

### Common Precedence Mistakes

```cpp
// ❌ MISTAKE 1: Forgetting logical AND has higher precedence than OR
bool result = false || true && false;  // true (not false!)
// Evaluated as: false || (true && false) = false || false = false
// BUT looks like it should be (false || true) && false = true && false = false

// ✓ CORRECT: Use parentheses to be explicit
bool result = (false || true) && false;  // false

// ❌ MISTAKE 2: Relational operators bind tighter than might seem
int a = 5;
if (a > 3 == true) { }  // Works but confusing!
// Evaluated as: (a > 3) == true = true == true = true

// ✓ CORRECT: Use parentheses
if ((a > 3) == true) { }

// ❌ MISTAKE 3: Bitwise operators have lower precedence than relational
int x = 5 & 3 < 2;  // true & 3 = 1 (not what intended!)
// Evaluated as: 5 & (3 < 2) = 5 & 0 = 0

// ✓ CORRECT: Use parentheses
int x = (5 & 3) < 2;  // (1) < 2 = true
```

### Best Practice: Use Parentheses

```cpp
// Without parentheses (hard to read, easy to make mistakes)
bool check = x > 5 && y < 10 || z == 0;

// With parentheses (clear intent and precedence)
bool check = ((x > 5) && (y < 10)) || (z == 0);

// Very clear (though slightly verbose)
bool hasGoodScore = (x > 5) && (y < 10);
bool isReset = (z == 0);
bool check = hasGoodScore || isReset;
```

**Golden Rule:** When in doubt, use parentheses! They make code self-documenting and prevent subtle bugs.

---

## 🔹 Best Practices for Operators

```
┌──────────────────────────────────────────────────────────┐
│           Operators Best Practices                       │
├──────────────────────────────────────────────────────────┤
│ ARITHMETIC:                                              │
│ ✓ Use ++ and -- for incrementing/decrementing           │
│ ✓ Prefer ++i over i++ in loops                          │
│ ✓ Check for division by zero                            │
│ ✓ Be careful with modulus on negative numbers           │
│                                                          │
│ ASSIGNMENT:                                              │
│ ✓ Use compound operators (+=, -=) for clarity           │
│ ✓ Remember: = is assignment, == is comparison           │
│                                                          │
│ RELATIONAL:                                              │
│ ✓ Always use == for comparison, never = in conditions   │
│ ✓ Use parentheses for complex conditions                │
│                                                          │
│ LOGICAL:                                                 │
│ ✓ Understand short-circuit evaluation                   │
│ ✓ Place most likely true conditions first               │
│ ✓ Use !isEmpty() instead of isEmpty == false            │
│                                                          │
│ BITWISE:                                                 │
│ ✓ Use only when necessary for optimization              │
│ ✓ Add comments explaining bit operations                │
│ ✗ Don't use for beginners without clear reason          │
└──────────────────────────────────────────────────────────┘
```

---

## 🔹 Key Takeaways

**Arithmetic Operators:**

- Binary: +, -, \*, /, %
- Unary: ++, -- (pre- and post-increment/decrement)
- Pre-increment more efficient in loops

**Assignment Operators:**

- Simple: `=`
- Compound: `+=`, `-=`, `*=`, `/=`, `%=`
- Remember: `=` assigns, `==` compares

**Relational Operators:**

- Return boolean (true/false)
- Used in conditions: >, <, >=, <=, ==, !=

**Logical Operators:**

- AND (&&): Both true
- OR (||): At least one true
- NOT (!): Reverses boolean
- Short-circuit evaluation for efficiency

**Bitwise Operators:**

- Work on individual bits
- &, |, ^, ~, <<, >>
- Used for low-level optimization and competitive programming

**General:**

- Use parentheses to clarify operator precedence
- Understand operator precedence to avoid mistakes
- Different context requires different operator types

---

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
