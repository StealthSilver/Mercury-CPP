#include <iostream>
using namespace std;

int lastOccurance(int *arr, int n, int i, int target) {
    if (i == n)
        return -1;

    int ans = lastOccurance(arr, n, i + 1, target);
    if (ans != -1)
        return ans;

    if (arr[i] == target)
        return i;

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 2, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    int target = 2;
    cout << lastOccurance(arr, n, 0, target) << endl; // 3
    return 0;
}
