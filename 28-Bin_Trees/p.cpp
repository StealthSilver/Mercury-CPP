// MODULE 28 — Kth level of a binary tree (BFS / level order)

#include <iostream>
#include <queue>
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

vector<int> kthLevel(Node* root, int k) {
    vector<int> levelNodes;
    if (!root) {
        return levelNodes;
    }

    queue<Node*> q;
    q.push(root);
    int level = 0;

    cout << "BFS level by level (root = level 0):\n";

    while (!q.empty()) {
        int size = static_cast<int>(q.size());
        cout << "  Level " << level << ": ";
        for (int i = 0; i < size; ++i) {
            Node* cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (level == k) {
                levelNodes.push_back(cur->data);
            }
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        cout << (level == k ? "  <-- Kth level" : "") << "\n";
        ++level;
    }

    return levelNodes;
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

    cout << "Kth level of a binary tree\n";
    cout << "==========================\n\n";
    cout << "Root is level 0.\n\n";
    cout << "Tree:\n";
    cout << "        1          level 0\n";
    cout << "       / \\\n";
    cout << "      2   3        level 1\n";
    cout << "     / \\   \\\n";
    cout << "    4   5   6      level 2\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    for (int k : {0, 1, 2, 3}) {
        cout << "--- K = " << k << " ---\n";
        vector<int> nodes = kthLevel(root, k);
        cout << "Nodes at level " << k << ": ";
        if (nodes.empty()) {
            cout << "(none)\n";
        } else {
            for (int v : nodes) {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "Time: O(n) — visit each node once\n";
    cout << "Space: O(w) — max queue width; worst O(n)\n";

    freeTree(root);
    return 0;
}
