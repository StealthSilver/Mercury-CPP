// MODULE 26 — Problem 1: Time required to buy tickets

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int timeRequiredMath(const vector<int>& tickets, int k) {
    int time = 0;
    for (int i = 0; i < static_cast<int>(tickets.size()); ++i) {
        if (i <= k) {
            time += min(tickets[i], tickets[k]);
        } else {
            time += min(tickets[i], tickets[k] - 1);
        }
    }
    return time;
}

int timeRequiredSimulate(vector<int> tickets, int k) {
    queue<pair<int, int>> q;
    for (int i = 0; i < static_cast<int>(tickets.size()); ++i) {
        q.push({i, tickets[i]});
    }

    int seconds = 0;
    while (true) {
        auto [idx, left] = q.front();
        q.pop();
        --left;
        ++seconds;
        if (idx == k && left == 0) {
            return seconds;
        }
        if (left > 0) {
            q.push({idx, left});
        }
    }
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    int t1 = timeRequiredMath(tickets, k);
    int t2 = timeRequiredSimulate(tickets, k);

    cout << "Time to buy tickets\n\n";
    cout << "tickets: 2 3 2, k=2\n";
    cout << "math:      " << t1 << "\n";
    cout << "simulate:  " << t2 << "\n";
    cout << "expected:  6\n";

    return 0;
}
