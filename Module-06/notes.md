# DSA with C++ — Module 6 Notes

---

## 🔹 Introduction

This module covers **looping constructs** in C++. Loops are fundamental control flow structures that allow you to execute a block of code repeatedly. Understanding different loop types and their use cases is essential for writing efficient and concise code.

---

## 🔹 Loops Overview

Loops are used to execute a block of code repeatedly as long as a specified condition is true. This prevents code repetition and enables processing of large datasets efficiently.

```
┌────────────────────────────────────────────┐
│           Types of Loops in C++            │
├────────────────────────────────────────────┤
│ 1. for loop                                │
│ 2. while loop                              │
│ 3. do-while loop                           │
└────────────────────────────────────────────┘
```

---

## 🔹 1. FOR Loop

The **for loop** is the most commonly used loop structure. It combines initialization, condition checking, and increment/decrement operations in a single, concise statement.

### Basic Syntax

```cpp
for (initialization; condition; updation) {
    // Code block (loop body)
}
```

### How For Loop Works

```
┌───────────────────────────────────────────────────┐
│ Initialize variable (runs once)                   │
│         ↓                                         │
│ Check condition → TRUE → Execute loop body        │
│         ↓                                         │
│ FALSE → Exit loop                                 │
│         ↓                                         │
│ Execute updation statement                        │
│         ↓                                         │
│ Go back to condition check                        │
└───────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│              FOR Loop Characteristics                  │
├────────────────────────────────────────────────────────┤
│ • All three parts (init, condition, update) are        │
│   optional but generally recommended                   │
│ • Variables declared in initialization have scope     │
│   only within the loop                                │
│ • Initialization runs exactly once before loop starts  │
│ • Condition is checked before each iteration           │
│ • Updation happens after each iteration                │
│ • Best for fixed number of iterations                 │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- [a.cpp](a.cpp) - Basic for loop structure and iteration
- [c.cpp](c.cpp) - Printing a value multiple times
- [d.cpp](d.cpp) - Printing numbers from 1 to n
- [e.cpp](e.cpp) - Sum of n natural numbers

### Performance Tip

The sum of n natural numbers can be calculated directly using the formula $ \frac{n \times (n+1)}{2} $ instead of looping through all numbers, resulting in $ O(1) $ time complexity instead of $ O(n) $.

---

## 🔹 Infinite Loop

An **infinite loop** occurs when the loop condition is always true, causing the loop to run indefinitely. This fills system memory (RAM) and should be avoided unless intentionally designed.

### When Infinite Loops Occur

```
┌────────────────────────────────────────────────────────┐
│ Condition is always TRUE                               │
│         ↓                                              │
│ Loop body executes                                     │
│         ↓                                              │
│ Condition checked again → Still TRUE                   │
│         ↓                                              │
│ Never exits → System memory fills up                   │
└────────────────────────────────────────────────────────┘
```

### Example in Code

```cpp
// ❌ INFINITE LOOP: Condition always true
for (int i = 1; i > 0; i++) {
    // This runs forever because i keeps increasing
    // and i > 0 is always true
}

// ✓ Correct loop with proper termination
for (int i = 1; i <= 10; i++) {
    // Runs exactly 10 times, then i becomes 11
    // and the condition (i <= 10) becomes false
}
```

### Avoiding Infinite Loops

```
┌────────────────────────────────────────────────────────┐
│ Common Causes & Solutions                              │
├────────────────────────────────────────────────────────┤
│ • Missing updation statement                           │
│   Solution: Always update loop variable                │
│                                                        │
│ • Wrong comparison operator (< instead of >)           │
│   Solution: Verify condition logic                     │
│                                                        │
│ • Condition that never changes                         │
│   Solution: Ensure loop variable is modified           │
│                                                        │
│ • Off-by-one errors                                    │
│   Solution: Test boundary conditions carefully         │
└────────────────────────────────────────────────────────┘
```

Reference: [b.cpp](b.cpp)

---

## 🔹 2. WHILE Loop

The **while loop** continues to execute a block of code as long as a specified condition is true. It checks the condition before each iteration.

### Basic Syntax

```cpp
while (condition) {
    // Code block (loop body)
}
```

### How While Loop Works

```
┌────────────────────────────────────────────────┐
│ Check condition → TRUE → Execute loop body     │
│         ↓                                      │
│ Go back to condition check                     │
│         ↓                                      │
│ FALSE → Exit loop                              │
└────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│            WHILE Loop Characteristics                  │
├────────────────────────────────────────────────────────┤
│ • Condition is checked before loop body executes       │
│ • If condition is false initially, loop never runs     │
│ • Loop variable must be initialized before loop        │
│ • Loop variable must be updated inside loop body       │
│ • Good for unknown number of iterations                │
│ • More flexible than for loop for complex conditions   │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- [f.cpp](f.cpp) - Basic while loop usage
- [g.cpp](g.cpp) - Pattern printing with while loop
- [h.cpp](h.cpp) - Printing numbers from n to 1
- [i.cpp](i.cpp) - Sum of digits of a number
- [j.cpp](j.cpp) - Sum of odd digits only

---

## 🔹 3. DO-WHILE Loop

The **do-while loop** is similar to the while loop, except the condition is checked **after** the loop body executes. This ensures the loop body runs at least once.

### Basic Syntax

```cpp
do {
    // Code block (loop body) - always runs at least once
} while (condition);
```

### How Do-While Loop Works

```
┌────────────────────────────────────────────────┐
│ Execute loop body at least once                │
│         ↓                                      │
│ Check condition → TRUE → Execute body again    │
│         ↓                                      │
│ FALSE → Exit loop                              │
└────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│          DO-WHILE Loop Characteristics                 │
├────────────────────────────────────────────────────────┤
│ • Loop body ALWAYS executes at least once              │
│ • Condition is checked AFTER each iteration            │
│ • Useful for menu-driven programs                      │
│ • Good for input validation (ask again if invalid)    │
│ • Remember the semicolon after the condition           │
│ • Less commonly used than for and while loops          │
└────────────────────────────────────────────────────────┘
```

### When to Use

Use do-while loops when:

- You need guaranteed execution of loop body at least once
- Implementing menu systems where user must make a choice
- Validating user input (keep asking until valid)

Reference: [k.cpp](k.cpp)

---

## 🔹 4. BREAK Statement

The **break statement** is used to **immediately terminate a loop** and exit to the next statement after the loop. It is triggered when a specific condition is met.

### Syntax

```cpp
if (condition) {
    break;  // Exit loop immediately
}
```

### How Break Works

```
┌──────────────────────────────────────────────┐
│ Loop body executing                          │
│         ↓                                    │
│ If condition met → break executed            │
│         ↓                                    │
│ Exit loop and continue after loop            │
│         ↓                                    │
│ Next statement after loop executes           │
└──────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│           BREAK Statement Characteristics              │
├────────────────────────────────────────────────────────┤
│ • Terminates the innermost loop                        │
│ • Used in for, while, and do-while loops               │
│ • Used in switch statements                            │
│ • Provides early exit mechanism                        │
│ • Useful for finding elements or error conditions      │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- Exiting when a target value is found
- Stopping loop on invalid input
- Error handling within loops

Reference: [l.cpp](l.cpp), [m.cpp](m.cpp)

---

## 🔹 5. CONTINUE Statement

The **continue statement** is used to **skip the current iteration** and jump to the next iteration of the loop. The rest of the loop body is skipped, but the loop continues.

### Syntax

```cpp
if (condition) {
    continue;  // Skip to next iteration
}
```

### How Continue Works

```
┌──────────────────────────────────────────────┐
│ Loop body executing                          │
│         ↓                                    │
│ If condition met → continue executed         │
│         ↓                                    │
│ Skip remaining statements in loop body       │
│         ↓                                    │
│ Go to next iteration                         │
└──────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│          CONTINUE Statement Characteristics            │
├────────────────────────────────────────────────────────┤
│ • Skips the current iteration                          │
│ • Continues with the next iteration                    │
│ • Used in for, while, and do-while loops               │
│ • Useful for filtering or skipping specific cases      │
│ • Does not exit the loop                               │
└────────────────────────────────────────────────────────┘
```

### Comparison: Break vs Continue

```
┌──────────────────────┬──────────────┬─────────────────┐
│ Aspect               │ Break        │ Continue        │
├──────────────────────┼──────────────┼─────────────────┤
│ Action               │ Exit loop    │ Skip iteration  │
│ Loop continuation    │ Stops        │ Continues       │
│ Used for             │ Early exit   │ Filtering       │
│ Control flow         │ Next code    │ Next iteration  │
└──────────────────────┴──────────────┴─────────────────┘
```

Reference: [n.cpp](n.cpp), [o.cpp](o.cpp)

---

## 🔹 Prime Number Checking

A **prime number** is a natural number greater than 1 that has no positive divisors other than 1 and itself. Checking primality is a common algorithmic problem.

### Basic Approach

To check if number `n` is prime, test if any number from 2 to (n-1) divides `n` evenly.

### Optimized Approach

Only check divisors up to $ \sqrt{n} $ instead of $ n $. If no divisor exists up to the square root, then `n` is prime.

### Why This Works

If $ a \times b = n $ where $ a \leq b $, then $ a \leq \sqrt{n} $. So if `n` is composite, at least one factor exists that is $ \leq \sqrt{n} $.

### Time Complexity

```
┌────────────────────────────────────────────────────────┐
│              Prime Checking Complexity                 │
├────────────────────────────────────────────────────────┤
│ • Basic approach:     O(n)       - Check until n       │
│ • Optimized approach: O(√n)      - Check until √n      │
│                                                        │
│ Example: Check if 100 is prime                         │
│ • Basic:     Check 2 to 99 (98 iterations)             │
│ • Optimized: Check 2 to 10 (9 iterations)              │
│ • Over 10x faster!                                     │
└────────────────────────────────────────────────────────┘
```

Reference: [p.cpp](p.cpp) - Basic approach, [q.cpp](q.cpp) - Optimized approach

---

## 🔹 Practice Problems

The following programs demonstrate practical applications of loops:

```
┌──────┬──────────────────────────────────┬─────────────────────────┐
│ File │ Problem                          │ Concepts Covered        │
├──────┼──────────────────────────────────┼─────────────────────────┤
│ r.cpp│ Factorial of a Number            │ Loops, multiplication   │
│ s.cpp│ Multiplication Table             │ Nested loops            │
│ t.cpp│ Armstrong Number Checker         │ Digit extraction        │
│ u.cpp│ All Prime Numbers Until n        │ Prime checking, loops   │
│ v.cpp│ Fibonacci Sequence Until n       │ Series generation       │
└──────┴──────────────────────────────────┴─────────────────────────┘
```

---

## 🔹 Best Practices for Loops

```
┌────────────────────────────────────────────────────────┐
│              Loop Best Practices                       │
├────────────────────────────────────────────────────────┤
│ FOR LOOPS:                                             │
│ ✓ Use when number of iterations is known              │
│ ✓ Keep loop body simple and focused                   │
│ ✓ Use meaningful variable names (i, j, k acceptable)  │
│ ✓ Initialize loop counter properly                    │
│ ✗ Don't modify loop variable in complex ways          │
│                                                        │
│ WHILE LOOPS:                                           │
│ ✓ Use for unknown iteration count                      │
│ ✓ Ensure loop variable is always updated              │
│ ✓ Verify condition will eventually become false       │
│ ✗ Avoid infinite loops                                │
│                                                        │
│ DO-WHILE LOOPS:                                        │
│ ✓ Use when body must execute at least once            │
│ ✓ Ideal for menu-driven systems                       │
│ ✓ Remember the semicolon after while                  │
│                                                        │
│ GENERAL:                                               │
│ ✓ Use break/continue judiciously                      │
│ ✓ Keep nested loops under 2-3 levels                  │
│ ✓ Consider optimization for large datasets             │
│ ✗ Don't create unnecessarily complex conditions       │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Nested Loops

**Nested loops** occur when one loop is placed inside another loop. The inner loop completes all its iterations for each iteration of the outer loop.

### Example Structure

```
Outer loop iteration 1
  Inner loop iteration 1
  Inner loop iteration 2
  Inner loop iteration 3
Outer loop iteration 2
  Inner loop iteration 1
  Inner loop iteration 2
  Inner loop iteration 3
Outer loop iteration 3
  Inner loop iteration 1
  Inner loop iteration 2
  Inner loop iteration 3
```

### Time Complexity

For nested loops, the total operations = outer iterations × inner iterations

Example: Two nested loops each running 10 times = 10 × 10 = 100 operations

Reference: [s.cpp](s.cpp) - Multiplication table using nested loops
