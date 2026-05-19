// MODULE 28 — Diameter of tree — Approach 1: O(n^2)
// At each node, recompute height(left) and height(right)

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

int pathThrough(Node* root) {
    if (!root) {
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);
    return leftH + rightH + 2;
}

int maxDiameter = 0;

void checkEveryNode(Node* root) {
    if (!root) {
        return;
    }
    int through = pathThrough(root);
    if (through > maxDiameter) {
        maxDiameter = through;
    }
    cout << "  node " << root->data << ": height(left)=" << height(root->left)
         << ", height(right)=" << height(root->right)
         << "  =>  path through = " << through << "\n";
    checkEveryNode(root->left);
    checkEveryNode(root->right);
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

    cout << "Diameter — Approach 1 (O(n^2))\n";
    cout << "==============================\n\n";
    cout << "For EACH node: run height(left) + height(right) + 2\n";
    cout << "Each height() is O(n)  =>  total O(n^2)\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Check path through every node:\n";
    maxDiameter = 0;
    checkEveryNode(root);

    cout << "\nMaximum diameter: " << maxDiameter << " edges\n";
    cout << "Nodes on longest path: " << maxDiameter + 1 << "  (4-2-1-3-6)\n\n";
    cout << "Time: O(n^2)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
