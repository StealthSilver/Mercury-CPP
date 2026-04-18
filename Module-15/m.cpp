#include <iostream>
using namespace std;

int main()
{
    string str = "hello world";

    cout << str.length() << endl;
    cout << str[2] << endl;
    cout << str.at(2) << endl;

    return 0;
}