// MODULE 26 — First non-repeating character in a stream (queue + frequency)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string firstNonRepeatingStream(const string& stream) {
    int freq[256] = {};
    queue<char> q;
    string out;

    for (char c : stream) {
        ++freq[static_cast<unsigned char>(c)];
        q.push(c);

        while (!q.empty() && freq[static_cast<unsigned char>(q.front())] > 1) {
            q.pop();
        }

        out += q.empty() ? '#' : q.front();
    }
    return out;
}

int main() {
    string stream = "aabc";
    string ans = firstNonRepeatingStream(stream);

    cout << "First non-repeating in stream\n\n";
    cout << "stream: " << stream << "\n";
    cout << "output: " << ans << "\n";
    cout << "expected: a#bb\n";
    cout << "step-by-step: ";
    for (size_t i = 0; i < stream.size(); ++i) {
        cout << ans[i] << (i + 1 < stream.size() ? " " : "\n");
    }

    string s2 = "z";
    cout << "\nstream: " << s2 << " -> " << firstNonRepeatingStream(s2) << "\n";

    return 0;
}
