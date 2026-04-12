#include <iostream>
using namespace std;

int sum(int a, int b = 2) // b is the default parameter
{
    int sum = a + b;
    return sum;
}

int main()
{
    int res = sum(7);
    cout << res << endl;
    return 0;
}