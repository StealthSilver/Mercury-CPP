# DSA with C++ — Module 3 Notes

---

## 🔹 Introduction

This module covers **output operations**, **variables**, **data types**, **comments**, and **input operations** in C++.

---

## 🔹 Output Operations in C++

### The cout Statement

- Part of `iostream` library and `std` namespace
- Uses `<<` insertion operator to send data to output stream
- Can chain multiple values
- Every statement ends with semicolon

**Basic Syntax:** `cout << "output";`

---

## 🔹 Printing Patterns

**Illustration files:** [a.cpp](a.cpp) | [b.cpp](b.cpp)

### Two Approaches

- **Single cout with `\n`** - More compact
- **Multiple cout statements** - More readable, easier to modify

---

## 🔹 New Line: \n vs endl

```
┌────────────────────────────────────────────────────────────┐
│             \n vs endl Comparison                          │
├────────────────────┬───────────────────────────────────────┤
│ \n                 │ • Escape sequence for new line        │
│                    │ • Does NOT flush buffer               │
│                    │ • Faster (5-10x)                      │
│                    │ • Preferred for competitive coding    │
├────────────────────┼───────────────────────────────────────┤
│ endl               │ • Adds newline + flushes buffer       │
│                    │ • Slower                              │
│                    │ • Better for debugging/interactive    │
└────────────────────┴───────────────────────────────────────┘
```

### When to Use Each

| Situation                 | Use    | Reason                        |
| ------------------------- | ------ | ----------------------------- |
| Competitive Programming   | `\n`   | Speed critical                |
| Large Output Operations   | `\n`   | Minimize overhead             |
| Debugging                 | `endl` | Ensures output appears        |
| Interactive Programs      | `endl` | User needs immediate feedback |
| General Learning/Practice | Either | Based on preference           |

---

## 🔹 Escape Sequences

Special character combinations beginning with backslash `\` for characters difficult to type directly.

```
┌──────────────┬──────────────────────────────────────┐
│ Sequence     │ Meaning                              │
├──────────────┼──────────────────────────────────────┤
│ \n           │ New line                             │
│ \t           │ Horizontal tab                       │
│ \\           │ Backslash                            │
│ \"           │ Double quote                         │
│ \'           │ Single quote                         │
│ \r           │ Carriage return                      │
│ \b           │ Backspace                            │
│ \0           │ Null character                       │
└──────────────┴──────────────────────────────────────┘
```

---

## 🔹 Variables in C++

**Variables** are named storage containers in memory (RAM) used to hold data during program execution.

### How Variables Work

```
┌──────────────────────────────────────────────────────────┐
│              Variable Memory Model                       │
├──────────────────────────────────────────────────────────┤
│   Declaration: int age = 25;                             │
│                                                          │
│   Variable Name: age                                     │
│          ↓                                               │
│   ┌─────────────────────────────┐                       │
│   │  RAM (Main Memory)          │                       │
│   │  Address: 0x7fff5fbff8c4    │ ← Memory Location    │
│   │  Value: 25                  │ ← Data Stored        │
│   │  Size: 4 bytes              │ ← Memory Allocated   │
│   └─────────────────────────────┘                       │
└──────────────────────────────────────────────────────────┘
```

### Key Characteristics

1. **Memory Allocation** - Each variable reserves memory based on data type
2. **Meaningful Names** - Variable names should describe stored data
3. **Initialization** - Always initialize; uninitialized variables contain garbage values

**Syntax:** `dataType variableName = value;`

**Illustration file:** [c.cpp](c.cpp)

---

## 🔹 Variable Naming Rules

```
┌──────────────────────────────────────────────────────────────┐
│           Variable Naming Rules (MANDATORY)                  │
├────────┬─────────────────────────────────────────────────────┤
│ Rule 1 │ Must start with letter (a-z, A-Z) or underscore (_) │
│        │ Cannot start with digit                             │
├────────┼─────────────────────────────────────────────────────┤
│ Rule 2 │ Can contain: letters, digits, underscore only       │
├────────┼─────────────────────────────────────────────────────┤
│ Rule 3 │ Cannot use C++ keywords (int, class, return, etc.)  │
├────────┼─────────────────────────────────────────────────────┤
│ Rule 4 │ Case-sensitive (age ≠ Age ≠ AGE)                   │
└────────┴─────────────────────────────────────────────────────┘
```

### Naming Conventions (Best Practices)

```
┌────────────────────┬──────────────────┬─────────────────────┐
│ Convention         │ Example          │ Use Case            │
├────────────────────┼──────────────────┼─────────────────────┤
│ camelCase          │ studentAge       │ Variables, functions│
│ snake_case         │ student_age      │ Variables           │
│ PascalCase         │ StudentAge       │ Classes             │
│ UPPER_SNAKE_CASE   │ MAX_VALUE        │ Constants           │
└────────────────────┴──────────────────┴─────────────────────┘
```

### Common C++ Keywords (Reserved - Cannot Use)

```
alignas    alignof    and        and_eq     asm        auto
bitand     bitor      bool       break      case       catch
char       char16_t   char32_t   class      compl      const
constexpr  continue   decltype   default    delete     do
double     else       enum       explicit   export     extern
false      float      for        friend     goto       if
inline     int        long       mutable    namespace  new
noexcept   not        not_eq     nullptr    operator   or
or_eq      private    protected  public     register   return
short      signed     sizeof     static     struct     switch
template   this       throw      true       try        typedef
typeid     typename   union      unsigned   using      virtual
void       volatile   while      xor        xor_eq
```

---

## 🔹 Data Types in C++

**Data types** define:

- Amount of memory allocated
- Range of values that can be stored
- Operations that can be performed

```
┌────────────────────────────────────────────────────────┐
│              C++ Data Type Hierarchy                   │
├────────────────────────────────────────────────────────┤
│  Data Types                                            │
│      ├── Primitive (Built-in)                          │
│      │       ├── Integer (int)                         │
│      │       ├── Character (char)                      │
│      │       ├── Boolean (bool)                        │
│      │       ├── Float (float)                         │
│      │       └── Double (double)                       │
│      │                                                 │
│      └── Non-Primitive (Derived)                       │
│              ├── String (string)                       │
│              ├── Array                                 │
│              ├── Pointer                               │
│              └── Class/Struct                          │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Primitive Data Types

```
┌──────────────┬──────────┬────────────────────────────────────┐
│ Data Type    │ Size     │ Description                        │
├──────────────┼──────────┼────────────────────────────────────┤
│ int          │ 4 bytes  │ Whole numbers                      │
│              │          │ Range: -2,147,483,648 to           │
│              │          │         2,147,483,647              │
├──────────────┼──────────┼────────────────────────────────────┤
│ char         │ 1 byte   │ Single character (single quotes)   │
│              │          │ Stores ASCII value internally      │
├──────────────┼──────────┼────────────────────────────────────┤
│ bool         │ 1 byte   │ Logical values: true or false      │
├──────────────┼──────────┼────────────────────────────────────┤
│ float        │ 4 bytes  │ Decimal numbers                    │
│              │          │ Precision: ~7 decimal digits       │
├──────────────┼──────────┼────────────────────────────────────┤
│ double       │ 8 bytes  │ Large decimal numbers              │
│              │          │ Precision: ~15 decimal digits      │
└──────────────┴──────────┴────────────────────────────────────┘
```

### Memory Size Visualization

```
char    [1 byte]           ■
bool    [1 byte]           ■
int     [4 bytes]          ■■■■
float   [4 bytes]          ■■■■
double  [8 bytes]          ■■■■■■■■
```

---

## 🔹 Non-Primitive Data Types

### 1. String

- Stores sequences of characters (text)
- Variable length, enclosed in double quotes (" ")
- Requires `#include <string>`
- More flexible than character arrays

**String vs Char:**

- `char` = single character, single quotes: `'A'`
- `string` = text, double quotes: `"Hello"`

### 2. Array

- Stores multiple values of same data type
- Fixed size, zero-indexed
- Contiguous memory locations

---

## 🔹 Type Modifiers

```
┌──────────────┬────────────────────────────────────────────┐
│ Modifier     │ Effect                                     │
├──────────────┼────────────────────────────────────────────┤
│ signed       │ Positive and negative (default for int)    │
│ unsigned     │ Only positive (doubles positive range)     │
│ short        │ Reduces size (usually 2 bytes)             │
│ long         │ Increases size (usually 8 bytes)           │
└──────────────┴────────────────────────────────────────────┘
```

---

## 🔹 Data Type Selection Guide

```
┌────────────────────────────────────────────────────────────┐
│ Data to Store      │ Recommended Type                      │
├────────────────────┼───────────────────────────────────────┤
│ Whole numbers      │ int                                   │
│ Single character   │ char                                  │
│ Text/words         │ string                                │
│ True/false values  │ bool                                  │
│ Decimal numbers    │ float (less precision)                │
│                    │ double (more precision)               │
│ Very large numbers │ long or long long                     │
│ Only positive      │ unsigned int                          │
└────────────────────┴───────────────────────────────────────┘
```

---

## 🔹 Comments in C++

Non-executable lines explaining code. Compiler ignores comments.

### Types

**1. Single Line Comment**

- Syntax: `//`
- Everything after `//` on that line is ignored
- Used for brief explanations

**2. Multi-Line Comment**

- Syntax: `/* ... */`
- Everything between symbols is ignored
- Can span multiple lines
- Used for longer explanations or temporarily disabling code

### Best Practices

```
┌────────────────────────────────────────────────────────────┐
│                   Comment Best Practices                   │
├────────────────────────────────────────────────────────────┤
│ ✓ Explain complex logic or algorithms                     │
│ ✓ Document function purpose and parameters                │
│ ✓ Add TODO notes for future improvements                  │
│ ✓ Temporarily disable code during debugging               │
│ ✓ Add copyright or license information                    │
│                                                            │
│ ✗ Don't state the obvious                                 │
│ ✗ Don't replace clear code with unclear comments          │
│ ✗ Don't leave outdated comments                           │
└────────────────────────────────────────────────────────────┘
```

---

## 🔹 Data Types Demonstration

**Illustration file:** [d.cpp](d.cpp)

Demonstrates various C++ data types, sizes, and formatting.

### Key Concepts

- **Header Files:**
  - `<iostream>` - For input/output (`cout`, `cin`, `endl`)
  - `<iomanip>` - For formatting (`fixed`, `setprecision()`)

- **sizeof() Operator** - Returns size of data type/variable in bytes

- **Formatting Manipulators:**

```
┌──────────────────┬─────────────────────────────────────────┐
│ Manipulator      │ Purpose                                 │
├──────────────────┼─────────────────────────────────────────┤
│ fixed            │ Fixed-point notation for decimals       │
│ setprecision(n)  │ Set decimal places to n                 │
│ boolalpha        │ Display bool as true/false not 1/0      │
│ endl             │ New line and flush buffer               │
│ \n               │ New line (faster, no flush)             │
└──────────────────┴─────────────────────────────────────────┘
```

### Type Casting

Converts one data type to another.

**Implicit casting (automatic):**

- int → double (no data loss)

**Explicit casting (manual):**

- `(int)ch` - char → int (shows ASCII value)
- `(int)pi` - double → int (loses decimal part)

**Common Scenarios:**

- `(int)'A'` → 65 (ASCII value)
- `(char)65` → 'A' (character from ASCII)
- `(int)9.99` → 9 (truncates decimal)

---

## 🔹 INPUT IN C++

### User Input with cin

Use **`cin`** (console input) with extraction operator **`>>`** to take user input.

**Syntax:** `cin >> variableName;`

**Limitation of cin:**

- Stops reading at whitespace (spaces, tabs, newlines)
- Cannot read entire lines with spaces

**Example:** If user inputs "John Doe", `cin >> name;` only reads "John"

**Illustration file:** [e.cpp](e.cpp)

---

### Getting Complete Line Input with getline()

Use **`getline()`** function to read an entire line including spaces until newline character is encountered.

**Syntax:** `getline(cin, stringVariable);`

**Key Features:**

- Reads entire line including spaces
- Stops at newline character (`\n`)
- Better for reading sentences or names with spaces
- Requires `#include <string>` header

**Comparison: cin vs getline()**

```
┌─────────────┬──────────────────────────────┬──────────────────────────────┐
│ Input Type  │ cin >> variable              │ getline(cin, variable)       │
├─────────────┼──────────────────────────────┼──────────────────────────────┤
│ User Input  │ "John Doe"                   │ "John Doe"                   │
│ Reads       │ "John" only                  │ "John Doe" (entire line)     │
│ Stops At    │ First whitespace             │ Newline character            │
│ Spaces      │ NOT included                 │ Included in string           │
│ Use Case    │ Single words, numbers        │ Full names, sentences        │
└─────────────┴──────────────────────────────┴──────────────────────────────┘
```

**Example Program Using getline():**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    string address;

    cout << "Enter your full name: ";
    getline(cin, fullName);  // Reads entire line including spaces

    cout << "Enter your address: ";
    getline(cin, address);   // Reads entire line including spaces

    cout << "\nYou entered:" << endl;
    cout << "Name: " << fullName << endl;
    cout << "Address: " << address << endl;

    return 0;
}
```

**Sample Execution:**

```
Enter your full name: Rajat Saraswat
Enter your address: 123 Main Street, New York
You entered:
Name: Rajat Saraswat
Address: 123 Main Street, New York
```

**Illustration file:** [e.cpp](e.cpp)

---

## 🔹 Key Takeaways

### Essential Concepts

1. `cout` is standard output stream; `cin` is standard input stream
2. Use `\n` for performance, `endl` for debugging
3. Always initialize variables to avoid garbage values
4. Choose meaningful variable names
5. Data types determine memory, value range, and operations
6. Primitive types are built-in; non-primitive are derived
7. Comments explain code without affecting execution

### Variable Naming Summary

```
✓ Start with letter or underscore
✓ Use letters, digits, underscore only
✓ Cannot use C++ keywords
✓ Case-sensitive
✗ Cannot start with digit
✗ Cannot contain spaces or special characters (except _)
```

### Memory Sizes

```
char    → 1 byte  → 8 bits
bool    → 1 byte  → 8 bits
int     → 4 bytes → 32 bits
float   → 4 bytes → 32 bits
double  → 8 bytes → 64 bits
```

### Best Practices

- Use `int` for whole numbers
- Use `double` for decimals (better precision than float)
- Use `bool` for true/false conditions
- Use `string` for text (requires `#include <string>`)
- Initialize variables at declaration
- Choose descriptive names
- Use camelCase or snake_case consistently
- Comment complex logic, not obvious code

---

## 🔹 Problems

**Practice problems for Module 3:**

1. **Average of Three Numbers**
   - Take three numbers from the user and find their average
   - **Solution:** [f.cpp](f.cpp)

2. **Area of Square**
   - Input the side of a square and output its area
   - **Solution:** [g.cpp](g.cpp)

3. **Shopping Bill Calculator**
   - Enter cost of 3 items from the user (using float data type) - a pencil, a pen and an eraser
   - Output the total cost of the items back to the user as their bill
   - **Solution:** [h.cpp](h.cpp)

4. **Simple Interest Calculator**
   - Build a Simple Interest Calculator
   - **Solution:** [i.cpp](i.cpp)

5. **Area of Circle**
   - Write a program to calculate the area of a circle
   - **Solution:** [j.cpp](j.cpp)

---
