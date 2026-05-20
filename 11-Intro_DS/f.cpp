#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    int marks[n]; // Note: Variable-length arrays work in some compilers

    // Input elements
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    // Print length
    cout << "Length of the array is: " << n << endl;

    // Print elements
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << endl;
    }

    return 0;
}