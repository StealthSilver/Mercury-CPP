#include <iostream>
using namespace std;

void printArr(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(char *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        char curr = arr[i];
        int prev = i - 1;

        // Change comparison for descending
        while (prev >= 0 && arr[prev] < curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

int main()
{
    char arr[] = {'f', 'b', 'a', 'c', 'd'};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArr(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array (Descending): ";
    printArr(arr, n);

    return 0;
}