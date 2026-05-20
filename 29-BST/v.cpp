// MODULE 29 — Problem 5: Maximum sum BST subtree (LeetCode 1373)

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
    long long sum;
    long long maxSum;
    long long minVal;
    long long maxVal;
};

Info solve(Node* root) {
    if (!root) {
        return {true, 0, 0, LLONG_MAX, LLONG_MIN};
    }

    Info left = solve(root->left);
    Info right = solve(root->right);

    if (left.isBST && right.isBST && left.maxVal < root->data && right.minVal > root->data) {
        long long total = left.sum + right.sum + root->data;
        long long best = max({left.maxSum, right.maxSum, total});
        cout << "  subtree at " << root->data << " is BST, sum=" << total << "\n";
        return {true, total, best,
                min(left.minVal, static_cast<long long>(root->data)),
                max(right.maxVal, static_cast<long long>(root->data))};
    }

    long long best = max(left.maxSum, right.maxSum);
    return {false, 0, best, 0, 0};
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
    cout << "Problem 5: Maximum sum BST subtree\n";
    cout << "==================================\n\n";

    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(3);

    cout << "Tree (general binary tree, not full BST):\n";
    cout << "           1\n          / \\\n         4   3\n";
    cout << "        / \\   \\\n       4   2   5\n      / \\\n     6   3\n\n";

    Info ans = solve(root);
    cout << "\nMaximum sum BST subtree: " << ans.maxSum << "\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
