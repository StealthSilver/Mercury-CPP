// MODULE 28 — Problem 5: Maximum path sum (LeetCode 124)

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

int maxAns = INT_MIN;

int maxGain(Node* root) {
    if (!root) {
        return 0;
    }

    int leftGain = max(0, maxGain(root->left));
    int rightGain = max(0, maxGain(root->right));
    int through = leftGain + root->data + rightGain;

    cout << "  node " << root->data << ": L=" << leftGain << ", R=" << rightGain
         << ", through=" << through << "\n";

    maxAns = max(maxAns, through);
    return root->data + max(leftGain, rightGain);
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
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    return root;
}

int main() {
    cout << "Problem 5: Maximum path sum\n";
    cout << "===========================\n\n";
    cout << "Path need not pass through root.\n\n";
    cout << "Tree:\n";
    cout << "       -10\n       /  \\\n      9   20\n         /  \\\n        15   7\n\n";

    Node* root = buildTree();
    maxAns = INT_MIN;
    cout << "Post-order gains:\n";
    maxGain(root);

    cout << "\nBest path: 15 -> 20 -> 7  sum = " << maxAns << "\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
