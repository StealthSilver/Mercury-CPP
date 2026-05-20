// MODULE 28 — Problem 2: Invert binary tree (LeetCode 226)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void printPreorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void invertTree(Node* root) {
    if (!root) {
        return;
    }
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
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
    cout << "Problem 2: Invert binary tree\n";
    cout << "=============================\n\n";

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Before:\n";
    cout << "    1\n   / \\\n  2   3\n / \\\n4   5\n\n";

    cout << "Preorder before: ";
    printPreorder(root);
    cout << "\n";

    invertTree(root);

    cout << "\nAfter invert (mirror):\n";
    cout << "    1\n   / \\\n  3   2\n     / \\\n    5   4\n\n";

    cout << "Preorder after: ";
    printPreorder(root);
    cout << "\n\nTime: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
