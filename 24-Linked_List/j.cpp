// Module 24 — Iterators on std::list
// Iterators = safe, uniform way to walk a container (like temp = head in a.cpp)

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void printWithIterator(const list<int>& lst, const string& label) {
    cout << label << ": ";
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " <-> ";
    }
    cout << "END" << endl;
}

int main() {
    list<int> lst = {10, 20, 30, 40};

    // begin() → first element; end() → one past the last (sentinel, not dereferenced)
    list<int>::iterator it = lst.begin();
    cout << "First element: " << *it << endl;

    ++it;
    cout << "Second element: " << *it << endl;

    // Classic loop — same pattern as walking a linked list with temp
    cout << "Forward traversal: ";
    for (it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Insert before the position pointed to by iterator (here before 30)
    it = lst.begin();
    ++it;
    ++it;  // points to 30
    lst.insert(it, 25);
    printWithIterator(lst, "After insert(25) before 30");

    // Erase at iterator
    it = lst.begin();
    ++it;  // points to 20
    it = lst.erase(it);
    printWithIterator(lst, "After erase(20)");
    cout << "Iterator now at: " << *it << endl;  // erase returns next valid iterator

    // std::distance — number of steps from begin to it (O(n) for list)
    cout << "distance(begin, it) = " << distance(lst.begin(), it) << endl;

    return 0;
}
