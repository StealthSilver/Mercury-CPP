# 📘 DSA with C++ — Module 2 Notes

## C++ and Other Programming Languages

---

## 🔹 Introduction

This module introduces **C++ as a programming language** and explains the foundational concepts required before starting Data Structures and Algorithms (DSA).  
It focuses on understanding how C++ programs are structured, how they execute, and how compilation works.

---

## 🔹 C++ Source Code Files

- C++ programs are written in files with the **.cpp** extension.
- Each `.cpp` file contains instructions written using the C++ programming language.

Example illustration file:

- a.cpp

---

## 🔹 a.cpp — C++ Boilerplate Code (Template Code)

This file represents the **basic template of a C++ program**.  
Every C++ program follows this basic structure.

Illustration file:

- a.cpp

---

## 🔹 Explanation of Boilerplate Code

The `#include <iostream>` line is a **preprocessor directive**.  
It is used to include prewritten code from the standard library.  
This header file enables input and output operations such as `cin` and `cout`.

The `using namespace std;` statement allows direct access to standard library objects.  
Without this, we would need to write `std::cout` or `std::cin` every time.

The `int main()` function is the **starting point of execution**.  
Every C++ program must contain a `main()` function.

Curly braces `{ }` define a **block of code**.  
Any block of code in C++ is written inside curly braces.

The `return 0;` statement ends the program and indicates successful execution.

---

## 🔹 Important Rules in C++

- Any C++ program executes **from top to bottom**
- Program execution always begins from the `main()` function
- Every statement in C++ must end with a **semicolon ( ; )**
- Curly braces define the scope of a block

---

## 🔹 How Does the Code Run?

The execution process of a C++ program follows this flow:

code.cpp → Compiler → Executable File → Output

The compiler converts the source code into an executable file.  
The executable file is then run to produce output.

---

## 🔹 Executable File Extensions

- On **Windows**, the executable file extension is **.exe**
- On **Linux-based systems**, the executable file extension is **.out**

---

## 🔹 Running a C++ Program in a Code Editor

After writing the code, the program is executed in two steps:

1. **Compilation step**  
   The compiler checks the code and creates an executable file.

2. **Execution step**  
   The executable file is run to produce output.

---

## 🔹 b.cpp — First C++ Program

This file demonstrates the **first output program in C++**.

Illustration file:

- b.cpp

Key points:

- `cout` is used to print output
- `<<` is known as the insertion operator
- Semicolon marks the end of the statement

---

## 🔹 Output in C++

- Output in C++ is displayed using `cout`
- Multiple values can be printed using the insertion operator
- Every output statement must end with a semicolon

---

## 🔹 Preprocessor Directives

- Preprocessor directives start with the `#` symbol
- They are processed **before compilation**
- Used to include header files or define constants

Examples of usage:

- Input and output operations
- Mathematical functions
- Data structures such as stacks and queues

---

## 🔹 c.cpp — Macros Definition

Macros are **symbolic constants** defined using preprocessor directives.

Illustration file:

- c.cpp

Characteristics of macros:

- They are global constants
- Defined at the top of the file
- Their values cannot be changed during execution
- They do not have a data type

---

## 🔹 Key Points About Macros

- Macros are replaced during preprocessing
- They improve code readability
- Commonly used for fixed values

---
