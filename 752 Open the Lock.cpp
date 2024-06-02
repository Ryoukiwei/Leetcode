#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int openLock(vector<string> &deadends, string target)
//     {
//         unordered_set<string> visited(deadends.begin(), deadends.end());
//         if (visited.count("0000"))
//             return -1;
//         if (target == "0000")
//             return 0;

//         int ans = 0;
//         queue<string> q{{"0000"}};

//         while (!q.empty())
//         {
//             ++ans;
//             size_t qsize = q.size();
//             while (qsize--)
//             {
//                 string lock = q.front();
//                 q.pop();

//                 for (char &wheel : lock)
//                 {
//                     const char temp = wheel;
//                     wheel = (wheel == '9') ? '0' : wheel + 1;
//                     if (lock == target)
//                         return ans;
//                     if (!visited.count(lock))
//                     {
//                         q.push(lock);
//                         visited.insert(lock);
//                     }

//                     wheel = temp;
//                     wheel = (wheel == '0') ? '9' : wheel - 1;
//                     if (lock == target)
//                         return ans;
//                     if (!visited.count(lock))
//                     {
//                         q.push(lock);
//                         visited.insert(lock);
//                     }

//                     wheel = temp;
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution
{
public:
    int openLock(vector<string> &deadends, const string &target)
    {
        bitset<10000> visited = 0;
        for (const string &s : deadends)
        {
            visited[stoi(s)] = 1;
        }

        if (visited[0])
            return -1;

        array<int, 4> bases = {1, 10, 100, 1000};

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0] = 1;
        const int goal = stoi(target);

        while (!q.empty())
        {
            auto [turn, cur] = q.front();
            q.pop();

            if (cur == goal)
                return turn;

            int digit, t = cur;
            for (int d = 0; d < 4; ++d)
            {
                digit = t % 10;
                t /= 10;
                for (const int i : {-1, 1})
                {
                    int dnext = (digit + i + 10) % 10;
                    int next = cur + (dnext - digit) * bases[d];
                    if (!visited[next])
                    {
                        q.emplace(turn + 1, next);
                        visited[next] = 1;
                    }
                }
            }
        }

        return -1;
    }
};
