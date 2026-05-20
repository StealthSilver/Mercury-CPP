#include <iostream>
using namespace std;

bool findDuplicate(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << boolalpha << findDuplicate(arr, n) << endl;
}