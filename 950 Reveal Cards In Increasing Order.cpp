#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        auto top = deck.begin(), bottom = deck.end();
        sort(top, bottom, greater<int>());

        deque<int> dq{*top++};

        for (auto card = top; card != bottom; ++card)
        {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(*card);
        }

        return {dq.begin(), dq.end()};
    }
};

// class Solution
// {
// public:
//     vector<int> deckRevealedIncreasing(vector<int> &deck)
//     {

//         sort(deck.begin(), deck.end());

//         int n = deck.size();
//         vector<int> ans(n);
//         bitset<1000> inserted = {false};
//         bool canInsert = true;

//         int j = 0;
//         for (int i = 0; j < n; ++i)
//         {
//             if (i >= n)
//                 i %= n;

//             if (!inserted[i])
//             {
//                 if (canInsert)
//                 {
//                     inserted[i] = true;
//                     ans[i] = deck[j++];
//                 }

//                 canInsert = !canInsert;
//             }
//         }

//         return ans;
//     }
// };