#include <iostream>
using namespace std;

int main()
{
    int num, original, digit, sum = 0;

    cout << "Enter a 3 digit number: ";
    cin >> num;

    original = num;

    while (num > 0)
    {
        digit = num % 10;                  // get last digit
        sum = sum + digit * digit * digit; // cube and add
        num = num / 10;                    // remove last digit
    }

    if (sum == original)
        cout << "Armstrong number";
    else
        cout << "Not an Armstrong number";

    return 0;
}