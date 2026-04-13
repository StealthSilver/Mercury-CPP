#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            st = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 67, 68, 69, 90};
    int n = sizeof(arr) / sizeof(int);
    int key;

    cout << "Enter the key you need to search for: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Key found at index: " << result << endl;
    else
        cout << "Key not found!" << endl;

    return 0;
}