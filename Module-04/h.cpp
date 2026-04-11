#include <iostream>

using namespace std;

int main()
{

    int a = 3;

    int b = a++; // post increment
    cout << "a = " << b << endl;

    int c = ++a; // pre increment
    cout << "a = " << c << endl;

    int d = 8;

    int e = d--; // post decrement
    cout << "e = " << e << endl;

    int f = --d; // pre decrement
    cout << "f = " << f << endl;

    return 0;
}