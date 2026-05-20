// MODULE 36 — LeetCode 630: Course Schedule III (greedy + max-heap)

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Greedy: process courses by increasing lastDay. Keep taking each course; if total
// time exceeds its deadline, drop the longest course taken so far (exchange argument).
// Time O(n log n), Space O(n).
int scheduleCourse(vector<vector<int>> courses) {
    sort(courses.begin(), courses.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    priority_queue<int> pq;  // durations of chosen courses
    int time = 0;
    for (const auto& c : courses) {
        int dur = c[0], last = c[1];
        pq.push(dur);
        time += dur;
        if (time > last) {
            time -= pq.top();
            pq.pop();
        }
    }
    return (int)pq.size();
}

int main() {
    cout << "Module 36 — Course Schedule III (p.cpp)\n";
    cout << "======================================\n\n";
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    cout << "Max courses = " << scheduleCourse(courses) << " (expect 3)\n";
    return 0;
}
