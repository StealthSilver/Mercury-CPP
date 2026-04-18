// b.cpp
#include <iostream>
using namespace std;

// Function that allocates and uses heap memory
void func()
{
    int *ptr = new int; // allocated in heap
    *ptr = 100;

    cout << "Value inside heap (func): " << *ptr << endl;
    cout << "Heap address: " << ptr << endl;
    cout << "Pointer address (stack): " << &ptr << endl;

    delete ptr; // freeing heap memory (VERY IMPORTANT)
}

int main()
{
    func();
    return 0;
}