#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        for (const char c : letters)
        {
            ++cnt[c - 'a'];
        }

        return helper(words, 0, score);
    }

private:
    array<int, 26> cnt = {};

    int helper(const vector<string> &words, int start, const vector<int> &score)
    {
        const int n = words.size();
        int ans = 0;

        for (int i = start; i < n; ++i)
        {
            const int totalGet = pick(words, i, score);
            if (totalGet > 0)
                ans = max(ans, totalGet + helper(words, i + 1, score));
            restore(words, i);
        }

        return ans;
    }

    int pick(const vector<string> &words, int i, const vector<int> &score)
    {
        bool valid = true;
        int totalGet = 0;

        for (const char c : words[i])
        {
            if (--cnt[c - 'a'] < 0)
                valid = false;
            totalGet += score[c - 'a'];
        }

        return valid ? totalGet : -1;
    }

    void restore(const vector<string> &words, int i)
    {
        for (const char c : words[i])
        {
            ++cnt[c - 'a'];
        }
    }
};