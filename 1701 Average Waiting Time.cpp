#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double waiting = 0, curr = 0;
        for (const auto &customer : customers)
        {
            curr = max(curr, customer.front() * 1.0) + customer.back();
            waiting += curr - customer.front();
        }

        return waiting / customers.size();
    }
};