#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int *aptr = &a;

    cout << aptr << endl;
    aptr++;
    cout << aptr << endl;

    char ch = 'A';
    char *bptr = &ch; // Changed int* to char*
    // C++ treats char* as a string, so to print the memory address,
    // we cast it to void*
    cout << (void *)bptr << endl;
    bptr++; // Moves the pointer by 1 byte (size of a char)

    cout << (void *)bptr << endl;

    return 0;
}