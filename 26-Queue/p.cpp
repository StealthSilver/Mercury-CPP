// MODULE 26 — Problem 4: LRU cache (hash map + list)

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int, int>> order;  // front = LRU, back = MRU
    unordered_map<int, list<pair<int, int>>::iterator> pos;

    void touch(list<pair<int, int>>::iterator it) {
        order.splice(order.end(), order, it);
    }

public:
    explicit LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) {
            return -1;
        }
        touch(it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            touch(it->second);
            return;
        }
        order.push_back({key, value});
        pos[key] = prev(order.end());
        if (static_cast<int>(order.size()) > cap) {
            int lruKey = order.front().first;
            order.pop_front();
            pos.erase(lruKey);
        }
    }
};

int main() {
    cout << "LRU cache\n\n";

    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1): " << cache.get(1) << "  (expected 1)\n";

    cache.put(3, 3);  // evicts key 2
    cout << "get(2): " << cache.get(2) << "  (expected -1)\n";

    cache.put(4, 4);  // evicts key 1
    cout << "get(1): " << cache.get(1) << "  (expected -1)\n";
    cout << "get(3): " << cache.get(3) << "  (expected 3)\n";
    cout << "get(4): " << cache.get(4) << "  (expected 4)\n";

    return 0;
}
