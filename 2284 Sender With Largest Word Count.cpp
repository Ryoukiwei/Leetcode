#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        size_t n = senders.size();
        unordered_map<string, int> record;

        for (int i = 0; i < n; i++)
        {
            int words = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            record[senders[i]] += words;
        }

        string ans = senders[0];

        for (auto &[sender, words] : record)
        {
            if (record[ans] < words || (record[ans] == words && ans < sender))
                ans = sender;
        }

        return ans;
    }
};