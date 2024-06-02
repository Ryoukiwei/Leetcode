#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> map;

        for (auto &path : paths)
        {
            map[path[0]]++;
        }

        for (auto &path : paths)
        {
            map[path[1]]--;

            if (map[path[1]] == -1)
                return path[1];
        }

        return "";
    }
};