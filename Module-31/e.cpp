// MODULE 31 — Rehashing when load factor exceeds threshold

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class HashTable {
    int M;
    int count = 0;
    double maxLoad;
    vector<list<pair<int, string>>> buckets;

    int hash(int key) const { return key % M; }

    void insertInternal(int key, const string& value) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    void rehash() {
        cout << "  *** REHASH: load factor " << (double)count / M << " >= " << maxLoad << " ***\n";
        cout << "  Old M = " << M << ", new M = " << (2 * M) << "\n";

        auto oldBuckets = move(buckets);
        int oldM = M;
        M *= 2;
        buckets.assign(M, {});

        count = 0;
        for (int i = 0; i < oldM; ++i) {
            for (const auto& p : oldBuckets[i]) {
                cout << "    re-insert (" << p.first << ", \"" << p.second << "\")  →  "
                     << p.first << " % " << M << " = " << (p.first % M) << "\n";
                insertInternal(p.first, p.second);
                ++count;
            }
        }
        cout << "  Rehash done. count=" << count << ", M=" << M << "\n\n";
    }

public:
    HashTable(int tableSize, double load = 0.75)
        : M(tableSize), maxLoad(load), buckets(tableSize) {}

    void insert(int key, const string& value) {
        // Rehash when load factor reaches maxLoad (e.g. 3/4 = 0.75)
        if (M > 0 && count >= static_cast<int>(M * maxLoad)) {
            rehash();
        }
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
        ++count;
        cout << "  insert(" << key << ")  α = " << count << "/" << M << " = "
             << (double)count / M << "\n";
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
    cout << "Module 31 — Rehashing (e.cpp)\n";
    cout << "=============================\n\n";

    cout << "Start M=4, rehash when count/M > 0.75\n\n";

    HashTable ht(4);

    for (int key : {5, 9, 13, 17}) {
        ht.insert(key, "v" + to_string(key));
    }

    cout << "Table after inserts (note M doubled):\n";
    ht.print();

    cout << "\nRehash cost: O(n) one-time; keeps average insert/search O(1).\n";
    return 0;
}
