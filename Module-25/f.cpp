// MODULE 25 — std::stack from the STL (<stack> header)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename Container>
static void drainPrint(const char* label, stack<int, Container>& s) {
    cout << label << " (pop order): ";
    bool first = true;
    while (!s.empty()) {
        if (!first) {
            cout << " ";
        }
        first = false;
        cout << s.top();
        s.pop();
    }
    cout << "\n";
}

int main() {
    // Default underlying container is std::deque<int>
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "s1 (deque-backed default) top: " << s1.top() << " size: " << s1.size() << "\n";
    s1.pop();
    cout << "after pop, top: " << s1.top() << "\n\n";

    // Explicit container: std::vector<int> as backing store
    stack<int, vector<int>> s2;
    s2.push(10);
    s2.push(20);
    s2.push(30);
    cout << "s2 (vector-backed) top: " << s2.top() << "\n";

    // No clear(): drain with pop, or assign empty stack
    stack<int> tmp;
    s1.swap(tmp);  // s1 is now empty; tmp holds old contents
    cout << "s1 empty after swap? " << (s1.empty() ? "yes" : "no") << "\n";
    drainPrint("tmp contents", tmp);

    drainPrint("s2 drained", s2);

    return 0;
}
