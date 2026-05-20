// MODULE 36 — LeetCode 127: Word Ladder (BFS on implicit edit graph)

#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// Shortest path from beginWord to endWord where edges = one-letter mutations in
// wordList (endWord must appear in wordList for a path to end there in LC;
// some statements count beginWord in the path length — we print word count).
int ladderLength(const string& beginWord, const string& endWord,
                 const vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    dict.erase(beginWord);

    while (!q.empty()) {
        auto [w, d] = q.front();
        q.pop();
        if (w == endWord) return d;

        string nw = w;
        for (size_t i = 0; i < nw.size(); i++) {
            char old = nw[i];
            for (char c = 'a'; c <= 'z'; c++) {
                nw[i] = c;
                if (dict.count(nw)) {
                    dict.erase(nw);
                    q.push({nw, d + 1});
                }
            }
            nw[i] = old;
        }
    }
    return 0;
}

int main() {
    cout << "Module 36 — Word Ladder (m.cpp)\n";
    cout << "=================================\n\n";
    string begin = "hit", end = "cog";
    vector<string> official = {"hot", "dot", "dog", "lot", "log", "cog"};
    int steps = ladderLength(begin, end, official);
    cout << "hit -> cog with dictionary: steps (words in path) = " << steps << " (expect 5)\n";
    return 0;
}
