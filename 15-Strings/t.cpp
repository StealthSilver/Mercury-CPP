#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        // If opening bracket, push
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            // If stack empty → invalid
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            // Check matching pairs
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // Stack should be empty if valid
    return st.empty();
}

int main()
{
    string s = "{[()]}";

    if (isValid(s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}