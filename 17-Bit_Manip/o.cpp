#include <iostream>
using namespace std;

int countSetBits(int num)
{
    int count = 0;

    while (num > 0)
    {
        num = num & (num - 1); // removes last set bit
        count++;
    }

    return count;
}

int main()
{
    int num;

    cout << "Enter number: ";
    cin >> num;

    cout << "Set bits: " << countSetBits(num) << endl;

    return 0;
}