// MODULE 29 — Convert BST to balanced BST (LeetCode 1382)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else {
        root->right = insertBST(root->right, key);
    }
    return root;
}

void inorderCollect(Node* root, vector<int>& a) {
    if (!root) {
        return;
    }
    inorderCollect(root->left, a);
    a.push_back(root->data);
    inorderCollect(root->right, a);
}

Node* buildBalanced(vector<int>& a, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int mid = l + (r - l) / 2;
    Node* root = new Node(a[mid]);
    root->left = buildBalanced(a, l, mid - 1);
    root->right = buildBalanced(a, mid + 1, r);
    return root;
}

int height(Node* root) {
    if (!root) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
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
    cout << "Convert BST to balanced BST\n";
    cout << "===========================\n\n";

    Node* skewed = nullptr;
    for (int x : {1, 2, 3, 4, 5, 6, 7}) {
        skewed = insertBST(skewed, x);
    }

    cout << "Before (skewed — sorted insert):\n    1\n     \\\n      2\n       \\\n        ...\n";
    cout << "Height: " << height(skewed) << "  (O(n) — bad)\n\n";

    vector<int> sorted;
    inorderCollect(skewed, sorted);
    cout << "Step 1: inorder -> sorted array: ";
    for (int x : sorted) {
        cout << x << " ";
    }
    cout << "\n\nStep 2: build balanced BST from array (middle as root)\n\n";

    freeTree(skewed);

    Node* balanced = buildBalanced(sorted, 0, static_cast<int>(sorted.size()) - 1);
    cout << "After (balanced):\n        4\n      /   \\\n     2     6\n    / \\   / \\\n   1  3  5   7\n\n";
    cout << "Height: " << height(balanced) << "  (O(log n))\n";
    cout << "Time: O(n)   Space: O(n) for array + O(log n) build\n";

    freeTree(balanced);
    return 0;
}
