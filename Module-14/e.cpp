#include <iostream>
using namespace std;

int diagonalSum(int mat[][5], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
    }

    return sum;
}

int main()
{
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    int result = diagonalSum(mat, 5);

    cout << "Main Diagonal Sum = " << result << endl;

    return 0;
}