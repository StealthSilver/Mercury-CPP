// MODULE 30 — priority_queue with pairs and custom objects (Student)

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// --- 1. Student class (custom object) ---------------------------------------

class Student {
public:
    string name;
    int roll;
    int marks;

    Student(string n, int r, int m) : name(std::move(n)), roll(r), marks(m) {}

    // For default priority_queue: top() = "largest" by operator<
    // Higher marks = higher priority → return true if *this is worse than other
    bool operator<(const Student& other) const { return marks < other.marks; }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " (roll=" << s.roll << ", marks=" << s.marks << ")";
        return os;
    }
};

// Alternate: compare by roll (smallest roll = highest priority) without changing Student
struct CompareByRoll {
    bool operator()(const Student& a, const Student& b) const {
        return a.roll > b.roll;  // min-roll on top (greater<> style inside PQ)
    }
};

// --- 2. Pair comparators ------------------------------------------------------

// Top pair with smallest first element (min-heap on .first)
struct ComparePairMinFirst {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        return a.first > b.first;
    }
};

void demoPairs() {
    cout << "PART 1 — priority_queue<pair<int, string>>\n";
    cout << "==========================================\n\n";

    cout << "A) Default (less<pair>) → lexicographically LARGEST pair on top\n";
    priority_queue<pair<int, string>> pqMax;
    pqMax.push({3, "gamma"});
    pqMax.push({5, "alpha"});
    pqMax.push({5, "beta"});
    pqMax.push({1, "zeta"});

    cout << "   pop order: ";
    while (!pqMax.empty()) {
        auto p = pqMax.top();
        pqMax.pop();
        cout << "(" << p.first << ",\"" << p.second << "\") ";
    }
    cout << "\n   (compares first, then second string)\n\n";

    cout << "B) Custom ComparePairMinFirst → smallest .first on top\n";
    priority_queue<pair<int, string>, vector<pair<int, string>>, ComparePairMinFirst> pqMin;
    pqMin.push({3, "gamma"});
    pqMin.push({5, "alpha"});
    pqMin.push({1, "zeta"});
    pqMin.push({5, "beta"});

    cout << "   pop order: ";
    while (!pqMin.empty()) {
        auto p = pqMin.top();
        pqMin.pop();
        cout << "(" << p.first << ",\"" << p.second << "\") ";
    }
    cout << "\n\n";
}

void demoStudents() {
    cout << "PART 2 — priority_queue<Student>\n";
    cout << "================================\n\n";

    cout << "A) operator< on Student → highest marks on top (max-heap by marks)\n";
    priority_queue<Student> byMarks;
    byMarks.push(Student("Anita", 102, 88));
    byMarks.push(Student("Ravi", 105, 92));
    byMarks.push(Student("Kiran", 101, 75));
    byMarks.push(Student("Meera", 103, 92));

    cout << "   pop order:\n";
    while (!byMarks.empty()) {
        cout << "     " << byMarks.top() << "\n";
        byMarks.pop();
    }
    cout << "\n";

    cout << "B) CompareByRoll → smallest roll number on top\n";
    priority_queue<Student, vector<Student>, CompareByRoll> byRoll;
    byRoll.push(Student("Anita", 102, 88));
    byRoll.push(Student("Ravi", 105, 92));
    byRoll.push(Student("Kiran", 101, 75));
    byRoll.push(Student("Meera", 103, 92));

    cout << "   pop order:\n";
    while (!byRoll.empty()) {
        cout << "     " << byRoll.top() << "\n";
        byRoll.pop();
    }
    cout << "\n";
}

void demoPairsWithStudentIds() {
    cout << "PART 3 — pair<marks, Student name> as heap entry\n";
    cout << "=================================================\n\n";

    // pair in PQ: often (priority, payload) e.g. (marks, name) or (distance, node)
    priority_queue<pair<int, string>> pq;
    pq.push({88, "Anita"});
    pq.push({92, "Ravi"});
    pq.push({75, "Kiran"});
    pq.push({92, "Meera"});

    cout << "   pair.first = marks, pair.second = name\n";
    cout << "   top student by marks:\n";
    while (!pq.empty()) {
        auto [m, name] = pq.top();
        pq.pop();
        cout << "     " << name << " — " << m << " marks\n";
    }
}

int main() {
    cout << "Module 30 — PQ for pairs & objects (d.cpp)\n";
    cout << "==========================================\n\n";

    demoPairs();
    demoStudents();
    demoPairsWithStudentIds();

    cout << "Rule: priority_queue top = \"best\" per your Compare / operator<\n";

    return 0;
}
