#include <iostream>
using namespace std;

int sum(int a, int b)
{
    cout << a + b << endl;
    return a + b;
}

double sum2(double a, double b)
{
    cout << a + b << endl;
    return a + b;
}

int main()
{
    sum(2, 3);
    sum2(1.5, 2.5);

    return 0;
}