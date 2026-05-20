// MODULE 31 — Union and intersection of two arrays (unique elements)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> arrayUnion(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> u(a.begin(), a.end());
    for (int x : b) {
        u.insert(x);
    }
    return vector<int>(u.begin(), u.end());
}

vector<int> arrayIntersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> setB(b.begin(), b.end());
    unordered_set<int> common;
    for (int x : a) {
        if (setB.count(x)) {
            common.insert(x);
        }
    }
    return vector<int>(common.begin(), common.end());
}

void printVec(const string& label, const vector<int>& v) {
    cout << "   " << label << ": ";
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    cout << "Module 31 — Union & Intersection (n.cpp)\n";
    cout << "========================================\n\n";

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {3, 4, 5, 6, 7};

    cout << "   A = 1 2 3 4 5\n";
    cout << "   B = 3 4 5 6 7\n\n";

    printVec("Union", arrayUnion(a, b));
    printVec("Intersection", arrayIntersection(a, b));

    cout << "\nUnion: all unique from A and B.\n";
    cout << "Intersection: elements present in both.\n";
    cout << "Time: O(n + m) avg   Space: O(n + m)\n";
    return 0;
}
