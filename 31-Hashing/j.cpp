// MODULE 31 — set (STL ordered: unique sorted keys, BST)

#include <iostream>
#include <set>
using namespace std;

int main() {
    cout << "Module 31 — set (j.cpp)\n";
    cout << "=======================\n\n";

    cout << "set = sorted unique keys only (BST, O(log n))\n\n";

    set<int> s;

    cout << "1. INSERT (duplicates ignored)\n";
    for (int x : {40, 10, 30, 10, 20}) {
        bool ok = s.insert(x).second;
        cout << "   insert(" << x << ")  →  " << (ok ? "added" : "duplicate") << "\n";
    }
    cout << "\n";

    cout << "2. ITERATION — sorted order\n";
    cout << "   elements: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "3. SEARCH\n";
    cout << "   count(30) = " << s.count(30) << "\n";
    cout << "   count(99) = " << s.count(99) << "\n\n";

    cout << "4. lower_bound — first element >= 25\n";
    auto lb = s.lower_bound(25);
    if (lb != s.end()) {
        cout << "   lower_bound(25) → " << *lb << "\n";
    }
    cout << "\n";

    cout << "5. SMALLEST / LARGEST\n";
    cout << "   *begin()  = " << *s.begin() << "\n";
    cout << "   *rbegin() = " << *s.rbegin() << "\n\n";

    cout << "6. ERASE\n";
    s.erase(30);
    cout << "   after erase(30): ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "Use set when you need SORTED unique elements.\n";
    cout << "Time: insert/search/erase O(log n)   Space: O(n)\n";

    return 0;
}
