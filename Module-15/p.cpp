#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "cat";
    string str2 = "dog";

    cout << boolalpha << (str1 == str2) << endl;
    cout << boolalpha << (str1 < str2) << endl;
    cout << boolalpha << (str1 > str2) << endl;

    return 0;
}