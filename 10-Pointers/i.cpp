#include <iostream>
using namespace std;

void changeA(int &a) // reference variable
{
    a = 20;
    cout << a << endl;
}

int main()
{
    int a = 10;
    changeA(a);
    cout << a << endl;

    return 0;
}