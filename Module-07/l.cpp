#include <iostream>
using namespace std;

int main()
{

    int n = 5;

    for (int i = 1; i <= 5; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // stars
        for (int k = 1; k <= 5; k++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}