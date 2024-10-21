#include <string>
#include <string_view>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        size_t ans = 0;
        helper(s, 0, {}, ans);
        return ans;
    }

private:
    void helper(const string &s, int start, unordered_set<string_view> &&seen, size_t &ans)
    {
        const int len = s.length();
        if (start == len)
        {
            ans = max(ans, seen.size());
            return;
        }

        for (int i = 1; start + i <= len; ++i)
        {
            string_view candidate(s.data() + start, i);
            if (seen.find(candidate) == seen.end())
            {
                seen.insert(candidate);
                helper(s, start + i, move(seen), ans);
                seen.erase(candidate);
            }
        }
    }
};