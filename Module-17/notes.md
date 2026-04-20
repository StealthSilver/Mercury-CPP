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

mask = 1<<i
(num & mask) -> 0 -> 0 , >0 -> 1

SET THE ith BIT -> i.cpp

0 -> 1
1 -> 1 do this for the its bit

we need 1 on the ith position
thereforce the bitmask will be 1<<i
and the operation will be num | mask

CLEAR THE ith BIT -> j.cpp

0 -> 0
1 -> 0 do this for the ith bit

bitMask will be ~(1<<i)
and the operation will be num & mask

CHECK for Power of 2 -> k.cpp

a. all the powers of 2 have only one 1 -> 1 set bit

b. also all the num which are 2^n - 1 are all 1s at every bit

c. also (2^n) & (2^n - 1 ) = 0

PRACTICE QUESTION -> l.cpp

Qs. WAF to update the ith bit in a number according to given value (0 or 1).
num = 7, i = 2, val = O
num = 7, i = 3, val =1

this is basically updating the ith bit for this we will

1. make the bit as 0
2. num | (val << i)

PRACTICE QUESTION -> m.cpp
Qs. WAF to clear last i bits of a number.
num = 15, i = 2

Create a mask that has:
0s in last i positions
1s everywhere else
Then AND it with the number

PRACTICE QUESTION

Count the set bits in a number

method 1 -> n.cpp
Check last bit, then shift right
do count ++

method 2 -> o.cpp
Brian Kernighan’s Algorithm (Faster)
remove the last set bit each time

FAST EXPONENTIATION

X^n = x*x*x\*x... n times

method 1 -> p.cpp
multiply x to itself again and again
this will happen in O(n)

method 2 -> q.cpp
convert n in binary form

now we will loop throught the binary form of pow(n)
also any n will have at max -> log2n bits
this will have the time complexity of O(logn)
