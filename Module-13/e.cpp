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

void countingSort(int *arr, int n)
{
    //  Find maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    //  Create count array
    int count[maxVal + 1] = {0};

    // Store frequency
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    //  Reconstruct sorted array
    int index = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    printArr(arr, n);

    countingSort(arr, n);

    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}