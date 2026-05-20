// MODULE 37 — Variation: Min Cost Climbing Stairs (LeetCode 746 style)
// cost[i] = price to step ON stair i. Can start at 0 or 1. Reach index n (top).

#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(const vector<int>& cost) {
    int n = (int)cost.size();
    if (n == 0) return 0;
    int prev = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int nxt = cost[i] + min(prev, cur);
        prev = cur;
        cur = nxt;
    }
    return min(prev, cur);
}

int main() {
    cout << "Module 37 — Min Cost Climbing Stairs (e.cpp)\n";
    cout << "============================================\n\n";

    vector<int> cost = {10, 15, 20};
    cout << "cost = [10, 15, 20]\n";
    cout << "Min cost to top: " << minCostClimbingStairs(cost) << " (expect 15)\n\n";

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "LC sample: min cost = " << minCostClimbingStairs(cost2) << " (expect 6)\n";
    return 0;
}
