#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Integer type
    int num1 = 4;
    cout << "Integer (int): " << num1 << endl;
    cout << "Size: " << sizeof(num1) << " bytes" << endl
         << endl;

    // Float type
    float num2 = 4.5;
    cout << "Float: " << num2 << endl;
    cout << "Size: " << sizeof(num2) << " bytes" << endl
         << endl;

    // Double type
    double num3 = 434.4343;
    cout << "Double: " << fixed << setprecision(4) << num3 << endl;
    cout << "Size: " << sizeof(num3) << " bytes" << endl
         << endl;

    // Boolean type
    bool isAdult = true;
    cout << "Boolean: " << boolalpha << isAdult << endl;
    cout << "Size: " << sizeof(isAdult) << " bytes" << endl
         << endl;

    // Character type
    char grade = 'A';
    cout << "Character: " << grade << endl;
    cout << "ASCII value: " << (int)grade << endl;
    cout << "Size: " << sizeof(grade) << " bytes" << endl
         << endl;

    // Additional data types
    long long bigNum = 9876543210;
    cout << "Long Long: " << bigNum << endl;
    cout << "Size: " << sizeof(bigNum) << " bytes" << endl
         << endl;

    short smallNum = 32767;
    cout << "Short: " << smallNum << endl;
    cout << "Size: " << sizeof(smallNum) << " bytes" << endl
         << endl;

    // String type
    string name = "Mercury-CPP";
    cout << "String: " << name << endl;
    cout << "Size: " << sizeof(name) << " bytes" << endl;

    return 0;
}