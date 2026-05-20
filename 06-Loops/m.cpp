#include <iostream>
using namespace std;

int main()
{

    int i;

    while (true)
    {
        cout << "enter the number \n";
        cin >> i;

        if (i % 10 == 0)
        {
            break;
        }
    }

    cout << "out of the loop \n";

    return 0;
}