# DSA with C++ — Module 13 Notes

SORTING :
we have to arrange the elements in ascending or descending order

[2,3,1,4,5]
ascending order -> [1,2,3,4,5]
descending order -> [5,4,3,2,1]

we have four basic methods for sorting

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Counting Sort

in the coding problems we dont use any of the above algorithms as they are not that efficient.

BUBBLE SORT -> a.cpp

large elements come to end by swapping with adjecent
n-1 turns are taken

time complexity -> O(n\*(n-1) / 2) -> O(n^2)
space complexity -> O(1)

boolean swapping optimisation -> b.cpp
if array is already sorted then we sont need any swaps . so if there are no swaps in an iteration we chack a boolean and early return

SELECTION SORT -> c.cpp

pick the smallest element (from unsorted) and put in the begining

we diivde the array in two parts sorted and unsorted and then find the smallest int eh unsorted and then place it in the begining of unsorted

time complexity -> O(n^2)
space complexity -> O(1)

INSERTION SORT -> d.cpp

pick an element from the unsorted part and place it correctly in sorted part

time complexity -> O(n^2)
space complexity -> O(1)

COUNTING SORT -> e.cpp

we use it when the range of numbers in the array is low

use a frequency count of elements from min to max

time complexity -> O(n + k)
space complexity -> O(k)
here k is a constant range

INBUILT SORT

C++ has an inbuilt sort function with the time complexity of O(nlogn)

Ascending Order
sort(start,end)

Descending Order
sort(start, end, greater<int>)
