#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<int> ans;
        vector<vector<int>> filtered;

        // restaurants[i] = [id_i, rating_i, veganFriendly_i, price_i, distance_i]
        auto preferred = [&](const auto &restaurant)
        {
            return (!veganFriendly || restaurant[2]) && restaurant[3] <= maxPrice && restaurant[4] <= maxDistance;
        };
        copy_if(restaurants.begin(), restaurants.end(), back_inserter(filtered), preferred);

        auto compare = [](const auto &a, const auto &b)
        {
            return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
        };
        sort(filtered.begin(), filtered.end(), compare);

        transform(filtered.begin(), filtered.end(), back_inserter(ans), [](const auto &vec)
                  { return vec[0]; });

        return ans;
    }
};