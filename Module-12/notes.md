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

go to each subarray adnds then traverse the sub array to get the sum and then compare it with INT_MIN

time complexity -> O(n^3)

2. optimised approach -> c.cpp

no need to find the sum of all the subarrays again and agian. we can just add the new element in the sum calculated for the previous step for the subarray

time complexity -> O(n^2) -> double loop

3. Kadane's algorithm -> d.cpp

this is a dynamic programming algorithm

if +ve + +ve -> positive
if -ve + bigger +ve -> positive
if bigger -ve + -ve -> negative (we will not add this case at all), instead make it 0

time complexity -> O(n); -> single loop

BUY AND SELL STOCKS

price of the stocks for the different days are given. we have to buy the stock on some day and some day later we have to sell it. find what will be the max profit

e.cpp

find the best buy price for each days and store them in another array then find the max profit by sell price - buy price

time complxity -> O(n)
space complexity -> O(n)
