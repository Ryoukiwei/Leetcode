#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        const int n = skill.size();
        const int maxTeamSkill = accumulate(skill.begin(), skill.end(), 0LL) * 2 / n;
        const int maxSkillVal = *max_element(skill.begin(), skill.end());
        long long ans = 0;

        vector<int> cnt(maxSkillVal + 1);

        for (int s : skill)
        {
            ++cnt[s];
        }

        for (int skill_i = 1; skill_i <= maxSkillVal; ++skill_i)
        {
            while (cnt[skill_i] > 0)
            {
                const int skill_j = maxTeamSkill - skill_i;
                if (skill_j < 1 || skill_j > maxSkillVal || cnt[skill_j] <= 0)
                    return -1;

                ans += static_cast<long long>(skill_i) * skill_j;
                --cnt[skill_i];
                --cnt[skill_j];
            }
        }

        return ans;
    }
};
