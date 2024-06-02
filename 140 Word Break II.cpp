#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict{wordDict.begin(), wordDict.end()};
        unordered_map<string, vector<string>> mem;
        return helper(s, dict, mem);
    }

private:
    vector<string> helper(const string &s, unordered_set<string> &dict, unordered_map<string, vector<string>> &mem)
    {
        auto it = mem.find(s);
        if (it != mem.end())
            return it->second;

        const int n = s.length();
        vector<string> ans;

        for (int i = 1; i < n; ++i)
        {
            const string &front = s.substr(0, i);
            const string &back = s.substr(i);

            if (dict.count(front))
            {
                vector<string> words = helper(back, dict, mem);
                for (const string &word : words)
                {
                    ans.emplace_back(front + " " + word);
                }
            }
        }

        if (dict.count(s))
            ans.emplace_back(s);

        return mem[s] = ans;
    }
};