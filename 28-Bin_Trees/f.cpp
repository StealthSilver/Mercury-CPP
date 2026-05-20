// MODULE 28 — Height of binary tree (max edges from root to leaf)

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

int height(Node* root) {
    if (!root) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

int heightVerbose(Node* root, int depth) {
    if (!root) {
        return -1;
    }
    int leftH = heightVerbose(root->left, depth + 1);
    int rightH = heightVerbose(root->right, depth + 1);
    int h = 1 + max(leftH, rightH);

    string indent(depth * 2, ' ');
    cout << indent << "node " << root->data << ": "
         << "height(left)=" << leftH << ", height(right)=" << rightH
         << "  =>  height(" << root->data << ") = 1 + max = " << h << "\n";

    return h;
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

    cout << "Height of binary tree\n";
    cout << "=====================\n\n";
    cout << "Definition: max number of EDGES from root to any leaf.\n";
    cout << "Leaf height = 0.  Empty subtree returns -1.\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Bottom-up height calculation:\n";
    int h = heightVerbose(root, 0);
    cout << "\nTree height (from root): " << h << " edges\n";
    cout << "Longest paths: 1->2->4, 1->2->5, or 1->3->6 (each has 2 edges)\n\n";
    cout << "Time: O(n)   Space: O(h) recursion stack\n";

    freeTree(root);
    return 0;
}
