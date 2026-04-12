#include <iostream>
using namespace std;

int product(int a, int b)
{
    int pro = a * b;
    return pro;
}

int main()
{
    int res = product(3, 4);
    cout << res << endl;
    return 0;
}