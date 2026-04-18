# DSA with C++ — Module 15 Notes

CHAR DATA TYPE

char -> char array[] -> strings

chat data type -> stores character -> 1 byte memory
a.cpp
we can store lower case elements, upper case elements, special characters, single digits
we can also store /n, /t

all the chars are encoded as ASCII -> American Standard COde for Information Interchange
this is a 7 bit charset can store 128 characters

'a' - 97
'A' - 65

CHARACTER ARRAY -> b.cpp

char arr[5] = {'a', 'b', 'c', 'd', 'e'};

we can use char arrays to store strings and then the array has to end with \0
all the char arrays storing the string are Explicitly Terminated by null character

we also have string literals
"string literal"

we can create char arrays also by inputing a string literal -> c.cpp

INPUT THE CHAR ARRAY -> d.cpp

you can input the strings in the char array
to input the string with the spaces we need to use the cin.getline() function -> e.cpp

cin.getline(name of array, no of chars, delimiter)

delimiter is an optional argument which stops the input when that char appears

CONVERT TO UPPERCASE -> f.cpp

convert the char array to uppercase

CONVERT TO LOWERCASE -> g.cpp

convert the char array to lowercase

REVERSE A CHAR ARRAY -> h.cpp

take two pointers one at start and one at end and swap the variables
time complexity -> O(n/2) -> O(n)

VALID PALLINDROME -> i.cpp

pallindromes are words same from both the sides

make two pointers one at start and one at end and then check the chars

time complexity -> O(n)

CSTRING FUNCTIONS -> j.cpp

these functions exist in the <cstring> header file

• strcpy( dest, src) : to copy string from src to dest
• strcat( str1, str2) : to concatenate/join str1 with str2
• strcmp( str1, str2) : compares 2 strings based on values (-ve, 0,+ve)

STRINGS in C++ -> k.cpp

strings use OOPs in c++

there is a string class in C++, we can make objects from the string class
also there are methods from the string class

C++ Strings are objects of pre-defined string class in STL (Standard Template Library).
C++ Strings have useful member functions.
C++ Strings are dynamic (their size can change at run time).
C++ Strings support operators like +, ==, ›, ‹ etc.
C++ Strings are stored contiguously in memory.

all member functions of the string class are called by the dot (.) operator

FOR EACH LOOP -> l.cpp

for(char ch : str){
...
}

STRING MEMBER FUNCTIONS -> m.cpp

Member Functions
• str.length( ) -> length of the string
• str.at( idx) -> char at perticular index
• str.substr( startldx, size ) -> substrings, continuous part of a string
• str.find( word ) -> searches the word in the string, passes the index of first occourance and if not found returns -1 (returns the string equivalent of -1)

string names are not pointers so while passing as function arguments we need not pass the size

we can also pass another argument that will be the starting index
str.find("abc" , 20) -> start searching for abc after the 20th index

VALID ANAGRAM

anagrams are words that have same number of characters and are rerranged

we have been given two strings, we have to tell if they are anagrams or not

1. we can sort both the strigns and compare them -> n.cpp
   time complexity -> O(nlogn), we will be using merge sort

2. we will track the chars and make an auxillary array -> o.cpp
   make array of length 26 and add the count of each alphabet as they occour in hte string.
   then for the second string we decrease the count.
   time complexity -> O(n), space complexity -> O(1), as auxillary array will have size 26 always

we can compare strings using operators -> p.cpp

PRACTICE PROBLEMS

1. Count how many times lowercase vowels occurred in a String entered
   by the user. -> q.cpp
