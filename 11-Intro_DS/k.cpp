#include <iostream>
using namespace std;

int LinearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the key you want to find: ";
    cin >> key;

    int index = LinearSearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}