#include <iostream>
using namespace std;

void findAllOccurrences(int arr[], int n, int i, int key) {
    if (i == n)
        return;

    if (arr[i] == key)
        cout << i << " ";

    findAllOccurrences(arr, n, i + 1, key);
}

int main() {
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n = 9;
    int key = 2;
    findAllOccurrences(arr, n, 0, key); // 1 5 7 8
    cout << endl;
    return 0;
}
