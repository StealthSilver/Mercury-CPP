// MODULE 32 — Insert into a trie (character by character)

#include <iostream>
#include <string>
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
        cout << "Insert \"" << word << "\":\n";

        for (int i = 0; i < static_cast<int>(word.size()); i++) {
            int idx = word[i] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
                cout << "   step " << i + 1 << ": create child '" << word[i] << "'\n";
            } else {
                cout << "   step " << i + 1 << ": follow existing '" << word[i] << "'\n";
            }
            node = node->children[idx];
        }
        node->isEnd = true;
        cout << "   mark isEnd = true at end of \"" << word << "\"\n\n";
    }
};

int main() {
    cout << "Module 32 — Insert in Trie (b.cpp)\n";
    cout << "==================================\n\n";

    Trie trie;

    trie.insert("the");
    trie.insert("there");

    cout << "Insert reuses the path t-h-e from \"the\", then adds r-e.\n";
    cout << "Time per insert: O(L)   L = word length\n";

    return 0;
}
