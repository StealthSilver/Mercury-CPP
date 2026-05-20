#include <iostream>
using namespace std;

int main()
{
    // Pointer created in stack (inside main)
    int *ptr;

    // Dynamically allocating memory in heap
    ptr = new int; // memory allocated at runtime in heap

    // Assigning value to allocated memory
    *ptr = 42;

    cout << "Value stored in heap: " << *ptr << endl;
    cout << "Address of heap memory (ptr): " << ptr << endl;
    cout << "Address of pointer itself (in stack): " << &ptr << endl;

    // Freeing allocated heap memory (important!)
    delete ptr;

    return 0;
}