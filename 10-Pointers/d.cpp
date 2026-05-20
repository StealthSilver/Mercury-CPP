#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;

    cout << "value of the variable stored at : " << ptr << " is " << *ptr << endl;

    *ptr = 20; // we can also modify the value
    cout << a << endl;

    return 0;
}