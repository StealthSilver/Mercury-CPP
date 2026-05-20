#include <iostream>
using namespace std;

int clearIthBit(int num, int i)
{
    int mask = ~(1 << i);
    return num & mask;
}

int main()
{
    int num, i;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter bit position (i): ";
    cin >> i;

    cout << "Result after clearing bit: " << clearIthBit(num, i) << endl;

    return 0;
}