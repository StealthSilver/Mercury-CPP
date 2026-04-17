#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char work[] = "code";
    char arr[5] = "code"; // size will be 5 as the null char will also be stored
    char arr2[] = {'c', 'o', 'd', 'e', '\0'};
    char str[100] = {'c', 'o', 'd', 'e', '\0'}; // at all the remaining indices garbage values are stored

    cout << work << endl;
    cout << arr << endl;
    cout << arr2 << endl;
    cout << str << endl;
    cout << strlen(work) << endl; // in this the length of the null char is not included
    return 0;
}