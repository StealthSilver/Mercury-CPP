#include <iostream>
using namespace std;

int main()
{

    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    cout << mat << endl;        // this is the address of the first row (which is an array of 5 ints)
    cout << mat + 1 << endl;    // this is the address of the second row (which is an array of 5 ints)
    cout << mat[0] << endl;     // this is the address of the first row (which is an array of 5 ints)
    cout << mat[0] + 1 << endl; // this is the address of the second element of the first row (which is an int)

    return 0;
}