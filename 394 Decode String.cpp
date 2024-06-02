#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string ans;
        stack<int> num;
        stack<string> str;
        int n = 0;

        for (char c : s)
        {
            if (isdigit(c))
                n = n * 10 + c - '0';
            else if (c == '[')
            {
                num.push(n);
                str.push(ans);
                n = 0;
                ans.clear();
            }
            else if (c == ']')
            {
                int t = num.top();
                num.pop();

                while (t--)
                {
                    str.top() += ans;
                }
                ans = str.top();
                str.pop();
            }
            else
                ans += c;
        }

        return ans;
    }
};