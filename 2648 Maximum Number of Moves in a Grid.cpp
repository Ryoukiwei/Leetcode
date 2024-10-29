#include <vector>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid.begin()->size();
        bitset<1001> curr, next;

        for (int i = 0; i < m; ++i)
        {
            curr.set(i);
        }

        for (int j = 0; j < n - 1; ++j)
        {
            next.reset();
            for (int i = 0; i < m; ++i)
            {
                if (curr[i])
                {
                    for (int k = i - 1; k <= i + 1; ++k)
                    {
                        if (k >= 0 && k < m && grid[i][j] < grid[k][j + 1])
                            next.set(k);
                    }
                }
            }

            if (next.none())
                return j;

            curr = next;
        }

        return n - 1;
    }
};