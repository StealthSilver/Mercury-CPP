#include <iostream>
using namespace std;

bool isPrime(int n) // optimised approach
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << "True";
    else
        cout << "False";

    return 0;
}