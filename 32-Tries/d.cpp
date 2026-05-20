// MODULE 32 — Word Break: can the string be segmented into dictionary words? (Trie + DP)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode* children[ALPHABET];
    bool isEnd;

    TrieNode() : isEnd(false) {
        for (int i = 0; i < ALPHABET; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool wordBreak(const string& s) const {
        int n = static_cast<int>(s.size());
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) {
                continue;
            }
            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) {
                    break;
                }
                node = node->children[idx];
                if (node->isEnd) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    cout << "Module 32 — Word Break (d.cpp)\n";
    cout << "===============================\n\n";

    vector<string> dictionary = {"i", "like", "sam", "samsung", "mobile", "ice"};
    string key = "ilikesamsung";

    Trie trie;
    for (const string& w : dictionary) {
        trie.insert(w);
    }

    cout << "Dictionary: ";
    for (const string& w : dictionary) cout << "\"" << w << "\" ";
    cout << "\nKey: \"" << key << "\"\n\n";

    bool ok = trie.wordBreak(key);
    cout << "wordBreak = " << (ok ? "true" : "false") << "\n";
    cout << "Example split: i | like | samsung\n\n";

    cout << "Logic: dp[i] = true if s[0..i-1] can be segmented.\n";
    cout << "From each i with dp[i], walk trie on s[i..] and set dp[j+1] when a word ends.\n";
    cout << "Time: O(n^2) in worst case (n = |s|), O(n * alphabet) per char in practice\n";
    cout << "Space: O(n) for dp + trie size O(sum of dict word lengths)\n";

    return 0;
}
