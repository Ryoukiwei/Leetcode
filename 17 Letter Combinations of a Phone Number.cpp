#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string cur;
        vector<string> ans;
        helper(digits, mapping, 0, cur, ans);
        return ans;
    }

private:
    void helper(const string &digits, const vector<string> mapping, int i, string &cur, vector<string> &ans)
    {
        if (i == digits.length())
        {
            ans.emplace_back(cur);
            return;
        }

        int num = digits[i] - '0' - 2;

        for (const char c : mapping[num])
        {
            cur += c;
            helper(digits, mapping, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};