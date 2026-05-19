// MODULE 25 — Problem 4: Trapping rain water (monotonic stack)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int trap(const vector<int>& height) {
    stack<int> st;
    int water = 0;

    for (int i = 0; i < static_cast<int>(height.size()); ++i) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int mid = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int left = st.top();
            int dist = i - left - 1;
            int bounded = min(height[i], height[left]) - height[mid];
            water += bounded * dist;
        }
        st.push(i);
    }
    return water;
}

int main() {
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int got = trap(h);

    cout << "Trapping rain water\n\n";
    cout << "height: ";
    for (int x : h) {
        cout << x << " ";
    }
    cout << "\nwater trapped: " << got << "  (expected 6)\n";
    cout << (got == 6 ? "OK\n" : "FAIL\n");

    return 0;
}
