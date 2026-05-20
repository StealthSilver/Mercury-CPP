#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor)
{
    // Handle overflow
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Convert to long to avoid overflow
    long long dvd = llabs(dividend);
    long long dvs = llabs(divisor);

    long long quotient = 0;

    while (dvd >= dvs)
    {
        long long temp = dvs, multiple = 1;

        // Find largest shift
        while (dvd >= (temp << 1))
        {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        quotient += multiple;
    }

    return negative ? -quotient : quotient;
}

int main()
{
    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    cout << "Quotient: " << divide(dividend, divisor) << endl;

    return 0;
}