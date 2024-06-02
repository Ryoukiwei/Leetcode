#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int i = 0, j = tokens.size() - 1;
        int ans = 0, temp = 0;

        sort(tokens.begin(), tokens.end());

        while (i <= j)
        {
            while (i <= j && tokens[i] <= power)
            {
                power -= tokens[i++];
                ans = max(ans, ++temp);
            }

            if (i > j || !temp)
                break;

            --temp;
            power += tokens[j--];
        }

        return ans;
    }
};