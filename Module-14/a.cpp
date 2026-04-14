#include <iostream>
using namespace std;

int main()
{

    int marks[5][2] = {
        {85, 90},
        {78, 82},
        {92, 88},
        {80, 85},
        {90, 95}};

    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < 2; j++)
        {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}