#include <iostream>
using namespace std;

int main()
{

    int a, original, sum = 0, digit = 0;
    cout << "enter the number :" << endl;
    cin >> a;
    original = a;

    while (a > 0)
    {
        digit = a % 10;
        sum += (digit * digit * digit);
        a /= 10;
    }

    cout << (original == sum ? "yes" : "no") << endl;
}