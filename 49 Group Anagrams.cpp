#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> record;

        for (string s : strs)
        {
            vector<int> count(26);
            string temp;

            for (char c : s)
            {
                count[c - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                if (count[i])
                    temp += string(1, i + 'a') + to_string(count[i]);
            }

            record[temp].push_back(s);
        }

        for (auto r : record)
        {
            ans.push_back(r.second);
        }

        return ans;
    }
};