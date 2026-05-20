// MODULE 27 — Job sequencing (greedy: sort by profit, latest free slot)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int id;
    int profit;
    int deadline;
};

int jobSequencing(vector<int> profit, vector<int> deadline) {
    int n = static_cast<int>(profit.size());
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        jobs[i] = {i, profit[i], deadline[i]};
    }

    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) { return a.profit > b.profit; });

    int maxD = 0;
    for (int d : deadline) {
        maxD = max(maxD, d);
    }

    vector<bool> slot(maxD, false);
    int total = 0;

    for (const Job& j : jobs) {
        for (int t = min(maxD, j.deadline) - 1; t >= 0; --t) {
            if (!slot[t]) {
                slot[t] = true;
                total += j.profit;
                break;
            }
        }
    }
    return total;
}

int main() {
    vector<int> profit = {100, 10, 15, 27};
    vector<int> deadline = {2, 1, 2, 1};

    int ans = jobSequencing(profit, deadline);

    cout << "Job sequencing (max profit)\n\n";
    cout << "Job  profit  deadline\n";
    const char* names[] = {"A", "B", "C", "D"};
    for (int i = 0; i < static_cast<int>(profit.size()); ++i) {
        cout << " " << names[i] << "    " << profit[i] << "      " << deadline[i] << "\n";
    }
    cout << "\nmax total profit: " << ans << "  (expected 127)\n";
    cout << "schedule: D at slot 1, A at slot 2\n";

    return 0;
}
