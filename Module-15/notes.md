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
• str.substr( startldx, size )
• str.find( word )
