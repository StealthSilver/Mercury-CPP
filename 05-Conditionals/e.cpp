#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "enter the marks" << endl;
    cin >> marks;

    if (marks >= 90)
    {
        cout << "Grade A" << endl;
    }
    else if (marks >= 80)
    {
        cout << "Grade B" << endl;
    }
    else
    {
        cout << "Grade C" << endl;
    }

    return 0;
}