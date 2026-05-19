// MODULE 31 — Insert into hash table (chaining)

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class HashTable {
    int M;
    int count = 0;
    vector<list<pair<int, string>>> buckets;

    int hash(int key) const { return key % M; }

public:
    explicit HashTable(int tableSize) : M(tableSize), buckets(tableSize) {}

    void insert(int key, const string& value) {
        int idx = hash(key);
        cout << "  insert(" << key << ", \"" << value << "\")\n";
        cout << "    hash(" << key << ") = " << key << " % " << M << " = " << idx << "\n";

        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                cout << "    key exists → update value \"" << p.second << "\" to \"" << value
                     << "\"\n";
                p.second = value;
                return;
            }
        }

        buckets[idx].push_back({key, value});
        ++count;
        cout << "    new key → push_back on bucket " << idx << " (chain length "
             << buckets[idx].size() << ")\n";
    }

    void print() const {
        for (int i = 0; i < M; ++i) {
            cout << "  [" << i << "] ";
            if (buckets[i].empty()) {
                cout << "empty\n";
            } else {
                for (const auto& p : buckets[i]) {
                    cout << "(" << p.first << ",\"" << p.second << "\") ";
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    cout << "Module 31 — Insert in hash table (d.cpp)\n";
    cout << "========================================\n\n";

    HashTable ht(10);

    cout << "Case 1 — empty bucket:\n";
    ht.insert(7, "C");
    cout << "\n";

    cout << "Case 2 — collision (same bucket as 13):\n";
    ht.insert(13, "A");
    ht.insert(23, "B");
    cout << "\n";

    cout << "Case 3 — update duplicate key:\n";
    ht.insert(13, "A-updated");
    cout << "\n";

    cout << "Final table:\n";
    ht.print();

    cout << "\nAvg insert: O(1)   Worst: O(n) if chain is long\n";
    return 0;
}
