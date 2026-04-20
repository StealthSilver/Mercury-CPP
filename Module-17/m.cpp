#include <iostream>
using namespace std;

int clearLastIBits(int num, int i)
{
    int mask = (~0) << i;
    return num & mask;
}

int main()
{
    int num, i;

    cout << "Enter number: ";
    cin >> num;

    cout << "Enter i: ";
    cin >> i;

    cout << "Result after clearing last " << i << " bits: "
         << clearLastIBits(num, i) << endl;

    return 0;
}