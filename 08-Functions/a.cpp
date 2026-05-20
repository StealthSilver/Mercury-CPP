#include <iostream>
using namespace std;

void sayHello()
{
    cout << "Hello" << endl;
}

void sayBye()
{
    cout << "Bye" << endl;
}

int main()
{
    sayHello(); // function call
    sayHello();
    sayBye();
    return 0;
}