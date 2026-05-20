// MODULE 29 — Sorted array to balanced BST (LeetCode 108)

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

Node* buildBalanced(vector<int>& a, int left, int right, int depth) {
    if (left > right) {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    string indent(depth * 2, ' ');
    cout << indent << "range [" << left << ".." << right << "] mid=" << mid
         << " value=" << a[mid] << " -> root\n";

    Node* root = new Node(a[mid]);
    root->left = buildBalanced(a, left, mid - 1, depth + 1);
    root->right = buildBalanced(a, mid + 1, right, depth + 1);
    return root;
}

int height(Node* root) {
    if (!root) {
        return -1;
    }
    return 1 + max(height(root->left), height(root->right));
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << "Sorted array to balanced BST\n";
    cout << "============================\n\n";
    cout << "Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\nPick MIDDLE element as root so left/right halves are balanced.\n\n";

    Node* root = buildBalanced(arr, 0, static_cast<int>(arr.size()) - 1, 0);

    cout << "\nResulting BST (balanced):\n";
    cout << "        4\n      /   \\\n     2     6\n    / \\   / \\\n   1  3  5   7\n\n";

    cout << "Inorder: ";
    inorder(root);
    cout << "\nHeight: " << height(root) << "  (≈ log2(n) for n=7)\n";
    cout << "Time: O(n)   Space: O(log n) recursion\n";

    freeTree(root);
    return 0;
}
