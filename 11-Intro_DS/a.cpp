#include <iostream>
using namespace std;

int main()
{

    int marks[50]; // initializing the array

    cout << marks[0] << endl;
    cout << marks[2] << endl;
    cout << marks[49] << endl;

    cout << sizeof(marks) << endl; // gives the bytes allocated to the array

    cout << sizeof(marks) / sizeof(int) << endl; // gives the length of array

    return 0;
}