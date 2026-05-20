// MODULE 31 — Build hash table: array of linked lists (chains)

#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class HashTable {
protected:
    int M;
    int count = 0;
    vector<list<pair<int, string>>> buckets;

    int hash(int key) const { return key % M; }

public:
    explicit HashTable(int tableSize) : M(tableSize), buckets(tableSize) {}

    int size() const { return count; }
    int bucketCount() const { return M; }

    void demoPush(int key, const string& value) {
        buckets[hash(key)].push_back({key, value});
        ++count;
    }

    void print() const {
        cout << "  Array of " << M << " buckets (each bucket = a linked list):\n\n";
        for (int i = 0; i < M; ++i) {
            cout << "  buckets[" << i << "] → ";
            if (buckets[i].empty()) {
                cout << "empty\n";
            } else {
                bool first = true;
                for (const auto& p : buckets[i]) {
                    if (!first) {
                        cout << " → ";
                    }
                    cout << "(" << p.first << ",\"" << p.second << "\")";
                    first = false;
                }
                cout << " → null\n";
            }
        }
    }
};

int main() {
    cout << "Module 31 — Build hash table (c.cpp)\n";
    cout << "====================================\n\n";

    cout << "Structure:\n";
    cout << "  • Array buckets[0 .. M-1]\n";
    cout << "  • buckets[i] = linked list of (key, value)\n";
    cout << "  • hash(key) = key % M  →  picks which list\n\n";

    HashTable ht(5);
    cout << "Empty table, M = 5:\n";
    ht.print();

    cout << "\nAfter one insert (12, \"Hi\"):\n";
    cout << "  12 % 5 = 2  →  buckets[2] gets (12,\"Hi\")\n\n";

    ht.demoPush(12, "Hi");
    ht.print();

    cout << "\nThis is how chaining is built: array + LL per slot.\n";
    cout << "See d.cpp (insert), e.cpp (rehash), f.cpp (search).\n";

    return 0;
}
