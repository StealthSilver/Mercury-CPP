// MODULE 31 — Hash table: insert, search, remove (unordered_map)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    cout << "Module 31 — Hash table (a.cpp)\n";
    cout << "==============================\n\n";

    cout << "unordered_map = hash table of (key, value) pairs\n";
    cout << "Keys are unordered; avg insert/search/remove = O(1)\n\n";

    unordered_map<string, int> marks;

    // --- Insert (O(1) average) ---
    cout << "1. INSERT\n";
    marks["Anita"] = 95;
    marks["Ravi"] = 88;
    marks.insert({"Kiran", 76});
    marks["Anita"] = 97;  // update existing key
    cout << "   Anita=97, Ravi=88, Kiran=76\n\n";

    // --- Search (O(1) average) ---
    cout << "2. SEARCH\n";
    string key = "Ravi";
    if (marks.count(key)) {
        cout << "   count(\"" << key << "\") = 1  →  marks[\"" << key << "\"] = " << marks[key] << "\n";
    }

    auto it = marks.find("Meera");
    if (it == marks.end()) {
        cout << "   find(\"Meera\") → not found\n";
    }

    cout << "\n   All pairs (unordered iteration):\n";
    for (const auto& p : marks) {
        cout << "     " << p.first << " → " << p.second << "\n";
    }
    cout << "\n";

    // --- Remove (O(1) average) ---
    cout << "3. REMOVE\n";
    marks.erase("Kiran");
    cout << "   erase(\"Kiran\")  →  size = " << marks.size() << "\n";
    cout << "   count(\"Kiran\") = " << marks.count("Kiran") << "\n\n";

    cout << "Use hash table when you need fast lookup by key in unordered data.\n";
    cout << "Time: insert/search/remove O(1) avg   Space: O(n)\n";

    return 0;
}
