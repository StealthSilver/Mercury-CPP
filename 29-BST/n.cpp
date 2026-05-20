// MODULE 29 — Merge two BSTs (LeetCode 220 style)

#include <iostream>
#include <vector>
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
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root, vector<int>& out) {
    if (!root) {
        return;
    }
    inorder(root->left, out);
    out.push_back(root->data);
    inorder(root->right, out);
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

vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> merged;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        merged.push_back(a[i++]);
    }
    while (j < b.size()) {
        merged.push_back(b[j++]);
    }
    return merged;
}

void printInorder(Node* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
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
    cout << "Merge two BSTs\n";
    cout << "==============\n\n";

    Node* bst1 = nullptr;
    for (int x : {2, 1, 3}) {
        bst1 = insert(bst1, x);
    }

    Node* bst2 = nullptr;
    for (int x : {7, 5, 9}) {
        bst2 = insert(bst2, x);
    }

    cout << "BST1 inorder: ";
    vector<int> v1, v2;
    inorder(bst1, v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << "\nBST2 inorder: ";
    inorder(bst2, v2);
    for (int x : v2) {
        cout << x << " ";
    }
    cout << "\n\n";

    vector<int> merged = mergeSorted(v1, v2);
    cout << "Merged sorted: ";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << "\n\nBuild balanced BST from merged array:\n";

    Node* mergedTree = buildBalanced(merged, 0, static_cast<int>(merged.size()) - 1);

    cout << "        5\n      /   \\\n     2     7\n    / \\     \\\n   1   3     9\n\n";

    cout << "Merged tree inorder: ";
    printInorder(mergedTree);
    cout << "\n\nTime: O(m+n)   Space: O(m+n)\n";

    freeTree(bst1);
    freeTree(bst2);
    freeTree(mergedTree);
    return 0;
}
