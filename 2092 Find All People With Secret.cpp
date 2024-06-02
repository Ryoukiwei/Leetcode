#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        auto compare = [](const vector<int> &a, const vector<int> &b)
        { return a[2] < b[2]; };
        sort(meetings.begin(), meetings.end(), compare);

        unordered_set<int> ans;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        size_t m = meetings.size();
        parent[firstPerson] = 0;
        ans.insert(0);
        ans.insert(firstPerson);

        int i = 0;
        while (i < m)
        {
            unordered_set<int> temp;
            int j = i;

            // 找到相同時間的所有會議
            while (j < m && meetings[i][2] == meetings[j][2])
            {
                int a = meetings[j][0], b = meetings[j][1];
                temp.insert(a);
                temp.insert(b);
                combine(a, b, parent);
                j++;
            }

            for (int t : temp)
            {
                if (find(t, parent) != 0)
                    parent[t] = t;
                else
                    ans.insert(t);
            }

            i = j;
        }

        return vector<int>(ans.begin(), ans.end());
    }

private:
    int find(int a, vector<int> &parent)
    {
        if (parent[a] == a)
            return a;

        parent[a] = find(parent[a], parent);

        return parent[a];
    }

    void combine(int a, int b, vector<int> &parent)
    {
        a = find(a, parent);
        b = find(b, parent);

        if (a == b)
            return;

        if (a > b)
            swap(a, b);

        parent[b] = a;
    }
};