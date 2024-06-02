#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans;
        ans.reserve(s.size());
        int left = 0;
        int right = count(s.begin(), s.end(), ')');

        for (const char c : s)
        {
            if (c == '(')
            {
                if (left == right)
                    continue;

                ++left;
            }

            else if (c == ')')
            {
                --right;

                if (!left)
                    continue;

                --left;
            }

            ans.push_back(c);
        }

        return ans;
    }
};