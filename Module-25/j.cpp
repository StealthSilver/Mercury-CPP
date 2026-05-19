// MODULE 25 — Stock span problem (monotonic stack)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(const vector<int>& price) {
    int n = static_cast<int>(price.size());
    vector<int> span(n);
    stack<int> st;  // indices; prices on stack are strictly decreasing top to bottom

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = calculateSpan(price);

    cout << "Stock span problem\n\n";
    cout << "Day:   ";
    for (int i = 0; i < static_cast<int>(price.size()); ++i) {
        cout << i << "  ";
    }
    cout << "\nPrice: ";
    for (int p : price) {
        cout << p << "  ";
    }
    cout << "\nSpan:  ";
    for (int s : span) {
        cout << s << "  ";
    }
    cout << "\n\nExpected span: 1  1  1  2  1  4  6\n";

    return 0;
}
