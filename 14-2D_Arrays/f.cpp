#include <iostream>
#include <utility>
using namespace std;

pair<int, int> searchKey(int mat[][5], int n)
{
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == key)
            {
                return {i, j};
            }
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

    pair<int, int> result = searchKey(mat, 5);

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