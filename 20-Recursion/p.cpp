#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binarySearch(arr, s, mid - 1, key);
    return binarySearch(arr, mid + 1, e, key);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int key = 5;
    cout << binarySearch(arr, 0, n - 1, key) << endl; // 4
    return 0;
}
