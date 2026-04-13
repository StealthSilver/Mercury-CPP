#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n)
{

    for (int i = 1; i < n - 1; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) // for ascending order
        // while (prev >= 0 && arr[prev] < curr) -> for descending order
        {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

int main()
{
    int arr[] = {5, 4, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    printArr(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}