#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        double l = 0, r = 1;
        const int n = arr.size();

        while (l < r)
        {
            const double mid = (l + r) / 2.0;
            int p = 0, q = 1, cnt = 0;

            for (int i = 0, j = 1; i < n; ++i)
            {
                while (j < n && arr[i] > mid * arr[j])
                    ++j;

                if (j == n)
                    break;

                cnt += n - j;
                if (p * arr[j] < q * arr[i])
                {
                    p = arr[i];
                    q = arr[j];
                }
            }

            if (cnt == k)
                return {p, q};

            if (cnt < k)
                l = mid;
            else
                r = mid;
        }

        throw;
    }
};