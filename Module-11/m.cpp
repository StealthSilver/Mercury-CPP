#include <iostream>
using namespace std;

void ReverseArray(int *arr, int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);

        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        start++;
        end--;
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