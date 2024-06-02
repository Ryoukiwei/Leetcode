#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        size_t m = nums1.size(), n = nums2.size();
        int l = (m + n + 1) / 2, r = (m + n + 2) / 2;
        int mid1 = find(nums1, 0, nums2, 0, l);
        int mid2 = find(nums1, 0, nums2, 0, r);

        return (mid1 + mid2) / 2.0;
    }

private:
    int find(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2, int k)
    {
        size_t m = nums1.size(), n = nums2.size();

        if (idx1 >= m)
            return nums2[idx2 + k - 1];
        if (idx2 >= n)
            return nums1[idx1 + k - 1];

        if (k == 1)
            return min(nums1[idx1], nums2[idx2]);

        int mid1 = (idx1 + k / 2 - 1 < m) ? nums1[idx1 + k / 2 - 1] : INT_MAX;
        int mid2 = (idx2 + k / 2 - 1 < n) ? nums2[idx2 + k / 2 - 1] : INT_MAX;

        if (mid1 < mid2)
            return find(nums1, idx1 + k / 2, nums2, idx2, k - k / 2);

        return find(nums1, idx1, nums2, idx2 + k / 2, k - k / 2);
    }
};
