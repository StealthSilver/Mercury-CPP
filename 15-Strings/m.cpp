#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello world";

    cout << str.length() << endl;
    cout << str[2] << endl;
    cout << str.at(2) << endl;
    cout << str.substr(1, 6) << endl;
    cout << str.find("orl") << endl;

    return 0;
}