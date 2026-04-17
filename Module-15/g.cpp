#include <iostream>
using namespace std;

// function to convert char array to lowercase
void toLower(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int main()
{
    char str[] = "F.CPP";

    toLower(str);

    cout << "Lowercase: " << str << endl;

    return 0;
}