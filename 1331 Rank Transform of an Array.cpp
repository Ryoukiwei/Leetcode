#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        if (arr.empty())
            return {};

        const int n = arr.size();
        vector<pair<int, int>> sortedArr(n);
        for (int i = 0; i < n; ++i)
        {
            sortedArr[i] = {arr[i], i};
        }

        sort(sortedArr.begin(), sortedArr.end());

        auto begin = sortedArr.begin(), end = sortedArr.end();
        int rank = 1;
        arr[begin->second] = 1;

        for (auto it = next(begin); it != end; ++it)
        {
            if (it->first != prev(it)->first)
                ++rank;
            arr[it->second] = rank;
        }

        return arr;
    }
};