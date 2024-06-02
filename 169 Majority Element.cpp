#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, ans = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                ans = num;
                count = 1;
            }
            else if (num == ans)
                count++;
            else
                count--;
        }

        return ans;
    }
};