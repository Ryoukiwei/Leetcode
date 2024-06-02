#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int ans = 0;

        for (int num : nums)
        {
            int divisor = 0;

            for (int i = 2; i * i <= num; ++i)
            {
                if (!(num % i))
                {
                    if (divisor)
                    {
                        divisor = 0;
                        break;
                    }
                    else
                        divisor = i;
                }
            }

            if (divisor && divisor * divisor < num)
                ans += (1 + num + divisor + num / divisor);
        }

        return ans;
    }
};