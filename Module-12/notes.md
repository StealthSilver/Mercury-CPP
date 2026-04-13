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

TRAPPING RAINWATER

there is an array with the heights given. we have to find the total amount of water trapped. given all the heights greater than zero.

f.cpp -> the bar needs a valley to trap water i.e. larger bars on both sides.
min of (left largest and right largest) bars gives the trapped water.
also min size n >=3
water cannot trap in ascending, descending or equal bars

amount of water = height \* width (for this case)

find the trapped water for all the bars and then add then to get the total amount

create two new auxiliary arrays (helper arrays crated for hte problem) , leftMax , rightMax

to get left max for ith index = max(leftmax[i-1] , height[i-1]);
to get right max for ith index = max(rightmax[i+1] , height[i+1]);

get the min of left max and right max for every index
to get the amount of water for every height find the min - height[i]
ignore the negative values, set them to 0. Then finally add the individual amounts to get the total water trapped

also initialise the heights like this
leftMax[0] = height[0];
rightMax[n - 1] = heights[n - 1];

    as if initialised as INT_MAX and INT_MIN then adding or subtracting will take to negative or positive values and the values in the int are circular

time complexity -> O(n)
space complexity -> O(n)

we can solve this and the BUY AND SELL STOCKS with stacks also, time complexity will be same.

PROBLEM 1 : g.cpp
Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.

Brute force approach
time comeplexity -> O(n^2)
space complexity -> O(1)

it can also be done by sorting which decreses the time complexity by O(nlogn)
and hashset which decreases the time complexity by O(n);

PROBLEM 2 : h.cpp
Question 2 : There is an integer array nums sorted in ascending order (with distinct values)

Prior to being passed to your function, nums is possibly rotated at an unknown pivot
index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7]
might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the
index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

PROBLEM 3 : i.cpp
Question 3 : Given an integer array nums, find a subarray that has the largest
product, and return the product. The test cases are generated so that the answer will
fit in a 32-bit integer.
