#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;
    vec.push_back(5);                               // adding elements at the back
    cout << "size: " << vec.size() << endl;         // 5
    cout << "capacity: " << vec.capacity() << endl; // 8
    vec.pop_back();                                 // removing elements from the back
    cout << "size: " << vec.size() << endl;         // 5
    cout << "capacity: " << vec.capacity() << endl; // 8

    return 0;
}