// MODULE 32 — Trie::startsWith(prefix) — walk trie; no isEnd required

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

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }

    bool search(const string& word) const {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }
};

int main() {
    cout << "Module 32 — startsWith (f.cpp)\n";
    cout << "==============================\n\n";

    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    Trie trie;
    for (const string& w : words) {
        trie.insert(w);
    }

    cout << "Words inserted: ";
    for (const string& w : words) cout << w << " ";
    cout << "\n\n";

    vector<string> prefixes = {"app", "appl", "man", "wo", "woman", "wom", "ban"};
    for (const string& p : prefixes) {
        cout << "startsWith(\"" << p << "\") = " << (trie.startsWith(p) ? "true" : "false");
        cout << "    search(\"" << p << "\") = " << (trie.search(p) ? "true" : "false") << "\n";
    }
    cout << "\n";

    cout << "startsWith: path exists for every char of prefix (isEnd not required).\n";
    cout << "search: path exists AND last node has isEnd (full dictionary word).\n";
    cout << "Time: O(L) for both   L = prefix or word length\n";

    return 0;
}
