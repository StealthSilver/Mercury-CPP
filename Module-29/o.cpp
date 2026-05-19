// MODULE 29 — AVL Tree: insert with rotations (self-balancing BST)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int v) : data(v), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* n) { return n ? n->height : 0; }

void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

int balanceFactor(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rightRotate(Node* y) {
    cout << "    RIGHT rotation at " << y->data << "\n";
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    cout << "    LEFT rotation at " << x->data << "\n";
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balance(Node* root) {
    if (!root) {
        return nullptr;
    }
    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1) {
        if (balanceFactor(root->left) >= 0) {
            cout << "  LL case at " << root->data << "\n";
            return rightRotate(root);
        }
        cout << "  LR case at " << root->data << "\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1) {
        if (balanceFactor(root->right) <= 0) {
            cout << "  RR case at " << root->data << "\n";
            return leftRotate(root);
        }
        cout << "  RL case at " << root->data << "\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* insertAVL(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insertAVL(root->left, key);
    } else if (key > root->data) {
        root->right = insertAVL(root->right, key);
    } else {
        return root;
    }
    return balance(root);
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << "(h=" << root->height << ",bf=" << balanceFactor(root) << ") ";
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
    cout << "AVL Tree — insert with rotations\n";
    cout << "================================\n\n";
    cout << "Balance factor = height(left) - height(right)\n";
    cout << "|BF| must be <= 1 at every node.\n\n";

    Node* root = nullptr;
    vector<int> keys = {10, 20, 30, 40, 50, 25};

    for (int k : keys) {
        cout << "Insert " << k << ":\n";
        root = insertAVL(root, k);
        cout << "  Inorder: ";
        inorder(root);
        cout << "\n\n";
    }

    cout << "After all inserts, tree stays balanced (height O(log n))\n";
    cout << "Time per insert: O(log n)   Space: O(log n)\n";

    freeTree(root);
    return 0;
}
