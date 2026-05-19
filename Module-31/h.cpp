// MODULE 31 — unordered_set (STL hash table: unique keys only)

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    cout << "Module 31 — unordered_set (h.cpp)\n";
    cout << "==================================\n\n";

    unordered_set<int> seen;

    cout << "1. INSERT unique keys\n";
    vector<int> arr = {4, 1, 2, 1, 5, 2};
    for (int x : arr) {
        bool inserted = seen.insert(x).second;
        cout << "   insert(" << x << ")  →  " << (inserted ? "new" : "duplicate, ignored")
             << "\n";
    }
    cout << "   size = " << seen.size() << "\n\n";

    cout << "2. SEARCH (membership)\n";
    for (int q : {2, 9}) {
        cout << "   count(" << q << ") = " << seen.count(q)
             << (seen.count(q) ? "  (present)" : "  (absent)") << "\n";
    }
    cout << "\n";

    cout << "3. vs unordered_map for \"visited\"\n";
    cout << "   set:   seen.insert(nodeId)\n";
    cout << "   map:   visited[nodeId] = true  (more verbose)\n\n";

    cout << "4. set vs unordered_set (sorted vs hash)\n";
    set<int> sortedSet(seen.begin(), seen.end());
    cout << "   set (sorted):           ";
    for (int x : sortedSet) {
        cout << x << " ";
    }
    cout << "\n   unordered_set:          ";
    for (int x : seen) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "unordered_set: unique keys, hash, O(1) avg count/insert\n";
    return 0;
}
