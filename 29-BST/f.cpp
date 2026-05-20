// MODULE 29 — Delete value in BST (3 cases)

#include <iostream>
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

Node* minNode(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) {
        return nullptr;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
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

void demo(const char* label, int key) {
    cout << label << " — delete " << key << "\n";
}

int main() {
    cout << "Delete value in BST\n";
    cout << "===================\n\n";

    cout << "Case 1: LEAF (no children)\n";
    Node* t1 = nullptr;
    for (int x : {3, 1, 6}) {
        t1 = insert(t1, x);
    }
    cout << "Before: inorder ";
    inorder(t1);
    cout << "\n";
    t1 = deleteNode(t1, 1);
    cout << "After delete 1: ";
    inorder(t1);
    cout << "\n\n";

    cout << "Case 2: ONE child\n";
    Node* t2 = nullptr;
    for (int x : {8, 3, 10, 14}) {
        t2 = insert(t2, x);
    }
    cout << "Before: inorder ";
    inorder(t2);
    cout << "\n";
    t2 = deleteNode(t2, 10);
    cout << "After delete 10 (only right child): ";
    inorder(t2);
    cout << "\n\n";

    cout << "Case 3: TWO children (inorder successor)\n";
    Node* t3 = nullptr;
    for (int x : {8, 3, 10, 1, 6, 14, 7}) {
        t3 = insert(t3, x);
    }
    cout << "Before: inorder ";
    inorder(t3);
    cout << "\n";
    cout << "Delete 3 -> replace with successor 6\n";
    t3 = deleteNode(t3, 3);
    cout << "After: ";
    inorder(t3);
    cout << "\n\n";

    cout << "Time: O(h)   Space: O(h)\n";

    freeTree(t1);
    freeTree(t2);
    freeTree(t3);
    return 0;
}
