// MODULE 25 — Largest rectangle in a histogram (monotonic stack)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(const vector<int>& heights) {
    int n = static_cast<int>(heights.size());
    stack<int> st;  // indices; heights on stack are increasing
    int maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        int cur = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > cur) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        if (i < n) {
            st.push(i);
        }
    }
    return maxArea;
}

int main() {
    vector<pair<vector<int>, int>> tests = {
        {{2, 1, 5, 6, 2, 3}, 10},
        {{6, 2, 5, 4, 5, 1, 6}, 12},
        {{1, 1, 1, 1}, 4},
    };

    cout << "Largest rectangle in histogram\n\n";
    for (const auto& t : tests) {
        int got = largestRectangleArea(t.first);
        cout << "heights: ";
        for (int h : t.first) {
            cout << h << " ";
        }
        cout << "\nmax area: " << got;
        cout << "  (expected " << t.second << ")";
        cout << (got == t.second ? "  OK\n\n" : "  FAIL\n\n");
    }

    return 0;
}
