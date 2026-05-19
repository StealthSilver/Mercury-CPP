// MODULE 26 — std::deque (double-ended queue) — STL illustration

#include <deque>
#include <iostream>
using namespace std;

static void printDeque(const char* label, const deque<int>& d) {
    cout << label << " | size=" << d.size() << " | front -> back: ";
    for (size_t i = 0; i < d.size(); ++i) {
        cout << d[i];
        if (i + 1 < d.size()) {
            cout << " ";
        }
    }
    cout << " | front()=" << (d.empty() ? -1 : d.front())
         << " back()=" << (d.empty() ? -1 : d.back()) << "\n";
}

int main() {
    cout << "=== std::deque — double-ended queue ===\n\n";

    deque<int> d;

    cout << "1. empty(): " << d.empty() << "  size(): " << d.size() << "\n\n";

    d.push_back(3);
    printDeque("2. push_back(3)", d);

    d.push_back(4);
    printDeque("3. push_back(4)", d);

    d.push_front(2);
    printDeque("4. push_front(2)", d);

    d.push_front(1);
    printDeque("5. push_front(1)", d);

    cout << "6. front()=" << d.front() << "  back()=" << d.back() << "\n\n";

    d.pop_front();
    printDeque("7. pop_front() — removed 1", d);

    d.pop_back();
    printDeque("8. pop_back() — removed 4", d);

    d.push_front(10);
    d.push_back(20);
    printDeque("9. push_front(10), push_back(20)", d);

    cout << "10. operator[] d[0]=" << d[0] << " d[1]=" << d[1]
         << " (random access O(1))\n\n";

    cout << "11. clear()\n";
    d.clear();
    cout << "    empty=" << d.empty() << " size=" << d.size() << "\n";

    return 0;
}
