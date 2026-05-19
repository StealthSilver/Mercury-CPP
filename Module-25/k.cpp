// MODULE 25 — Next greater element (monotonic stack)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    vector<int> nge(n, -1);
    stack<int> st;  // indices waiting for a greater element to the right

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 25, 7, 23};
    vector<int> nge = nextGreaterElement(arr);

    cout << "Next greater element\n\n";
    cout << "Index: ";
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        cout << i << "   ";
    }
    cout << "\narr:   ";
    for (int x : arr) {
        cout << x << "   ";
    }
    cout << "\nnge:   ";
    for (int x : nge) {
        cout << x << "   ";
    }
    cout << "\n\nExpected nge: 5  25  25  -1  23  -1\n";

    return 0;
}
