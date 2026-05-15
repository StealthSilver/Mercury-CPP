#include <iostream>
using namespace std;

long long mergeAndCount(int *arr, int *temp, int si, int mid, int ei) {
    int i = si, j = mid + 1, k = si;
    long long invCount = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= ei)
        temp[k++] = arr[j++];

    for (int idx = si; idx <= ei; idx++)
        arr[idx] = temp[idx];

    return invCount;
}

long long mergeSortCount(int *arr, int *temp, int si, int ei) {
    if (si >= ei)
        return 0;

    int mid = si + (ei - si) / 2;

    long long left = mergeSortCount(arr, temp, si, mid);
    long long right = mergeSortCount(arr, temp, mid + 1, ei);
    long long cross = mergeAndCount(arr, temp, si, mid, ei);

    return left + right + cross;
}

long long inversionCount(int *arr, int n) {
    int *temp = new int[n];
    long long count = mergeSortCount(arr, temp, 0, n - 1);
    delete[] temp;
    return count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << inversionCount(arr, n) << endl; // 3

    int arr2[] = {5, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << inversionCount(arr2, n2) << endl; // 10

    return 0;
}
