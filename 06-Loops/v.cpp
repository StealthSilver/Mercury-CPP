#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    int a = 0, b = 1, next;

    cout << a << " " << b << " ";

    for (int i = 3; i <= n; i++)
    {
        next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }

    return 0;
}