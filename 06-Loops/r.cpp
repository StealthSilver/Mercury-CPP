#include <iostream>
using namespace std;

int main()
{

    int a;
    cout << "enter the number" << endl;

    cin >> a;

    int fact = 1;

    for (int i = 1; i <= a; i++)
    {
        fact *= i;
    }

    cout << "the factorial of " << a << " is " << fact << endl;

    return 0;
}