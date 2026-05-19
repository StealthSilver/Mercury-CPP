// MODULE 30 — Problem 1: K nearest cars to CO (max-heap of size K)

#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Car {
    string id;
    int x, y;
};

long long distSq(int cx, int cy, int x, int y) {
    long long dx = x - cx;
    long long dy = y - cy;
    return dx * dx + dy * dy;
}

vector<Car> kNearest(const vector<Car>& cars, int cx, int cy, int k) {
    // Max-heap by distance² — top = farthest among current set
    auto cmp = [](const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first < b.first;
    };
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)> pq(cmp);

    cout << "  CO = (" << cx << ", " << cy << "), K = " << k << "\n";
    cout << "  d² = (x-cx)² + (y-cy)²\n\n";

    for (int i = 0; i < static_cast<int>(cars.size()); ++i) {
        long long d2 = distSq(cx, cy, cars[i].x, cars[i].y);
        cout << "  " << cars[i].id << " (" << cars[i].x << ", " << cars[i].y
             << ")  d² = " << d2 << "\n";
        pq.push({d2, i});
        if (static_cast<int>(pq.size()) > k) {
            cout << "    heap size > K → pop farthest (d²=" << pq.top().first << ")\n";
            pq.pop();
        }
    }

    vector<Car> ans;
    while (!pq.empty()) {
        ans.push_back(cars[pq.top().second]);
        pq.pop();
    }
    return ans;
}

int main() {
    cout << "Problem 1: K nearest cars\n";
    cout << "=========================\n\n";

    int cx = 3, cy = 3, k = 2;
    vector<Car> cars = {
        {"C1", 5, -1},
        {"C2", -2, 4},
        {"C3", 3, 2},
        {"C4", 8, 8},
    };

    vector<Car> nearest = kNearest(cars, cx, cy, k);

    cout << "\nK nearest cars (unordered in heap):\n";
    for (const Car& c : nearest) {
        long long d2 = distSq(cx, cy, c.x, c.y);
        cout << "  " << c.id << " (" << c.x << ", " << c.y << ")  d²=" << d2
             << "  d≈" << sqrt(static_cast<double>(d2)) << "\n";
    }

    cout << "\nTime: O(n log K)   Space: O(K)\n";
    return 0;
}
