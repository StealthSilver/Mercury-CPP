#include <iostream>

using namespace std;

int main()
{

    float num1, num2;

    cout << "enter the numbers" << endl;
    cin >> num1 >> num2;

    if (num1 > num2)
    {
        cout << num1 << endl;
    }
    else
    {
        cout << num2 << endl;
    }
    return 0;
}