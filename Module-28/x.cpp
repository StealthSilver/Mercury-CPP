// MODULE 28 — Problem 4: Duplicate subtrees (LeetCode 652)

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

vector<Node*> duplicates;

string serialize(Node* root) {
    if (!root) {
        return "#";
    }
    string s = to_string(root->data) + "," + serialize(root->left) + "," +
               serialize(root->right);
    return s;
}

string dfs(Node* root, map<string, int>& freq) {
    if (!root) {
        return "#";
    }
    string left = dfs(root->left, freq);
    string right = dfs(root->right, freq);
    string key = to_string(root->data) + "," + left + "," + right;

    freq[key]++;
    if (freq[key] == 2) {
        duplicates.push_back(root);
        cout << "  duplicate subtree root " << root->data
             << "  key=" << key << "\n";
    }
    return key;
}

void freeTree(Node* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(2);
    root->right->right->left = new Node(4);
    return root;
}

int main() {
    cout << "Problem 4: Duplicate subtrees\n";
    cout << "===============================\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     /     \\\n    4       2\n";
    cout << "                   /\n";
    cout << "                  4\n\n";
    cout << "Two matching subtrees (2 with right child 4):\n\n";

    Node* root = buildTree();
    map<string, int> freq;
    dfs(root, freq);

    cout << "\nReturn one root per duplicate pattern: ";
    for (Node* n : duplicates) {
        cout << n->data << " ";
    }
    cout << "\n\nTime: O(n)   Space: O(n) map + strings\n";

    freeTree(root);
    return 0;
}
