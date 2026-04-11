#include <iostream>

using namespace std;

int main()
{

    float marks;

    cout << "enter the marks" << endl;
    cin >> marks;

    if (marks >= 33)
    {
        cout << "pass" << endl;
    }
    else
    {
        cout << "fail" << endl;
    }
    return 0;
}