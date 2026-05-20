#include <iostream>
using namespace std;

bool isEven(int a)
{
    bool res = (a % 2 == 0);
    return res;
}

int main()
{
    bool ans = isEven(9);

    cout << (ans ? "it is even" : "it is odd") << endl;
    return 0;
}