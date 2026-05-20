// MODULE 25 — Problem 3: Simplify Unix path (stack)

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

string simplifyPath(const string& path) {
    stack<string> st;
    stringstream ss(path);
    string token;

    while (getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue;
        }
        if (token == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(token);
        }
    }

    if (st.empty()) {
        return "/";
    }

    string res;
    stack<string> order;
    while (!st.empty()) {
        order.push(st.top());
        st.pop();
    }
    while (!order.empty()) {
        res += "/" + order.top();
        order.pop();
    }
    return res;
}

int main() {
    struct Case {
        string in;
        string expect;
    };

    Case tests[] = {
        {"/home//foo/", "/home/foo"},
        {"/home/user/Documents/../Pictures", "/home/user/Pictures"},
        {"/../", "/"},
        {"/a/./b/../../c/", "/c"},
    };

    cout << "Simplify path\n\n";
    for (const Case& t : tests) {
        string got = simplifyPath(t.in);
        cout << "in:  " << t.in << "\nout: " << got << "\n";
        cout << (got == t.expect ? "OK\n\n" : "FAIL\n\n");
    }

    return 0;
}
