// MODULE 39 — Generate all well-formed parentheses for n pairs

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generate(int open, int close, int n, string& cur, vector<string>& out) {
    if ((int)cur.size() == 2 * n) {
        out.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        generate(open + 1, close, n, cur, out);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        generate(open, close + 1, n, cur, out);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> out;
    string cur;
    generate(0, 0, n, cur, out);
    return out;
}

int main() {
    cout << "Module 39 — Generate Parentheses (n.cpp)\n";
    cout << "========================================\n\n";

    for (int n : {1, 2, 3}) {
        auto res = generateParenthesis(n);
        cout << "n = " << n << " -> " << res.size() << " strings (C_" << n << "):\n";
        for (const string& s : res) cout << "  " << s << "\n";
        cout << "\n";
    }
    return 0;
}
