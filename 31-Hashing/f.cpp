// MODULE 31 — Search in hash table (walk chain)

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class HashTable {
    int M;
    vector<list<pair<int, string>>> buckets;

    int hash(int key) const { return key % M; }

public:
    explicit HashTable(int tableSize) : M(tableSize), buckets(tableSize) {}

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
        cout << "  search(" << key << ")\n";
        cout << "    hash → bucket " << idx << "\n";
        cout << "    walk chain: ";

        int step = 0;
        for (const auto& p : buckets[idx]) {
            cout << "(" << p.first << ",\"" << p.second << "\") ";
            ++step;
            if (p.first == key) {
                out = p.second;
                cout << "\n    match at step " << step << " → found \"" << out << "\"\n";
                return true;
            }
        }
        cout << "\n    end of chain → not found\n";
        return false;
    }
};

int main() {
    cout << "Module 31 — Search in hash table (f.cpp)\n";
    cout << "========================================\n\n";

    HashTable ht(10);
    ht.insert(13, "A");
    ht.insert(23, "B");
    ht.insert(7, "C");

    string val;

    cout << "Hit after 2 steps (collision chain):\n";
    ht.search(23, val);

    cout << "\nMiss — empty bucket:\n";
    ht.search(99, val);

    cout << "\nHit — single node in bucket:\n";
    ht.search(7, val);

    cout << "\nAvg search: O(1)   Worst: O(n)\n";
    return 0;
}
