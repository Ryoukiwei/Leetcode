#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        parant.resize(n);
        rank.resize(n, 1);
        iota(parant.begin(), parant.end(), 0);
    }

    int find(int x)
    {
        if (parant[x] != x)
            parant[x] = find(parant[x]);

        return parant[x];
    }

    void unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB)
        {
            if (rank[rootA] > rank[rootB])
                swap(rootA, rootB);

            parant[rootA] = rootB;
            rank[rootB] += rank[rootA];
        }
    }

private:
    vector<int> parant;
    vector<int> rank;
};

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int M = *max_element(nums.begin(), nums.end());
        UnionFind uf(M + 1);

        for (int num : nums)
        {
            for (int i = 2; i <= sqrt(num); i++)
            {
                if (!(num % i))
                {
                    uf.unite(num, i);
                    uf.unite(num, num / i);
                }
            }
        }

        unordered_map<int, int> componentSize;
        int ans = 1;

        for (int num : nums)
        {
            int root = uf.find(num);
            componentSize[root]++;
            ans = max(ans, componentSize[root]);
        }

        return ans;
    }
};
