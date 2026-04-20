# DSA with C++ — Module 17 Notes

BIT MANIPULATION

prerequisites : binary number system, conversions

BITWISE OPERATORS

Bitwise AND & -> a.cpp

0 & 0 -> 0
0 & 1 -> 0
1 & 0 -> 0
1 & 1 -> 1

Bitwise OR | -> b.cpp

0 | 0 -> 0
0 | 1 -> 1
1 | 0 -> 1
1 | 1 -> 1

Bitwise XOR ^ -> c.cpp

0 ^ 0 -> 0
0 ^ 1 -> 1
1 ^ 0 -> 1
1 ^ 1 -> 1

1s COMPLEMENT

Binary NOT Operator ~

~0 -> -1
~1 -> -2

here when we find the not of any number we are finding its one's complement form

so to get the ~ of any number (2's complement)

1. find its 1's complement (this will give the sign)
2. then add 1 (this will give the magnitude)

e.g. 6 -> 00000110
1's complement -> 11111001
adding 1 -> 0000111
therefore ~6 -> -7

BINARY SHIFT OPERATORS -> e.cpp

left shift <<
num << i pos (shift bits i positions towards the left) -> fill the empty spaces with 0

right shift >>
num >> i pos (shift bits i positions towards the right) -> fill the empty spaces with 0

a << b = a\*2^b
