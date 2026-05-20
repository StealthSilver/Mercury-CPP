// MODULE 32 — Search in a trie (prefix walk + isEnd check)

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

    bool search(const string& key) const {
        TrieNode* node = root;
        cout << "Search \"" << key << "\":\n";

        for (int i = 0; i < static_cast<int>(key.size()); i++) {
            int idx = key[i] - 'a';
            if (!node->children[idx]) {
                cout << "   step " << i + 1 << ": '" << key[i]
                     << "' missing  ->  NOT FOUND\n";
                return false;
            }
            cout << "   step " << i + 1 << ": follow '" << key[i] << "'\n";
            node = node->children[idx];
        }

        if (node->isEnd) {
            cout << "   isEnd = true  ->  FOUND\n";
            return true;
        }
        cout << "   path exists but isEnd = false  ->  NOT A FULL WORD\n";
        return false;
    }

    bool startsWith(const string& prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    cout << "Module 32 — Search in Trie (c.cpp)\n";
    cout << "==================================\n\n";

    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;
    for (const string& w : words) {
        trie.insert(w);
    }

    trie.search("there");
    cout << "\n";
    trie.search("the");
    cout << "\n";
    trie.search("tha");
    cout << "\n";
    trie.search("apple");
    cout << "\n";

    cout << "startsWith(\"the\") = " << (trie.startsWith("the") ? "true" : "false") << "\n";
    cout << "startsWith(\"tha\")  = " << (trie.startsWith("tha") ? "true" : "false") << "\n\n";

    cout << "Search time: O(L)   L = key length (not number of words)\n";
    return 0;
}
