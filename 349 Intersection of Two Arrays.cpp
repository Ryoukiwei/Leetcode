#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(ans));
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> ans;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         auto it1 = nums1.begin();
//         auto it2 = nums2.begin();

//         while (it1 != nums1.end() && it2 != nums2.end())
//         {
//             if (*it1 < *it2)
//                 it1++;
//             else
//             {
//                 if (!(*it2 < *it1))
//                 {
//                     if (ans.empty() || ans.back() != *it1)
//                         ans.emplace_back(*it1);
//                     it1++;
//                 }
//                 it2++;
//             }
//         }

//         return ans;
//     }
// };