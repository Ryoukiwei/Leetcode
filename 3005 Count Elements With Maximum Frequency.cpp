#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101);

        for (int num : nums)
        {
            freq[num]++;
        }

        int ans = 0, max = -1;

        for (int f : freq)
        {
            if (max < f)
            {
                max = f;
                ans = f;
            }
            else if (max == f)
                ans += f;
        }

        return ans;
    }
};