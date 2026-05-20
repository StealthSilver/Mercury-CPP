// MODULE 32 — Trie (prefix tree): structure and building from a word list

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

    void printFrom(TrieNode* node, string path, int depth) const {
        if (node->isEnd) {
            cout << string(depth * 2, ' ') << path << "  [END]\n";
        }
        for (int i = 0; i < ALPHABET; i++) {
            if (node->children[i]) {
                char ch = static_cast<char>('a' + i);
                printFrom(node->children[i], path + ch, depth + 1);
            }
        }
    }

    void printStructure() const {
        cout << "(root)\n";
        printFrom(root, "", 1);
    }
};

int main() {
    cout << "Module 32 — Building a Trie (a.cpp)\n";
    cout << "===================================\n\n";

    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    cout << "Words to insert:\n";
    for (const string& w : words) {
        cout << "  " << w << "\n";
    }
    cout << "\n";

    Trie trie;
    for (const string& w : words) {
        trie.insert(w);
    }

    cout << "Trie structure (paths from root, [END] = complete word):\n";
    trie.printStructure();

    cout << "\nEach level = one character. Shared prefixes share the same path.\n";
    cout << "Example: \"the\", \"there\", \"their\", \"thee\" all share t-h-e.\n";
    cout << "K-ary tree: each node has up to 26 children (a-z).\n";
    cout << "Build time: O(total characters)   Space: O(total characters)\n";

    return 0;
}
