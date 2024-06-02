#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int freq = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; i++)
        {
            if (vowels.count(s[i]))
                freq++;
        }

        int ans = freq;

        for (int i = k; i < s.length(); i++)
        {
            if (vowels.count(s[i - k]))
                freq--;
            if (vowels.count(s[i]))
                freq++;

            ans = max(ans, freq);
        }

        return ans;
    }
};
