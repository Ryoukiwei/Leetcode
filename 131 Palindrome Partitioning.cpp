#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        helper(s, 0, {}, ans);

        return ans;
    }

private:
    void helper(const string &s, int start, vector<string> &&record, vector<vector<string>> &ans)
    {
        if (start == s.length())
        {
            ans.emplace_back(record);
            return;
        }

        for (int i = start; i < s.length(); ++i)
        {
            if (isPalindrome(s, start, i))
            {
                record.emplace_back(s.substr(start, i - start + 1));
                helper(s, i + 1, move(record), ans);
                record.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};