#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[10];
    cin >> word;

    cout << "the word is " << word << endl;
    cout << "the length of the word is " << strlen(word) << endl;
    return 0;
}