# DSA with C++ — Module 15 Notes

---

## 🔹 Introduction to Strings and Characters

**Strings** are sequences of characters that represent text and are fundamental to most programs. C++ provides multiple ways to work with strings, from basic character arrays to the powerful string class.

### The Character Data Type

```
┌────────────────────────────────────────────────────────┐
│            Char Data Type Fundamentals                 │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ • Stores a single character                            │
│ • Memory size: 1 byte (8 bits)                         │
│ • Encoding: ASCII (7-bit standard)                     │
│                                                        │
│ CAPABILITIES:                                          │
│ • Lowercase letters: a-z                               │
│ • Uppercase letters: A-Z                               │
│ • Digits: 0-9                                          │
│ • Special characters: !, @, #, $, etc.                 │
│ • Escape sequences: \n, \t, \r, \\, \'                 │
│                                                        │
│ ASCII ENCODING REFERENCE:                              │
│ • 'a' (lowercase): ASCII value 97                      │
│ • 'A' (uppercase): ASCII value 65                      │
│ • '0' (digit): ASCII value 48                          │
│ • NULL character: '\0' (ASCII 0)                       │
│ • Printable ASCII: values 32-126                       │
│                                                        │
│ DECLARATION:                                           │
│ char ch = 'x';  // Single character                    │
│ char escape = '\n';  // Escape sequence                │
└────────────────────────────────────────────────────────┘
```

### ASCII Encoding System

```
┌────────────────────────────────────────────────────────┐
│      American Standard Code for Information            │
│                  Interchange (ASCII)                   │
├────────────────────────────────────────────────────────┤
│ • 7-bit character encoding standard                    │
│ • Represents 128 unique characters (0-127)             │
│ • Widely used in all programming languages             │
│ • Extended ASCII: 8-bit (256 characters including      │
│   special symbols)                                     │
│                                                        │
│ KEY RANGES:                                            │
│ • 48-57:   Digits 0-9                                  │
│ • 65-90:   Uppercase A-Z                               │
│ • 97-122:  Lowercase a-z                               │
│ • 32:      Space character                             │
│                                                        │
│ USAGE IN C++:                                          │
│ char c1 = 65;      // Stores 'A'                       │
│ char c2 = 'A';     // Same as above                    │
│ int val = 'A';     // Can be used as int (implicit)    │
│ if (ch >= 'a' && ch <= 'z')  // Check lowercase        │
└────────────────────────────────────────────────────────┘
```

Reference: [a.cpp](a.cpp) - Character data type demonstrations

---

## 🔹 Character Arrays and Strings

---

## 🔹 Character Arrays and Strings

A **character array** is a collection of characters stored sequentially in memory. When terminated with a null character ('\0'), it represents a C-style string.

### Declaration and Initialization

```
┌────────────────────────────────────────────────────────┐
│      Character Array Declarations                      │
├────────────────────────────────────────────────────────┤
│ METHOD 1: Array of individual characters               │
│ char arr[5] = {'a', 'b', 'c', 'd', 'e'};               │
│ → NOT a string (no null terminator)                    │
│                                                        │
│ METHOD 2: String literal (automatic termination)       │
│ char str[6] = "hello";  // '\0' added automatically    │
│ or shorter: char str[] = "hello";                      │
│                                                        │
│ METHOD 3: String literal pointer                       │
│ const char* str = "hello";                             │
│ → Points to constant string in memory                  │
│                                                        │
│ NULL TERMINATOR:                                       │
│ • Every C-style string ends with '\0'                  │
│ • ASCII value: 0                                       │
│ • Indicates string end to string functions             │
│ • Size formula: length + 1 (for null terminator)       │
│                                                        │
│ EXAMPLE MEMORY LAYOUT:                                 │
│ Array: ['h']['e']['l']['l']['o']['\0']                 │
│ Index:  [0]  [1]  [2]  [3]  [4]  [5]                   │
└────────────────────────────────────────────────────────┘
```

### String Literals

```
┌────────────────────────────────────────────────────────┐
│           String Literals in C++                       │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Text enclosed in double quotes represents a string     │
│ Examples: "hello", "world", "123", ""                  │
│                                                        │
│ STORAGE:                                               │
│ • Stored in read-only memory (const data section)      │
│ • Automatically null-terminated                        │
│ • Cannot be modified at runtime                        │
│                                                        │
│ USAGE:                                                 │
│ const char* ptr = "hello";  // Pointer to literal      │
│ cout << "Direct print";     // Direct printing         │
│ char arr[] = "copy";        // Copy literal to array    │
│                                                        │
│ ESCAPING:                                              │
│ • \" → Include quote in string                         │
│ • \\ → Include backslash                               │
│ • \n → Newline                                         │
│ • \t → Tab                                             │
│ • \0 → Null character (explicit)                       │
└────────────────────────────────────────────────────────┘
```

Reference: [b.cpp](b.cpp) - Character array basics, [c.cpp](c.cpp) - Initialization from string literals

---

## 🔹 Input and Output for Character Arrays

Reading character arrays from user input requires special attention to handle spaces and multiple characters correctly.

### Input Methods

```
┌────────────────────────────────────────────────────────┐
│         Input Methods for Character Arrays             │
├────────────────────────────────────────────────────────┤
│ METHOD 1: cin >> (stops at whitespace)                 │
│ char arr[50];                                          │
│ cin >> arr;                                            │
│ Input: "hello world"                                   │
│ Result: "hello" (stops at space)                       │
│ ✗ Cannot capture spaces                                │
│                                                        │
│ METHOD 2: cin.getline() (recommended)                  │
│ char arr[50];                                          │
│ cin.getline(arr, 50);  // read up to 49 chars          │
│ Input: "hello world"                                   │
│ Result: "hello world" (includes spaces)                │
│ ✓ Can capture entire line with spaces                  │
│                                                        │
│ SYNTAX:                                                │
│ cin.getline(array, size, delimiter);                   │
│                                                        │
│ PARAMETERS:                                            │
│ • array: destination array                             │
│ • size: maximum characters to read (includes '\0')     │
│ • delimiter: stop character (default: '\n')            │
│                                                        │
│ EXAMPLE:                                               │
│ cin.getline(name, 100, '\n');  // Read until newline   │
│ cin.getline(csv, 100, ',');    // Read until comma     │
└────────────────────────────────────────────────────────┘
```

### Output

```
┌────────────────────────────────────────────────────────┐
│         Output for Character Arrays                    │
├────────────────────────────────────────────────────────┤
│ SIMPLE OUTPUT:                                         │
│ cout << arr;        // Prints entire string           │
│ cout << arr[0];     // Prints single character         │
│                                                        │
│ ELEMENT-BY-ELEMENT:                                    │
│ for(int i = 0; arr[i] != '\0'; i++)                    │
│   cout << arr[i];                                      │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n)  - Must iterate through array               │
│ Space: O(1) - No extra space needed                    │
└────────────────────────────────────────────────────────┘
```

Reference: [d.cpp](d.cpp) - Basic I/O, [e.cpp](e.cpp) - Using cin.getline()

---

## 🔹 Character Manipulation

**Transforming characters** is essential for text processing. Common operations include converting case and reversing strings.

### Converting to Uppercase

```
┌────────────────────────────────────────────────────────┐
│       Converting Characters to Uppercase               │
├────────────────────────────────────────────────────────┤
│ METHOD 1: Using toupper() function (ctype.h)           │
│ for (int i = 0; str[i] != '\0'; i++)                   │
│   str[i] = toupper(str[i]);                            │
│                                                        │
│ METHOD 2: ASCII arithmetic                             │
│ if (str[i] >= 'a' && str[i] <= 'z')                    │
│   str[i] = str[i] - 32;  // 'a' - 'A' = 32             │
│ // or: str[i] = str[i] - ('a' - 'A');                  │
│                                                        │
│ KEY FACTS:                                             │
│ • Uppercase A-Z: ASCII 65-90                           │
│ • Lowercase a-z: ASCII 97-122                          │
│ • Difference: 32 (97 - 65 = 32)                        │
│ • Only affects lowercase letters                       │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n)  - Visit each character once                │
│ Space: O(1) - In-place modification                    │
└────────────────────────────────────────────────────────┘
```

### Converting to Lowercase

```
┌────────────────────────────────────────────────────────┐
│       Converting Characters to Lowercase               │
├────────────────────────────────────────────────────────┤
│ METHOD 1: Using tolower() function (ctype.h)           │
│ for (int i = 0; str[i] != '\0'; i++)                   │
│   str[i] = tolower(str[i]);                            │
│                                                        │
│ METHOD 2: ASCII arithmetic                             │
│ if (str[i] >= 'A' && str[i] <= 'Z')                    │
│   str[i] = str[i] + 32;  // Add 32 to uppercase        │
│                                                        │
│ LOGIC:                                                 │
│ • Lowercase = Uppercase + 32                           │
│ • Only affects uppercase letters                       │
│ • Numbers and special chars unaffected                 │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n)                                             │
│ Space: O(1) - In-place operation                       │
└────────────────────────────────────────────────────────┘
```

Reference: [f.cpp](f.cpp) - Uppercase conversion, [g.cpp](g.cpp) - Lowercase conversion

---

## 🔹 Reversing Character Arrays

**Problem**: Reverse a character array so elements appear in opposite order.

### Two-Pointer Approach

```
┌────────────────────────────────────────────────────────┐
│         Reverse Array Algorithm                        │
├────────────────────────────────────────────────────────┤
│ CONCEPT:                                               │
│ Use two pointers: one at start, one at end             │
│ Swap elements and move pointers toward center          │
│                                                        │
│ ALGORITHM:                                             │
│ int left = 0;                                          │
│ int right = length - 1;                                │
│                                                        │
│ while (left < right):                                  │
│   swap(arr[left], arr[right]);                         │
│   left++;                                              │
│   right--;                                             │
│                                                        │
│ EXAMPLE:                                               │
│ Original: ['h']['e']['l']['l']['o']                    │
│           [ 0][ 1][ 2][ 3][ 4]                         │
│                                                        │
│ Step 1:   ['o']['e']['l']['l']['h']  (swap 0 and 4)    │
│ Step 2:   ['o']['l']['l']['e']['h']  (swap 1 and 3)    │
│ Step 3:   ['o']['l']['l']['e']['h']  (stop at center)  │
│                                                        │
│ Result:   ['o']['l']['l']['e']['h']                    │
│           "olleh"                                      │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n/2) = O(n)  - Visit each element once         │
│ Space: O(1)   - In-place, only two pointers            │
└────────────────────────────────────────────────────────┘
```

Reference: [h.cpp](h.cpp) - String reversal implementation

---

## 🔹 Palindromes

**Palindrome**: A word, phrase, or sequence that reads the same forwards and backwards.

### Palindrome Detection

```
┌────────────────────────────────────────────────────────┐
│      Palindrome Validation Algorithm                   │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ A string is palindrome if str[i] == str[n-1-i]         │
│ for all valid positions                                │
│                                                        │
│ EXAMPLES:                                              │
│ "racecar"     → Palindrome ✓                           │
│ "hello"       → Not palindrome ✗                       │
│ "a"           → Palindrome ✓                           │
│ "radar"       → Palindrome ✓                           │
│ "12321"       → Palindrome ✓                           │
│                                                        │
│ ALGORITHM:                                             │
│ int left = 0;                                          │
│ int right = length - 1;                                │
│                                                        │
│ while (left < right):                                  │
│   if (str[left] != str[right])                         │
│     return false;  // Not a palindrome                 │
│   left++;                                              │
│   right--;                                             │
│ return true;  // Is a palindrome                       │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n)  - Compare each position once               │
│ Space: O(1) - Only pointer variables                   │
└────────────────────────────────────────────────────────┘
```

### Step-by-Step Example

```
Check "racecar" for palindrome:

String: ['r']['a']['c']['e']['c']['a']['r']
Index:   [0] [1] [2] [3] [4] [5] [6]

Step 1: Compare [0] and [6]: 'r' == 'r' ✓
Step 2: Compare [1] and [5]: 'a' == 'a' ✓
Step 3: Compare [2] and [4]: 'c' == 'c' ✓
Step 4: left (3) >= right (3), stop
Result: IS PALINDROME
```

Reference: [i.cpp](i.cpp) - Palindrome validation implementation

---

## 🔹 C String Functions (cstring Library)

The `<cstring>` header provides functions for working with C-style strings that are null-terminated character arrays.

### Core String Functions

```
┌────────────────────────────────────────────────────────┐
│       Essential C String Functions                     │
├────────────────────────────────────────────────────────┤
│ 1. strcpy(dest, src)                                   │
│    PURPOSE: Copy string from src to dest               │
│    SYNTAX: strcpy(destinationArray, sourceArray);      │
│    RETURN: Pointer to dest                             │
│    DANGER: ⚠️  Buffer overflow risk!                    │
│    EXAMPLE: strcpy(name, "Alice");                     │
│                                                        │
│ 2. strcat(str1, str2)                                  │
│    PURPOSE: Concatenate (join) str2 to str1            │
│    SYNTAX: strcat(stringA, stringB);                   │
│    RETURN: Pointer to str1                             │
│    EFFECT: str1 modified, str2 unchanged               │
│    EXAMPLE: strcat(greeting, " World");                │
│                                                        │
│ 3. strcmp(str1, str2)                                  │
│    PURPOSE: Compare two strings lexicographically      │
│    SYNTAX: strcmp(string1, string2);                   │
│    RETURN VALUE:                                       │
│      • 0 if strings are equal                          │
│      • < 0 if str1 comes before str2                   │
│      • > 0 if str1 comes after str2                    │
│    EXAMPLE: if (strcmp(pass, "secret") == 0) { ... }   │
│                                                        │
│ COMPLEXITY:                                            │
│ • strcpy: O(n)  where n = source string length         │
│ • strcat: O(n+m) where n = dest len, m = src len       │
│ • strcmp: O(min(n, m)) in best case, O(max(n,m)) worst │
│                                                        │
│ ⚠️  WARNING:                                            │
│ These functions are unsafe if array size unknown       │
│ Modern C++ prefers: strncpy, strncat strcpy_s (safer)  │
└────────────────────────────────────────────────────────┘
```

Reference: [j.cpp](j.cpp) - C string functions demonstration

---

## 🔹 C++ String Class

Modern C++ provides the `string` class from the Standard Template Library (STL), which is much more powerful and safe than C-style character arrays.

### String Class Advantages

```
┌────────────────────────────────────────────────────────┐
│      C++ String Class Features                         │
├────────────────────────────────────────────────────────┤
│ C++ STRINGS vs C-STYLE ARRAYS:                         │
│                                                        │
│ • Type: Object from STL string class                   │
│ • Declaration: string str = "hello";                   │
│ • Length: Dynamic (changes at runtime)                 │
│ • Memory: Handled automatically (no overflow risk)     │
│ • Functions: Rich set of member functions              │
│ • Operators: Supports +, ==, >, <, etc.                │
│ • Containment: Stored contiguously in memory           │
│                                                        │
│ KEY ADVANTAGES:                                        │
│ ✓ Type-safe operations                                 │
│ ✓ Automatic memory management                          │
│ ✓ No buffer overflow concerns                          │
│ ✓ Easy concatenation with + operator                   │
│ ✓ Easy comparison with operators                       │
│ ✓ Rich set of built-in methods                         │
│ ✓ Can be passed to functions without size parameter    │
│                                                        │
│ DECLARATION & INITIALIZATION:                          │
│ string str1;                // Empty string            │
│ string str2 = "hello";      // From literal            │
│ string str3(5, 'a');        // 5 'a' characters        │
│ string str4 = str2;         // Copy assignment         │
│                                                        │
│ #include <string>  // Must include header              │
│ using namespace std;                                   │
└────────────────────────────────────────────────────────┘
```

### Iterating Through Strings

```
┌────────────────────────────────────────────────────────┐
│       Range-Based For Loop (C++11 and later)           │
├────────────────────────────────────────────────────────┤
│ SYNTAX:                                                │
│ for (char ch : string)                                 │
│ {                                                      │
│   // Process each character                            │
│ }                                                      │
│                                                        │
│ EXAMPLE:                                               │
│ string str = "hello";                                  │
│ for (char ch : str)                                    │
│   cout << ch << " ";                                   │
│ Output: h e l l o                                      │
│                                                        │
│ EQUIVALENT TRADITIONAL LOOP:                           │
│ for (int i = 0; i < str.length(); i++)                 │
│   cout << str[i] << " ";                               │
│                                                        │
│ ADVANTAGES OF RANGE-BASED:                             │
│ • Cleaner syntax                                       │
│ • No need to manage index                              │
│ • No risk of index-out-of-bounds                       │
│ • Works with any container type                        │
│                                                        │
│ COMPLEXITY:                                            │
│ Time: O(n)  - Visit each character once                │
│ Space: O(1) - No extra space (ch is reference)         │
└────────────────────────────────────────────────────────┘
```

Reference: [k.cpp](k.cpp) - String class introduction, [l.cpp](l.cpp) - For-each loop demonstrations

---

## 🔹 String Member Functions

The C++ string class provides numerous methods for string manipulation, searching, and analysis.

### Core Member Functions

```
┌────────────────────────────────────────────────────────┐
│       Essential String Member Functions                │
├────────────────────────────────────────────────────────┤
│ 1. str.length()                                        │
│    Returns: Integer length of string (excluding '\0')  │
│    Complexity: O(1) - usually cached                   │
│    Example: int len = str.length();                    │
│                                                        │
│ 2. str.at(index)                                       │
│    Returns: Character at given index                   │
│    Throws: out_of_range exception if invalid index     │
│    Complexity: O(1) - direct access                    │
│    Example: char c = str.at(2);  // 3rd character      │
│    Note: Can also use str[index] but doesn't throw     │
│                                                        │
│ 3. str.substr(startIndex, length)                      │
│    Returns: New string with specified substring        │
│    Parameters: startIndex, length (optional)           │
│    Complexity: O(length) - copies characters           │
│    Examples:                                           │
│      str.substr(2);      // From index 2 to end        │
│      str.substr(2, 3);   // 3 chars starting at 2      │
│    String "hello": str.substr(1, 3) returns "ell"      │
│                                                        │
│ 4. str.find(substring, startPos)                       │
│    Returns: Index of first occurrence of substring     │
│    Return if not found: string::npos (special value)   │
│    Complexity: O(n*m) where n=string len, m=sub len    │
│    Examples:                                           │
│      str.find("ll");           // Search from start    │
│      str.find("ll", 3);        // Search from index 3  │
│      if (str.find("x") != string::npos) { found }      │
│                                                        │
│ COMPARISON:                                            │
│ Time complexities assume typical implementations        │
│ Actual performance may vary based on compiler           │
└────────────────────────────────────────────────────────┘
```

### String Operators

```
┌────────────────────────────────────────────────────────┐
│          String Operators                              │
├────────────────────────────────────────────────────────┤
│ CONCATENATION:                                         │
│ string s1 = "Hello";                                   │
│ string s2 = "World";                                   │
│ string s3 = s1 + " " + s2;  // "Hello World"           │
│ s1 += s2;                    // Appends s2 to s1        │
│                                                        │
│ COMPARISON:                                            │
│ str1 == str2    // Equality (lexicographic)            │
│ str1 != str2    // Not equal                           │
│ str1 < str2     // Less than (alphabetical)            │
│ str1 > str2     // Greater than                        │
│ str1 <= str2    // Less or equal                       │
│ str1 >= str2    // Greater or equal                    │
│                                                        │
│ EXAMPLE:                                               │
│ if (name1 == name2) { matched }                        │
│ if (str1 < str2) { s1 comes first alphabetically }     │
└────────────────────────────────────────────────────────┘
```

Reference: [m.cpp](m.cpp) - String member functions demonstration

---

## 🔹 Character Frequency Analysis

**Problem**: Analyze character frequency in strings, essential for various applications like anagram validation and cryptography.

### Valid Anagrams

```
┌────────────────────────────────────────────────────────┐
│           Anagram Definition & Detection               │
├────────────────────────────────────────────────────────┤
│ DEFINITION:                                            │
│ Two strings are anagrams if they contain the same      │
│ characters with the same frequency, in any order       │
│                                                        │
│ EXAMPLES:                                              │
│ "listen" and "silent"     → ANAGRAMS ✓                 │
│ "hello" and "world"       → NOT ANAGRAMS ✗             │
│ "abc" and "bca"           → ANAGRAMS ✓                 │
│ "evil" and "vile"         → ANAGRAMS ✓                 │
│ "dormitory" and "dirty room" → ANAGRAMS ✓              │
│                                                        │
│ APPROACH 1: Sort and Compare                           │
│ 1. Sort both strings                                   │
│ 2. Compare sorted results                              │
│ Time: O(n log n) - sorting dominates                   │
│ Space: O(1) - in-place sort (or O(n) if copy)          │
│                                                        │
│ APPROACH 2: Character Frequency Array (Optimal)        │
│ 1. Create frequency array of size 26 for lowercase     │
│ 2. Increment counts for str1                           │
│ 3. Decrement counts for str2                           │
│ 4. Check if all counts are zero                        │
│ Time: O(n) - single pass through each string           │
│ Space: O(1) - fixed array of 26 (constant space)       │
│                                                        │
│ ALGORITHM (Frequency Method):                          │
│ int freq[26] = {0};                                    │
│                                                        │
│ for (char c : str1)                                    │
│   freq[c - 'a']++;                                     │
│                                                        │
│ for (char c : str2)                                    │
│   freq[c - 'a']--;                                     │
│                                                        │
│ for (int i = 0; i < 26; i++)                           │
│   if (freq[i] != 0) return false;                      │
│ return true;                                           │
└────────────────────────────────────────────────────────┘
```

Reference: [n.cpp](n.cpp) - Sort-based approach, [o.cpp](o.cpp) - Frequency array approach, [p.cpp](p.cpp) - Using string operators

---

## 🔹 Practice Problems

### Problem 1: Count Lowercase Vowels

**Count how many times lowercase vowels (a, e, i, o, u) appeared in a string entered by the user.**

```
Example:
Input: "Hello World"
Output: e=1, o=2 (total=3)

Algorithm:
1. Input string from user
2. Iterate through each character
3. Check if character is a vowel
4. Increment appropriate counter
5. Display results

Complexity:
Time: O(n) - scan entire string once
Space: O(1) - only counters for 5 vowels
```

Reference: [q.cpp](q.cpp)

### Problem 2: String Swap to Make Equal

**Given two strings s1 and s2 of equal length, determine if you can make both strings equal by performing at most one string swap on exactly one of the strings.**

```
A string swap means: choose two indices and swap the characters
at those positions.

Example:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: Swap first and last char of s2: "kanb" → "bank"

Approach:
1. If strings already equal, return true
2. Try all possible swaps in s1
3. For each swap, check if s1 == s2
4. Try all possible swaps in s2
5. Return true if any swap works, false otherwise

Complexity:
Time: O(n²) - try each pair of positions, each creates O(n) comparison
Space: O(n) - for string copies
```

Reference: [r.cpp](r.cpp)

### Problem 3: Determine if Two Strings Are Close (LeetCode 1657)

**Two strings are close if you can transform one into the other using these operations:**

```
Operation 1: Swap any two existing characters
  Example: "abcde" → "aecdb"

Operation 2: Transform every occurrence of character X into Y,
  and every occurrence of Y into X simultaneously
  Example: "aacabb" → "bbcbaa" (swap a↔b)

You can use operations on either string as many times as needed.
Return true if word1 and word2 are close, false otherwise.

Key Insights:
• Operation 1 allows any rearrangement (permutation)
• Operation 2 allows character transformation
• Both operations preserve character counts (frequency)
• Strings are close if they have same character set with same frequencies

Approach:
1. Check if both strings have same length
2. Check if both strings contain same unique characters
3. Check if character frequencies are identical
4. If all true, then close; else not close

Complexity:
Time: O(n) - iterate through strings
Space: O(1) - at most 26 letters in alphabet
```

Reference: [s.cpp](s.cpp)

### Problem 4: Valid Parentheses (LeetCode 20)

**Given a string with brackets, determine if the input string is valid.**

```
Valid criteria:
1. Open brackets must be closed by same type
2. Brackets must be closed in correct order
3. Every closing bracket has a corresponding opening bracket

Valid characters: '(', ')', '{', '}', '[', ']'

Examples:
"()" → true
"()[]{}" → true
"([{}])" → true
"([)]" → false (wrong order)
"{[" → false (unclosed)

Approach:
Use a stack (LIFO - Last In First Out)
1. Iterate through each character
2. If opening bracket: push to stack
3. If closing bracket:
   - Check if stack empty (no matching opening)
   - Pop from stack and verify it matches
4. After loop: stack should be empty
5. If stack empty, valid; else invalid

Complexity:
Time: O(n) - visit each character once
Space: O(n) - stack may contain up to n/2 characters
```

Reference: [t.cpp](t.cpp)

---

## 🔹 Summary of Key Concepts

```
┌────────────────────────────────────────────────────────┐
│         Module 15 Quick Reference                      │
├────────────────────────────────────────────────────────┤
│ CHARACTER ARRAYS:                                      │
│ • Single byte per character                            │
│ • Null-terminated ('\0') for strings                   │
│ • ASCII encoding for compatibility                     │
│ • Limited features, manual management                  │
│                                                        │
│ C++ STRINGS:                                           │
│ • Dynamic size, automatic memory                       │
│ • Rich member functions                                │
│ • Operator support (+, ==, <, >)                       │
│ • Type-safe operations                                 │
│                                                        │
│ COMMON OPERATIONS:                                     │
│ • Conversion: toupper(), tolower()                      │
│ • Reversal: Two-pointer technique, O(n)                │
│ • Palindrome: Compare from both ends                   │
│ • Frequency: Array or map-based counting               │
│ • Anagram: Compare character frequencies               │
│                                                        │
│ C STRING FUNCTIONS:                                    │
│ • strcpy: Copy (buffer overflow risk!)                 │
│ • strcat: Concatenate                                  │
│ • strcmp: Compare lexicographically                    │
│                                                        │
│ STRING METHODS:                                        │
│ • length(): Get size                                   │
│ • at(i): Access character with bounds check            │
│ • substr(): Extract substring                          │
│ • find(): Search for substring                         │
└────────────────────────────────────────────────────────┘
```

---

## 🔹 Best Practices for String Programming

```
┌────────────────────────────────────────────────────────┐
│        String Programming Best Practices               │
├────────────────────────────────────────────────────────┤
│ DESIGN:                                                │
│ ✓ Prefer C++ string class over char arrays             │
│ ✓ Use const string& for function parameters            │
│ ✓ Validate input length before processing              │
│ ✓ Consider edge cases: empty, single char, unicode     │
│                                                        │
│ IMPLEMENTATION:                                        │
│ ✓ Use range-based for loops for iteration              │
│ ✓ Use string operators instead of functions            │
│ ✓ Prefer string::find() over manual searching          │
│ ✓ Be aware of string::npos for not-found               │
│ ✓ Use substr() for extracting parts                    │
│                                                        │
│ PERFORMANCE:                                           │
│ ✓ Reserve space if size is known: str.reserve(n)      │
│ ✓ Avoid repeated concatenation in loops                │
│ ✓ Use move semantics when applicable (C++11)           │
│ ✓ Profile string operations in performance-critical    │
│                                                        │
│ SAFETY:                                                │
│ ✓ Never ignore invalid string operations               │
│ ✓ Check bounds when using at()                         │
│ ✓ Understand npos return values                        │
│ ✓ Validate length() before indexing                    │
│ ✗ Avoid strcpy, strcat (unsafe functions)              │
│                                                        │
│ SPECIAL CONSIDERATIONS:                                │
│ ✓ Case sensitivity: 'A' != 'a'                         │
│ ✓ Whitespace: spaces, tabs, newlines matter            │
│ ✓ Escaping: \n, \t, \\ need special handling           │
│ ✓ Unicode: Standard string handles ASCII/UTF-8         │
└────────────────────────────────────────────────────────┘
```
