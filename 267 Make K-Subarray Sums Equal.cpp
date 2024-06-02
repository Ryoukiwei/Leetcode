#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &arr, int k)
    {
        const int n = arr.size();
        int gcd = __gcd(n, k);
        long long ans = 0;

        for (int i = 0; i < gcd; i++)
        {
            vector<int> temp;
            for (int j = i; j < n; j += gcd)
            {
                temp.emplace_back(arr[j]);
            }

            size_t half = temp.size() / 2;
            nth_element(temp.begin(), temp.begin() + half, temp.end());
            int median = temp[half];

            for (const int num : temp)
            {
                ans += abs(num - median);
            }
        }

        return ans;
    }
};
