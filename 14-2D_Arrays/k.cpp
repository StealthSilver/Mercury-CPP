#include <iostream>
using namespace std;

int main()
{

    int arr[4][5] = {
        {7, 2, 7, 4, 5},
        {1, 7, 3, 7, 8},
        {9, 6, 7, 2, 7},
        {4, 7, 5, 7, 1}};

    int target = 7, count = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == target)
            {
                count++;
            }
        }
    }

    cout << "the result is : " << count << endl;
    return 0;
}