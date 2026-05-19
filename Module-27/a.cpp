// MODULE 27 — Activity selection (greedy: sort by finish time)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Activity {
    int idx;
    int start;
    int end;
};

vector<int> activitySelection(const vector<int>& start, const vector<int>& end) {
    int n = static_cast<int>(start.size());
    vector<Activity> acts(n);
    for (int i = 0; i < n; ++i) {
        acts[i] = {i, start[i], end[i]};
    }

    sort(acts.begin(), acts.end(),
         [](const Activity& a, const Activity& b) { return a.end < b.end; });

    vector<int> chosen;
    if (n == 0) {
        return chosen;
    }

    chosen.push_back(acts[0].idx);
    int lastEnd = acts[0].end;

    for (int i = 1; i < n; ++i) {
        if (acts[i].start >= lastEnd) {
            chosen.push_back(acts[i].idx);
            lastEnd = acts[i].end;
        }
    }
    return chosen;
}

int main() {
    vector<int> start = {10, 12, 20};
    vector<int> end = {20, 25, 30};

    vector<int> picked = activitySelection(start, end);

    cout << "Activity selection (greedy)\n\n";
    cout << "start: ";
    for (int s : start) {
        cout << s << " ";
    }
    cout << "\nend:   ";
    for (int e : end) {
        cout << e << " ";
    }
    cout << "\n\nmax activities: " << picked.size() << "  (expected 2)\n";
    cout << "chosen indices: ";
    for (int i : picked) {
        cout << i << " ";
    }
    cout << "\nintervals: ";
    for (int i : picked) {
        cout << "[" << start[i] << "," << end[i] << "] ";
    }
    cout << "\n";

    return 0;
}
