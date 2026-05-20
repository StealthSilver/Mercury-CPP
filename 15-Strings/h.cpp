#include <iostream>
using namespace std;

int main()
{

    char str[] = "hello";
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }
    // reverse the char array
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    cout << "Reversed: " << str << endl;
    return 0;
}