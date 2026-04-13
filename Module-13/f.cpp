#include <iostream>
#include <algorithm> // for sort
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[8] = {1, 5, 8, 3, 9, 2, 5, 7};

    // Ascending order
    sort(arr, arr + 8);
    cout << "Ascending order: ";
    print(arr, 8);

    // Descending order
    sort(arr, arr + 8, greater<int>());
    cout << "Descending order: ";
    print(arr, 8);

    return 0;
}