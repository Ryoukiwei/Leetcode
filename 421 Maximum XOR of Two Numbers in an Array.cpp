#include <bits/stdc++.h>
using namespace std;

using vecit = vector<int>::iterator;
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if (nums.size() == 1)
            return 0;

        const int maxNum = *max_element(nums.begin(), nums.end());
        int maxBit = static_cast<int>(log2(maxNum));

        auto pos = nums.begin();
        int chosen = 0;

        while (maxBit >= 0)
        {
            chosen = 1 << maxBit;
            pos = lower_bound(nums.begin(), nums.end(), chosen);

            if (pos == nums.begin())
            {
                for (int &num : nums)
                {
                    num -= chosen;
                }
            }

            else if (pos != nums.end())
            {
                for (auto it = pos; it != nums.end(); ++it)
                {
                    *it -= chosen;
                }
                break;
            }

            --maxBit;
        }

        return helper(nums, nums.begin(), pos - 1, pos, nums.end() - 1, maxBit - 1) + chosen;
    }

private:
    int helper(vector<int> &nums, vecit l1, vecit r1, vecit l2, vecit r2, int maxBit)
    {
        if (l1 == r1 && l2 == r2)
            return *l1 ^ *l2;

        if (maxBit == -1)
            return 0;

        const int chosen = 1 << maxBit;
        auto pos1 = lower_bound(l1, r1 + 1, chosen);
        auto pos2 = lower_bound(l2, r2 + 1, chosen);

        for (auto it = pos1; it != r1 + 1; ++it)
            *it -= chosen;

        for (auto it = pos2; it != r2 + 1; ++it)
            *it -= chosen;

        int val1 = 0, val2 = 0;

        if (pos1 != l1 && pos2 != r2 + 1)
            val1 = helper(nums, l1, pos1 - 1, pos2, r2, maxBit - 1) + chosen;

        if (pos1 != r1 + 1 && pos2 != l2)
            val2 = helper(nums, pos1, r1, l2, pos2 - 1, maxBit - 1) + chosen;

        if (val1 || val2)
            return max(val1, val2);

        return helper(nums, l1, r1, l2, r2, maxBit - 1);
    }
};

// class TrieNode
// {
// public:
//     vector<shared_ptr<TrieNode>> children;
//     TrieNode() : children(2) {}
// };

// class Trie
// {

// public:
//     Trie(int maxBit) : maxBit(maxBit) {}

//     void insert(int n)
//     {
//         shared_ptr<TrieNode> node = root;

//         for (int i = maxBit; i >= 0; --i)
//         {
//             const int bit = n >> i & 1;

//             if (!node->children[bit])
//                 node->children[bit] = make_shared<TrieNode>();

//             node = node->children[bit];
//         }
//     }

//     int maximumXOR(int n)
//     {
//         int ans = 0;
//         shared_ptr<TrieNode> node = root;

//         for (int i = maxBit; i >= 0; --i)
//         {
//             const int bit = (n >> i) & 1;
//             const int flip = bit ^ 1;

//             if (node->children[flip])
//             {
//                 ans |= 1 << i;
//                 node = node->children[flip];
//             }
//             else if (node->children[bit])
//                 node = node->children[bit];
//             else
//                 return 0; // There's nothing
//         }

//         return ans;
//     }

// private:
//     const int maxBit;
//     shared_ptr<TrieNode> root = make_shared<TrieNode>();
// };

// class Solution
// {
// public:
//     int findMaximumXOR(vector<int> &nums)
//     {
//         const int maxNum = *max_element(nums.begin(), nums.end());
//         if (!maxNum)
//             return 0;

//         const int maxBit = static_cast<int>(log2(maxNum));
//         int ans = 0;

//         Trie bitTrie(maxBit);

//         for (const int num : nums)
//         {
//             ans = max(ans, bitTrie.maximumXOR(num));
//             bitTrie.insert(num);
//         }

//         return ans;
//     }
// };

// class Solution
// {
// public:
//     int findMaximumXOR(vector<int> &nums)
//     {
//         const int maxNum = *max_element(nums.begin(), nums.end());
//         if (!maxNum)
//             return 0;

//         const int maxBit = static_cast<int>(log2(maxNum));
//         unordered_set<int> leftBits;
//         int ans = 0, mask = 0;

//         for (int i = maxBit; i >= 0; --i)
//         {
//             leftBits.clear();

//             mask |= 1 << i;

//             for (const int num : nums)
//             {
//                 leftBits.insert(num & mask);
//             }

//             const int chosen = ans | 1 << i;

//             for (const int leftBit : leftBits)
//             {
//                 if (leftBits.count(leftBit ^ chosen))
//                 {
//                     ans = chosen;
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
// };
