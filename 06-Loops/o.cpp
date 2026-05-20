#include <iostream>
using namespace std;

int main()
{

    int i;

    while (true)
    {
        cout << "enter the number : " << endl;
        cin >> i;
        if (i % 10 == 0)
        {
            continue;
        }
        cout << i << endl;
    }

    return 0;
}