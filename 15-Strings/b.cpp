#include <iostream>
using namespace std;

int main()
{

    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;

    cout << arr << endl; // this will give the complete array, not the address

    char str[5] = {'c', 'o', 'd', 'e', '\0'};
    cout << str << endl;

    "Hello world"; // this is a string literal

    return 0;
}