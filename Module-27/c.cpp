// MODULE 27 — std::pair illustration

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    cout << "=== std::pair in C++ ===\n\n";

    // 1. Create pairs
    pair<int, int> p1(3, 7);
    pair<int, int> p2 = make_pair(10, 20);
    pair<string, int> p3 = {"Alice", 21};

    cout << "1. create:\n";
    cout << "   p1 = (" << p1.first << ", " << p1.second << ")\n";
    cout << "   p2 = (" << p2.first << ", " << p2.second << ")\n";
    cout << "   p3 = (" << p3.first << ", " << p3.second << ")\n\n";

    // 2. Modify members
    p1.first = 100;
    cout << "2. after p1.first = 100: (" << p1.first << ", " << p1.second << ")\n\n";

    // 3. Structured bindings (C++17)
    auto [start, end] = p2;
    cout << "3. structured binding: start=" << start << " end=" << end << "\n\n";

    // 4. vector of pairs — activity intervals
    vector<pair<int, int>> acts = {{10, 20}, {12, 25}, {20, 30}};

    sort(acts.begin(), acts.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;  // sort by end time
         });

    cout << "4. intervals sorted by end (start, end):\n";
    for (const auto& p : acts) {
        cout << "   (" << p.first << ", " << p.second << ")\n";
    }

    // 5. Greedy count using pairs (same logic as b.cpp)
    int count = 1;
    int currEnd = acts[0].second;
    for (size_t i = 1; i < acts.size(); ++i) {
        if (acts[i].first >= currEnd) {
            count++;
            currEnd = acts[i].second;
        }
    }
    cout << "\n5. max activities from pairs: " << count << "  (expected 2)\n";

    // 6. Comparison
    pair<int, int> a = {1, 5};
    pair<int, int> b = {2, 0};
    cout << "\n6. {1,5} < {2,0}? " << (a < b ? "true" : "false") << "\n";

    return 0;
}
