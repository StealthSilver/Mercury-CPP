// MODULE 30 — Problem 2: Connect N ropes — minimum total cost (min-heap)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int connectRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    int totalCost = 0;
    int step = 1;

    cout << "  Initial min-heap: ";
    priority_queue<int, vector<int>, greater<int>> show = pq;
    while (!show.empty()) {
        cout << show.top() << " ";
        show.pop();
    }
    cout << "\n\n";

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int cost = a + b;
        totalCost += cost;
        pq.push(cost);

        cout << "  Step " << step++ << ": join " << a << " + " << b << " = " << cost
             << "  (running total = " << totalCost << ")\n";
    }

    return totalCost;
}

int main() {
    cout << "Problem 2: Connect N ropes (min cost)\n";
    cout << "====================================\n\n";

    vector<int> ropes = {14, 3, 2, 6};
    cout << "Rope lengths: ";
    for (int x : ropes) {
        cout << x << " ";
    }
    cout << "\n\n";

    int ans = connectRopes(ropes);
    cout << "\nMinimum total cost = " << ans << "\n";
    cout << "Time: O(n log n)   Space: O(n)\n";

    return 0;
}
