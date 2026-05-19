// MODULE 29 — Red-Black Tree: insert with fix-up (self-balancing BST)

#include <iostream>
#include <vector>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int v) : data(v), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    Node* root = nullptr;

    void rotateLeft(Node* x) {
        cout << "    LEFT rotate at " << x->data << "\n";
        Node* y = x->right;
        x->right = y->left;
        if (y->left) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (!x->parent) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* y) {
        cout << "    RIGHT rotate at " << y->data << "\n";
        Node* x = y->left;
        y->left = x->right;
        if (x->right) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (!y->parent) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* z) {
        while (z->parent && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* uncle = z->parent->parent->right;
                if (uncle && uncle->color == RED) {
                    cout << "  Recolor: parent, uncle RED -> BLACK; grandparent RED\n";
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        cout << "  Zig-zag (LR style) — rotate parent\n";
                        z = z->parent;
                        rotateLeft(z);
                    }
                    cout << "  Recolor + rotate grandparent\n";
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateRight(z->parent->parent);
                    z = root;
                    break;
                }
            } else {
                Node* uncle = z->parent->parent->left;
                if (uncle && uncle->color == RED) {
                    cout << "  Recolor: parent, uncle RED -> BLACK; grandparent RED\n";
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        cout << "  Zig-zag (RL style) — rotate parent\n";
                        z = z->parent;
                        rotateRight(z);
                    }
                    cout << "  Recolor + rotate grandparent\n";
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rotateLeft(z->parent->parent);
                    z = root;
                    break;
                }
            }
        }
        root->color = BLACK;
    }

public:
    void insert(int key) {
        Node* node = new Node(key);
        Node* y = nullptr;
        Node* x = root;

        while (x) {
            y = x;
            if (key < x->data) {
                x = x->left;
            } else if (key > x->data) {
                x = x->right;
            } else {
                delete node;
                return;
            }
        }

        node->parent = y;
        if (!y) {
            root = node;
        } else if (key < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        cout << "Insert " << key << " (new node RED)\n";
        fixInsert(node);
    }

    void inorder(Node* n) {
        if (!n) {
            return;
        }
        inorder(n->left);
        cout << n->data << (n->color == RED ? "R" : "B") << " ";
        inorder(n->right);
    }

    void print() {
        inorder(root);
        cout << "\n";
    }

    Node* getRoot() { return root; }
};

int main() {
    cout << "Red-Black Tree — insert with fix-up\n";
    cout << "===================================\n\n";
    cout << "Properties: root BLACK, no two consecutive REDs,\n";
    cout << "every path has same black-height.\n\n";

    RedBlackTree tree;
    vector<int> keys = {10, 20, 30, 15, 25, 5};

    for (int k : keys) {
        tree.insert(k);
        cout << "  Inorder (R/B): ";
        tree.print();
        cout << "\n";
    }

    cout << "Used in C++ std::map / std::set for O(log n) operations\n";
    cout << "Time per insert: O(log n)   Space: O(log n)\n";

    return 0;
}
