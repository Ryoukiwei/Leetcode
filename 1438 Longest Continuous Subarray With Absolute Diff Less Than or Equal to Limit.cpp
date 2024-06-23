#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int ans = 1;
        deque<int> minQ, maxQ;
        auto end = nums.end();

        for (auto l = nums.begin(), r = nums.begin(); r != end; ++r)
        {
            while (!minQ.empty() && minQ.back() > *r)
                minQ.pop_back();
            minQ.push_back(*r);

            while (!maxQ.empty() && maxQ.back() < *r)
                maxQ.pop_back();
            maxQ.push_back(*r);

            while (maxQ.front() - minQ.front() > limit)
            {
                if (minQ.front() == *l)
                    minQ.pop_front();
                if (maxQ.front() == *l)
                    maxQ.pop_front();

                ++l;
            }

            ans = max(ans, static_cast<int>(r - l + 1));
        }

        return ans;
    }
};