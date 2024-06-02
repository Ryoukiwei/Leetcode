#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using Graph = unordered_map<string, unordered_map<string, double>>;
    using vvs = vector<vector<string>>;

public:
    vector<double> calcEquation(vvs &equations, vector<double> &values, vvs &queries)
    {
        vector<double> ans;
        ans.reserve(queries.size());

        auto val = values.begin();
        for (const auto &equation : equations)
        {
            const string &A = equation[0];
            const string &B = equation[1];
            graph[A].emplace(B, *val);
            graph[B].emplace(A, 1 / (*val));
            ++val;
        }

        for (const auto &query : queries)
        {
            const string &C = query[0];
            const string &D = query[1];

            if (graph.count(C) && graph.count(D))
                ans.emplace_back(calcVal(C, D, unordered_set<string>()));
            else
                ans.emplace_back(-1);
        }

        return ans;
    }

private:
    Graph graph;

    double calcVal(const string &A, const string &C, unordered_set<string> &&seen)
    {
        if (A == C)
            return 1.0;

        if (graph[A].count(C))
            return graph[A][C];

        seen.insert(A);

        for (const auto &[B, value] : graph[A])
        {
            if (seen.count(B))
                continue;

            const double sol = calcVal(B, C, move(seen));
            if (sol > 0.0)
                return value * sol;
        }

        return -1.0;
    }
};

class Solution
{
public:
    using Node = pair<string, double>;
    using Graph = unordered_map<string, Node>;
    using vvs = vector<vector<string>>;

public:
    vector<double> calcEquation(vvs &equations, vector<double> &values, vvs &queries)
    {
        vector<double> ans;
        ans.reserve(queries.size());

        auto val = values.begin();
        for (const auto &equation : equations)
        {
            const string &A = equation[0];
            const string &B = equation[1];

            if (!parents.count(A) && !parents.count(B))
            {
                parents.emplace(A, make_pair(B, *val));
                parents.emplace(B, make_pair(B, 1.0));
            }

            else if (!parents.count(A))
                parents.emplace(A, make_pair(B, *val));

            else if (!parents.count(B))
                parents.emplace(B, make_pair(A, 1.0 / (*val)));

            else
            {
                auto &rA = find(A);
                auto &rB = find(B);
                parents[rA.first] = make_pair(rB.first, (*val) / rA.second * rB.second);
            }

            ++val;
        }

        for (const auto &query : queries)
        {
            const string &C = query[0];
            const string &D = query[1];

            if (!(parents.count(C) && parents.count(D)))
            {
                ans.emplace_back(-1.0);
                continue;
            }
            auto &rC = find(C);
            auto &rD = find(D);

            if (rC.first != rD.first)
                ans.emplace_back(-1.0);
            else
                ans.emplace_back(rC.second / rD.second);
        }

        return ans;
    }

private:
    Graph parents;

    Node &find(const string &x)
    {
        if (x != parents[x].first)
        {
            const auto &p = find(parents[x].first);
            parents[x].first = p.first;
            parents[x].second *= p.second;
        }
        return parents[x];
    }
};