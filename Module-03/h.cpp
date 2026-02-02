#include <iostream>
using namespace std;

int main()
{
    float pencil, eraser, pen;
    cout << "enter the price of pencil \n";
    cin >> pencil;

    cout << "enter the price of eraser \n";
    cin >> eraser;

    cout << "enter the price of pen \n";
    cin >> pen;

    float total = (pencil + pen + eraser) + ((pencil + pen + eraser) / 100 * 18);

    cout << "the total price is " << total << "\n";
    return 0;
}