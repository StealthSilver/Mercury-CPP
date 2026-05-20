#include <iostream>
using namespace std;

int main()
{

    int a;
    cout << "enter the number : " << endl;
    cin >> a;

    bool isPrime = true;

    for (int i = 2; i <= a - 1; i++)
    {
        if (a % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << (isPrime ? "Its a prime" : "Not a prime") << endl;

    return 0;
}