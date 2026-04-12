#include <iostream>
using namespace std;

long long fact(int a)
{
    long long ans = 1;
    for (int i = 1; i <= a; i++)
        ans *= i;
    return ans;
}

long long NcR(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return fact(n) / (fact(r) * fact(n - r));
}

int main()
{
    cout << NcR(5, 2) << endl;
    return 0;
}