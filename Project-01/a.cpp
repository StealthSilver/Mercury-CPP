#include <iostream>
#include <cmath>
using namespace std;

void addition(double num1, double num2)
{
    cout << "result is : " << num1 + num2 << endl;
}

void subtraction(double num1, double num2)
{
    cout << "result is : " << num1 - num2 << endl;
}

void multiplication(double num1, double num2)
{
    cout << "result is : " << num1 * num2 << endl;
}

void division(double num1, double num2)
{
    if (num2 == 0)
        cout << "Error: Division by zero!" << endl;
    else
        cout << "result is : " << num1 / num2 << endl;
}

void modulous(double num1, double num2)
{
    if (int(num2) == 0)
    {
        cout << "Error: Modulus by zero!" << endl;
        return;
    }
    cout << "result is : " << int(num1) % int(num2) << endl;
}

void exponentiation(double num1, double num2)
{
    cout << "result is : " << pow(num1, num2) << endl;
}

void logarithm(double num1, double num2)
{
    if (num1 <= 0 || num2 <= 0 || num2 == 1)
        cout << "Invalid input for logarithm" << endl;
    else
        cout << "result is : " << log(num1) / log(num2) << endl;
}

void sine(double num)
{
    cout << "result is : " << sin(num) << endl;
}

void cosine(double num)
{
    cout << "result is : " << cos(num) << endl;
}

void tangent(double num)
{
    cout << "result is : " << tan(num) << endl;
}

void sqroot(double num)
{
    if (num < 0)
        cout << "Invalid input for square root" << endl;
    else
        cout << "result is : " << sqrt(num) << endl;
}

int factorial(int num)
{
    if (num < 0)
        return -1;
    if (num == 0 || num == 1)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    double num1, num2, num;
    char opn;
    cout << "THIS IS A SCIENTIFIC CALCULATOR" << endl;
    cout << "enter the operation you want to perform" << endl;
    cout << "'+' -> addition" << endl;
    cout << "'-' -> subtraction" << endl;
    cout << "'*' -> multiplication" << endl;
    cout << "'/' -> division" << endl;
    cout << "'%' -> modulus" << endl;
    cout << "'^' -> exponentiation" << endl;
    cout << "'l' -> logarithm" << endl;
    cout << "'s' -> sine" << endl;
    cout << "'c' -> cosine" << endl;
    cout << "'t' -> tangent" << endl;
    cout << "'#' -> sqrt" << endl;
    cout << "'!' -> factorial" << endl;
    cin >> opn;

    switch (opn)
    {
    case '+':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        addition(num1, num2);
        break;
    case '-':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        subtraction(num1, num2);
        break;
    case '*':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        multiplication(num1, num2);
        break;
    case '/':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        division(num1, num2);
        break;
    case '%':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        modulous(num1, num2);
        break;
    case '^':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        exponentiation(num1, num2);
        break;
    case 'l':
        cout << "Enter the first number : " << endl;
        cin >> num1;
        cout << "Enter the second number : " << endl;
        cin >> num2;
        logarithm(num1, num2);
        break;
    case 's':
        cout << "enter the number you want to find the sine of : ";
        cin >> num;
        num = num * M_PI / 180;
        sine(num);
        break;
    case 'c':
        cout << "enter the number you want to find the cosine of : ";
        cin >> num;
        num = num * M_PI / 180;
        cosine(num);
        break;
    case 't':
        cout << "enter the number you want to find the tangent of : ";
        cin >> num;
        num = num * M_PI / 180;
        tangent(num);
        break;
    case '#':
        cout << "enter the number you want to find the sqrt of : ";
        cin >> num;
        sqroot(num);
        break;
    case '!':
    {
        cout << "enter the number you want to find the factorial of : ";
        cin >> num;
        int n = int(num);
        int result = factorial(n);
        if (result == -1)
            cout << "Invalid input for factorial" << endl;
        else
            cout << "result is : " << result << endl;
        break;
    }
    default:
        cout << "Invalid Operation" << endl;
    }

    return 0;
}