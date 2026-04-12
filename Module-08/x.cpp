#include <iostream>
using namespace std;

bool isPalindrome(int a)
{
    int original = a;
    int digit = 0;
    int reverse = 0;

    while (a > 0)
    {
        digit = a % 10;
        reverse = reverse * 10 + digit;
        a /= 10;
    }

    return reverse == original;
}

int main()
{
    bool res = isPalindrome(121);

    cout << (res ? "Yes it's a palindrome\n"
                 : "No it's not a palindrome\n");

    return 0;
}