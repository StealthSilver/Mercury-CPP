#include <iostream>
using namespace std;

// int MaxOf3(int a, int b, int c)
// {
//     int ans = max(a, max(b, c));
//     return ans;
// }

int MaxOf3(int a, int b, int c)
{
    int ans;

    if (a > b && a > c)
    {
        ans = a;
    }
    else if (b > a && b > c)
    {
        ans = b;
    }
    else
    {
        ans = c;
    }

    return ans;
}

int main()
{

    int res = MaxOf3(4, 5, 9);
    cout << res << endl;

    return 0;
}