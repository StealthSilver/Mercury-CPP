#include <iostream>
using namespace std;

int power(int x, int n)
{
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        result = result * x;
    }

    return result;
}

int main()
{
    int x, n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "Result: " << power(x, n) << endl;

    return 0;
}