# DSA with C++ — Module 8 Notes

---

## 🔹 Introduction

This module covers **functions** in C++. Functions are fundamental building blocks that promote code reusability, modularity, and maintainability. Understanding functions, their parameters, memory management, and scoping is essential for writing clean, organized, and efficient code.

---

## 🔹 What Are Functions?

A **function** is a reusable block of code that performs a specific task. Functions help organize code into logical units, reduce redundancy, and improve code readability.

### Basic Syntax

```cpp
returnType functionName(parameters) {
    // Function body - code to execute
    return value;  // optional, depends on return type
}

functionName(arguments);  // Function call
```

### How Functions Work

```
┌────────────────────────────────────────────┐
│ Program execution in main()                │
│         ↓                                  │
│ Function call encountered                  │
│         ↓                                  │
│ Jump to function definition                │
│         ↓                                  │
│ Execute function body                      │
│         ↓                                  │
│ Return control to calling location         │
│         ↓                                  │
│ Continue with next statement               │
└────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│           Function Characteristics                     │
├────────────────────────────────────────────────────────┤
│ • Functions execute only when called                   │
│ • Execution always starts from main()                  │
│ • Functions can have inputs (parameters)               │
│ • Functions can return values or void (nothing)        │
│ • Functions promote code reusability                   │
│ • Functions should have a single responsibility        │
└────────────────────────────────────────────────────────┘
```

### Return Types

- **Specific Type** (int, double, char, etc.): Function must return a value of that type
- **void**: Function does not return any value

### Common Use Cases

Reference: [a.cpp](a.cpp) - Basic function structure and execution

---

## 🔹 Defining and Calling Functions

Functions must be defined before they are used in the program. The structure consists of a definition and a call.

### Function Definition

A **function definition** includes the complete implementation with the return type, name, parameters, and body.

### Function Call

A **function call** is when you invoke the function using its name and pass the necessary arguments.

### Execution Flow

When main() executes:

1. Statements in main() execute sequentially
2. When a function call is encountered, control jumps to that function
3. The function executes completely
4. Control returns to the statement after the function call in main()

Reference: [b.cpp](b.cpp) - Indirect function calling and execution order

---

## 🔹 Forward Declaration

**Forward declaration** (also called function prototype) allows you to declare a function before defining it. This is useful when organizing code or when functions call each other.

### Declaration vs Definition

```
┌────────────────────────────────────────────────────────┐
│                Declaration vs Definition               │
├────────────────────────────────────────────────────────┤
│ DECLARATION (Function Prototype):                       │
│ • Specifies function name, return type, parameters     │
│ • Ends with semicolon                                  │
│ • Example: int add(int a, int b);                      │
│                                                        │
│ DEFINITION (Function Implementation):                  │
│ • Includes the complete function body                  │
│ • No semicolon, has braces {}                          │
│ • Example: int add(int a, int b) { return a + b; }    │
└────────────────────────────────────────────────────────┘
```

### Best Practice

- Declare all functions at the top of the file (before main)
- Define functions after the main function
- This provides a clear interface of what functions exist

Reference: [c.cpp](c.cpp) - Forward declaration usage

---

## 🔹 Parameters and Arguments

**Parameters** are variables in the function definition that specify what data the function needs. **Arguments** are the actual values passed when calling the function.

### Understanding Parameters vs Arguments

```
┌────────────────────────────────────────────────────────┐
│           Parameters vs Arguments                      │
├────────────────────────────────────────────────────────┤
│ PARAMETERS:                                            │
│ • Variables defined in function signature             │
│ • Part of function definition                          │
│ • Example: int add(int a, int b) - a, b are params    │
│                                                        │
│ ARGUMENTS:                                             │
│ • Actual values passed during function call            │
│ • Example: add(5, 3) - 5 and 3 are arguments          │
│ • Must match parameter types and order                 │
└────────────────────────────────────────────────────────┘
```

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│          Parameter/Argument Characteristics            │
├────────────────────────────────────────────────────────┤
│ • Parameters allow functions to accept input           │
│ • Multiple parameters separated by commas              │
│ • Argument count must match parameter count            │
│ • Argument types must be compatible with parameters    │
│ • Arguments are passed in order (left to right)        │
│ • Parameters have function-level scope                 │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

- [d.cpp](d.cpp) - Functions with multiple parameters
- [f.cpp](f.cpp) - Function for product of two numbers
- [g.cpp](g.cpp) - Function for even-odd checking
- [h.cpp](h.cpp) - Factorial function using parameters

---

## 🔹 Default Parameters

**Default parameters** allow you to specify a default value for parameters. If no argument is provided for a parameter with a default value, the default is used.

### Syntax

```cpp
returnType functionName(type param1, type param2 = defaultValue) {
    // Function body
}
```

### Key Rules

```
┌────────────────────────────────────────────────────────┐
│         Default Parameter Rules                        │
├────────────────────────────────────────────────────────┤
│ • Default parameters must be declared in order         │
│ • Once you use a default parameter, all following      │
│   parameters must also have default values             │
│ • The first parameter CANNOT be a default parameter    │
│ • Defaults can only be specified in declaration        │
│ • Cannot repeat default values in definition           │
│ • Improves function flexibility and usability          │
└────────────────────────────────────────────────────────┘
```

### Example

```
functionName(a, b = 5, c = 10)  ✓ VALID
functionName(a = 1, b, c)       ✗ INVALID (first param has default)
```

Reference: [e.cpp](e.cpp) - Default parameter usage

---

## 🔹 Functions in Memory

Understanding how functions use computer memory is crucial for writing efficient programs. C++ uses two main memory regions: the **Stack** and the **Heap**.

### Memory Types

```
┌────────────────────────────────────────────────────────┐
│              Memory in C++                             │
├────────────────────────────────────────────────────────┤
│ STACK: Static memory allocation                        │
│ • Used for function calls and local variables          │
│ • Automatically managed (freed when scope ends)        │
│ • Fast access                                          │
│ • Limited size                                         │
│ • LIFO (Last In, First Out) structure                  │
│                                                        │
│ HEAP: Dynamic memory allocation                        │
│ • Used for dynamic memory (pointers, new/delete)       │
│ • Manually managed (programmer's responsibility)       │
│ • Slower access than stack                             │
│ • Larger available memory                              │
│ • Persists until explicitly freed                      │
└────────────────────────────────────────────────────────┘
```

### Stack Frames

When a function is called, a **stack frame** (also called activation record) is created on the stack. This frame contains:

- Function parameters
- Local variables
- Return address
- Other function state information

### Function Call Stack

```
┌─────────────────────────────────────────────────────────┐
│                    Memory Stack                         │
├─────────────────────────────────────────────────────────┤
│ main() stack frame                                      │
│   ├── main()'s local variables                          │
│   ├── main()'s parameters                              │
│   └── function1() stack frame (called from main)       │
│       ├── function1()'s local variables                │
│       ├── function1()'s parameters                     │
│       └── function2() stack frame (called from func1)  │
│           ├── function2()'s local variables            │
│           └── function2()'s parameters                 │
│                                                        │
│ Current function is ALWAYS at the TOP of the stack     │
└─────────────────────────────────────────────────────────┘
```

### Stack Frame Lifecycle

1. **Creation**: Stack frame created when function is called
2. **Execution**: Function body executes, stack frame holds variables
3. **Return**: Function completes and returns a value (if any)
4. **Deletion**: Stack frame is deleted, memory is freed automatically

### Key Characteristics

```
┌────────────────────────────────────────────────────────┐
│         Function Memory Characteristics                │
├────────────────────────────────────────────────────────┤
│ • Each function call gets its own stack frame          │
│ • Even main() has a stack frame                        │
│ • Nested functions create stacked frames               │
│ • When function returns, its frame is removed          │
│ • Memory is automatically reclaimed                    │
│ • Local variables only exist during function call      │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Scope

**Scope** refers to the region or context in which a variable is accessible. Understanding scope is crucial for managing variables and avoiding naming conflicts.

### Types of Scope

```
┌────────────────────────────────────────────────────────┐
│              Scope Types in C++                        │
├────────────────────────────────────────────────────────┤
│ LOCAL SCOPE:                                           │
│ • Variables defined within a function                  │
│ • Accessible only within that function                 │
│ • Includes loop variables, conditional blocks         │
│ • Created when scope begins, destroyed when ends      │
│                                                        │
│ GLOBAL SCOPE:                                          │
│ • Variables defined outside any function               │
│ • Accessible from any function in the program          │
│ • Defined at the top of the file                       │
│ • Exist for the entire program duration                │
│                                                        │
│ BLOCK SCOPE:                                           │
│ • Variables within {} braces                           │
│ • Examples: loops, if-else, functions                  │
│ • Each block creates its own local scope               │
└────────────────────────────────────────────────────────┘
```

### Scope Example

```cpp
int global = 10;  // Global scope - accessible everywhere

void function1() {
    int local1 = 20;  // Local to function1
    // Can access: global, local1

    if (true) {
        int local2 = 30;  // Local to if block
        // Can access: global, local1, local2
    }
    // Cannot access: local2 (out of scope)
}

void function2() {
    // Can access: global
    // Cannot access: local1 (belongs to function1)
}
```

### Best Practices for Scope

```
┌────────────────────────────────────────────────────────┐
│         Scope Best Practices                           │
├────────────────────────────────────────────────────────┤
│ • Define variables with narrowest scope possible       │
│ • Prefer local over global (easier to manage)          │
│ • Minimize use of global variables                     │
│ • Local variables are safer and more readable          │
│ • Group related variables together                     │
│ • Use meaningful variable names to avoid conflicts     │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

Reference: [i.cpp](i.cpp) - Prime number checker with scoping

---

## 🔹 Function Overloading

**Function overloading** allows you to have multiple functions with the same name but different parameters. The compiler automatically selects the appropriate function based on the arguments provided.

### What is Overloading?

When you have multiple functions with the same name but different parameter lists, you're using function overloading. This provides a convenient way to use the same function name for similar operations.

### How to Overload

You can differentiate functions by:

```
┌────────────────────────────────────────────────────────┐
│           Ways to Differentiate Functions              │
├────────────────────────────────────────────────────────┤
│ 1. DIFFERENT NUMBER OF PARAMETERS:                     │
│    • void display(int x)                               │
│    • void display(int x, int y)                        │
│    • void display(int x, int y, int z)                 │
│                                                        │
│ 2. DIFFERENT PARAMETER TYPES:                          │
│    • void display(int x)                               │
│    • void display(double x)                            │
│    • void display(char x)                              │
│                                                        │
│ 3. COMBINATION OF BOTH:                                │
│    • void display(int x)                               │
│    • void display(int x, double y)                     │
└────────────────────────────────────────────────────────┘
```

### What Cannot Be Overloaded

```
┌────────────────────────────────────────────────────────┐
│    Overloading Restrictions                            │
├────────────────────────────────────────────────────────┤
│ ✗ Return type ALONE - cannot differentiate             │
│   int func() and double func() are INVALID             │
│ ✗ Combined with other differences works, but           │
│   return type alone is not enough                      │
│                                                        │
│ ✓ Return type + parameter difference:                  │
│   int func(int x) and double func(double x) OK         │
└────────────────────────────────────────────────────────┘
```

### Compiler Resolution

When you call an overloaded function, the compiler:

1. Looks at the function name
2. Checks the argument count and types
3. Finds the matching function definition
4. Calls that specific function

### Benefits

```
┌────────────────────────────────────────────────────────┐
│         Function Overloading Benefits                  │
├────────────────────────────────────────────────────────┤
│ • Improves code readability with same function name    │
│ • Makes code more intuitive and easier to use          │
│ • Reduces naming conflicts                             │
│ • Enables polymorphism and flexibility                 │
│ • Simplifies API design                                │
└────────────────────────────────────────────────────────┘
```

### Common Use Cases

Reference: [k.cpp](k.cpp) - Demonstrating why overloading is necessary

---

## 🔹 Practice Problems

The following programs demonstrate practical applications of functions:

```
┌───────┬──────────────────────────────┬──────────────────────┐
│ File  │ Problem                      │ Concepts Covered     │
├───────┼──────────────────────────────┼──────────────────────┤
│ j.cpp │ Binomial Coefficient         │ Parameters, recursion│
│ m.cpp │ Primes in Range 2 to n       │ Overloading, loops   │
│ n.cpp │ Palindrome Checker           │ String manipulation  │
│ o.cpp │ Sum of Digits                │ Digit extraction     │
│ p.cpp │ Next Character               │ Character handling   │
│ q.cpp │ Maximum of Three Numbers     │ Overloading         │
│ r.cpp │ Perfect Square Checker       │ Mathematical logic   │
└───────┴──────────────────────────────┴──────────────────────┘
```

---

## 🔹 Best Practices for Functions

```
┌────────────────────────────────────────────────────────┐
│              Function Best Practices                   │
├────────────────────────────────────────────────────────┤
│ NAMING & STRUCTURE:                                    │
│ ✓ Use descriptive function names (verbs advised)       │
│ ✓ Keep functions focused on single task                │
│ ✓ Avoid overly long functions (≤50 lines is good)      │
│ ✓ Use forward declarations for clarity                 │
│                                                        │
│ PARAMETERS:                                            │
│ ✓ Use meaningful parameter names                       │
│ ✓ Minimize number of parameters (≤4 is ideal)          │
│ ✓ Use default parameters for optional values           │
│ ✓ Order parameters logically                           │
│                                                        │
│ MEMORY & SCOPE:                                        │
│ ✓ Use local variables when possible                    │
│ ✓ Minimize global variables                            │
│ ✓ Return values by value for simple types              │
│ ✓ Be aware of stack memory limitations                 │
│                                                        │
│ DOCUMENTATION:                                         │
│ ✓ Add comments explaining function purpose             │
│ ✓ Document parameters and return values                │
│ ✓ Include complexity analysis if relevant              │
│ ✓ Provide usage examples                               │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Summary

Functions are the building blocks of modular, maintainable C++ code. Key takeaways:

```
┌────────────────────────────────────────────────────────┐
│         Key Concepts Summary                           │
├────────────────────────────────────────────────────────┤
│ • Functions promote code reusability                   │
│ • Understand forward declaration for organization      │
│ • Parameters and arguments work together               │
│ • Default parameters increase flexibility              │
│ • Stack frames manage function memory                  │
│ • Scope controls variable accessibility                │
│ • Overloading enables polymorphic behavior             │
│ • All concepts work together for clean code            │
└────────────────────────────────────────────────────────┘
```
