// MODULE 28 — Bottom view of binary tree (BFS + horizontal distance + map)

#include <iostream>
#include <map>
#include <queue>
#include <utility>
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

vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) {
        return result;
    }

    map<int, int> bottom;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    cout << "BFS (always overwrite map[HD] — deepest wins):\n";
    while (!q.empty()) {
        Node* cur = q.front().first;
        int hd = q.front().second;
        q.pop();

        cout << "  visit " << cur->data << " at HD=" << hd;
        if (bottom.count(hd)) {
            cout << "  -> bottom[" << hd << "]=" << cur->data
                 << " (was " << bottom[hd] << ")\n";
        } else {
            cout << "  -> bottom[" << hd << "]=" << cur->data << "\n";
        }
        bottom[hd] = cur->data;

        if (cur->left) {
            q.push({cur->left, hd - 1});
        }
        if (cur->right) {
            q.push({cur->right, hd + 1});
        }
    }

    cout << "\nBottom view left to right (by HD):\n  ";
    for (auto& p : bottom) {
        cout << "HD " << p.first << " -> " << p.second << "   ";
        result.push_back(p.second);
    }
    cout << "\n\nSequence: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << "\n";
    return result;
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

    cout << "Bottom view of binary tree\n";
    cout << "==========================\n\n";
    cout << "Horizontal distance: root=0, left=HD-1, right=HD+1\n\n";
    cout << "Tree with HD labels:\n";
    cout << "           1(0)\n";
    cout << "          /    \\\n";
    cout << "      2(-1)    3(1)\n";
    cout << "      /  \\       \\\n";
    cout << "  4(-2) 5(0)    6(2)\n\n";

    idx = 0;
    Node* root = buildFromPreorder(arr);
    bottomView(root);

    cout << "\nCompare top view:    4 2 1 3 6\n";
    cout << "       bottom view:  4 2 5 3 6  (HD 0: 5 instead of 1)\n";
    cout << "Time: O(n log n)   Space: O(n)\n";

    freeTree(root);
    return 0;
}
