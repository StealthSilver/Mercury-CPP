#include <iostream>
using namespace std;

int main()
{
    int num = 44;

    bool isEven = num % 2 == 0 ? true : false;
    cout << boolalpha << isEven << endl;

    return 0;
}