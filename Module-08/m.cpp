#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printPrime(int a)
{
    int count = 0;

    // Count total primes first
    for (int i = 2; i <= a; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }

    cout << "Total primes from 2 to " << a << " are " << count << endl;

    // Print actual prime numbers
    for (int i = 2; i <= a; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    printPrime(n);

    return 0;
}