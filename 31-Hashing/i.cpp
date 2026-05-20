// MODULE 31 — map (STL ordered: key → value, BST)

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << "Module 31 — map (i.cpp)\n";
    cout << "=======================\n\n";

    cout << "map = sorted key → value (balanced BST, O(log n))\n\n";

    map<string, int> marks;

    cout << "1. INSERT (keys will be stored sorted)\n";
    marks["Ravi"] = 88;
    marks["Anita"] = 95;
    marks["Kiran"] = 76;
    marks["Anita"] = 97;  // update existing key
    cout << "   Insert order: Ravi, Anita, Kiran, Anita(update)\n\n";

    cout << "2. ITERATION — always sorted by key\n";
    for (const auto& p : marks) {
        cout << "   \"" << p.first << "\" → " << p.second << "\n";
    }
    cout << "\n";

    cout << "3. SEARCH\n";
    if (marks.count("Kiran")) {
        cout << "   marks[\"Kiran\"] = " << marks["Kiran"] << "\n";
    }
    auto it = marks.find("Meera");
    if (it == marks.end()) {
        cout << "   find(\"Meera\") → not found\n";
    }
    cout << "\n";

    cout << "4. lower_bound — first key >= \"K\"\n";
    auto lb = marks.lower_bound("K");
    if (lb != marks.end()) {
        cout << "   lower_bound(\"K\") → \"" << lb->first << "\" → " << lb->second << "\n";
    }
    cout << "\n";

    cout << "5. SMALLEST / LARGEST key\n";
    cout << "   smallest: \"" << marks.begin()->first << "\"\n";
    cout << "   largest:  \"" << marks.rbegin()->first << "\"\n\n";

    cout << "6. ERASE\n";
    marks.erase("Ravi");
    cout << "   after erase(\"Ravi\"), size = " << marks.size() << "\n";

    cout << "\nUse map when you need SORTED keys or lower_bound.\n";
    cout << "Time: insert/search/erase O(log n)   Space: O(n)\n";

    return 0;
}
