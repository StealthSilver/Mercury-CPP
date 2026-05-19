// MODULE 28 — Level order traversal (iterative BFS with queue)

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

void printQueueState(const queue<Node*>& q) {
    queue<Node*> copy = q;
    cout << "  queue: [";
    bool first = true;
    while (!copy.empty()) {
        if (!first) {
            cout << ", ";
        }
        cout << copy.front()->data;
        copy.pop();
        first = false;
    }
    cout << "]\n";
}

void levelOrder(Node* root) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    int step = 0;
    int level = 0;
    int nodesThisLevel = 1;
    int nodesNextLevel = 0;

    cout << "Level 0: ";

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        ++step;
        cout << "\n  Step " << step << ": dequeue & visit " << cur->data << "\n";

        if (cur->left) {
            q.push(cur->left);
            ++nodesNextLevel;
            cout << "           enqueue left  " << cur->left->data << "\n";
        }
        if (cur->right) {
            q.push(cur->right);
            ++nodesNextLevel;
            cout << "           enqueue right " << cur->right->data << "\n";
        }
        printQueueState(q);

        --nodesThisLevel;
        if (nodesThisLevel == 0 && !q.empty()) {
            ++level;
            nodesThisLevel = nodesNextLevel;
            nodesNextLevel = 0;
            cout << "\nLevel " << level << ": ";
        }
    }
    cout << "\n";
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

    cout << "Level order traversal (iterative BFS)\n";
    cout << "====================================\n\n";
    cout << "Order: level 0, then level 1, then level 2, ... (left to right)\n";
    cout << "Uses a queue (FIFO), not recursion.\n\n";
    cout << "Tree:\n";
    cout << "        1          level 0\n";
    cout << "       / \\\n";
    cout << "      2   3        level 1\n";
    cout << "     / \\   \\\n";
    cout << "    4   5   6      level 2\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);

    cout << "Queue simulation:\n";
    levelOrder(root);

    cout << "Output: 1 2 3 4 5 6\n";
    cout << "Time: O(n)   Space: O(w) queue width (worst O(n))\n";

    freeTree(root);
    return 0;
}
