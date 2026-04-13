#include <iostream>
using namespace std;

void ReverseArray(int *arr, int n)
{
    int temp[100]; // extra array

    // store elements in reverse order
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - 1 - i];
    }

    // copy back to original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 4, 5, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    PrintArray(arr, n);

    ReverseArray(arr, n);

    cout << "Reversed Array: ";
    PrintArray(arr, n);

    return 0;
}