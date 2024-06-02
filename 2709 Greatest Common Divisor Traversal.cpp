#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
vector<int> prime_factors[MAX];

int init = []()
{
    for (int i = 2; i < MAX; i++)
    {
        int v = i, div = 2;

        while (div <= v / div)
        {
            if (!(v % div))
            {
                prime_factors[i].push_back(div);

                while (!(v % div))
                    v /= div;
            }

            div++;
        }

        if (v > 1)
            prime_factors[i].push_back(v);
    }

    return 0;
}();

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n) { iota(parent.begin(), parent.end(), 0); }

    void unite(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
            return;

        if (rank[rootA] > rank[rootB])
            swap(rootA, rootB);

        parent[rootA] = rootB;
        rank[rootB] += rank[rootA];

        count--;
    }

    int find(int x)
    {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

private:
    int count;
    vector<int> parent;
    vector<int> rank;
};

class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        size_t n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        UnionFind uf(maxNum + n + 1);

        for (int i = 0; i < n; i++)
        {
            for (int j : prime_factors[nums[i]])
                uf.unite(i, j + n);
        }

        unordered_set<int> set;

        for (int i = 0; i < n; i++)
            set.insert(uf.find(i));

        return set.size() == 1;
    }
};