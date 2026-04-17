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
reverse without any external memory

take two pointers one at start and one at end and swap the variables
time complexity -> O(n/2) -> O(n)
