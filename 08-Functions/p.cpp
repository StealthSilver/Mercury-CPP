#include <iostream>
using namespace std;

char CharAfter(char a)
{
    if (a == 'z')
        return 'a';

    if (a == 'Z')
        return 'A';

    return a + 1;
}

int main()
{
    cout << CharAfter('A') << endl;
    cout << CharAfter('z') << endl;
    cout << CharAfter('Z') << endl;

    return 0;
}