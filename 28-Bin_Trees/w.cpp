// MODULE 28 — Problem 3: Delete leaf nodes with target value (LeetCode 1325)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void printInorder(Node* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node* removeLeaves(Node* root, int target) {
    if (!root) {
        return nullptr;
    }
    root->left = removeLeaves(root->left, target);
    root->right = removeLeaves(root->right, target);

    if (!root->left && !root->right && root->data == target) {
        cout << "  delete leaf " << target << "\n";
        delete root;
        return nullptr;
    }
    return root;
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
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
    return root;
}

int main() {
    cout << "Problem 3: Delete leaves with target value\n";
    cout << "==========================================\n\n";
    cout << "target = 2 — delete bottom 2s, then parents that become leaf 2s\n\n";

    cout << "Before:\n";
    cout << "        1\n       / \\\n      2   1\n     / \\   \\\n    2   2   2\n\n";

    Node* root = buildTree();
    cout << "Inorder before: ";
    printInorder(root);
    cout << "\n\nDeletion order:\n";

    root = removeLeaves(root, 2);

    cout << "\nAfter:\n";
    cout << "        1\n       / \\\n      1   1\n\n";

    cout << "Inorder after: ";
    printInorder(root);
    cout << "\n\nTime: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
