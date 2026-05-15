#include <iostream>
#include <string>
using namespace std;

void printArr(string arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(string arr[], int si, int mid, int ei) {
    int n = ei - si + 1;
    string *temp = new string[n];

    int i = si, j = mid + 1, k = 0;

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

void mergeSort(string arr[], int si, int ei) {
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main() {
    string arr[] = {"sun", "earth", "mars", "mercury"};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted: ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted:   ";
    printArr(arr, n); // earth mars mercury sun

    return 0;
}
