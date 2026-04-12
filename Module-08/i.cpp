#include <iostream>
using namespace std;

bool isPrime(int a)
{
    if (a <= 1)
        return false;

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }

    return true;
}

int main()
{

    bool res = isPrime(41);
    cout << boolalpha << res << endl;

    return 0;
}