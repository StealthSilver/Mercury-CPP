// MODULE 36 — LeetCode 269: Alien Dictionary (topology / lex order from sorted words)

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string alienOrder(const vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indeg;

    for (const string& w : words)
        for (char c : w) indeg[c] = 0;

    for (size_t i = 0; i + 1 < words.size(); i++) {
        const string& a = words[i];
        const string& b = words[i + 1];
        size_t len = min(a.size(), b.size());
        size_t j = 0;
        while (j < len && a[j] == b[j]) j++;
        if (j == len) {
            if (a.size() > b.size()) return "";  // invalid: prefix order wrong
            continue;
        }
        char u = a[j], v = b[j];
        if (!adj[u].count(v)) {
            adj[u].insert(v);
            indeg[v]++;
        }
    }

    queue<char> q;
    for (auto& [c, d] : indeg)
        if (d == 0) q.push(c);

    string ord;
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        ord.push_back(u);
        for (char v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return ord.size() == indeg.size() ? ord : "";
}

int main() {
    cout << "Module 36 — Alien Dictionary (q.cpp)\n";
    cout << "=====================================\n\n";
    vector<string> w = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Order: \"" << alienOrder(w) << "\" (one valid: wertf)\n";
    return 0;
}
