#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = *(strs.begin());
        int len = ans.length();

        for (const auto str : strs)
        {
            while (str.find(ans))
                ans = ans.substr(0, --len);

            if (ans.empty())
                return "";
        }

        return ans;
    }
};