#include <iostream>
using namespace std;

int WholeSquare(int a, int b)
{
    int ans = (a * a) + (b * b) + (2 * a * b);

    return ans;
}

int main()
{
    int res = WholeSquare(6, 7);

    cout << res << endl;

    return 0;
}