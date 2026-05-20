#include <iostream>
using namespace std;

int main()
{

    int marks[5];
    int len = sizeof(marks) / sizeof(int);

    for (int i = 0; i < len; i++)
    {
        cin >> marks[i];
    }
    cout << "length of the array is : " << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << [marks[i]] << endl;
    }
    return 0;
}