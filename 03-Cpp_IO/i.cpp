#include <iostream>
using namespace std;

int main()
{
    int principal, time;

    float rate;
    cout << "enter the principal amount : \n";
    cin >> principal;

    cout << "enter the rate : \n";
    cin >> rate;

    cout << "enter the time amont : \n";
    cin >> time;

    int si = principal * rate * time / 100;
    cout << "the simple interest on the " << principal << " after " << time << " is " << si << "\n";
    cout << "the total amount will be " << principal + si;
    return 0;
}