#include <iostream>
using namespace std;

void sayHello(); // forward decleration

int main()
{
    sayHello();
    return 0;
}

void sayHello()
{
    cout << "Hello" << endl;
    ;
}