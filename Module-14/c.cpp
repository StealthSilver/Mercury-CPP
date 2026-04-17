#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);

    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    // Sort marks for median & topper
    sort(marks.begin(), marks.end());

    // Topper
    int topper = marks[n - 1];

    // Average
    double sum = accumulate(marks.begin(), marks.end(), 0);
    double average = sum / n;

    // Median
    double median;
    if (n % 2 == 0)
    {
        median = (marks[n / 2 - 1] + marks[n / 2]) / 2.0;
    }
    else
    {
        median = marks[n / 2];
    }

    // Pass/Fail (assuming pass = 40)
    int pass = 0, fail = 0;
    for (int m : marks)
    {
        if (m >= 40)
            pass++;
        else
            fail++;
    }

    // Output
    cout << "\n--- Results ---\n";
    cout << "Topper Marks: " << topper << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Median Marks: " << median << endl;
    cout << "Passed Students: " << pass << endl;
    cout << "Failed Students: " << fail << endl;

    return 0;
}