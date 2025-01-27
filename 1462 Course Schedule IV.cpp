#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<bool> ans;
        vector<vector<bool>> isPrereqisite(numCourses, vector<bool>(numCourses));

        for (const auto &prereqisite : prerequisites)
        {
            const int u = prereqisite[0];
            const int v = prereqisite[1];
            isPrereqisite[u][v] = true;
        }

        for (int k = 0; k < numCourses; ++k)
        {
            for (int i = 0; i < numCourses; ++i)
            {
                for (int j = 0; j < numCourses; ++j)
                {
                    isPrereqisite[i][j] = isPrereqisite[i][j] || (isPrereqisite[i][k] && isPrereqisite[k][j]);
                }
            }
        }

        ans.reserve(queries.size());
        for (const auto &query : queries)
        {
            const int u = query[0];
            const int v = query[1];
            ans.push_back(isPrereqisite[u][v]);
        }

        return ans;
    }
};