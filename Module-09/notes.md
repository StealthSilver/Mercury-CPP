# DSA with C++ — Module 9 Notes

BINARY NUMBER SYSTEM

base 10 - 0 to 9 digits (decimal number system)

base 2 -> 0 and 1 (binary number system)

0 and 1 are the bits and bit manipularion is a strong technique for promlem solving

converting binary to decimal -> everythign is converted into binary by the assembler

11010 -> 1 \* 2^4 + 1 \* 2^3 + 0 \* 2^2 + 1 \* 2^1 + 0 \* 2^0 = 26

8 bits -> 1 byte

26 stored in a byte will be -> 00011010 (8 bits)

0001
001
01
all these three are same , they all are 1

converting decimal to binary

18 ->
18 % 2 -> 0 , 9
9 % 2 -> 1 , 4
4 % 2 -> 0 , 2
2 % 2 -> 0 , 1
1 % 2 -> 1

representation will be in reverse
10010

the concept of range comes from this only

1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 101
7 -> 111
8 -> 1000

For any number ≥ 2^n, at least n+1 bits are required.

DATA TYPE MODIFIERS -> a.cpp

alter the meaning of existing data types

long -> >= 4 bytes (more than int) - used with int and double , to store more data than4 bytes
short -> 2 bytes
signed -> signed int is same as int
unsigned -> can only store non-negative numbers
it increses the size of int as the MOST SIGNIFICANT BIT determines if the numebr is positive or negative, and unsigned frees up the MSB bit. so the range is 0 to 2^32
long long -> same as long long int

int -> 4 bytes (32 bits) . the range will be -2^31 to 2^31-1 (as 0 is included)
also the size of the data types depend on the system

if we write long long it implicitly means long long int

unsigned short int age -> we can combine different modifiers

b.cpp -> convert binary to decimal

c.cpp -> convert decimal to binary
