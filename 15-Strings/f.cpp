#include <iostream>
using namespace std;

void toUpper(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main()
{
    char str[] = "f.cpp";

    toUpper(str);

    cout << "Uppercase: " << str << endl;

    return 0;
}