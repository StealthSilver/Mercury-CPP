#include <iostream>
using namespace std;

int main()
{
    cout << "the AND operator" << endl;

    cout << ((true) && (true)) << endl;
    cout << ((true) && (false)) << endl;
    cout << ((false) && (false)) << endl;
    cout << ((false) && (true)) << endl;

    cout << "the OR operator" << endl;

    cout << ((true) || (true)) << endl;
    cout << ((true) || (false)) << endl;
    cout << ((false) || (false)) << endl;
    cout << ((false) || (true)) << endl;

    cout << "the NOT operator" << endl;

    cout << (!true) << endl;
    cout << (!false) << endl;

    return 0;
}