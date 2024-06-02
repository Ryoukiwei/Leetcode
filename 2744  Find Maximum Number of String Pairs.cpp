#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     const int SIZE = 26 * 26;

// public:
//     int maximumNumberOfStringPairs(vector<string> &words)
//     {
//         int ans = 0;
//         vector<bool> seen(SIZE);

//         auto hash = [](char a, char b)
//         {
//             return (a - 'a') * 26 + (b - 'a');
//         };

//         for (const auto &word : words)
//         {
//             if (seen[hash(word[1], word[0])])
//                 ++ans;
//             seen[hash(word[0], word[1])] = true;
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int ans = 0;
        unordered_set<string> seen;

        for (auto &word : words)
        {
            if (seen.find(word) != seen.end())
                ++ans;
            else
            {
                reverse(word.begin(), word.end());
                seen.insert(word);
            }
        }
        return ans;
    }
};
