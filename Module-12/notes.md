# DSA with C++ — Module 12 Notes

Advanced Concepts and Questions

PRINT SUBARRAY -> a.cpp
Subarray is continuous part of an array

1,2,3,4,5 -> original array

1,12,123,1234,12345
2,23,234,2345
3,34,345
4,45
5

Subsequence is non-continuous but they must just follow an order

same questions can be asked for strings, vectors

for a n sized array teh sub arrays are = n + n-1 + n-2 = n-3 . . . 1 = n(n+1)/2

time complexity -> O(n^3) -> as three loops are used
this can be optimised using strings to O(n^2);

space complexity -> O(1) -> no extra space is used

MAX SUBARRAY SUM

find the maximum of the sum of all subarrays for any array -> this is tricky for arrays having negative elements

1. brute force approach -> b.cpp
2. optimised approach -> c.cpp
3. Kadane's algorithm -> d.cpp
