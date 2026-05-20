#include <iostream>
using namespace std;

pair<int, int> binarySearchMatrix(int mat[][5], int rows, int cols)
{
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Convert 1D index to 2D
        int r = mid / cols;
        int c = mid % cols;

        if (mat[r][c] == key)
        {
            return {r, c};
        }
        else if (mat[r][c] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return {-1, -1};
}

int main()
{
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    pair<int, int> result = binarySearchMatrix(mat, 5, 5);

    if (result.first != -1)
    {
        cout << "Key found at: (" << result.first << ", " << result.second << ")" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    return 0;
}