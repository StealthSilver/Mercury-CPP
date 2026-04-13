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

void selectionSort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        // loop to find min
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx]) // -> ascending order;
            // if (arr[j] > arr[minIdx]) // descending order
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    int arr[] = {5, 4, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    printArr(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}