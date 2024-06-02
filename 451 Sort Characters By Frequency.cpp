#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        string ans;
        vector<string> record(s.size() + 1);
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        for (auto &f : freq)
            record[f.second].append(f.second, f.first);

        for (int i = s.size(); i > 0; i--)
        {
            if (!record[i].empty())
                ans.append(record[i]);
        }

        return ans;
    }
};