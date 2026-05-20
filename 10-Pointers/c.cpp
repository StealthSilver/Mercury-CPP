#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    int **pptr = &ptr; // pointer to a pointer

    cout << "Address of a is : " << ptr << endl;
    cout << "Address of prt is : " << pptr << endl;

    return 0;
}