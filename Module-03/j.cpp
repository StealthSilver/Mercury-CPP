#include <iostream>
using namespace std;
#define PI 3.14;

int main()
{
    float rad;

    cout << "enter the radius of the circle : \n";
    cin >> rad;

    float area = rad * rad * PI;

    cout << "the area of the circle is " << area << " \n";

    return 0;
}