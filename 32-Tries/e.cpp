// MODULE 32 — Shortest unique prefix for each word (trie + prefix counts)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode* children[ALPHABET];
    int prefixCount;

    TrieNode() : prefixCount(0) {
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
            node->prefixCount++;
        }
    }

    string shortestUniquePrefix(const string& word) const {
        TrieNode* node = root;
        string prefix;

        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            prefix += ch;
            if (node->prefixCount == 1) {
                break;
            }
        }
        return prefix;
    }
};

int main() {
    cout << "Module 32 — Shortest Unique Prefix (e.cpp)\n";
    cout << "==========================================\n\n";

    vector<string> words = {"zebra", "dog", "duck", "dove"};

    Trie trie;
    for (const string& w : words) {
        trie.insert(w);
    }

    cout << "Words (stored lowercase in trie):\n";
    for (const string& w : words) {
        cout << "  " << w << "  ->  \"" << trie.shortestUniquePrefix(w) << "\"\n";
    }
    cout << "\n";

    cout << "prefixCount at node = how many words share this prefix.\n";
    cout << "Stop at first node where count == 1 (only this word continues here).\n\n";

    cout << "Time: O(sum of lengths) to build + O(L) per query\n";
    cout << "Space: O(trie nodes)\n";

    return 0;
}
