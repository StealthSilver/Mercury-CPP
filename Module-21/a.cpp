#include <iostream>
using namespace std;

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Merge two sorted halves arr[si..mid] and arr[mid+1..ei] into one sorted range.
void merge(int *arr, int si, int mid, int ei) {
    int n = ei - si + 1;
    int *temp = new int[n];

    int i = si;       // left half start
    int j = mid + 1;  // right half start
    int k = 0;        // index in temp

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= ei)
        temp[k++] = arr[j++];

    for (int idx = 0; idx < n; idx++)
        arr[si + idx] = temp[idx];

    delete[] temp;
}

void mergeSort(int *arr, int si, int ei) {
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArr(arr, n);

    return 0;
}
