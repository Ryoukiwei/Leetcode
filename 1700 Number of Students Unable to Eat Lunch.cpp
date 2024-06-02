#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        array<int, 2> cnt = {0};

        for (const int student : students)
        {
            ++cnt[student];
        }

        auto swbegin = sandwiches.begin(), swend = sandwiches.end();
        for (auto it = swbegin; it != swend; ++it)
        {
            if (!cnt[*it])
                return swend - it;
            --cnt[*it];
        }

        return 0;
    }
};
