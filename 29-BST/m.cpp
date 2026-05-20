// MODULE 29 — Size of largest BST in a binary tree (LeetCode 333)

#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBST(Node* root) {
    if (!root) {
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info left = largestBST(root->left);
    Info right = largestBST(root->right);

    if (left.isBST && right.isBST && left.maxVal < root->data && right.minVal > root->data) {
        int totalSize = left.size + right.size + 1;
        cout << "  subtree at " << root->data << " is BST, size=" << totalSize << "\n";
        return {true, totalSize,
                min(left.minVal, root->data),
                max(right.maxVal, root->data)};
    }

    int best = max(left.size, right.size);
    cout << "  subtree at " << root->data << " NOT BST, best below=" << best << "\n";
    return {false, best, 0, 0};
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
    cout << "Largest BST in a binary tree\n";
    cout << "============================\n\n";

    // Tree with largest BST subtree of size 5 (nodes 4,2,5,1,3)
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(5);
    root->left->left->left->left = new Node(1);
    root->left->left->left->right = new Node(3);

    cout << "Tree (whole tree is NOT a BST; left part contains a BST):\n";
    cout << "           10\n          /  \\\n         5   15\n        / \\\n";
    cout << "       4   8\n      / \\\n     2   5\n    / \\\n   1   3\n\n";

    cout << "Post-order check:\n";
    Info ans = largestBST(root);
    cout << "\nLargest BST size: " << ans.size << "  (expected 5)\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
