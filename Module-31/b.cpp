// MODULE 31 — Collisions in hash table (chaining demo)

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Simple hash table: array of chains (lists of key-value pairs)
class ChainedHashTable {
    int M;
    vector<list<pair<int, string>>> buckets;

    int hash(int key) const { return key % M; }

public:
    explicit ChainedHashTable(int tableSize) : M(tableSize), buckets(tableSize) {}

    void insert(int key, const string& value) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    bool search(int key, string& out) const {
        int idx = hash(key);
        for (const auto& p : buckets[idx]) {
            if (p.first == key) {
                out = p.second;
                return true;
            }
        }
        return false;
    }

    void printTable() const {
        for (int i = 0; i < M; ++i) {
            cout << "  bucket " << i << ": ";
            if (buckets[i].empty()) {
                cout << "(empty)\n";
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
    cout << "Module 31 — Collisions (b.cpp)\n";
    cout << "==============================\n\n";

    cout << "hash(key) = key % M   (M = 10)\n\n";

    ChainedHashTable ht(10);

    cout << "Insert (13, \"A\")  →  13 % 10 = 3\n";
    ht.insert(13, "A");

    cout << "Insert (23, \"B\")  →  23 % 10 = 3  ← COLLISION with 13\n";
    ht.insert(23, "B");

    cout << "Insert (7, \"C\")   →  7 % 10 = 7\n";
    ht.insert(7, "C");

    cout << "\nTable after chaining:\n";
    ht.printTable();

    string val;
    cout << "\nSearch key 23: ";
    if (ht.search(23, val)) {
        cout << "found \"" << val << "\" (walk chain at bucket 3)\n";
    }

    cout << "\nCollision = same bucket; chaining stores a list per bucket.\n";
    cout << "C++ unordered_map handles this internally.\n";

    return 0;
}
