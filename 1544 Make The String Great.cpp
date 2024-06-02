#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string ans;
        ans.reserve(s.size());

        auto notGood = [](const char a, const char b)
        {
            return toupper(a) == toupper(b) && a != b;
        };

        for (const char c : s)
        {
            if (!ans.empty() && notGood(ans.back(), c))
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};

// class Solution
// {
// public:
//     string makeGood(string s)
//     {
//         auto it = s.begin();

//         while (it != s.end())
//         {
//             if (next(it) != s.end() && abs(*it - *next(it)) == 32)
//             {
//                 it = s.erase(it, next(it, 2));
//                 if (it != s.begin())
//                     --it;
//             }
//             else
//                 ++it;
//         }

//         return s;
//     }
// };