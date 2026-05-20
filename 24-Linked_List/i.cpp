// Module 24 — std::list (doubly linked list in the C++ STL)
// Illustrates push/pop, size, front, back — same ideas as custom List in a.cpp

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& lst, const string& label) {
    cout << label << " (size=" << lst.size() << "): ";
    for (int x : lst) {
        cout << x << " <-> ";
    }
    cout << "END" << endl;
}

int main() {
    list<int> lst;

    // push_front / push_back — O(1) at both ends (doubly linked inside)
    lst.push_back(30);
    lst.push_back(40);
    lst.push_front(20);
    lst.push_front(10);
    printList(lst, "After pushes");

    // front() / back() — read first and last (no pop)
    cout << "front() = " << lst.front() << endl;
    cout << "back()  = " << lst.back() << endl;

    // pop_front / pop_back — remove first / last
    lst.pop_front();
    lst.pop_back();
    printList(lst, "After pop_front & pop_back");

    // size() — number of elements
    cout << "size() = " << lst.size() << endl;

    return 0;
}
