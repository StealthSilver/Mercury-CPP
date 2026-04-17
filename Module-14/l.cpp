#include <iostream>
using namespace std;

int main()
{
    int arr[4][5] = {
        {7, 2, 7, 4, 5},
        {1, 7, 3, 7, 8},
        {9, 6, 7, 2, 7},
        {4, 7, 5, 7, 1}};

    int sum = 0;

    for (int j = 0; j < 5; j++)
    {
        sum += arr[1][j];
    }

    cout << sum << endl;

    return 0;
}