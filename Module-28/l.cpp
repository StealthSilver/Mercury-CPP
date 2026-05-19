// MODULE 28 — C++ map (STL): insert, access, count, loop, frequency

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printMap(const map<int, int>& m, const char* label) {
    cout << label << " (sorted by key):\n";
    for (auto p : m) {
        cout << "  " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
}

int main() {
    cout << "C++ map (STL)\n";
    cout << "=============\n\n";

  // --- create ---
    map<int, int> m;
    cout << "1. Create: map<int,int> m;\n";
    cout << "   size=" << m.size() << ", empty=" << (m.empty() ? "true" : "false") << "\n\n";

  // --- insert / update ---
    cout << "2. Insert / update with m[key] = val:\n";
    m[10] = 100;
    m[20] = 200;
    m[30] = 300;
    cout << "   m[10]=100, m[20]=200, m[30]=300\n";
    m[10] = 999;
    cout << "   m[10]=999  (updates existing key)\n";
    printMap(m, "   map");

  // --- access ---
    cout << "3. Access:\n";
    cout << "   m[20] = " << m[20] << "\n";
    cout << "   m.at(30) = " << m.at(30) << "\n\n";

  // --- count (key present?) ---
    cout << "4. m.count(key) — 1 if present, 0 if not:\n";
    cout << "   m.count(10) = " << m.count(10) << "\n";
    cout << "   m.count(99) = " << m.count(99) << "\n\n";

  // --- safe read (do not use [] if key might be missing) ---
    cout << "5. Safe check before read:\n";
    int key = 99;
    if (m.count(key)) {
        cout << "   key " << key << " has value " << m[key] << "\n";
    } else {
        cout << "   key " << key << " not in map\n";
    }
    cout << "\n";

  // --- insert() vs operator[] ---
    cout << "6. m.insert({key,val}) — only if key not present:\n";
    auto res = m.insert({40, 400});
    cout << "   insert(40,400): " << (res.second ? "inserted" : "failed") << "\n";
    res = m.insert({40, 1});
    cout << "   insert(40,1) again: " << (res.second ? "inserted" : "failed (40 exists)") << "\n";
    cout << "   m[40] still = " << m[40] << "\n\n";

  // --- loop (sorted keys) ---
    cout << "7. Loop — keys print in SORTED order:\n";
    for (auto p : m) {
        cout << "   " << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";

  // --- erase ---
    cout << "8. Erase key 20:\n";
    m.erase(20);
    printMap(m, "   map");

  // --- frequency count example ---
    cout << "9. Frequency count (common DSA use):\n";
    vector<int> arr = {1, 2, 1, 3, 2, 1};
    map<int, int> freq;
  cout << "   arr: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : arr) {
        freq[x]++;
    }
    cout << "   freq[x]++ gives:\n";
    for (auto p : freq) {
        cout << "   " << p.first << " appears " << p.second << " times\n";
    }
    cout << "\n";

    cout << "Complexity: insert/count/find/erase — O(log n) per op\n";
    cout << "Space: O(n) for n keys\n";

    return 0;
}
