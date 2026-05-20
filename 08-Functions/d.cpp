#include <iostream>
using namespace std;

int sum(int a, int b) // a,b are parameters
{
    int sum = a + b;
    return sum;
}

int difference(int a, int b)
{
    int diff = a - b;
    return diff;
}

int main()
{
    int res = sum(3, 4); // 3,4 are parameters
    cout << res << endl;
    int def = difference(5, 2);
    cout << def << endl;
    return 0;
}