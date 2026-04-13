#include <iostream>
using namespace std;

void printArr(int nums[], int n) // here the array is not passed but the integer pointer is passed
{

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " , ";
    }

    cout << endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr) / sizeof(int);

    printArr(arr, n);
    return 0;
}