#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char sentence[100];

    cin.getline(sentence, 40);
    cout << "your sentence was : " << sentence << endl;
    cout << "the length is : " << strlen(sentence) << endl;
    return 0;
}