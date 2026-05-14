// Program to analyze marks of students (after module 13)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to calculate median
double calculateMedian(vector<int> marks)
{
    int n = marks.size();
    sort(marks.begin(), marks.end());

    if (n % 2 == 0)
    {
        return (marks[n / 2 - 1] + marks[n / 2]) / 2.0;
    }
    else
    {
        return marks[n / 2];
    }
}

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

    // Sorting marks
    sort(marks.begin(), marks.end());

    // Topper
    int topper = marks.back();

    // Average
    double average = accumulate(marks.begin(), marks.end(), 0.0) / n;

    // Median
    double median = calculateMedian(marks);

    // Pass/Fail stats (assuming pass marks = 40)
    int pass = 0, fail = 0;
    for (int m : marks)
    {
        if (m >= 40)
            pass++;
        else
            fail++;
    }

    // Output
    cout << "\n--- Marks Analysis ---\n";
    cout << "Sorted Marks: ";
    for (int m : marks)
    {
        cout << m << " ";
    }

    cout << "\nTopper Marks: " << topper;
    cout << "\nAverage Marks: " << average;
    cout << "\nMedian Marks: " << median;
    cout << "\nPass Students: " << pass;
    cout << "\nFail Students: " << fail;

    return 0;
}