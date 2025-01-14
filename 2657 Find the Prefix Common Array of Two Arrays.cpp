#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        const int n = A.size();
        vector<int> cnt(n + 1);
        vector<int> ans;
        ans.reserve(n);

        for (int i = 0, prefix = 0; i < n; ++i)
        {
            if (++cnt[A[i]] == 2)
                ++prefix;
            if (++cnt[B[i]] == 2)
                ++prefix;
            ans.push_back(prefix);
        }

        return ans;
    }
};