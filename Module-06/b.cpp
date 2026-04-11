#include <iostream>
using namespace std;

int main()
{

    int num;

    for (num = 1; num >= 0; num++) // this is the infinite loop as the condition is always true
    {
        cout << num << endl;
    }

    cout << "the loop ends" << endl;

    return 0;
}