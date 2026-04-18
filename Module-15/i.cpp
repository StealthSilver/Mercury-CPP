#include <iostream>
#include <cstring>
using namespace std;

bool isPallindrom(char str[], int n)
{
    int st = 0, end = n - 1;
    while (st < end)
    {
        if (str[st++] != str[end--])
        {
            cout << "not a valid palindrome" << endl;
            return false;
        }
    }
    cout << "valid palindrome" << endl;
    return true;
}

int main()
{
    char word[] = "racecardef";
    isPallindrom(word, strlen(word));
    return 0;
}