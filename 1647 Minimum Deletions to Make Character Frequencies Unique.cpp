#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end());

        int temp = freq[25], ans = 0;

        for (int i = 24; i >= 0; i--)
        {
            if (freq[i] > temp - 1)
            {
                ans += freq[i] - max(temp - 1, 0);
                temp--;
            }
            else
                temp = freq[i];
        }

        return ans;
    }
};