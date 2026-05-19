// MODULE 29 — All root-to-leaf paths in a binary tree

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
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void printPath(const vector<int>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }
    cout << "\n";
}

void rootToLeaf(Node* root, vector<int>& path) {
    if (!root) {
        return;
    }

    path.push_back(root->data);

    if (!root->left && !root->right) {
        cout << "  path: ";
        printPath(path);
    } else {
        rootToLeaf(root->left, path);
        rootToLeaf(root->right, path);
    }

    path.pop_back();
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
    cout << "Root to leaf paths\n";
    cout << "==================\n\n";

    Node* root = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14}) {
        root = insert(root, x);
    }

    cout << "Tree:\n        8\n       / \\\n      3   10\n     / \\    \\\n";
    cout << "    1   6    14\n\n";

    vector<int> path;
    cout << "DFS + backtrack:\n";
    rootToLeaf(root, path);

    cout << "\n3 paths (one per leaf)\n";
    cout << "Time: O(n)   Space: O(h)\n";

    freeTree(root);
    return 0;
}
