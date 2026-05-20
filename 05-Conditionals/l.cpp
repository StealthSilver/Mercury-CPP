#include <iostream>
using namespace std;

int main()
{

    int num1, num2;
    char op;
    cout << "Enter the first number : " << endl;
    cin >> num1;

    cout << "Enter the second number : " << endl;
    cin >> num2;

    cout << "Enter the operation you need to perform : \n addition -> + \n subtraction -> - \n multiplication -> * \n division -> / \n"
         << endl;

    cin >> op;

    switch (op)
    {
    case '+':
        cout << "num 1 + num 2 = " << (num1 + num2) << endl;
        break;
    case '-':
        cout << "num 1 - num 2 = " << (num1 - num2) << endl;
        break;
    case '*':
        cout << "num 1 * num 2 = " << (num1 * num2) << endl;
        break;
    case '/':
        cout << "num 1 / num 2 = " << (num1 / num2) << endl;
        break;
    default:
        cout << "Invalid Operator" << endl;
    }
    return 0;
}