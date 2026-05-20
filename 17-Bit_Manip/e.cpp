#include <iostream>
using namespace std;

int main()
{
    int num = 5; // binary: 0101

    cout << "Binary Shift Operators Demonstration\n";

    // Left shift
    cout << "Left Shift (<<):\n";
    for (int i = 1; i <= 2; i++)
    {
        cout << num << " << " << i << " = " << (num << i) << endl;
    }

    cout << endl;

    // Right shift
    cout << "Right Shift (>>):\n";
    for (int i = 1; i <= 2; i++)
    {
        cout << num << " >> " << i << " = " << (num >> i) << endl;
    }

    return 0;
}