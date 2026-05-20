#include <iostream>
using namespace std;

int main()
{
    string str = "hello world";

    cout << str.length() << endl; // dot operator is used for member functions

    for (char ch : str)
    {
        cout << ch << ",";
    }
    cout << endl;

    return 0;
}