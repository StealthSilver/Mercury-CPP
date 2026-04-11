#include <iostream>
using namespace std;

int main()
{
    int n = 8;

    // upper half

    for (int i = 1; i <= n; i++)
    {

        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces

        for (int k = 1; k <= 2 * (n - i); k++)
        {
            cout << "  ";
        }

        // stars
        for (int l = 1; l <= i; l++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // lower half

    for (int i = n; i >= 1; i--)
    {

        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces

        for (int k = 1; k <= 2 * (n - i); k++)
        {
            cout << "  ";
        }

        // stars
        for (int l = 1; l <= i; l++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}