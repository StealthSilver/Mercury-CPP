#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // descending: i to 1
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        // ascending: 2 to i
        for (int j = 2; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}