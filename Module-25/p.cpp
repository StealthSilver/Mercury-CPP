// MODULE 25 — Problem 2: Decode string k[encoded] (two stacks)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string& s) {
    stack<int> counts;
    stack<string> strings;
    string cur;
    int k = 0;

    for (char c : s) {
        if (isdigit(static_cast<unsigned char>(c))) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            strings.push(cur);
            cur.clear();
            k = 0;
        } else if (c == ']') {
            int repeat = counts.top();
            counts.pop();
            string prev = strings.top();
            strings.pop();
            string block;
            block.reserve(cur.size() * repeat);
            for (int i = 0; i < repeat; ++i) {
                block += cur;
            }
            cur = prev + block;
        } else {
            cur += c;
        }
    }
    return cur;
}

int main() {
    struct Case {
        string in;
        string expect;
    };

    Case tests[] = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
    };

    cout << "Decode string\n\n";
    for (const Case& t : tests) {
        string got = decodeString(t.in);
        cout << "in:  " << t.in << "\nout: " << got << "\n";
        cout << (got == t.expect ? "OK\n\n" : "FAIL\n\n");
    }

    return 0;
}
