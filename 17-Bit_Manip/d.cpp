#include <iostream>
using namespace std;

int main()
{
    cout << "Bitwise NOT (~) Demonstration\n";

    int values[2] = {0, 1};

    for (int i = 0; i < 2; i++)
    {
        int a = values[i];

        cout << "~" << a << " = " << (~a) << endl;
    }

    return 0;
}