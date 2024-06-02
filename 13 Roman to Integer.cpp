#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        size_t n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = value[s[i + 1]] - value[s[i]];

            if (i == n - 1 || temp <= 0)
            {
                ans += value[s[i]];
            }
            else
            {
                ans += temp;
                i++;
            }
        }

        return ans;
    }

private:
    unordered_map<char, int> value = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
};
