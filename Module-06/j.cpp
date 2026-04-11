#include <iostream>
using namespace std;

int main()
{

    int n = 2312341;
    int digit, sum = 0;
    while (n > 0)
    {
        digit = n % 10;
        if (digit % 2 != 0)
        {
            sum += digit;
        }

        n /= 10;
    }

    cout << "the sum is " << sum << endl;

    return 0;
}