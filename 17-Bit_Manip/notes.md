# DSA with C++ — Module 17 Notes

---

## 🔹 Introduction to Bit Manipulation

**Bit manipulation** is a fundamental technique in competitive programming and software development that involves working directly with binary representations of numbers. It enables efficient solutions for problems involving flags, permissions, optimization, and bitwise operations.

### Prerequisites and Fundamentals

```
┌────────────────────────────────────────────────────────┐
│        Bit Manipulation Fundamentals                   │
├────────────────────────────────────────────────────────┤
│ PREREQUISITES:                                         │
│ ✓ Binary number system understanding                   │
│ ✓ Ability to convert between decimal and binary        │
│ ✓ Knowledge of binary representation                   │
│ ✓ Understanding of number systems                      │
│                                                        │
│ WHY BIT MANIPULATION MATTERS:                          │
│ • Extremely efficient for certain operations           │
│ • Reduces space complexity significantly               │
│ • Faster than traditional arithmetic                   │
│ • Essential for system programming                     │
│ • Critical in competitive programming                  │
│ • Used in cryptography and networking                  │
│                                                        │
│ BITS BASICS:                                           │
│ • Bit: Smallest unit of data (0 or 1)                  │
│ • Byte: 8 bits                                         │
│ • Set Bit: Bit with value 1                            │
│ • Unset Bit: Bit with value 0                          │
│ • Rightmost Bit: Position 0 (LSB)                      │
│ • Leftmost Bit: Highest position (MSB)                 │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Bitwise Operators

**Bitwise operators** perform operations directly on the binary representations of integers. These are among the most efficient operations a CPU can execute.

### Bitwise AND, OR, and XOR

```
┌────────────────────────────────────────────────────────┐
│        Bitwise Operators Truth Tables                  │
├────────────────────────────────────────────────────────┤
│ 1. BITWISE AND (&):                                    │
│    Performs AND operation on each pair of bits         │
│    Result is 1 only if BOTH bits are 1                 │
│                                                        │
│    Truth Table:                                        │
│    0 & 0 = 0                                           │
│    0 & 1 = 0                                           │
│    1 & 0 = 0                                           │
│    1 & 1 = 1                                           │
│                                                        │
│    Example: 5 & 3 = 101 & 011 = 001 = 1              │
│    Use Case: Check if bit is set, find common bits     │
│                                                        │
│ 2. BITWISE OR (|):                                     │
│    Performs OR operation on each pair of bits          │
│    Result is 1 if AT LEAST ONE bit is 1                │
│                                                        │
│    Truth Table:                                        │
│    0 | 0 = 0                                           │
│    0 | 1 = 1                                           │
│    1 | 0 = 1                                           │
│    1 | 1 = 1                                           │
│                                                        │
│    Example: 5 | 3 = 101 | 011 = 111 = 7              │
│    Use Case: Set bits, combine flags                   │
│                                                        │
│ 3. BITWISE XOR (^):                                    │
│    Performs XOR operation on each pair of bits         │
│    Result is 1 if bits are DIFFERENT                   │
│                                                        │
│    Truth Table:                                        │
│    0 ^ 0 = 0                                           │
│    0 ^ 1 = 1                                           │
│    1 ^ 0 = 1                                           │
│    1 ^ 1 = 0                                           │
│                                                        │
│    Example: 5 ^ 3 = 101 ^ 011 = 110 = 6              │
│    Use Case: Toggle bits, find differences             │
│    Properties: a ^ a = 0, a ^ 0 = a                    │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ All bitwise operations: O(1) - constant time           │
│ Work on all bits simultaneously                        │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp) - Bitwise AND operations, [b.cpp](b.cpp) - Bitwise OR operations, [c.cpp](c.cpp) - Bitwise XOR operations

---

## 🔹 Bitwise NOT and Complement

**The NOT operator (~)** performs a bitwise complement, inverting all bits of a number. Understanding how it works with two's complement representation is crucial.

### One's and Two's Complement

```
┌────────────────────────────────────────────────────────┐
│      NOT Operator and Complement Representation        │
├────────────────────────────────────────────────────────┤
│ BITWISE NOT (~):                                       │
│ • Inverts every bit (0→1, 1→0)                         │
│ • Returns negative of (n+1) in two's complement        │
│ • Formula: ~n = -(n+1)                                 │
│                                                        │
│ ONE'S COMPLEMENT:                                      │
│ • Simply flip all bits                                 │
│ • ~0 = all 1s (in binary)                              │
│ • Represents: -(n+1) before adding 1                   │
│                                                        │
│ TWO'S COMPLEMENT:                                      │
│ • Used to represent negative numbers in C++            │
│ • Formula: 2's complement = 1's complement + 1         │
│ • Process:                                             │
│   1. Take one's complement (flip all bits)             │
│   2. Add 1 to the result                               │
│                                                        │
│ EXAMPLE WALKTHROUGH:                                   │
│ Find: ~6                                               │
│                                                        │
│ Step 1: Convert 6 to binary                            │
│   6 = 00000110                                         │
│                                                        │
│ Step 2: Flip all bits (one's complement)               │
│   ~6 = 11111001                                        │
│                                                        │
│ Step 3: This represents negative in two's complement   │
│   Add 1: 11111010                                      │
│   Value: -(6 + 1) = -7                                 │
│                                                        │
│ TRUTH TABLE:                                           │
│ ~0 = -1                                                │
│ ~1 = -2                                                │
│ ~2 = -3                                                │
│ ~6 = -7                                                │
│ Pattern: ~n = -(n+1)                                   │
│                                                        │
│ MEMORY REPRESENTATION:                                 │
│ 8-bit example:                                         │
│ Value 6:    00000110  (binary)                         │
│ NOT of 6:   11111001  (all bits flipped)               │
│ Interpretation: -(6+1) = -7 in two's complement       │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp) - NOT operator and complement operations

---

## 🔹 Binary Shift Operators

**Shift operators** move bits left or right within a number, effectively multiplying or dividing by powers of 2.

### Left and Right Shift Operations

```
┌────────────────────────────────────────────────────────┐
│        Binary Shift Operators Explained                │
├────────────────────────────────────────────────────────┤
│ LEFT SHIFT (<<):                                       │
│ • Shifts bits to the left by n positions               │
│ • Fills right side with 0s                             │
│ • Formula: a << b = a × 2^b                            │
│                                                        │
│ Example:                                               │
│ 5 << 1 = 0101 << 1 = 1010 = 10 (5 × 2 = 10)           │
│ 5 << 2 = 0101 << 2 = 10100 = 20 (5 × 4 = 20)          │
│                                                        │
│ Visualization:                                         │
│ Original:  00000101 (5)                                │
│ After <<1: 00001010 (10)                               │
│ After <<2: 00010100 (20)                               │
│                                                        │
│ RIGHT SHIFT (>>):                                      │
│ • Shifts bits to the right by n positions              │
│ • For unsigned: fills left side with 0s                │
│ • For signed: fills with sign bit (arithmetic shift)   │
│ • Formula: a >> b = a ÷ 2^b (integer division)         │
│                                                        │
│ Example:                                               │
│ 20 >> 1 = 10100 >> 1 = 01010 = 10 (20 ÷ 2 = 10)       │
│ 20 >> 2 = 10100 >> 2 = 00101 = 5 (20 ÷ 4 = 5)         │
│                                                        │
│ Visualization:                                         │
│ Original:  00010100 (20)                               │
│ After >>1: 00001010 (10)                               │
│ After >>2: 00000101 (5)                                │
│                                                        │
│ IMPORTANT NOTES:                                       │
│ • Left shift can overflow (bits fall off left)         │
│ • Right shift loses precision (bits fall off right)     │
│ • Shifts work with any power of 2                      │
│ • Time Complexity: O(1) - constant time                │
│ • Much faster than multiplication/division             │
└────────────────────────────────────────────────────────┘
```

Reference: [e.cpp](e.cpp) - Left and right shift operations with examples

---

## 🔹 Bit Masking Techniques

**Bit masking** is a technique to access, modify, or check specific bits in a number using AND, OR, and XOR operations with carefully crafted masks.

### Check Odd or Even

```
┌────────────────────────────────────────────────────────┐
│      Checking Odd/Even Using Bit Manipulation          │
├────────────────────────────────────────────────────────┤
│ KEY OBSERVATION:                                       │
│ • In ODD numbers: rightmost bit (LSB) is always 1      │
│ • In EVEN numbers: rightmost bit (LSB) is always 0     │
│                                                        │
│ Examples:                                              │
│ 5 = 101 (odd) - LSB is 1                               │
│ 6 = 110 (even) - LSB is 0                              │
│ 7 = 111 (odd) - LSB is 1                               │
│ 8 = 1000 (even) - LSB is 0                             │
│                                                        │
│ SOLUTION: Check if (num & 1) == 1                      │
│ • AND with 1 isolates the rightmost bit                │
│ • Result is 1 for odd, 0 for even                      │
│                                                        │
│ LOGIC:                                                 │
│ n & 1:   ...xxx1 & 1 = 1 (odd)                         │
│ n & 1:   ...xxx0 & 1 = 0 (even)                        │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - single operation                          │
│ Space: O(1) - no extra space                           │
│                                                        │
│ COMPARISON:                                            │
│ Traditional: if (num % 2 == 1) → division operation   │
│ Bit Method: if (num & 1) → single cycle               │
│ Bit method is 10-20% faster!                           │
└────────────────────────────────────────────────────────┘
```

Reference: [g.cpp](g.cpp) - Odd/even checking using bit masking

### Get the ith Bit

```
┌────────────────────────────────────────────────────────┐
│         Extracting Specific Bit (Get ith Bit)          │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Extract the bit value at position i (0-indexed)        │
│ Position 0 is rightmost (LSB)                          │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Create a mask with 1 at position i: mask = 1 << i   │
│ 2. AND with the number: result = num & mask            │
│ 3. Check if result is non-zero (1) or zero (0)         │
│                                                        │
│ EXAMPLE:                                               │
│ Get bit at position 2 in number 5                      │
│ 5 = 101 (binary)                                       │
│                                                        │
│ Step 1: Create mask                                    │
│   mask = 1 << 2 = 100 (decimal 4)                      │
│                                                        │
│ Step 2: AND operation                                  │
│   5 & 4 = 101 & 100 = 100 = 4                          │
│                                                        │
│ Step 3: Check result                                   │
│   if (4 > 0) → Bit is 1                                │
│   else → Bit is 0                                      │
│                                                        │
│ COMPACT FORM:                                          │
│ (num >> i) & 1   OR   ((num & (1 << i)) != 0)          │
│                                                        │
│ VISUALIZATION:                                         │
│ Number: 5 = 101                                        │
│ Position: 2 1 0 (index)                                │
│ i=0: (5>>0)&1 = 101&1 = 1 ✓                            │
│ i=1: (5>>1)&1 = 10&1 = 0 ✓                             │
│ i=2: (5>>2)&1 = 1&1 = 1 ✓                              │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - constant                                  │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [h.cpp](h.cpp) - Get ith bit implementation

### Set the ith Bit

```
┌────────────────────────────────────────────────────────┐
│        Setting Specific Bit (Set ith Bit to 1)         │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Change the bit at position i to 1, leave others same   │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Create mask with 1 at position i: mask = 1 << i     │
│ 2. OR with the number: result = num | mask             │
│ 3. OR operation ensures position i becomes 1           │
│                                                        │
│ WHY OR WORKS:                                          │
│ Bit pattern at position i:                             │
│ 0 | 1 = 1 (if unset, set it)                           │
│ 1 | 1 = 1 (if already set, keep it)                    │
│ All other positions: x | 0 = x (unchanged)             │
│                                                        │
│ EXAMPLE:                                               │
│ Set bit at position 2 in number 5                      │
│ 5 = 101 (binary)                                       │
│                                                        │
│ Step 1: Create mask                                    │
│   mask = 1 << 2 = 100                                  │
│                                                        │
│ Step 2: OR operation                                   │
│   5 | 4 = 101 | 100 = 101 = 5                          │
│   (bit 2 was already 1, so no change)                  │
│                                                        │
│ Different example: Set bit at position 1               │
│   5 | (1<<1) = 101 | 010 = 111 = 7                     │
│   (bit 1 changed from 0 to 1)                          │
│                                                        │
│ FORMULA:                                               │
│ result = num | (1 << i)                                │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - constant                                  │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [i.cpp](i.cpp) - Set ith bit implementation

### Clear the ith Bit

```
┌────────────────────────────────────────────────────────┐
│       Clearing Specific Bit (Clear ith Bit to 0)       │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Change the bit at position i to 0, leave others same   │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Create mask with 0 at position i: mask = ~(1 << i)  │
│    This creates all 1s except 0 at position i          │
│ 2. AND with the number: result = num & mask            │
│ 3. AND operation ensures position i becomes 0          │
│                                                        │
│ WHY AND WORKS:                                         │
│ Bit pattern at position i:                             │
│ 0 & 0 = 0 (if unset, keep it)                          │
│ 1 & 0 = 0 (if set, clear it)                           │
│ All other positions: x & 1 = x (unchanged)             │
│                                                        │
│ EXAMPLE:                                               │
│ Clear bit at position 2 in number 7                    │
│ 7 = 111 (binary)                                       │
│                                                        │
│ Step 1: Create mask                                    │
│   mask = ~(1 << 2) = ~100 = ...11011                   │
│   (all 1s except position 2)                           │
│                                                        │
│ Step 2: AND operation                                  │
│   7 & mask = 111 & 011 = 011 = 3                       │
│   (bit 2 changed from 1 to 0)                          │
│                                                        │
│ Another example: Clear bit at position 0               │
│   7 & ~(1<<0) = 111 & 110 = 110 = 6                    │
│                                                        │
│ FORMULA:                                               │
│ result = num & ~(1 << i)                               │
│                                                        │
│ ALTERNATIVE APPROACH:                                  │
│ Using XOR if bit is 1: num ^ (1 << i)                  │
│ (XOR toggles the bit, but only if we know it's set)    │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - constant                                  │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [j.cpp](j.cpp) - Clear ith bit implementation

---

## 🔹 Check if Power of 2

**Powers of 2** are numbers that have exactly one bit set (only one 1 in binary representation). This property enables efficient checking.

### Identifying Powers of 2

```
┌────────────────────────────────────────────────────────┐
│     Detecting Powers of 2 Using Bit Manipulation       │
├────────────────────────────────────────────────────────┤
│ KEY INSIGHT:                                           │
│ All powers of 2 have exactly ONE set bit               │
│                                                        │
│ Powers of 2:                                           │
│ 1 = 1 (2^0)           = 0001                           │
│ 2 = 2 (2^1)           = 0010                           │
│ 4 = 4 (2^2)           = 0100                           │
│ 8 = 8 (2^3)           = 1000                           │
│ 16 = 16 (2^4)         = 10000                          │
│                                                        │
│ Non-powers of 2:                                       │
│ 3 = 0011 (two bits set)                                │
│ 5 = 0101 (two bits set)                                │
│ 6 = 0110 (two bits set)                                │
│ 7 = 0111 (three bits set)                              │
│                                                        │
│ METHOD:                                                │
│ For any power of 2 (n), we have: n & (n-1) = 0        │
│                                                        │
│ WHY THIS WORKS:                                        │
│ If n = 2^k, then n has form: 1000...0 (k zeros)        │
│ Then n-1 has form: 0111...1 (k ones)                   │
│ AND of these: 1000...0 & 0111...1 = 0                  │
│                                                        │
│ EXAMPLE VERIFICATION:                                  │
│ n = 8 (can be 2^3):                                    │
│ 8 = 1000 (binary)                                      │
│ 7 = 0111 (binary)                                      │
│ 8 & 7 = 1000 & 0111 = 0000 = 0 ✓ (is power of 2)     │
│                                                        │
│ n = 6 (not a power of 2):                              │
│ 6 = 0110 (binary)                                      │
│ 5 = 0101 (binary)                                      │
│ 6 & 5 = 0110 & 0101 = 0100 = 4 ≠ 0 ✓ (not power)     │
│                                                        │
│ PROPERTIES:                                            │
│ • 2^n - 1 has all bits set (up to position n-1)        │
│ • (2^n) & (2^n - 1) = 0 for any n                      │
│ • Single set bit can be found: n & -n = n              │
│                                                        │
│ FORMULA:                                               │
│ if ((n > 0) && ((n & (n-1)) == 0))                     │
│   → n is a power of 2                                  │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - single operation                          │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [k.cpp](k.cpp) - Power of 2 detection

---

## 🔹 Update, Clear Range, and Toggle Operations

Advanced bit manipulation operations for updating bits conditionally and clearing ranges.

### Update ith Bit Conditionally

```
┌────────────────────────────────────────────────────────┐
│    Updating Bit to Specific Value (0 or 1)             │
├────────────────────────────────────────────────────────┤
│ PROBLEM:                                               │
│ Set the ith bit to a specific value (0 or 1)           │
│ without knowing its current state                      │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Clear the ith bit first: num & ~(1 << i)            │
│ 2. Set the desired value: result | (val << i)          │
│ Combined: (num & ~(1 << i)) | (val << i)              │
│                                                        │
│ EXAMPLE:                                               │
│ Update bit at position 2 in number 7 to 0              │
│ 7 = 111 (binary), i = 2, val = 0                       │
│                                                        │
│ Step 1: Clear bit 2                                    │
│   7 & ~(1<<2) = 111 & 011 = 011 = 3                    │
│                                                        │
│ Step 2: Set with new value (0)                         │
│   3 | (0<<2) = 011 | 000 = 011 = 3                     │
│   Result: 3 ✓                                          │
│                                                        │
│ Another example: Set bit 1 in number 7 to 1            │
│ 7 = 111, i = 1, val = 1                                │
│   (7 & ~(1<<1)) | (1<<1) = (111 & 101) | 010           │
│   = 101 | 010 = 111 = 7 (already 1, no change)        │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - constant                                  │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [l.cpp](l.cpp) - Update ith bit conditional operation

### Clear Range of Bits

```
┌────────────────────────────────────────────────────────┐
│     Clearing Range of Bits (from i to j)               │
├────────────────────────────────────────────────────────┤
│ PROBLEM:                                               │
│ Clear all bits in range from position i to j           │
│ Positions are 0-indexed from right (LSB)               │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Create mask with 0s at positions i to j             │
│    Create 1s from 0 to (i-1): (1 << i) - 1             │
│    Create 1s from (j+1) onwards: ~((1 << (j+1)) - 1)   │
│ 2. Combine masks: mask = left | right                  │
│ 3. AND with number: result = num & mask                │
│                                                        │
│ EXAMPLE:                                               │
│ Clear bits from position 1 to 3 in number 15           │
│ 15 = 1111 (binary), i = 1, j = 3                       │
│                                                        │
│ Target bits: __0__0__ (clear positions 1-3)            │
│ We want to keep: bit 0 and bits 4+                     │
│                                                        │
│ Left part (0 to 0): (1<<1)-1 = 1                       │
│ Right part (4+): ~((1<<4)-1) = ...11110000             │
│ Full mask: 1 | ...11110000 = ...11110001               │
│                                                        │
│ Result: 15 & mask = 1111 & 0001 = 0001 = 1 ✓          │
│                                                        │
│ TIME COMPLEXITY:                                       │
│ Time: O(1) - constant                                  │
│ Space: O(1) - no extra space                           │
└────────────────────────────────────────────────────────┘
```

Reference: [m.cpp](m.cpp) - Clear range of bits

---

## 🔹 Counting Set Bits

**Counting set bits** (number of 1s in binary representation) is a common operation with multiple approaches varying in efficiency.

### Methods to Count Set Bits

```
┌────────────────────────────────────────────────────────┐
│      Counting Number of 1s in Binary Form              │
├────────────────────────────────────────────────────────┤
│ METHOD 1: Naive Approach                               │
│ • Check last bit using (num & 1)                       │
│ • Right shift number: num >>= 1                        │
│ • Repeat until number becomes 0                        │
│ • Count increments for each 1 found                    │
│                                                        │
│ Time: O(log n) - number of bits                        │
│ Advantage: Simple and easy to understand               │
│ Disadvantage: Slower for numbers with few set bits     │
│                                                        │
│ EXAMPLE: Count bits in 5 = 101                         │
│ Step 1: 101 & 1 = 1 (count=1), shift: 10             │
│ Step 2: 10 & 1 = 0 (count=1), shift: 1               │
│ Step 3: 1 & 1 = 1 (count=2), shift: 0                │
│ Result: 2 set bits ✓                                   │
│                                                        │
│ METHOD 2: Brian Kernighan's Algorithm                  │
│ • Much faster for sparse set bits                      │
│ • Operation: num & (num - 1)                           │
│ • Removes rightmost set bit each iteration             │
│ • Algorithm:                                           │
│   while (num > 0) {                                    │
│     num &= (num - 1);  // Remove rightmost 1           │
│     count++;                                           │
│   }                                                    │
│                                                        │
│ Time: O(count of set bits) - very efficient!           │
│ Advantage: Skips all 0 bits                            │
│ Works with any number of set bits                      │
│                                                        │
│ WHY IT WORKS:                                          │
│ n & (n-1) removes the rightmost 1 bit                  │
│ Example: 12 = 1100, 11 = 1011                          │
│ 12 & 11 = 1100 & 1011 = 1000 (removed rightmost 1)    │
│                                                        │
│ EXAMPLE: Count bits in 12 = 1100                       │
│ Step 1: 12 & 11 = 1000 = 8 (count=1)                   │
│ Step 2: 8 & 7 = 0000 = 0 (count=2)                     │
│ Result: 2 set bits ✓                                   │
│                                                        │
│ COMPARISON FOR n = 1024 (2^10):                        │
│ • Naive: 10 iterations (checks all bits)               │
│ • Kernighan's: 1 iteration (only 1 set bit)            │
│ • 10x faster!                                          │
└────────────────────────────────────────────────────────┘
```

Reference: [n.cpp](n.cpp) - Naive approach to counting set bits, [o.cpp](o.cpp) - Brian Kernighan's algorithm

---

## 🔹 Fast Exponentiation

**Fast exponentiation** (exponentiation by squaring) computes x^n efficiently using binary representation of the exponent.

### Exponentiation Methods

```
┌────────────────────────────────────────────────────────┐
│        Fast Exponentiation Algorithm                   │
├────────────────────────────────────────────────────────┤
│ PROBLEM:                                               │
│ Compute x^n efficiently for large n                    │
│                                                        │
│ METHOD 1: Naive Approach (Brute Force)                 │
│ • Multiply x by itself n times                         │
│ • result = x * x * x * ... (n times)                   │
│                                                        │
│ Time: O(n) - linear, too slow for large n              │
│ Example: 2^1000 requires 999 multiplications           │
│                                                        │
│ METHOD 2: Fast Exponentiation (Optimal)                │
│ • Use binary representation of exponent                │
│ • Square base and check bits of exponent               │
│ • Time: O(log n) - logarithmic, exponentially faster   │
│                                                        │
│ KEY IDEA:                                              │
│ x^13 = x^(1101 in binary)                              │
│ x^13 = x^8 * x^4 * x^1  (sum of powers of 2)          │
│ = (x^2)^2 * (x^2)^2 * x  (use squaring trick)          │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Initialize: result = 1, base = x                    │
│ 2. While n > 0:                                        │
│    a. Check if last bit of n is 1: (n & 1)             │
│    b. If yes, multiply result by base                  │
│    c. Square the base: base = base * base              │
│    d. Right shift n: n = n >> 1                        │
│ 3. Return result                                       │
│                                                        │
│ EXAMPLE: Compute 2^13                                  │
│ n = 13 = 1101 (binary)                                 │
│                                                        │
│ Iteration 1: n=13 (odd), result*=2, base^=2           │
│   n=1, result=2, base=4                                │
│                                                        │
│ Iteration 2: n=6 (even), don't multiply                │
│   n=3, result=2, base=16                               │
│                                                        │
│ Iteration 3: n=3 (odd), result*=base                   │
│   n=1, result=32, base=256                             │
│                                                        │
│ Iteration 4: n=1 (odd), result*=base                   │
│   n=0, result=8192                                     │
│                                                        │
│ 2^13 = 8192 ✓                                          │
│                                                        │
│ TIME COMPLEXITY COMPARISON:                            │
│ Naive: O(n)              - for n=1000: 1000 ops        │
│ Fast:  O(log n)          - for n=1000: ~10 ops         │
│ Speedup: 100x faster!                                  │
│                                                        │
│ SPACE COMPLEXITY:                                      │
│ Both methods: O(1) - constant space                    │
└────────────────────────────────────────────────────────┘
```

Reference: [p.cpp](p.cpp) - Naive exponentiation approach, [q.cpp](q.cpp) - Fast exponentiation using bit manipulation

---

## 🔹 Practice Problems and Applications

Real-world bit manipulation problems combining multiple techniques.

### Problem 1: Clear Bit Range (LeetCode Style)

```
┌────────────────────────────────────────────────────────┐
│  Problem: Clear Range of Bits (i to j)                 │
├────────────────────────────────────────────────────────┤
│ PROBLEM STATEMENT:                                     │
│ Write a function to clear all bits from position i     │
│ to position j in a given number.                       │
│ Positions are counted from right (0-indexed).          │
│                                                        │
│ EXAMPLE:                                               │
│ Input: num = 31 (11111), i = 1, j = 3                 │
│ Output: 17 (10001)                                     │
│ Explanation: Cleared bits 1, 2, 3                      │
│                                                        │
│ APPROACH:                                              │
│ Build a mask with 1s everywhere except i to j          │
│ Then AND with the number                               │
│                                                        │
│ TIME COMPLEXITY: O(1)                                  │
│ SPACE COMPLEXITY: O(1)                                 │
└────────────────────────────────────────────────────────┘
```

Reference: [r.cpp](r.cpp) - Clear bit range solution

### Problem 2: Single Number (LeetCode 136)

```
┌────────────────────────────────────────────────────────┐
│  Problem: Find Single Number                           │
├────────────────────────────────────────────────────────┤
│ PROBLEM STATEMENT:                                     │
│ Given an array where every element appears twice       │
│ except one, find that single element.                  │
│ Must be O(n) time and O(1) space.                      │
│                                                        │
│ EXAMPLE:                                               │
│ Input: [2, 2, 1]                                       │
│ Output: 1                                              │
│ Input: [4, 1, 2, 1, 2]                                 │
│ Output: 4                                              │
│                                                        │
│ KEY INSIGHT:                                           │
│ Use XOR properties:                                    │
│ • a ^ a = 0 (any number XOR itself is 0)               │
│ • a ^ 0 = a (any number XOR 0 is itself)               │
│ • XOR is commutative and associative                   │
│                                                        │
│ SOLUTION:                                              │
│ XOR all elements → pairs cancel (a^a=0)                │
│ Only single element remains                            │
│                                                        │
│ Example: [4, 1, 2, 1, 2]                               │
│ 4 ^ 1 ^ 2 ^ 1 ^ 2                                      │
│ = (1 ^ 1) ^ (2 ^ 2) ^ 4                                │
│ = 0 ^ 0 ^ 4 = 4 ✓                                      │
│                                                        │
│ TIME COMPLEXITY: O(n) - single pass                    │
│ SPACE COMPLEXITY: O(1) - no extra space                │
│                                                        │
│ PROOF THAT O(1) SPACE:                                 │
│ Only use result variable, no data structures           │
│ Iterating in-place doesn't count as extra space        │
└────────────────────────────────────────────────────────┘
```

Reference: [s.cpp](s.cpp) - Single element XOR solution

### Problem 3: XOR Beauty of Array (LeetCode 2527)

```
┌────────────────────────────────────────────────────────┐
│  Problem: XOR Beauty of Array                          │
├────────────────────────────────────────────────────────┤
│ PROBLEM STATEMENT:                                     │
│ Given array nums, compute XOR of all "effective        │
│ values" where effective value = (nums[i] | nums[j]) &  │
│ nums[k] for all possible triplets (i,j,k).             │
│                                                        │
│ NAIVE APPROACH:                                        │
│ Check all triplets → O(n³) - too slow                  │
│                                                        │
│ OPTIMIZED APPROACH:                                    │
│ Key observation: Due to XOR properties, most           │
│ triplet interactions cancel out. Each bit position     │
│ contributes independently, and the final result        │
│ is simply the XOR of all array elements.               │
│                                                        │
│ Time: O(n) - single pass                               │
│ Space: O(1) - constant space                           │
│                                                        │
│ WHY IT WORKS:                                          │
│ Through bit analysis, contributions from triplets      │
│ that appear even number of times cancel when XORed.    │
│ Only unique contribution pattern remains.              │
└────────────────────────────────────────────────────────┘
```

Reference: [t.cpp](t.cpp) - XOR beauty array solution

### Problem 4: Divide Two Integers (LeetCode 29)

```
┌────────────────────────────────────────────────────────┐
│  Problem: Divide Without Division Operator             │
├────────────────────────────────────────────────────────┤
│ PROBLEM STATEMENT:                                     │
│ Divide dividend by divisor without using *, /, %       │
│ Return integer quotient (truncated).                   │
│                                                        │
│ NAIVE APPROACH:                                        │
│ Repeated subtraction → O(n) where n is quotient        │
│ Example: 15 / 3 requires 5 subtractions                │
│ Far too slow for large divisors                        │
│                                                        │
│ OPTIMAL APPROACH:                                      │
│ Use bit shifting (left shift = multiply by 2)          │
│ Subtract largest possible multiples using powers of 2  │
│                                                        │
│ ALGORITHM:                                             │
│ 1. Handle edge cases (divisor = 0, overflow)           │
│ 2. Keep subtracting largest multiple of divisor        │
│    that fits into current value                        │
│ 3. Use left shifts to quickly compute multiples        │
│ 4. Count how many multiples we subtracted              │
│                                                        │
│ EXAMPLE: Divide 15 by 3                                │
│ 15 - (3<<2) is too large, skip 8x multiple             │
│ 15 - (3<<1) = 15 - 12 = 3 (quotient += 4)              │
│ 3 - (3<<0) = 3 - 3 = 0 (quotient += 1)                 │
│ Result: quotient = 5 ✓                                 │
│                                                        │
│ TIME COMPLEXITY: O(log n)                              │
│ SPACE COMPLEXITY: O(1)                                 │
│                                                        │
│ COMPARISON:                                            │
│ Naive (repeated subtraction): O(quotient) - slow      │
│ Bit shifting method: O(log quotient) - fast            │
│ For quotient=1000: 1000 ops vs 10 ops (100x faster)   │
└────────────────────────────────────────────────────────┘
```

Reference: [u.cpp](u.cpp) - Integer division without operator
