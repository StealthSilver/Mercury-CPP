// MODULE 32 — Longest word where every prefix is also in the dictionary (Trie + DFS)

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

    void dfs(TrieNode* node, string& path, string& best, bool atRoot) {
        if (!atRoot && !node->isEnd) {
            return;
        }

        if (node->isEnd && !path.empty()) {
            if (path.size() > best.size() || (path.size() == best.size() && path < best)) {
                best = path;
            }
        }

        for (int i = 0; i < ALPHABET; i++) {
            if (!node->children[i]) continue;
            path.push_back(static_cast<char>('a' + i));
            dfs(node->children[i], path, best, false);
            path.pop_back();
        }
    }

    string longestWordAllPrefixesInDict() {
        string path;
        string best;
        dfs(root, path, best, true);
        return best;
    }
};

int main() {
    cout << "Module 32 — Longest word, all prefixes in dict (h.cpp)\n";
    cout << "======================================================\n\n";

    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << "Dictionary: ";
    for (const string& w : dict) cout << w << " ";
    cout << "\n\n";

    Trie trie;
    for (const string& w : dict) {
        trie.insert(w);
    }

    string ans = trie.longestWordAllPrefixesInDict();
    cout << "Answer: \"" << ans << "\"\n\n";

    cout << "DFS: from root try any first letter; deeper steps only from isEnd nodes\n";
    cout << "(each prefix must be a dictionary word). Tie: longest, then lex smallest.\n";
    cout << "Time: O(N) trie nodes visited   Space: O(trie + recursion depth)\n";

    return 0;
}
