#include <iostream>
using namespace std;

int main()
{

    float income;

    cout << "Enter the annual income in Lakhs : " << endl;
    cin >> income;

    if (income <= 5)
    {
        cout << "The tax is : " << 0 << endl;
    }
    else if (income > 5 && income <= 10)
    {
        cout << "The tax is : " << income * 0.2 << " Lakhs" << endl;
    }
    else
    {
        cout << "The tax is : " << income * 0.3 << " Lakhs" << endl;
    }

    return 0;
}