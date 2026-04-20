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
a >> b = a / 2^b

PRACTICE QUESTIONS -> f.cpp

Qs. Predict the output for ~4
Qs. Predict the output for 8 >>

CHECK IF ODD or EVEN -> g.cpp

is all the binary form of odd numbers the rightmost bit is 1
in the even numbers its 0

we perform the bitmask operation to get the
for that we take the bitwise & with 1

Bit masks are used to access specific bits in a byte of data

Get ith Bit -> h.cpp

we have to find the bit at the ith position for any binary number
