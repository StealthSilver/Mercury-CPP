#include <iostream>
using namespace std;

// Distinct values, ascending sorted array rotated at unknown pivot.
// Returns index of target, or -1.
int searchRotated(int *arr, int si, int ei, int target) {
    if (si > ei)
        return -1;

    int mid = si + (ei - si) / 2;

    if (arr[mid] == target)
        return mid;

    // Left half [si..mid] is sorted
    if (arr[si] <= arr[mid]) {
        if (target >= arr[si] && target < arr[mid])
            return searchRotated(arr, si, mid - 1, target);
        return searchRotated(arr, mid + 1, ei, target);
    }

    // Right half [mid..ei] is sorted
    if (target > arr[mid] && target <= arr[ei])
        return searchRotated(arr, mid + 1, ei, target);
    return searchRotated(arr, si, mid - 1, target);
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << searchRotated(arr, 0, n - 1, 0) << endl;  // 4
    cout << searchRotated(arr, 0, n - 1, 3) << endl;  // -1
    cout << searchRotated(arr, 0, n - 1, 6) << endl;  // 2

    int arr2[] = {5, 6, 7, 0, 1, 2, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << searchRotated(arr2, 0, n2 - 1, 0) << endl; // 3

    return 0;
}
