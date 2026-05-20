// MODULE 39 — Box stacking: max height stack (rotate dims, nest by w,l,h)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxStackHeight(vector<vector<int>>& boxes) {
    for (auto& b : boxes)
        sort(b.begin(), b.end());
    sort(boxes.begin(), boxes.end());

    int n = (int)boxes.size();
    vector<int> dp(n);
    int best = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = boxes[i][2];
        for (int j = 0; j < i; j++) {
            if (boxes[j][0] <= boxes[i][0] && boxes[j][1] <= boxes[i][1] &&
                boxes[j][2] <= boxes[i][2])
                dp[i] = max(dp[i], dp[j] + boxes[i][2]);
        }
        best = max(best, dp[i]);
    }
    return best;
}

int main() {
    cout << "Module 39 — Box Stacking (s.cpp)\n";
    cout << "================================\n\n";

    vector<vector<int>> boxes = {{50, 45, 20}, {95, 87, 22}, {45, 43, 19},
                                 {24, 12, 18}, {95, 99, 11}};
    cout << "Steps:\n";
    cout << "  1. Sort each box dimensions (w <= l <= h)\n";
    cout << "  2. Sort boxes lexicographically by (w,l,h)\n";
    cout << "  3. LIS-style DP on height: dp[i] = max stack with box i on top\n\n";

    cout << "  max stack height: " << maxStackHeight(boxes) << "\n";
    return 0;
}
