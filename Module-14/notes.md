# DSA with C++ — Module 14 Notes

2D - Arrays

1D array -> linear array, stored in linear format
2D array -> matrix, data is stored in table format
3D array -> cubical array

there can be multidimentional arrays used for applications like image processing, compression etc.

Making the 2d array -> a.cpp

int student[2][3] = {{100, 20,30} , {30,40,50}};

rows and columns are specified. also individual elements are called cells

Input and Output for a 2D array -> b.cpp

2D Arrays in Memory
A 2D arrays is represented as a contiguous block of memory cells (linearly).

there are 2 ways to store the data martrix[3][3]

1 2 3
4 5 6
7 8 9

1. Row major
   1 2 3 4 5 6 7 8 9

2. Column Major
   1 4 7 2 5 8 3 6 9

SPIRAL MATRIX -> d.cpp

problem : you are given a n x m matrix. we have to print the matrix in a spiral way

you have to keep track of these 4 variables
strting row
starting col
ending row
ending col

for the outer spiral

top
for (scol to ecol)
mat[srow][j]

right
for(srow+1 to erow)
mat[i][erow]

bottom
for(ecol-1 to scol)
mat[erow][j]

left
for(erow-1 to srow +1)
mat[i][scol]

for the inner spiral

srow ++
scol++
erow--
ecol--

do this until
srow <= erow
srow < erow

DIOGNAL SUM -> e.cpp

for a square matrix of size n\*n find the sum of the main diognal

SEARCHING IN A SORTED ARRAY

search for a key in row wise or col wise sorted matrix

10 20 30 40
12 25 35 45
27 29 37 48
32 33 39 50

1. brute force approach -> f.cpp
   go to each cell and find the key : O(n^2)

2. Row or column wise binary search -> g.cpp
   for rows -> O(n*logm)
   for cols -> O(m*logn)

this is the better approach

3. Staircase Search - h.cpp
   best appraoch for multidimentional arrays
   it uses the both row sorted and column sorted unlike binary search which uses only one
   the time complexity is O(m+n) -> worst case

if n >>> m -> O(n) -> linear time complexity
if m >>>n -> O(m) -> linear time complexity

MATRIX POINTERS -> i.cpp

in the matrices the name of the matrix points towards the complete first row.
so the 2d array name behaves as the row pointer

passing matrix pointers to functions -> j.cpp

function(int (\*ptr)[4]){....}

here we pass the row pointer

it is same as

function(int mat[][4]){...}

whenever we pass matrices in functions we have to pass rows and columns seperately

PRACTICE PROBLEMS

1. Print the number of all 7’s that are in the 2d array. -> k.cpp
2. Print out the sum of the numbers in the second row of the “nums” array. -> l.cpp
3. Write a program to Find Transpose of a Matrix. -> m.cpp

4. You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 \* n - 1 (inclusive) should form the second row of the constructed 2D array, and so on. -> n.cpp

5. You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation. -> o.cpp
