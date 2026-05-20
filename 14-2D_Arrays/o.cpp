#include <iostream>
using namespace std;

// Function to rotate matrix 90 degrees clockwise
void rotateMatrix(int mat[][4], int n)
{
    // Step 1: Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(mat[i][start], mat[i][end]);
            start++;
            end--;
        }
    }
}

// Function to print matrix
void printMatrix(int mat[][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    cout << "Original Matrix:\n";
    printMatrix(mat, 4);

    rotateMatrix(mat, 4);

    cout << "\nRotated Matrix (90 deg clockwise):\n";
    printMatrix(mat, 4);

    return 0;
}