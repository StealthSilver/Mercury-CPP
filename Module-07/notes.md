# DSA with C++ — Module 7 Notes

---

## 🔹 Introduction

This module focuses on **nested loops** and their practical applications in **pattern printing**. Nested loops are essential for solving problems that involve multi-dimensional structures, matrix operations, and creating complex visual patterns. Understanding how to structure nested loops efficiently is crucial for writing clean and optimized code.

---

## 🔹 Nested Loops

**Nested loops** occur when one loop is placed inside another loop. The inner loop completes all its iterations for each iteration of the outer loop. This creates a multiplicative effect in the total number of operations.

### Basic Syntax

```cpp
for (int i = 0; i < outerLimit; i++) {           // Outer loop
    for (int j = 0; j < innerLimit; j++) {       // Inner loop
        // Code executes here
    }
}
```

### How Nested Loops Work

```
┌────────────────────────────────────────────────────────┐
│ Outer Loop Iteration 1                                 │
│   ├─ Inner Loop Iteration 1                           │
│   ├─ Inner Loop Iteration 2                           │
│   └─ Inner Loop Iteration 3 (completes)               │
│                                                        │
│ Outer Loop Iteration 2                                 │
│   ├─ Inner Loop Iteration 1                           │
│   ├─ Inner Loop Iteration 2                           │
│   └─ Inner Loop Iteration 3 (completes)               │
│                                                        │
│ Outer Loop Iteration 3                                 │
│   ├─ Inner Loop Iteration 1                           │
│   ├─ Inner Loop Iteration 2                           │
│   └─ Inner Loop Iteration 3 (completes)               │
└────────────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│         Nested Loops Characteristics                   │
├────────────────────────────────────────────────────────┤
│ • Inner loop completes all iterations per outer       │
│   iteration                                           │
│ • Total iterations = outer × inner iterations         │
│ • Inner loop counter typically starts fresh each time │
│ • Can be nested 3+ levels (not recommended)          │
│ • Scope of inner loop variable is within inner loop  │
│ • Each nesting level increases complexity             │
└────────────────────────────────────────────────────────┘
```

### Time Complexity

```
┌────────────────────────────────────────────────────────┐
│              Nested Loop Complexity                    │
├────────────────────────────────────────────────────────┤
│ 2 nested loops: O(n²)   - n × n operations            │
│ 3 nested loops: O(n³)   - n × n × n operations        │
│ m nested loops: O(n^m)  - exponential growth          │
│                                                        │
│ Example: Two loops, each running 5 times              │
│ Total operations = 5 × 5 = 25                         │
│                                                        │
│ Example: Three loops, each running 5 times            │
│ Total operations = 5 × 5 × 5 = 125                    │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp)

---

## 🔹 Pattern Printing with Nested Loops

**Pattern printing** is a classic application of nested loops. The structure is always the same:

- **Outer loop**: Controls the number of rows
- **Inner loop**: Controls what gets printed in each row (columns, characters, logic)

### The Pattern Printing Template

```cpp
for (int i = 0; i < n; i++) {           // Outer loop - rows
    for (int j = 0; j <= i; j++) {      // Inner loop - columns
        cout << "*";                    // Print pattern element
    }
    cout << endl;                       // New line after each row
}
```

### Key Concepts

```
┌────────────────────────────────────────────────────────┐
│         Pattern Printing Key Concepts                  │
├────────────────────────────────────────────────────────┤
│ • Outer loop variable (i) = current row number        │
│ • Inner loop variable (j) = current column number     │
│ • The relationship between i and j determines pattern │
│ • Printing spaces creates indentation/alignment       │
│ • The element printed (*, #, numbers) varies by type  │
│ • endl or "\n" creates row separation                 │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Star Pattern (Right Triangle)

A basic pyramid pattern where each row contains increasing number of stars.

### Pattern Example (n=5)

```
*
* *
* * *
* * * *
* * * * *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: 1 star         → i = 0, j runs 0 to 0        │
│ • Row 2: 2 stars        → i = 1, j runs 0 to 1        │
│ • Row 3: 3 stars        → i = 2, j runs 0 to 2        │
│ • Row n: n stars        → i = n-1, j runs 0 to n-1    │
│                                                        │
│ • Inner loop condition: j <= i                         │
│ • Spaces between elements optional                     │
│ • Equilateral appearance if spaces added              │
└────────────────────────────────────────────────────────┘
```

Reference: [b.cpp](b.cpp)

---

## 🔹 Inverted Star Pattern

A pyramid pattern that is inverted - starts with maximum stars and decreases.

### Pattern Example (n=5)

```
* * * * *
* * * *
* * *
* *
*
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: 5 stars        → i = 0, j runs 0 to n-1-i   │
│ • Row 2: 4 stars        → i = 1, j runs 0 to n-1-i   │
│ • Row 3: 3 stars        → i = 2, j runs 0 to n-1-i   │
│ • Row n: 1 star         → i = n-1, j runs 0 to 0     │
│                                                        │
│ • Inner loop condition: j < n - i                      │
│ • Opposite of the right triangle pattern              │
│ • Useful for creating bottom-heavy designs            │
└────────────────────────────────────────────────────────┘
```

Reference: [c.cpp](c.cpp)

---

## 🔹 Half Pyramid Pattern (Right-Aligned)

A right triangle pattern that is right-aligned, starting with spaces.

### Pattern Example (n=5)

```
    *
   * *
  * * *
 * * * *
* * * * *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: 4 spaces, 1 star    → spaces: n-1-i          │
│ • Row 2: 3 spaces, 2 stars   → spaces: n-1-i          │
│ • Row 3: 2 spaces, 3 stars   → spaces: n-1-i          │
│ • Row 4: 1 space, 4 stars    → spaces: n-1-i          │
│ • Row 5: 0 spaces, 5 stars   → spaces: n-1-i          │
│                                                        │
│ • First inner loop: Print spaces                       │
│ • Second inner loop: Print stars                       │
│ • Creates right-aligned pyramid effect                 │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp)

---

## 🔹 Character Pyramid Pattern

A pyramid where each row prints characters instead of stars, often in alphabetical or sequential order.

### Pattern Example (n=5)

```
A
B B
C C C
D D D D
E E E E E
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: Character A printed 1 time                    │
│ • Row 2: Character B printed 2 times                   │
│ • Row 3: Character C printed 3 times                   │
│ • Row i: Character (i+1)th printed i+1 times          │
│                                                        │
│ • Character calculation: char c = 'A' + i              │
│ • Each character repeats as many times as its row #    │
│ • Can use numbers (0, 1, 2...) or other symbols      │
└────────────────────────────────────────────────────────┘
```

Reference: [e.cpp](e.cpp)

---

## 🔹 Hollow Rectangle Pattern

A rectangle pattern where only the borders are printed, the interior is empty.

### Pattern Example (rows=4, cols=6)

```
* * * * * *
*         *
*         *
* * * * * *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • First row: All stars (complete row)                  │
│ • Middle rows: Star + spaces + star                    │
│ • Last row: All stars (complete row)                   │
│                                                        │
│ • Check if i == 0 OR i == n-1 → Print full row        │
│ • For middle rows:                                     │
│   - j == 0 OR j == m-1 → Print star                   │
│   - Otherwise → Print space                            │
│ • Creates hollow/frame effect                         │
└────────────────────────────────────────────────────────┘
```

Reference: [f.cpp](f.cpp)

---

## 🔹 Inverted and Rotated Half Pyramid

A pyramid pattern that is both inverted and rotated, creating a left-aligned decreasing pattern.

### Pattern Example (n=5)

```
* * * * *
  * * * *
    * * *
      * *
        *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: 0 spaces, 5 stars    → spaces: i              │
│ • Row 2: 2 spaces, 4 stars    → spaces: i              │
│ • Row 3: 4 spaces, 3 stars    → spaces: i              │
│ • Row 4: 6 spaces, 2 stars    → spaces: i              │
│ • Row 5: 8 spaces, 1 star     → spaces: i              │
│                                                        │
│ • First inner loop: Print spaces (i*2 spaces)         │
│ • Second inner loop: Print stars (n-i stars)          │
│ • Creates right-aligned inverted effect                │
└────────────────────────────────────────────────────────┘
```

Reference: [g.cpp](g.cpp)

---

## 🔹 Floyd's Triangle

A right triangle filled with sequential numbers starting from 1.

### Pattern Example (n=5)

```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row 1: Number 1              → 1 number               │
│ • Row 2: Numbers 2, 3          → 2 numbers              │
│ • Row 3: Numbers 4, 5, 6       → 3 numbers              │
│ • Row i: i consecutive numbers                         │
│                                                        │
│ • Uses a counter variable that increments across loops │
│ • Each outer loop iteration doesn't reset counter      │
│ • Numbers printed in sequential order                  │
│ • Popular competitive programming practice problem    │
└────────────────────────────────────────────────────────┘
```

Reference: [h.cpp](h.cpp)

---

## 🔹 Diamond Pattern

A diamond shape created by combining an upper pyramid and lower inverted pyramid.

### Pattern Example (n=5)

```
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Upper half: Right-aligned pyramid (rows 0 to n)     │
│ • Lower half: Inverted pyramid (rows n-1 to 0)        │
│                                                        │
│ • Upper half logic:                                    │
│   - Spaces: n - i - 1                                  │
│   - Stars: i + 1                                       │
│                                                        │
│ • Lower half logic:                                    │
│   - Spaces: i                                          │
│   - Stars: n - i - 1                                   │
│                                                        │
│ • Creates symmetrical diamond effect                  │
│ • Total rows = 2*n - 1                                 │
└────────────────────────────────────────────────────────┘
```

Reference: [i.cpp](i.cpp)

---

## 🔹 Butterfly Pattern

A symmetric pattern that resembles butterfly wings.

### Pattern Example (n=5)

```
*         *
* *     * *
* * * * * *
* *     * *
*         *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Left wing: Increasing stars, right padding spaces   │
│ • Right wing: Increasing stars, left padding spaces   │
│ • Middle row: All stars (widest point)                 │
│ • Total rows = n                                       │
│                                                        │
│ • For row i:                                           │
│   - Left stars: i + 1                                  │
│   - Middle spaces: n*2 - 2*(i+1)                       │
│   - Right stars: i + 1                                 │
│                                                        │
│ • Symmetric about both axes                            │
│ • Complex spacing calculation required                 │
└────────────────────────────────────────────────────────┘
```

Reference: [j.cpp](j.cpp)

---

## 🔹 Binary Triangle Pattern (0-1 Triangle)

A triangle pattern filled with alternating 0s and 1s in a specific pattern.

### Pattern Example (n=5)

```
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Left-most element depends on row number              │
│ • If row number is odd: starts with 1                  │
│ • If row number is even: starts with 0                 │
│                                                        │
│ • Calculation for element at (i, j):                   │
│   - If (i + j) is even → print 0                       │
│   - If (i + j) is odd  → print 1                       │
│                                                        │
│ • Creates alternating checkerboard pattern            │
│ • Good for understanding 2D logic                      │
└────────────────────────────────────────────────────────┘
```

Reference: [k.cpp](k.cpp)

---

## 🔹 Rhombus Pattern

A rhombus (diamond-like) shape with a solid fill.

### Pattern Example (n=5)

```
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Upper half: Expanding pyramid with spaces           │
│ • Lower half: Contracting pyramid with spaces         │
│                                                        │
│ • Upper half (i = 0 to n-1):                           │
│   - Leading spaces: n - 1 - i                          │
│   - Stars: i + 1                                       │
│                                                        │
│ • Lower half (i = n-1 down to 0):                      │
│   - Leading spaces: n - 1 - i                          │
│   - Stars: i                                           │
│                                                        │
│ • Symmetric pattern both vertically and horizontally  │
│ • Creates perfect rhombus shape                        │
└────────────────────────────────────────────────────────┘
```

Reference: [l.cpp](l.cpp)

---

## 🔹 Palindrome Pyramid Pattern

A pyramid where each row contains numbers that read the same forwards and backwards.

### Pattern Example (n=5)

```
1
1 2 1
1 2 3 2 1
1 2 3 4 3 2 1
1 2 3 4 5 4 3 2 1
```

### Characteristics

```
┌────────────────────────────────────────────────────────┐
│ • Row i: Numbers from 1 to i, then back down to 1     │
│ • Row 1: 1                                             │
│ • Row 2: 1, 2, 1 (palindrome)                          │
│ • Row 3: 1, 2, 3, 2, 1 (palindrome)                    │
│                                                        │
│ • First inner loop: Print 1 to i+1 (increasing)       │
│ • Second inner loop: Print i down to 1 (decreasing)   │
│                                                        │
│ • Each row is a palindrome                             │
│ • Demonstrates reverse loop logic                      │
│ • Combines multiple loop patterns                      │
└────────────────────────────────────────────────────────┘
```

Reference: [m.cpp](m.cpp)

---

## 🔹 Best Practices for Pattern Printing

```
┌────────────────────────────────────────────────────────┐
│         Pattern Printing Best Practices                │
├────────────────────────────────────────────────────────┤
│ ✓ Always initialize outer loop for row control         │
│ ✓ Use meaningful variable names (i, j for nested)     │
│ ✓ Plan pattern logic before coding                     │
│ ✓ Test with small values (n=3 or n=4) first           │
│ ✓ Break complex patterns into steps                    │
│ ✓ Use helper variables for complex calculations       │
│ ✓ Add comments explaining loop conditions             │
│ ✓ Print patterns to console for visual verification   │
│                                                        │
│ ✗ Don't hardcode pattern values                        │
│ ✗ Don't skip the "why" of each loop condition         │
│ ✗ Don't nest more than 3 loops (becomes confusing)    │
│ ✗ Don't mix different pattern logic without clarity    │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Problem-Solving Strategy

```
┌────────────────────────────────────────────────────────┐
│      Pattern Printing Problem-Solving Steps            │
├────────────────────────────────────────────────────────┤
│                                                        │
│ 1. ANALYZE: Understand the pattern                    │
│    • Count rows and elements per row                   │
│    • Identify the rule for each row                    │
│    • Notice any spacing or indentation                │
│                                                        │
│ 2. PLAN: Design the solution                          │
│    • Write outer loop for rows                         │
│    • Write inner loop logic for each row              │
│    • Identify what to print in each iteration         │
│                                                        │
│ 3. IMPLEMENT: Write the code                          │
│    • Start with basic nested loops                     │
│    • Add spacing logic if needed                       │
│    • Add character/number logic                        │
│                                                        │
│ 4. TEST: Verify with small inputs                     │
│    • Try n=3, then n=4, then n=5                      │
│    • Check edge cases (n=1, n=0 if applicable)        │
│    • Print output to verify correctness                │
│                                                        │
│ 5. OPTIMIZE: Improve if needed                        │
│    • Reduce redundant calculations                     │
│    • Use efficient space/character printing            │
│    • Consider performance for large n                 │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Common Pattern Categories

```
┌──────────┬────────────────────┬─────────────────┐
│ Category │ Characteristics    │ Difficulty      │
├──────────┼────────────────────┼─────────────────┤
│ Pyramids │ Increasing/        │ Easy/Medium     │
│          │ Decreasing rows    │                 │
│          │                    │                 │
│ Hollow   │ Border printing    │ Medium          │
│          │ Only frame visible │                 │
│          │                    │                 │
│ Symmetric│ Mirror pattern     │ Medium          │
│          │ Both halves needed │                 │
│          │                    │                 │
│ Complex  │ Multiple           │ Hard            │
│          │ calculations per   │                 │
│          │ iteration          │                 │
│          │                    │                 │
│ Numbered │ Sequential or      │ Medium          │
│          │ Pattern numbers    │                 │
└──────────┴────────────────────┴─────────────────┘
```

---

## 🔹 Summary Table

```
┌────┬──────────────────────┬──────────────────────────┐
│ # │ Pattern Name         │ File Reference           │
├────┼──────────────────────┼──────────────────────────┤
│ 1  │ Star Triangle        │ [b.cpp](b.cpp)           │
│ 2  │ Inverted Star        │ [c.cpp](c.cpp)           │
│ 3  │ Half Pyramid         │ [d.cpp](d.cpp)           │
│ 4  │ Character Pyramid    │ [e.cpp](e.cpp)           │
│ 5  │ Hollow Rectangle     │ [f.cpp](f.cpp)           │
│ 6  │ Rotated Pyramid      │ [g.cpp](g.cpp)           │
│ 7  │ Floyd's Triangle     │ [h.cpp](h.cpp)           │
│ 8  │ Diamond Pattern      │ [i.cpp](i.cpp)           │
│ 9  │ Butterfly Pattern    │ [j.cpp](j.cpp)           │
│ 10 │ Binary Triangle      │ [k.cpp](k.cpp)           │
│ 11 │ Rhombus Pattern      │ [l.cpp](l.cpp)           │
│ 12 │ Palindrome Pyramid   │ [m.cpp](m.cpp)           │
└────┴──────────────────────┴──────────────────────────┘
```
