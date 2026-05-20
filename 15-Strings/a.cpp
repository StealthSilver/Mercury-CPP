#include <iostream>
using namespace std;

int main()
{
    char ch1 = 'a';
    char ch2 = 'A';
    char ch3 = '1';
    char ch4 = '!';
    char ch5 = '\n'; // fixed

    cout << ch1 << endl;
    cout << int(ch1) << endl;

    // to get the position of some char in alph order
    char ch6 = 'f';
    int pos = ch6 - 'a';
    cout << pos << endl;

    return 0;
}