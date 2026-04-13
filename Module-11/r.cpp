#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *ptr1 = &a;
    int *ptr2 = ptr1 + 3;

    cout << ptr2 << endl;
    cout << ptr1 << endl;

    // Pointer subtraction returns the number of elements between them, not bytes
    cout << ptr2 - ptr1 << endl;
    cout << "There are 3 integer spaces between them" << endl;

    return 0;
}
