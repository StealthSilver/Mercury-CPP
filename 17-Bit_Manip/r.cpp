#include <iostream>
using namespace std;

int clearBitsInRange(int num, int i, int j)
{
    int left = (~0) << (j + 1);
    int right = (1 << i) - 1;

    int mask = left | right;

    return num & mask;
}

int main()
{
    int num, i, j;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter i and j: ";
    cin >> i >> j;

    cout << "Result after clearing bits from " << i << " to " << j << " is: "
         << clearBitsInRange(num, i, j) << endl;

    return 0;
}