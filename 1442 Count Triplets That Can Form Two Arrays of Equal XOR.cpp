#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        const int n = arr.size();
        unordered_map<int, int> freq = {{0, 1}};
        unordered_map<int, int> sum;

        int ans = 0;
        int temp = 0;

        for (int i = 0; i < n; ++i)
        {
            temp ^= arr[i];
            ans += freq[temp] * i - sum[temp];
            ++freq[temp];
            sum[temp] += i + 1;
        }

        return ans;
    }
};