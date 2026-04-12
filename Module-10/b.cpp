#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    cout << "Address of a is : " << ptr << endl;
    cout << "size of prt is : " << sizeof(ptr) << endl;

    float pi = 3.14;

    float *ptr2 = &pi;
    cout << "Address of pi is : " << ptr2 << endl;
    cout << "size of prt2 is : " << sizeof(ptr2) << endl;

    return 0;
}