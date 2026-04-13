#include <iostream>
using namespace std;

int main()
{
    int marks[10] = {4, 3, 7, 2, 8, 3, 9, 2, 1, 3};

    int n = sizeof(marks) / sizeof(int);

    int max = marks[0];
    int min = marks[0];
    int max_index = 0;
    int min_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > max)
        {
            max = marks[i];
            max_index = i;
        }

        if (marks[i] < min)
        {
            min = marks[i];
            min_index = i;
        }
    }

    cout << "The max of the array is " << max
         << " at the index " << max_index << endl;

    cout << "The min of the array is " << min
         << " at the index " << min_index << endl;

    return 0;
}