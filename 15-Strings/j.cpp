#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[100];
    char str2[100] = "hello world";

    strcpy(str1, str2);
    cout << str1 << endl;

    char str3[] = "abc";
    char str4[] = "xyz";

    strcat(str3, str4);
    cout << str3 << endl;

    char str5[] = "lmn";
    char str6[] = "lmn";

    cout << strcmp(str5, str6) << endl; // for equal
    cout << strcmp(str1, str2) << endl; // value of characters are checked one after the other
    cout << strcmp(str3, str4) << endl;
    return 0;
}