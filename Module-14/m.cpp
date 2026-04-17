#include <iostream>
using namespace std;

void findTranspose(int arr[4][5])
{
    int transpose[5][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }

    cout << "Transpose matrix:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[4][5] = {
        {7, 2, 7, 4, 5},
        {1, 7, 3, 7, 8},
        {9, 6, 7, 2, 7},
        {4, 7, 5, 7, 1}};

    findTranspose(arr);

    return 0;
}