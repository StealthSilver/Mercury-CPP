#include <iostream>
using namespace std;

int getIthBit(int num, int i)
{
    int mask = 1 << i;

    if (num & mask)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num, i;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter bit position (i): ";
    cin >> i;

    cout << "Bit at position " << i << " is: " << getIthBit(num, i) << endl;

    return 0;
}