// MODULE 28 — Preorder traversal (recursive): root → left → right

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

int step = 0;

void preorder(Node* root) {
    if (!root) {
        return;
    }
    ++step;
    cout << "  Step " << step << ": visit " << root->data << "\n";
    preorder(root->left);
    preorder(root->right);
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

    cout << "Preorder traversal (recursive)\n";
    cout << "==============================\n\n";
    cout << "Order: ROOT -> LEFT subtree -> RIGHT subtree\n\n";
    cout << "Tree:\n";
    cout << "        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Visit trace:\n";
    step = 0;
    preorder(root);
    cout << "\nOutput: 1 2 4 5 3 6\n";
    cout << "Time: O(n)   Space: O(h) recursion stack\n";

    freeTree(root);
    return 0;
}
