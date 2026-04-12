#include <iostream>
using namespace std;

int SumOfDigits(int a)
{
    int sum = 0, digit = 0;

    while (a > 0)
    {
        digit = a % 10;
        sum += digit;
        a /= 10;
    }

    return sum;
}

int main()
{

    int ans = SumOfDigits(123456789);
    cout << ans << endl;

    return 0;
}