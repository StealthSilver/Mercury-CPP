// MODULE 29 — Inorder traversal of BST gives sorted sequence

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* buildBST() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    return root;
}

void inorder(Node* root, vector<int>& out, int& step) {
    if (!root) {
        return;
    }
    inorder(root->left, out, step);
    ++step;
    cout << "  Step " << step << ": visit " << root->data << "\n";
    out.push_back(root->data);
    inorder(root->right, out, step);
}

void preorder(Node* root, vector<int>& out) {
    if (!root) {
        return;
    }
    out.push_back(root->data);
    preorder(root->left, out);
    preorder(root->right, out);
}

void postorder(Node* root, vector<int>& out) {
    if (!root) {
        return;
    }
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->data);
}

bool isSorted(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }
    return true;
}

void printVec(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
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
    cout << "Inorder of BST = sorted sequence\n";
    cout << "=================================\n\n";
    cout << "BST (left < root < right at every node):\n\n";
    cout << "        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n       \\    /\n        7  13\n\n";

    Node* root = buildBST();

    cout << "INORDER (left -> root -> right):\n";
    vector<int> inorderVals;
    int step = 0;
    inorder(root, inorderVals, step);
    cout << "\nInorder sequence: ";
    printVec(inorderVals);
    cout << "\nIs sorted? " << (isSorted(inorderVals) ? "yes" : "no") << "\n\n";

    vector<int> pre, post;
    preorder(root, pre);
    postorder(root, post);

    cout << "PREORDER (root -> left -> right):  ";
    printVec(pre);
    cout << "\nIs sorted? " << (isSorted(pre) ? "yes" : "no") << "\n\n";

    cout << "POSTORDER (left -> right -> root): ";
    printVec(post);
    cout << "\nIs sorted? " << (isSorted(post) ? "yes" : "no") << "\n\n";

    cout << "Why inorder sorts on a BST:\n";
    cout << "  visit all smaller (left) before node, then all larger (right)\n\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
