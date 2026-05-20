#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "hello";
    cout << str << endl;

    str = "yellow";
    cout << str << endl;
    cout << str[0] << str[1] << endl;

    string str2;
    getline(cin, str2); // we can also pass the delimiter as the third argument
    cout << str2 << endl;

    return 0;
}