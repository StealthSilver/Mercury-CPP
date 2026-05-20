#include <iostream>
using namespace std;

int main()
{
    int eng, math, sci;

    cout << "enter the english marks \n";
    cin >> eng;
    cout << "enter the maths marks \n";
    cin >> math;
    cout << "enter the science marks \n";
    cin >> sci;

    int average = (eng + math + sci) / 3;

    cout << "the average marks are " << average << endl;

    return 0;
}