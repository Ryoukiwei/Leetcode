#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0, i = 0, j = height.size() - 1;

        while (i < j)
        {
            int h = min(height[i], height[j]);
            ans = max(ans, h * (j - i));
            while (i < j && h == height[i])
                i++;
            while (i < j && h == height[j])
                j--;
        }

        return ans;
    }
};