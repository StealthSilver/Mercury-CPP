#include <iostream>
using namespace std;

int fastPower(int x, int n)
{
    int result = 1;
    int base = x;

    while (n > 0)
    {
        if (n & 1)
        {
            result = result * base;
        }

        base = base * base;
        n = n >> 1;
    }

    return result;
}

int main()
{
    int x, n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "Result: " << fastPower(x, n) << endl;

    return 0;
}