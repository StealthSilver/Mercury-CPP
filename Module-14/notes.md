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
