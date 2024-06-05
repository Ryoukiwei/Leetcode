#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        array<int, 26> freq = {};
        fill(freq.begin(), freq.end(), INT_MAX);

        for (const string &word : words)
        {
            array<int, 26> temp = {};
            for (const char c : word)
            {
                ++temp[c - 'a'];
            }

            for (int i = 0; i < 26; ++i)
            {
                freq[i] = min(freq[i], temp[i]);
            }
        }

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < freq[i]; ++j)
            {
                ans.emplace_back(1, static_cast<char>(i + 'a'));
            }
        }

        return ans;
    }
};