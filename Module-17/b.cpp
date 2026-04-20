// or.cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Bitwise OR Demonstration\n";

    int values[2] = {0, 1};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a = values[i];
            b = values[j];

            cout << a << " | " << b << " = " << (a | b) << endl;
        }
    }

    return 0;
}