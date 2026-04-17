#include <iostream>
using namespace std;

void func(int mat[][5], int rows, int cols)
{
    cout << "Inside func 1: " << mat << endl; // this is the address of the first row (which is an array of 5 ints)
}

void func2(int (*mat)[5], int rows, int cols)
{
    cout << "Inside func 2: " << mat << endl; // this is the address of the first row (which is an array of 5 ints)
}

// both the functions above are equivalent and can be called with the same 2D array.
// The first one uses a more traditional C-style syntax, while the second one uses a pointer to an array of 5 ints. Both will work correctly and print the address of the first row of the 2D array when called.

int main()
{

    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    func(mat, 5, 5);
    func2(mat, 5, 5);

    return 0;
}