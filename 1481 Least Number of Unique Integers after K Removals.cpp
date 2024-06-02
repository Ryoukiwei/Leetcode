#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq;
        vector<int> temp;

        for (int i : arr)
        {
            freq[i]++;
        }

        for (auto kv : freq)
        {
            temp.emplace_back(kv.second);
        }

        sort(temp.begin(), temp.end());
        size_t n = temp.size();

        for (int i = 0; i < n; i++)
        {
            k -= temp[i];

            if (k < 0)
                return n - i;
        }

        return 0;
    }
};

// class Solution
// {
// public:
//     int findLeastNumOfUniqueInts(vector<int> &arr, int k)
//     {
//         unordered_map<int, int> freq;
//         priority_queue<int, vector<int>, greater<int>> minHeap;

//         for (int i : arr)
//         {
//             freq[i]++;
//         }

//         for (auto kv : freq)
//         {
//             minHeap.push(kv.second);
//         }

//         while (k > 0)
//         {
//             int top = minHeap.top();
//             minHeap.pop();

//             k -= top;
//         }

//         return minHeap.size() + (k < 0 ? 1 : 0);
//     }
// };