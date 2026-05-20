// MODULE 28 — LCA Approach 2: parent pointers + walk up — O(n) time, O(1) extra space

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : data(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->right->parent = root->right;
    return root;
}

Node* findNode(Node* root, int val) {
    if (!root) {
        return nullptr;
    }
    if (root->data == val) {
        return root;
    }
    Node* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

int depth(Node* node) {
    int d = 0;
    while (node) {
        ++d;
        node = node->parent;
    }
    return d;
}

Node* lcaWithParent(Node* p, Node* q) {
    int d1 = depth(p);
    int d2 = depth(q);
    cout << "  depth(" << p->data << ")=" << d1 << ", depth(" << q->data << ")=" << d2 << "\n";

    while (d1 > d2) {
        cout << "  move " << p->data << " up (deeper node)\n";
        p = p->parent;
        --d1;
    }
    while (d2 > d1) {
        cout << "  move " << q->data << " up\n";
        q = q->parent;
        --d2;
    }

    cout << "  same depth — walk both up together:\n";
    while (p != q) {
        cout << "    " << p->data << " and " << q->data << " -> ";
        p = p->parent;
        q = q->parent;
        cout << p->data << " and " << q->data << "\n";
    }
    return p;
}

// Classic recursive LCA — O(n) time, O(h) stack (no path arrays)
Node* lcaRecursive(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    Node* left = lcaRecursive(root->left, p, q);
    Node* right = lcaRecursive(root->right, p, q);
    if (left && right) {
        return root;
    }
    return left ? left : right;
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
    cout << "LCA — Approach 2 (O(1) extra space with parent pointers)\n";
    cout << "=======================================================\n\n";
    cout << "Idea: align depth of p and q, then climb parent until they meet.\n";
    cout << "No path vectors — only a few pointers.\n\n";
    cout << "Tree:\n        1\n       / \\\n      2   3\n     / \\   \\\n    4   5   6\n\n";

    Node* root = buildTree();

    struct Test {
        int a, b;
    };
    Test tests[] = {{4, 5}, {4, 6}, {2, 3}};

    for (const Test& t : tests) {
        cout << "--- LCA(" << t.a << ", " << t.b << ") — parent walk ---\n";
        Node* p = findNode(root, t.a);
        Node* q = findNode(root, t.b);
        Node* ans = lcaWithParent(p, q);
        cout << "Answer: " << ans->data << "\n\n";
    }

    cout << "--- Same tree: recursive LCA (no parent field needed) ---\n";
    Node* p = findNode(root, 4);
    Node* q = findNode(root, 6);
    Node* rec = lcaRecursive(root, p, q);
    cout << "LCA(4,6) recursive = " << rec->data << "\n\n";

    cout << "Parent-pointer method:\n";
    cout << "  Time: O(n) to build parents once; each query O(h)\n";
    cout << "  Extra space: O(1) — only pointers while walking\n\n";
    cout << "Recursive method:\n";
    cout << "  Time: O(n)   Extra space: O(h) call stack\n";

    freeTree(root);
    return 0;
}
