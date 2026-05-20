// MODULE 27 — Fractional knapsack (greedy by value/weight ratio)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

double fractionalKnapsack(vector<int> value, vector<int> weight, int W) {
    int n = static_cast<int>(value.size());
    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        items[i] = {value[i], weight[i],
                    static_cast<double>(value[i]) / weight[i]};
    }

    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b) { return a.ratio > b.ratio; });

    double ans = 0;
    int cap = W;

    for (const Item& it : items) {
        if (cap >= it.weight) {
            ans += it.value;
            cap -= it.weight;
        } else {
            if (cap > 0) {
                ans += it.value * (static_cast<double>(cap) / it.weight);
            }
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;

    double ans = fractionalKnapsack(value, weight, W);

    cout << "Fractional knapsack (greedy)\n\n";
    cout << "value:  ";
    for (int v : value) {
        cout << v << " ";
    }
    cout << "\nweight: ";
    for (int w : weight) {
        cout << w << " ";
    }
    cout << "\nW = " << W << "\n\n";

    cout << "ratios v/w: ";
    for (size_t i = 0; i < value.size(); ++i) {
        cout << (static_cast<double>(value[i]) / weight[i]) << " ";
    }
    cout << "\n\nmax value: " << ans << "  (expected 240)\n";

    return 0;
}
