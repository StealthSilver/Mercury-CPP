// MODULE 31 — unordered_map (STL hash table: key → value)

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    cout << "Module 31 — unordered_map (g.cpp)\n";
    cout << "=================================\n\n";

    unordered_map<string, int> freq;

    cout << "1. INSERT / UPDATE (key → value)\n";
    vector<pair<string, int>> words = {{"apple", 1}, {"banana", 1}, {"apple", 1}};
    for (const auto& w : words) {
        freq[w.first]++;
        cout << "   ++freq[\"" << w.first << "\"]  →  " << freq[w.first] << "\n";
    }
    cout << "\n";

    cout << "2. SEARCH\n";
    cout << "   freq[\"apple\"] = " << freq["apple"] << "\n";
    cout << "   count(\"grape\") = " << freq.count("grape") << "\n\n";

    cout << "3. ITERATION (order NOT sorted by key)\n";
    for (const auto& p : freq) {
        cout << "   \"" << p.first << "\" → " << p.second << "\n";
    }
    cout << "\n";

    cout << "4. map vs unordered_map (same inserts, different order)\n";
    map<string, int> ordered;
    for (const auto& p : freq) {
        ordered[p.first] = p.second;
    }
    cout << "   map (sorted keys): ";
    for (const auto& p : ordered) {
        cout << p.first << " ";
    }
    cout << "\n   unordered_map:     ";
    for (const auto& p : freq) {
        cout << p.first << " ";
    }
    cout << "\n\n";

    cout << "unordered_map: hash table, O(1) avg, keys NOT sorted\n";
    return 0;
}
