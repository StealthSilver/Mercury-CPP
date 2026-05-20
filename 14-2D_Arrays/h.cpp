#include <iostream>
using namespace std;

pair<int, int> staircaseSearch(int mat[][5], int rows, int cols)
{
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int i = 0;        // start row
    int j = cols - 1; // start at top-right

    while (i < rows && j >= 0)
    {
        if (mat[i][j] == key)
        {
            return {i, j};
        }
        else if (mat[i][j] > key)
        {
            j--; // move left
        }
        else
        {
            i++; // move down
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

    pair<int, int> result = staircaseSearch(mat, 5, 5);

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