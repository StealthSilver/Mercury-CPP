#include <iostream>
using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Lomuto partition: pivot = arr[ei]. Returns final pivot index.
int partition(int *arr, int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1; // last index of region <= pivot

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[ei]);
    return i + 1;
}

void quickSort(int *arr, int si, int ei) {
    if (si >= ei)
        return;

    int p = partition(arr, si, ei);

    quickSort(arr, si, p - 1);
    quickSort(arr, p + 1, ei);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    printArr(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArr(arr, n);

    return 0;
}
