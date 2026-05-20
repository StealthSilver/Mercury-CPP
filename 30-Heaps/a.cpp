// MODULE 30 — priority_queue basics (max-heap vs min-heap)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    cout << "Module 30 — Priority Queue (heap) demo\n";
    cout << "======================================\n\n";

    cout << "1. Max-heap (default): largest on top\n";
    priority_queue<int> maxPQ;
    for (int x : {5, 1, 9, 3, 7}) {
        maxPQ.push(x);
    }
    cout << "   push: 5, 1, 9, 3, 7\n   pop order: ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << "\n\n";

    cout << "2. Min-heap: smallest on top (greater<int>)\n";
    priority_queue<int, vector<int>, greater<int>> minPQ;
    for (int x : {5, 1, 9, 3, 7}) {
        minPQ.push(x);
    }
    cout << "   push: 5, 1, 9, 3, 7\n   pop order: ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << "\n\n";

    cout << "3. Top 3 largest — min-heap of size 3\n";
    const int k = 3;
    priority_queue<int, vector<int>, greater<int>> topK;
    vector<int> nums = {4, 1, 7, 3, 9, 2, 8};
    for (int x : nums) {
        topK.push(x);
        if (static_cast<int>(topK.size()) > k) {
            topK.pop();
        }
    }
    cout << "   array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n   heap holds top " << k << " (pop order): ";
    while (!topK.empty()) {
        cout << topK.top() << " ";
        topK.pop();
    }
    cout << "\n\n";

    cout << "Compare: full sort = O(n log n), top-k heap = O(n log k)\n";

    return 0;
}
