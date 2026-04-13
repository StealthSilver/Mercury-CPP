#include <iostream>
using namespace std;

int main()
{
    int marks[10] = {4, 3, 7, 2, 8, 3, 9, 2, 1, 3};

    int n = sizeof(marks) / sizeof(int);

    int max = marks[0];
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
            index = i;
        }
    }

    cout << "The max of the array is " << max
         << " at the index " << index << endl;

    return 0;
}