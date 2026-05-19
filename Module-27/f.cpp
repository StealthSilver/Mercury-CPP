// MODULE 27 — Maximum length chain of pairs (greedy by second element)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxPairChain(vector<pair<int, int>> pairs) {
    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             if (a.second != b.second) {
                 return a.second < b.second;
             }
             return a.first < b.first;
         });

    if (pairs.empty()) {
        return 0;
    }

    int count = 1;
    int end = pairs[0].second;

    for (size_t i = 1; i < pairs.size(); ++i) {
        if (pairs[i].first > end) {
            count++;
            end = pairs[i].second;
        }
    }
    return count;
}

int main() {
    vector<pair<int, int>> pairs = {{1, 2}, {7, 8}, {4, 5}};

    int len = maxPairChain(pairs);

    cout << "Max length chain of pairs\n\n";
    cout << "pairs (a,b) — chain if b_prev < a_next:\n";
    for (auto& p : pairs) {
        cout << "  (" << p.first << ", " << p.second << ")\n";
    }
    cout << "\nlongest chain length: " << len << "  (expected 3)\n";
    cout << "one chain: (1,2) -> (4,5) -> (7,8)\n";

    return 0;
}
