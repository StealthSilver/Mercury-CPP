# DSA with C++ — Module 14 Notes

---

## 🔹 Introduction to Multidimensional Arrays

**Arrays** can have multiple dimensions to represent structured data with more complexity than a simple linear list.

### Types of Arrays

```
┌────────────────────────────────────────────────────────┐
│            Multidimensional Arrays                     │
├────────────────────────────────────────────────────────┤
│ 1D ARRAY (Linear):                                     │
│ • One-dimensional linear arrangement                   │
│ • Syntax: int arr[5];                                  │
│ • Example: [1, 2, 3, 4, 5]                             │
│ • Use: Simple sequences, vectors                       │
│                                                        │
│ 2D ARRAY (Matrix/Table):                               │
│ • Two-dimensional tabular arrangement                  │
│ • Syntax: int mat[3][4];  (3 rows, 4 columns)         │
│ • Represents a matrix with rows and columns            │
│ • Use: Images, spreadsheets, game grids                │
│                                                        │
│ 3D ARRAY (Cubical):                                    │
│ • Three-dimensional cubic arrangement                  │
│ • Syntax: int cube[2][3][4];                           │
│ • Represents volume data                               │
│ • Use: 3D graphics, volumetric data, animations        │
│                                                        │
│ nD ARRAY (General):                                    │
│ • Any number of dimensions possible                    │
│ • Complex data structures                              │
│ • Use: Scientific computing, image processing          │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Two-Dimensional Arrays

A **2D array** (matrix) is a collection of rows and columns, where each element is accessed using two indices: row and column. This is the most commonly used multidimensional array.

### Declaration and Initialization

```
┌────────────────────────────────────────────────────────┐
│        2D Array Declaration & Initialization           │
├────────────────────────────────────────────────────────┤
│ SYNTAX:                                                │
│ data_type arrayName[rows][columns];                    │
│                                                        │
│ EXAMPLE WITH INITIALIZATION:                           │
│ int student[2][3] = {{100, 20, 30},                    │
│                      {30, 40, 50}};                    │
│                                                        │
│ VISUALIZATION:                                         │
│       Col 0  Col 1  Col 2                              │
│ Row 0 [100]  [20]   [30]                               │
│ Row 1 [30]   [40]   [50]                               │
│                                                        │
│ ACCESSING ELEMENTS:                                    │
│ int value = student[1][2];  // Returns 50             │
│                                                        │
│ MEMORY VISUALIZATION:                                  │
│ Sequential memory: [100, 20, 30, 30, 40, 50]           │
│ (2 × 3 = 6 elements total)                             │
└────────────────────────────────────────────────────────┘
```

### Key Terminology

```
┌────────────────────────────────────────────────────────┐
│            2D Array Terminology                        │
├────────────────────────────────────────────────────────┤
│ • Rows: Horizontal lines of elements                   │
│ • Columns: Vertical lines of elements                  │
│ • Cells: Individual elements in the matrix             │
│ • Index: Position identifier (row_index, col_index)   │
│ • Dimensions: 2 for 2D arrays (m rows × n columns)    │
│                                                        │
│ Example: int mat[3][4]                                 │
│ • 3 rows (0, 1, 2)                                     │
│ • 4 columns (0, 1, 2, 3)                               │
│ • Total cells: 3 × 4 = 12                              │
│ • Valid access: mat[0][0] to mat[2][3]                 │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp) - 2D array declaration and basic operations

---

## 🔹 Input and Output for 2D Arrays

Reading from and printing 2D arrays requires nested loops to access each row and column.

### Input/Output Operations

```
┌────────────────────────────────────────────────────────┐
│         Input/Output for 2D Arrays                     │
├────────────────────────────────────────────────────────┤
│ INPUT (Using nested loops):                            │
│ for (int i = 0; i < rows; i++)                         │
│   for (int j = 0; j < cols; j++)                       │
│     cin >> mat[i][j];                                  │
│                                                        │
│ OUTPUT (Formatted printing):                           │
│ for (int i = 0; i < rows; i++) {                       │
│   for (int j = 0; j < cols; j++)                       │
│     cout << mat[i][j] << " ";                          │
│   cout << endl;  // New line after each row            │
│ }                                                      │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(m × n)  where m = rows, n = columns            │
│ Space: O(m × n) for array storage                      │
└────────────────────────────────────────────────────────┘
```

### Example: 3×4 Matrix

```
Input:  1  2  3  4
        5  6  7  8
        9  10 11 12

Output: 1  2  3  4
        5  6  7  8
        9  10 11 12
```

Reference: [b.cpp](b.cpp) - Input and output operations for 2D arrays

---

## 🔹 2D Arrays in Memory

**Important**: A 2D array is stored as a **contiguous block of memory** in linear fashion, even though we visualize it as a table. The order depends on the storage method used by the compiler.

### Storage Layouts

```
┌────────────────────────────────────────────────────────┐
│         Memory Storage Methods                         │
├────────────────────────────────────────────────────────┤
│ Visual Matrix (3×3):                                   │
│    [1]  [2]  [3]                                       │
│    [4]  [5]  [6]                                       │
│    [7]  [8]  [9]                                       │
│                                                        │
│ 1. ROW-MAJOR ORDER (C/C++ Default):                    │
│    Memory: [1, 2, 3, 4, 5, 6, 7, 8, 9]                 │
│    Fill rows from left to right, then next row         │
│    Used by: C, C++, Java, Python                       │
│                                                        │
│ 2. COLUMN-MAJOR ORDER (Fortran, MATLAB):               │
│    Memory: [1, 4, 7, 2, 5, 8, 3, 6, 9]                 │
│    Fill columns from top to bottom, then next column   │
│    Used by: Fortran, MATLAB, R                         │
│                                                        │
│ IMPORTANCE:                                            │
│ Understanding storage order affects:                   │
│ • Memory access patterns (cache efficiency)            │
│ • Pointer arithmetic                                   │
│ • Function parameter passing                          │
└────────────────────────────────────────────────────────┘
```

### Memory Address Calculation (Row-Major)

```
┌────────────────────────────────────────────────────────┐
│     Address Calculation for Element                    │
├────────────────────────────────────────────────────────┤
│ For array mat[rows][cols]:                             │
│                                                        │
│ Address of mat[i][j] = base_address +                  │
│                        (i × cols + j) × sizeof(int)    │
│                                                        │
│ Example: mat[2][1] in a 3×3 int matrix                 │
│ Address = base + (2 × 3 + 1) × 4                       │
│         = base + 7 × 4                                 │
│         = base + 28 bytes                              │
│                                                        │
│ This explains why we must specify column count         │
│ when passing 2D arrays to functions!                   │
└────────────────────────────────────────────────────────┘
```

Reference: [c.cpp](c.cpp) - Memory layout demonstration

---

## 🔹 Spiral Matrix Traversal

**Problem**: Print all elements of an n×m matrix in spiral order (clockwise from outside to inside).

### Algorithm Overview

```
┌────────────────────────────────────────────────────────┐
│          Spiral Traversal Approach                     │
├────────────────────────────────────────────────────────┤
│ Maintain four boundaries:                              │
│ • top:    row index of top boundary                    │
│ • bottom: row index of bottom boundary                 │
│ • left:   column index of left boundary                │
│ • right:  column index of right boundary               │
│                                                        │
│ Algorithm Steps:                                       │
│ 1. Traverse right: left to right in top row            │
│ 2. Traverse down:  top to bottom in right column       │
│ 3. Traverse left:  right to left in bottom row         │
│ 4. Traverse up:    bottom to top in left column        │
│ 5. Move inward:    top++, bottom--, left++, right--   │
│ 6. Repeat until top <= bottom && left <= right         │
└────────────────────────────────────────────────────────┘
```

### Step-by-Step Visualization

```
Original Matrix:        Spiral Order:
 1  2  3  4             1  2  3  4
 5  6  7  8      →      5  6  7  8
 9  10 11 12            9  10 11 12

Step 1 (Right):  [1, 2, 3, 4]
Step 2 (Down):   [8, 12]
Step 3 (Left):   [11, 10, 9]
Step 4 (Up):     [5, 6]
Step 5 (Right):  [7]

Final Result: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
```

### Complexity Analysis

```
┌────────────────────────────────────────────────────────┐
│       Spiral Traversal Complexity                      │
├────────────────────────────────────────────────────────┤
│ Time Complexity:  O(m × n)                             │
│   Each element visited exactly once                    │
│   m = number of rows, n = number of columns            │
│                                                        │
│ Space Complexity: O(1)                                 │
│   Only using constant variables for boundaries         │
│   (Not counting output array)                          │
│                                                        │
│ Best Case: O(m × n)                                    │
│ Average Case: O(m × n)                                 │
│ Worst Case: O(m × n)                                   │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp) - Spiral matrix implementation

---

## 🔹 Diagonal Sum

**Problem**: Find the sum of all diagonal elements in a square matrix (both main diagonal and anti-diagonal).

### Diagonal Elements Definition

```
┌────────────────────────────────────────────────────────┐
│            Diagonal Elements                           │
├────────────────────────────────────────────────────────┤
│ For an n×n square matrix:                              │
│                                                        │
│ MAIN DIAGONAL (↘):                                     │
│ Elements where row_index == column_index               │
│ Positions: [0,0], [1,1], [2,2], ..., [n-1, n-1]       │
│                                                        │
│ ANTI-DIAGONAL (↙):                                     │
│ Elements where row_index + column_index == n - 1       │
│ Positions: [0,n-1], [1,n-2], [2,n-3], ..., [n-1, 0]   │
│                                                        │
│ EXAMPLE (4×4 matrix):                                  │
│  A  B  C  D                                            │
│  E  F  G  H     Main Diagonal: A, F, K, P             │
│  I  J  K  L     Anti-Diagonal: D, G, J, M             │
│  M  N  O  P                                            │
│                                                        │
│ NOTE: If n is odd, center element counted once         │
└────────────────────────────────────────────────────────┘
```

### Algorithm

```
┌────────────────────────────────────────────────────────┐
│       Diagonal Sum Algorithm                           │
├────────────────────────────────────────────────────────┤
│ sum = 0                                                │
│                                                        │
│ for i = 0 to n-1:                                      │
│   sum += mat[i][i]          // Main diagonal           │
│   if i != n-1-i:            // Avoid double counting   │
│     sum += mat[i][n-1-i]    // Anti-diagonal           │
│                                                        │
│ Complexity:                                            │
│ Time: O(n)  - Single loop through rows                 │
│ Space: O(1) - Only sum variable needed                 │
└────────────────────────────────────────────────────────┘
```

Reference: [e.cpp](e.cpp) - Diagonal sum calculation

---

## 🔹 Searching in Sorted 2D Arrays

**Problem**: Search for a target element in a matrix where each row and column is sorted in ascending order.

### Sample Matrix

```
Matrix Example:
   Col0  Col1  Col2  Col3
Row0 10    20    30    40
Row1 12    25    35    45
Row2 27    29    37    48
Row3 32    33    39    50

Task: Find target element in this sorted matrix
```

### Three Approaches with Complexity

```
┌────────────────────────────────────────────────────────┐
│      Search Methods in Sorted 2D Arrays                │
├────────────────────────────────────────────────────────┤
│ 1. BRUTE FORCE:                                        │
│    Check every cell in matrix                          │
│    Time: O(m × n)  - Linear search                     │
│    Space: O(1)                                         │
│    ✗ Inefficient, ignores sorted property              │
│                                                        │
│ 2. ROW/COLUMN BINARY SEARCH:                           │
│    Binary search on each row or column separately      │
│    Time: O(m × log n) for each row                     │
│       or O(n × log m) for each column                  │
│    Space: O(1) or O(log m) recursion stack             │
│    ✓ Better, but doesn't use full sorting info         │
│                                                        │
│ 3. STAIRCASE SEARCH (Best):                            │
│    Start from top-right or bottom-left corner          │
│    Utilize both row and column sorting                 │
│    Time: O(m + n)  - Linear time!                      │
│    Space: O(1)                                         │
│    ✓ Uses all sorting information                      │
└────────────────────────────────────────────────────────┘
```

### Staircase Search Algorithm (Optimal)

```
┌────────────────────────────────────────────────────────┐
│        Staircase Search Strategy                       │
├────────────────────────────────────────────────────────┤
│ APPROACH 1: Start from top-right corner               │
│ i = 0 (row), j = cols - 1 (column)                     │
│                                                        │
│ while i < rows and j >= 0:                             │
│   if mat[i][j] == target:                              │
│     return found                                       │
│   else if mat[i][j] > target:                          │
│     j--     // Move left (smaller values)              │
│   else:                                                │
│     i++     // Move down (larger values)               │
│                                                        │
│ APPROACH 2: Start from bottom-left corner              │
│ i = rows - 1, j = 0                                    │
│ Same logic: eliminate row/column based on comparison   │
│                                                        │
│ KEY INSIGHT:                                           │
│ • From any corner, can always eliminate either         │
│   one complete row or column in each step              │
│ • Maximum steps = m + n (rows + columns)               │
│ • Movement pattern creates "staircase" path            │
└────────────────────────────────────────────────────────┘
```

### Complexity Comparison

```
┌────────────────────────────────────────────────────────┐
│      Time Complexity Analysis                          │
├────────────────────────────────────────────────────────┤
│ Given: m rows, n columns                               │
│                                                        │
│ When m >>> n:    Staircase is O(m)      [Linear!]      │
│ When n >>> m:    Staircase is O(n)      [Linear!]      │
│ When m ≈ n:      Staircase is O(m+n)    [Best option]  │
│                                                        │
│ Comparison with n = m (square matrix):                 │
│ • Brute Force:          O(n²)                          │
│ • Binary Search:        O(n log n)                     │
│ • Staircase Search:     O(n)                           │
│                                                        │
│ Staircase is superior in all scenarios!                │
└────────────────────────────────────────────────────────┘
```

Reference: [f.cpp](f.cpp) - Brute force, [g.cpp](g.cpp) - Binary search, [h.cpp](h.cpp) - Staircase search

---

## 🔹 2D Array Pointers

Understanding how pointers work with 2D arrays is crucial for advanced array manipulation and function passing.

### Pointer-to-Array Concept

```
┌────────────────────────────────────────────────────────┐
│         2D Array and Pointer Relationship              │
├────────────────────────────────────────────────────────┤
│ For declaration: int mat[3][4];                        │
│                                                        │
│ KEY FACT:                                              │
│ • mat (array name) points to the entire first row      │
│ • Type of mat: int(*)[4]  (pointer to array of 4 ints) │
│ • mat[0] points to first element of first row          │
│ • Type of mat[0]: int*  (pointer to int)               │
│                                                        │
│ POINTER ARITHMETIC:                                    │
│ • mat + 1 → points to second row (moves 4 ints)        │
│ • *(mat + 1) → address of second row's first element   │
│ • *(mat + i) + j → address of mat[i][j]                │
│ • *(*(mat + i) + j) → value of mat[i][j]               │
│                                                        │
│ DECLARATION:                                           │
│ int (*ptr)[4] = mat;  // Pointer to row of 4 ints      │
│ ptr[1][2]  // Accesses mat[1][2]                       │
└────────────────────────────────────────────────────────┘
```

### Array Name Behavior

```
┌────────────────────────────────────────────────────────┐
│      Array Name Interpretation                         │
├────────────────────────────────────────────────────────┤
│ int mat[3][4];                                         │
│                                                        │
│ The array name 'mat' represents different things       │
│ depending on context:                                  │
│                                                        │
│ sizeof(mat):     12 × sizeof(int)  [entire array]      │
│ sizeof(mat[0]):  4 × sizeof(int)   [first row]         │
│ sizeof(*mat):    4 × sizeof(int)   [what mat points] │
│                                                        │
│ This is why sizeof(array) works correctly for 2D       │
│ arrays but NOT for pointers passed to functions!       │
│                                                        │
│ IMPORTANT: When passed to function, array decays      │
│ to pointer, losing dimension information!              │
└────────────────────────────────────────────────────────┘
```

Reference: [i.cpp](i.cpp) - 2D array pointer demonstration

---

## 🔹 Passing 2D Arrays to Functions

Functions receiving 2D arrays require special syntax to maintain row information.

### Function Parameter Syntax

```
┌────────────────────────────────────────────────────────┐
│        Passing 2D Arrays to Functions                  │
├────────────────────────────────────────────────────────┤
│ METHOD 1: Explicit Size (Preferred)                    │
│ void printMatrix(int mat[][4], int rows) {             │
│   for(int i = 0; i < rows; i++)                        │
│     for(int j = 0; j < 4; j++)                         │
│       cout << mat[i][j];                               │
│ }                                                      │
│                                                        │
│ METHOD 2: Row Pointer Syntax                           │
│ void printMatrix(int (*ptr)[4], int rows) {            │
│   for(int i = 0; i < rows; i++)                        │
│     for(int j = 0; j < 4; j++)                         │
│       cout << ptr[i][j];                               │
│ }                                                      │
│                                                        │
│ IMPORTANT RULES:                                       │
│ • Column dimension is ALWAYS required                  │
│ • Row dimension must be passed separately as parameter │
│ • Compiler needs to know bytes per row for arithmetic  │
│ • Cannot use dynamic row size in bracket notation      │
│                                                        │
│ Usage:                                                 │
│ int matrix[3][4] = {...};                              │
│ printMatrix(matrix, 3);                                │
└────────────────────────────────────────────────────────┘
```

### Why Column Size is Mandatory

```
┌────────────────────────────────────────────────────────┐
│       Column Size Necessity                            │
├────────────────────────────────────────────────────────┤
│ When accessing mat[i][j]:                              │
│ • Compiler calculates: address = mat + i*cols + j      │
│ • Must know cols to increment row pointer correctly    │
│ • Different col sizes = different pointer arithmetic   │
│                                                        │
│ Example:                                               │
│ int arr1[3][4];    // Increment by 4*sizeof(int)       │
│ int arr2[3][5];    // Increment by 5*sizeof(int)       │
│                                                        │
│ Without knowing column size, cannot determine          │
│ how much to jump when moving between rows!             │
└────────────────────────────────────────────────────────┘
```

Reference: [j.cpp](j.cpp) - Function passing demonstrations

---

## 🔹 Practice Problems

### Problem 1: Count Occurrences

**Count all occurrences of a specific digit (e.g., 7) in a 2D array.**

Reference: [k.cpp](k.cpp)

### Problem 2: Row Sum

**Calculate and print the sum of elements in a specific row of a 2D array.**

Reference: [l.cpp](l.cpp)

### Problem 3: Matrix Transpose

**Find the transpose of an n×m matrix and store it in an m×n matrix.**

```
For matrix[2][3]:          Transpose[3][2]:
1  2  3          →         1  4
4  5  6                     2  5
                            3  6

transpose[i][j] = mat[j][i]

Time: O(m × n)
Space: O(m × n) for new matrix
```

Reference: [m.cpp](m.cpp)

### Problem 4: 1D to 2D Array Construction

**Given a 1D array and dimensions m and n, construct a 2D array of size m×n using all elements from the 1D array in row-major order.**

```
Input: original = [1,2,3,4,5,6], m = 2, n = 3

Output: [[1, 2, 3],
         [4, 5, 6]]

Time: O(m × n)
Space: O(m × n)
```

Reference: [n.cpp](n.cpp)

### Problem 5: Rotate Matrix 90° Clockwise

**Rotate an n×n matrix 90 degrees clockwise in-place without using extra space.**

```
Original:       After 90° CW Rotation:
1  2  3         7  4  1
4  5  6    →    8  5  2
7  8  9         9  6  3

Algorithm:
Step 1: Transpose matrix (swap mat[i][j] with mat[j][i])
Step 2: Reverse each row

Complexity:
Time: O(n²)   - Touch each element twice
Space: O(1)   - In-place operation
```

Reference: [o.cpp](o.cpp)

---

## 🔹 Summary of Key Concepts

```
┌────────────────────────────────────────────────────────┐
│         Module 14 Quick Reference                      │
├────────────────────────────────────────────────────────┤
│ 2D ARRAYS:                                             │
│ • Declaration: int arr[rows][cols];                    │
│ • Stored in contiguous memory (row-major in C++)       │
│ • Access formula: base + (i*cols + j)*sizeof()         │
│                                                        │
│ TRAVERSALS:                                            │
│ • Linear: O(m×n) time, simple nested loops             │
│ • Spiral: O(m×n) time, track 4 boundaries             │
│                                                        │
│ SEARCHING:                                             │
│ • Brute force: O(m×n)                                  │
│ • Staircase search: O(m+n) for sorted matrix           │
│                                                        │
│ TRANSFORMATIONS:                                       │
│ • Transpose: O(m×n)                                    │
│ • Rotate: O(n²) for in-place rotation                  │
│                                                        │
│ FUNCTIONS:                                             │
│ • Always pass row count separately                     │
│ • Column count must be fixed or in parameters          │
│ • Use int (*ptr)[cols] or int arr[][cols]             │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Best Practices for 2D Arrays

```
┌────────────────────────────────────────────────────────┐
│        2D Array Best Practices                         │
├────────────────────────────────────────────────────────┤
│ DESIGN:                                                │
│ ✓ Use meaningful variable names for rows/cols          │
│ ✓ Document expected dimensions in comments             │
│ ✓ Validate indices before access (prevent out-of-bounds)
│                                                        │
│ IMPLEMENTATION:                                        │
│ ✓ Prefer row-major order for cache efficiency          │
│ ✓ Use const for dimensions when known at compile-time  │
│ ✓ Pass dimensions explicitly to functions              │
│ ✓ Be careful with pointer arithmetic                   │
│                                                        │
│ EDGE CASES:                                            │
│ ✓ Test with 1×1 matrices                               │
│ ✓ Test with rectangular matrices (m ≠ n)              │
│ ✓ Test with large dimensions (memory considerations)   │
│ ✓ Handle boundary conditions in algorithms             │
│                                                        │
│ PERFORMANCE:                                           │
│ ✓ Use staircase search for sorted arrays               │
│ ✓ Avoid unnecessary array copies                       │
│ ✓ Consider cache-friendly access patterns              │
│ ✓ Profile before optimizing complex operations         │
└────────────────────────────────────────────────────────┘
```
