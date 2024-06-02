#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int ans = 0;

        for (int percentage : batteryPercentages)
        {
            if (percentage > ans)
                ans++;
        }

        return ans;
    }
};