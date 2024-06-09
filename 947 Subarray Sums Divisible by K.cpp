#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0;
        int sum = 0;
        vector<int> cnt(k);
        cnt.front() = 1;

        for (const int num : nums)
        {
            sum += num;
            int remain = sum % k;
            if (remain < 0)
                remain += k;
            ans += cnt[remain]++;
        }

        return ans;
    }
};