#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        const int len = s.length();
        string ans;
        ans.reserve(len);
        stack<int> pos_stack;
        unordered_map<int, int> mapping;

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
                pos_stack.push(i);
            else if (s[i] == ')')
            {
                const int j = pos_stack.top();
                pos_stack.pop();
                mapping[i] = j;
                mapping[j] = i;
            }
        }

        for (int pos = 0, dir = 1; pos < len; pos += dir)
        {
            if (s[pos] == '(' || s[pos] == ')')
            {
                pos = mapping[pos];
                dir = -dir;
            }
            else
                ans.push_back(s[pos]);
        }

        return ans;
    }
};

// class Solution
// {
// public:
//     string reverseParentheses(string s)
//     {
//         vector<int> bound;
//         bound.reserve((s.length() + 1) / 2);
//         string ans;

//         for (auto c : s)
//         {
//             if (c == '(')
//             {
//                 bound.push_back(ans.length());
//                 continue;
//             }

//             if (c == ')')
//             {
//                 reverse(ans.begin() + bound.back(), ans.end());
//                 bound.pop_back();
//                 continue;
//             }

//             ans.push_back(c);
//         }

//         return ans;
//     }
// };