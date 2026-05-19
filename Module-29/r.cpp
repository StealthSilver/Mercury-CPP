// MODULE 29 — Problem 1: Range sum of BST (LeetCode 938)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

int rangeSum(Node* root, int low, int high) {
    if (!root) {
        return 0;
    }
    if (root->data < low) {
        return rangeSum(root->right, low, high);
    }
    if (root->data > high) {
        return rangeSum(root->left, low, high);
    }
    return root->data + rangeSum(root->left, low, high) + rangeSum(root->right, low, high);
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
    cout << "Problem 1: Range sum of BST\n";
    cout << "============================\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14, 7, 13}) {
        root = insert(root, x);
    }

    cout << "BST inorder: 1 3 6 7 8 10 13 14\n\n";

    int low = 6, high = 10;
    int sum = rangeSum(root, low, high);
    cout << "Sum in [" << low << ", " << high << "] = " << sum << "\n";
    cout << "Nodes: 6 + 7 + 8 + 10 = 31\n\n";
    cout << "Time: O(h + k)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
