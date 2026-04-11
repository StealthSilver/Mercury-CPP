#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i; // add factors
        }
    }

    if (sum == num)
        cout << "Perfect number";
    else
        cout << "Not a perfect number";

    return 0;
}