#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end());

        vector<int> prices, maxBeauty;
        prices.reserve(items.size());
        maxBeauty.reserve(items.size());
        int currBeauty = 0;

        for (const auto &item : items)
        {
            const int price = item[0];
            const int beauty = item[1];

            currBeauty = max(currBeauty, beauty);
            prices.push_back(price);
            maxBeauty.push_back(currBeauty);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int qPrice : queries)
        {
            const int pos = upper_bound(prices.begin(), prices.end(), qPrice) - prices.begin();
            ans.push_back(pos > 0 ? maxBeauty[pos - 1] : 0);
        }

        return ans;
    }
};