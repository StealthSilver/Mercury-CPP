// MODULE 26 — std::queue from the STL: all common member functions

#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
using namespace std;

static void printQueue(const char* label, const queue<int>& q) {
    queue<int> copy = q;
    cout << label << " (front -> back): ";
    bool first = true;
    while (!copy.empty()) {
        if (!first) {
            cout << " ";
        }
        first = false;
        cout << copy.front();
        copy.pop();
    }
    cout << " | size=" << q.size() << "\n";
}

int main() {
    cout << "=== std::queue — all common functions ===\n\n";

    // --- Constructors ---
    queue<int> q1;  // default (empty), underlying deque<int>
    cout << "1. default queue<int> q1;  empty=" << q1.empty() << " size=" << q1.size() << "\n";

    queue<int> q2;
    q2.push(10);
    q2.push(20);
    queue<int> q3(q2);  // copy constructor
    cout << "2. copy queue<int> q3(q2);  q3.front()=" << q3.front() << " q3.back()=" << q3.back() << "\n";

    deque<int> d = {100, 200, 300};
    queue<int> q4(d);  // construct from underlying container
    cout << "3. queue<int> q4(deque);  q4.front()=" << q4.front() << " q4.back()=" << q4.back() << "\n";

    queue<int> q5 = move(q4);  // move constructor (q4 now empty)
    cout << "4. move construct q5;  q5.size()=" << q5.size() << " q4.empty()=" << q4.empty() << "\n\n";

    // --- push, emplace, front, back, size, empty ---
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);  // emplace forwards to underlying container
    cout << "5. push(1), push(2), emplace(3):\n";
    cout << "   front()=" << q.front() << "  back()=" << q.back()
         << "  size()=" << q.size() << "  empty()=" << q.empty() << "\n";
    printQueue("   ", q);

    // --- pop (void return) ---
    int removed = q.front();
    q.pop();
    cout << "6. pop() after reading front; removed " << removed << "\n";
    printQueue("   ", q);

    // --- operator= (copy assignment) ---
    queue<int> other;
    other.push(99);
    q = other;
    cout << "7. q = other (copy assign); q.front()=" << q.front() << "\n";

    queue<int> movedSrc;
    movedSrc.push(7);
    movedSrc.push(8);
    q = move(movedSrc);
    cout << "8. q = move(movedSrc); q.back()=" << q.back() << "\n\n";

    // --- member swap ---
    queue<int> a, b;
    a.push(1);
    a.push(2);
    b.push(100);
    a.swap(b);
    cout << "9. a.swap(b):\n";
    printQueue("   a", a);
    printQueue("   b", b);

    // --- non-member swap ---
    swap(a, b);
    cout << "10. swap(a, b) non-member:\n";
    printQueue("   a", a);
    printQueue("   b", b);

    // --- relational operators ---
    queue<int> x, y;
    x.push(1);
    x.push(2);
    y.push(1);
    y.push(2);
    queue<int> z;
    z.push(1);
    cout << "11. x==y: " << (x == y ? "true" : "false")
         << "  x!=z: " << (x != z ? "true" : "false")
         << "  x<z: " << (x < z ? "true" : "false") << "\n\n";

    // --- different underlying container: list ---
    queue<int, list<int>> qList;
    qList.push(5);
    qList.push(6);
    cout << "12. queue<int, list<int>>  front=" << qList.front()
         << " back=" << qList.back() << "\n\n";

    // --- no clear(): drain or swap to empty ---
    queue<int> drain;
    drain.push(1);
    drain.push(2);
    drain.push(3);
    cout << "13. clear by draining pop():\n";
    while (!drain.empty()) {
        cout << "    pop " << drain.front() << "\n";
        drain.pop();
    }
    cout << "    empty=" << drain.empty() << "\n";

    queue<int> tmp;
    tmp.push(9);
    queue<int> withData;
    withData.push(1);
    withData.push(2);
    withData.swap(tmp);
    cout << "14. swap to empty: withData.size()=" << withData.size()
         << " tmp.size()=" << tmp.size() << "\n";

    return 0;
}
