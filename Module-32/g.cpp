// MODULE 32 — Count distinct substrings (suffix trie: each new node = new substring)

#include <iostream>
#include <string>
using namespace std;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode* children[ALPHABET];

    TrieNode() {
        for (int i = 0; i < ALPHABET; i++) {
            children[i] = nullptr;
        }
    }
};

void freeTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET; i++) {
        freeTrie(node->children[i]);
    }
    delete node;
}

int insertSuffix(TrieNode* root, const string& suffix) {
    int newNodes = 0;
    TrieNode* node = root;
    for (char ch : suffix) {
        int idx = ch - 'a';
        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
            newNodes++;
        }
        node = node->children[idx];
    }
    return newNodes;
}

int countDistinctSubstrings(const string& s) {
    TrieNode* root = new TrieNode();
    int total = 0;

    for (size_t i = 0; i < s.size(); i++) {
        total += insertSuffix(root, s.substr(i));
    }

    freeTrie(root);
    return total;
}

int main() {
    cout << "Module 32 — Count Unique Substrings (g.cpp)\n";
    cout << "===========================================\n\n";

    string str = "ababa";
    int ans = countDistinctSubstrings(str);

    cout << "str = \"" << str << "\"\n";
    cout << "Distinct substrings count = " << ans << "\n\n";

    cout << "Listed: a, ab, aba, abab, ababa, b, ba, bab, baba  (9 distinct).\n";
    cout << "Some references incorrectly state 10 for \"ababa\"; trie count above is exact.\n\n";

    cout << "Logic: insert every suffix s[i..n-1] into one trie.\n";
    cout << "Each NEW node created = one new distinct substring (path from root).\n";
    cout << "Time: O(n^2) character steps   Space: O(n^2) nodes worst case\n";

    return 0;
}
