#include <iostream>
#include <cmath>
using namespace std;

int BinToDec(int n)
{
    int dec = 0, i = 0, rem;

    while (n != 0)
    {
        rem = n % 10;
        n /= 10;

        dec += rem * pow(2, i);
        i++;
    }

    return dec;
}

int main()
{
    int ans = BinToDec(101);
    cout << "Decimal: " << ans << endl;

    return 0;
}