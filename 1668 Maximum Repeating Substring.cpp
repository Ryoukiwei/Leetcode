#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int ans = 0;
        int k = sequence.length() / word.length();

        string temp = word;

        for (int i = 1; i <= k; i++)
        {
            if (sequence.find(temp) != string::npos)
                ans = i;
            temp += word;
        }

        return ans;
    }
};