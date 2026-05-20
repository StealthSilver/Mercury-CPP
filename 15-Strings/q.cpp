#include <iostream>
using namespace std;

int countLowercaseVowels(string str)
{
    int count = 0;

    for (char c : str)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string input;

    input = "poUUAaubfhj";

    int result = countLowercaseVowels(input);

    cout << "Number of lowercase vowels: " << result << endl;

    return 0;
}