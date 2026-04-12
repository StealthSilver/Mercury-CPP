#include <iostream>
using namespace std;

int DecToBin(int n)
{
    int power = 1;
    int binNum = 0;

    while (n > 0)
    {
        int rem = n % 2;
        binNum += rem * power;
        n = n / 2;
        power = power * 10;
    }

    return binNum;
}

int main()
{
    int ans = DecToBin(124);
    cout << "Binary : " << ans << endl;

    return 0;
}