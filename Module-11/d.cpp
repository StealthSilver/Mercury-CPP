#include <iostream>
using namespace std;

int main()
{

    int marks[10] = {3, 4, 5, 6, 7, 8, 9, 23, 43, 2};
    int len = sizeof(marks) / sizeof(int);

    for (int i = 0; i < len; i++)
    {
        cout << marks[i] << endl;
    }
    cout << "length of the array is : " << len << endl;
    return 0;
}