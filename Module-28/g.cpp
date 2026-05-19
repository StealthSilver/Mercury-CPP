// MODULE 28 — Count nodes in binary tree

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

int idx = 0;

Node* buildFromPreorder(const vector<int>& arr) {
    if (idx >= static_cast<int>(arr.size()) || arr[idx] == -1) {
        ++idx;
        return nullptr;
    }
    Node* root = new Node(arr[idx++]);
    root->left = buildFromPreorder(arr);
    root->right = buildFromPreorder(arr);
    return root;
}

int countNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countVerbose(Node* root) {
    if (!root) {
        return 0;
    }
    int leftC = countVerbose(root->left);
    int rightC = countVerbose(root->right);
    int total = 1 + leftC + rightC;
    cout << "  node " << root->data << ": 1 + count(left)=" << leftC
         << " + count(right)=" << rightC << " = " << total << "\n";
    return total;
}

void freeTree(Node* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    cout << "Count nodes in binary tree\n";
    cout << "==========================\n\n";
    cout << "Rule: count = 1 + count(left) + count(right)\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Combine from leaves upward:\n";
    int n = countVerbose(root);
    cout << "\nTotal nodes: " << n << "  (expected 6)\n";
    cout << "Nodes: 1, 2, 3, 4, 5, 6\n\n";
    cout << "Time: O(n)   Space: O(h) recursion stack\n";

    freeTree(root);
    return 0;
}
