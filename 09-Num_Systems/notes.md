# DSA with C++ — Module 9 Notes

---

## 🔹 Introduction

This module covers **number systems and data type modifiers** in C++. Understanding how numbers are represented at the binary level and how to manipulate data types is fundamental to writing efficient and correct programs. This knowledge is especially important for optimizing memory usage, understanding data ranges, and performing bit manipulation operations.

---

## 🔹 Number Systems Overview

Different number systems are used to represent values in computing. The two most important systems are decimal (base 10) used by humans and binary (base 2) used by computers.

```
┌──────────────────────────────────────┐
│     Number Systems in Computing      │
├──────────────────────────────────────┤
│ • Decimal (Base 10): 0-9 digits      │
│ • Binary (Base 2): 0-1 bits          │
│ • Octal (Base 8): 0-7 digits         │
│ • Hexadecimal (Base 16): 0-9, A-F    │
└──────────────────────────────────────┘
```

---

## 🔹 1. BINARY NUMBER SYSTEM

The **binary number system** is the fundamental representation used by computers to store and process all data. Every number, character, and instruction is ultimately stored as a sequence of binary digits (bits).

### Basic Concepts

A **bit** (binary digit) is the smallest unit of data in computing and can only have two values: **0** or **1**.

A **byte** is a standardized unit of digital information comprising **8 bits**, commonly used to measure memory and storage capacity.

```
┌────────────────────────────────────────┐
│          Binary Fundamentals           │
├────────────────────────────────────────┤
│ • Base: 2 (only digits 0 and 1)        │
│ • Each position represents power of 2   │
│ • LSB (Least Significant Bit): Rightmost│
│ • MSB (Most Significant Bit): Leftmost  │
│ • 1 byte = 8 bits                       │
│ • Bit manipulation is crucial for DSA   │
└────────────────────────────────────────┘
```

### Binary to Decimal Conversion

To convert a binary number to decimal, multiply each bit by its corresponding power of 2 and sum the results.

**Formula:**
$$\text{Decimal} = \sum_{i=0}^{n-1} b_i \times 2^i$$

where $b_i$ is the bit at position $i$ (0 = rightmost)

**Example:** Convert $11010_2$ to decimal

$$11010_2 = 1 \times 2^4 + 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0$$
$$= 16 + 8 + 0 + 2 + 0 = 26_{10}$$

### Decimal to Binary Conversion

To convert a decimal number to binary, repeatedly divide by 2 and collect the remainders in reverse order.

**Process:**

1. Divide the number by 2
2. Record the remainder (0 or 1)
3. Divide the quotient by 2 again
4. Repeat until quotient becomes 0
5. Read remainders from bottom to top

**Example:** Convert $18_{10}$ to binary

```
18 ÷ 2 = 9 remainder 0
 9 ÷ 2 = 4 remainder 1
 4 ÷ 2 = 2 remainder 0
 2 ÷ 2 = 1 remainder 0
 1 ÷ 2 = 0 remainder 1

Reading from bottom to top: 10010₂
```

### Bit Representation

Every integer is stored in memory using a fixed number of bits. For a given number of bits $n$:

```
┌────────────────┬────────────────────────────┐
│ Bits Required  │ Range of Numbers           │
├────────────────┼────────────────────────────┤
│ 1 bit          │ 0 to 1                     │
│ 2 bits         │ 0 to 3                     │
│ 3 bits         │ 0 to 7                     │
│ 4 bits         │ 0 to 15                    │
│ 8 bits (1 byte)│ 0 to 255                   │
│ 16 bits        │ 0 to 65,535                │
│ 32 bits        │ 0 to 4,294,967,295        │
└────────────────┴────────────────────────────┘
```

**Key Rule:** For any number $\geq 2^n$, at least $n+1$ bits are required.

### Byte Representations

The same number can be represented in multiple ways depending on the number of bits:

- $26_{10} = 11010_2 = 00011010_2$ (8-bit representation)

All these representations are equivalent; they just show the same value with different bit padding.

### Common Use Cases

- [b.cpp](b.cpp) - Convert binary to decimal
- [c.cpp](c.cpp) - Convert decimal to binary

---

## 🔹 2. DATA TYPES IN C++

C++ provides various data types to store different kinds of data. Each data type has a specific size and range of values it can represent.

### Basic Data Types

```
┌──────────────┬─────────────────────┬──────────────────────┐
│ Data Type    │ Typical Size        │ Range                │
├──────────────┼─────────────────────┼──────────────────────┤
│ int          │ 4 bytes (32 bits)   │ -2³¹ to 2³¹-1        │
│ short int    │ 2 bytes (16 bits)   │ -2¹⁵ to 2¹⁵-1        │
│ long int     │ 4-8 bytes           │ Depends on system    │
│ long long    │ 8 bytes (64 bits)   │ -2⁶³ to 2⁶³-1        │
│ float        │ 4 bytes             │ Approximately 1.2e-38 to 3.4e+38 │
│ double       │ 8 bytes             │ Approximately 2.2e-308 to 1.8e+308 │
│ long double  │ 8-16 bytes (system dependent) │ Extended range │
└──────────────┴─────────────────────┴──────────────────────┘
```

**Note:** The exact size of data types depends on the system and compiler. Use `sizeof()` operator to check actual sizes on your system.

---

## 🔹 3. DATA TYPE MODIFIERS

**Data type modifiers** are keywords that alter the meaning and behavior of existing data types. They affect the size, range, and interpretation of the data stored.

### Types of Modifiers

#### 1. **short**

Reduces the size of integer types, typically allocating **2 bytes** instead of 4.

```
┌────────────────────────────────────────────────┐
│ short int (or short)                           │
├────────────────────────────────────────────────┤
│ • Size: 2 bytes (16 bits)                      │
│ • Range: -32,768 to 32,767                     │
│ • Use when: Memory is limited                  │
│ • Example: short age = 25;                     │
└────────────────────────────────────────────────┘
```

#### 2. **long**

Increases the size of integer and floating-point types to store larger values.

```
┌────────────────────────────────────────────────┐
│ long int (or long)                             │
├────────────────────────────────────────────────┤
│ • Size: 4 or 8 bytes (system dependent)        │
│ • Range: Larger than int                       │
│ • Can be used with: int, double                │
│ • Example: long int population = 1000000;      │
│ • Also: long double for higher precision       │
└────────────────────────────────────────────────┘
```

#### 3. **long long**

Extended integer type providing **8 bytes** of storage, supporting very large numbers.

```
┌────────────────────────────────────────────────┐
│ long long (automatically means long long int)  │
├────────────────────────────────────────────────┤
│ • Size: 8 bytes (64 bits)                      │
│ • Range: -2⁶³ to 2⁶³-1                         │
│ • Use when: Large numbers needed               │
│ • Example: long long largeNum = 9223372036854775807; │
└────────────────────────────────────────────────┘
```

#### 4. **signed**

Explicitly marks a variable as a **signed integer**, which can represent both positive and negative numbers. This is the **default** for most integer types.

```
┌────────────────────────────────────────────────┐
│ signed int (equivalent to just "int")          │
├────────────────────────────────────────────────┤
│ • MSB (Most Significant Bit) is sign bit       │
│ • Range includes negative numbers              │
│ • 0 = positive, 1 = negative                   │
│ • Example: signed int temperature = -5;        │
│ • Usually omitted (int is signed by default)   │
└────────────────────────────────────────────────┘
```

#### 5. **unsigned**

Marks a variable as **unsigned**, allowing storage of only **non-negative numbers** (0 and positive). This effectively doubles the maximum positive value.

**How it works:** In signed integers, the MSB (Most Significant Bit) is reserved as a sign bit. Using `unsigned` frees up this bit for the magnitude, allowing larger positive values.

```
┌────────────────────────────────────────────────┐
│ unsigned int                                   │
├────────────────────────────────────────────────┤
│ • No sign bit needed (MSB is used for value)   │
│ • Range: 0 to 2³²-1 (for 32-bit system)        │
│ • Doubles the maximum positive value           │
│ • Cannot store negative numbers                │
│ • Example: unsigned int age = 150;             │
└────────────────────────────────────────────────┘
```

### Combining Modifiers

Multiple modifiers can be combined to create specific data types:

**Examples:**

- `unsigned short int` - Non-negative 16-bit integer
- `unsigned long int` - Non-negative larger integer
- `long long int` - 64-bit signed integer
- `unsigned long long` - 64-bit non-negative integer

**Order note:** Modifiers can typically be arranged in any order (e.g., `unsigned long int` = `long unsigned int`)

### Modifier Comparison

```
┌──────────────────┬─────────────────┬──────────────────┐
│ Type             │ Size            │ Range            │
├──────────────────┼─────────────────┼──────────────────┤
│ int              │ 4 bytes         │ -2³¹ to 2³¹-1    │
│ short int        │ 2 bytes         │ -2¹⁵ to 2¹⁵-1    │
│ long int         │ 4-8 bytes       │ System dependent │
│ long long int    │ 8 bytes         │ -2⁶³ to 2⁶³-1    │
│ unsigned int     │ 4 bytes         │ 0 to 2³²-1       │
│ unsigned short   │ 2 bytes         │ 0 to 2¹⁶-1       │
│ unsigned long    │ 4-8 bytes       │ System dependent │
└──────────────────┴─────────────────┴──────────────────┘
```

### Common Use Cases

- [a.cpp](a.cpp) - Demonstrating sizeof() for various data types and modifiers

---

## 🔹 4. FINDING DATA TYPE SIZES

The `sizeof()` operator returns the size of a data type or variable in **bytes**.

### Syntax

```cpp
cout << sizeof(data_type) << endl;
cout << sizeof(variable) << endl;
```

### Why Check Sizes?

- Verify actual sizes on your system (they can vary)
- Understand memory allocation
- Ensure data type is appropriate for range needed
- Debug unexpected behavior

### Size Typically Depends On

```
┌────────────────────────────────────────────────┐
│ Factors Affecting Data Type Size               │
├────────────────────────────────────────────────┤
│ • Operating system (32-bit vs 64-bit)          │
│ • Compiler used (GCC, Clang, MSVC, etc.)       │
│ • Platform (x86, x64, ARM, etc.)               │
│ • Compiler optimization flags                  │
│ • Architecture and processor                   │
└────────────────────────────────────────────────┘
```

Always use `sizeof()` to verify sizes rather than assuming standard values.

---

## 🔹 5. RANGE CALCULATION

The range of a data type is determined by the number of bits allocated and whether it is signed or unsigned.

### Range Formula

For an $n$-bit integer:

**Signed integers:** $-2^{n-1}$ to $2^{n-1} - 1$
(One bit used for sign, $n-1$ bits for magnitude)

**Unsigned integers:** $0$ to $2^n - 1$
(All bits used for magnitude)

### Why the Asymmetry in Signed Range?

In signed integers, $2^{n-1}$ negative values are possible (from $-2^{n-1}$ to $-1$) but only $2^{n-1} - 1$ positive values (from $0$ to $2^{n-1}-1$), because 0 is included in the positive side and uses one representation slot.

### Examples

```
┌─────────────────┬────────────┬──────────────────────┐
│ Data Type       │ Bits (n)   │ Range                │
├─────────────────┼────────────┼──────────────────────┤
│ signed char     │ 8          │ -128 to 127          │
│ unsigned char   │ 8          │ 0 to 255             │
│ signed short    │ 16         │ -32,768 to 32,767    │
│ unsigned short  │ 16         │ 0 to 65,535          │
│ signed int      │ 32         │ -2,147,483,648 to    │
│                 │            │  2,147,483,647       │
│ unsigned int    │ 32         │ 0 to 4,294,967,295   │
└─────────────────┴────────────┴──────────────────────┘
```

---

## 🔹 Best Practices for Data Types

```
┌────────────────────────────────────────────────────────┐
│            Data Type Best Practices                    │
├────────────────────────────────────────────────────────┤
│ SELECTION:                                             │
│ ✓ Choose data type based on expected range            │
│ ✓ Use unsigned for non-negative values                │
│ ✓ Use long long for very large numbers                │
│ ✓ Use float/double for decimal numbers                │
│ ✗ Don't assume fixed sizes across systems             │
│                                                        │
│ MEMORY:                                                │
│ ✓ Use smaller types (short, unsigned) if possible     │
│ ✓ Consider system memory constraints                  │
│ ✓ Profile to find memory bottlenecks                  │
│ ✗ Don't use long long when int suffices               │
│                                                        │
│ VERIFICATION:                                          │
│ ✓ Use sizeof() to check actual sizes                  │
│ ✓ Test edge cases (min/max values)                    │
│ ✓ Document assumed ranges in comments                │
│ ✓ Be aware of overflow possibilities                  │
│                                                        │
│ CLARITY:                                               │
│ ✓ Use explicit types (prefer long int over long)      │
│ ✓ Keep type declarations readable                     │
│ ✓ Group similar variable declarations together        │
│ ✗ Don't use overly complex modifier combinations      │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Summary

```
┌──────────────────────────────────────────────────────────┐
│                Module 09 Key Concepts                    │
├──────────────────────────────────────────────────────────┤
│ • Binary system uses only 0 and 1                        │
│ • Conversion between binary and decimal is fundamental   │
│ • Data types define storage size and range              │
│ • Modifiers (short, long, signed, unsigned) alter types │
│ • sizeof() reveals actual sizes on your system          │
│ • Range depends on bits and sign                        │
│ • Choose appropriate types for your problem             │
│ • Always verify sizes on your system                    │
│ • Bit manipulation is essential for DSA                 │
└──────────────────────────────────────────────────────────┘
```
