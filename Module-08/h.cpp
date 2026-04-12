#include <iostream>
using namespace std;

int fact(int a)
{

    int ans = 1;

    for (int i = 1; i <= a; i++)
    {
        ans *= i;
    }

    return ans;
}

int main()
{
    int res = fact(4);
    cout << res << endl;

    return 0;
}