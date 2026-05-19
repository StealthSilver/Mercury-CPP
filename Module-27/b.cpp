// MODULE 27 — maxActivities (greedy count) — course-style loop

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {
    int n = static_cast<int>(start.size());
    if (n == 0) {
        return 0;
    }

    // Sort indices by finish time (end[])
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(),
         [&](int a, int b) { return end[a] < end[b]; });

    vector<int> s(n), e(n);
    for (int i = 0; i < n; ++i) {
        s[i] = start[idx[i]];
        e[i] = end[idx[i]];
    }
    start = move(s);
    end = move(e);

    // A0 — select first activity (earliest end)
    int count = 1;
    int currEndTime = end[0];

    for (int i = 1; i < static_cast<int>(start.size()); ++i) {
        if (start[i] >= currEndTime) {  // non-overlapping
            count++;
            currEndTime = end[i];
        }
    }
    return count;
}

int main() {
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};

    int ans = maxActivities(start, end);

    cout << "maxActivities (b.cpp)\n\n";
    cout << "start: ";
    for (int x : start) {
        cout << x << " ";
    }
    cout << "\nend:   ";
    for (int x : end) {
        cout << x << " ";
    }
    cout << "\n\nmax activities: " << ans << "  (expected 2)\n";

    return 0;
}
