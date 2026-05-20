#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter year: ";
    cin >> year;

    if (year % 400 == 0)
        cout << "Leap year";
    else if (year % 100 == 0)
        cout << "Not a leap year";
    else if (year % 4 == 0)
        cout << "Leap year";
    else
        cout << "Not a leap year";

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int year;
//     cout << "Enter the year: ";
//     cin >> year;

//     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//     {
//         cout << "Leap year" << endl;
//     }
//     else
//     {
//         cout << "Not a leap year" << endl;
//     }

//     return 0;
// }