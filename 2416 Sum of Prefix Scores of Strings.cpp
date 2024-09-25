#include <bits/stdc++.h>
using namespace std;

// class TrieNode
// {
// public:
//     array<TrieNode *, 26> children;
//     int cnt;

//     TrieNode() : cnt(0)
//     {
//         children.fill(nullptr);
//     }
// };

// class Trie
// {
// public:
//     Trie() : root(new TrieNode()) {}

//     void insert(const string &word)
//     {
//         TrieNode *node = root;
//         for (char c : word)
//         {
//             const int i = c - 'a';
//             if (!node->children[i])
//                 node->children[i] = new TrieNode();

//             node = node->children[i];
//             ++node->cnt;
//         }
//     }

//     int getScore(const string &word)
//     {
//         TrieNode *node = root;
//         int score = 0;

//         for (char c : word)
//         {
//             const int i = c - 'a';
//             if (!node->children[i])
//                 break;

//             node = node->children[i];
//             score += node->cnt;
//         }

//         return score;
//     }

// private:
//     TrieNode *root;
// };

// class Solution
// {
// public:
//     vector<int> sumPrefixScores(vector<string> &words)
//     {
//         Trie trie;

//         for (const auto &word : words)
//         {
//             trie.insert(word);
//         }

//         vector<int> ans;
//         ans.reserve(words.size());
//         for (const auto &word : words)
//         {
//             ans.emplace_back(trie.getScore(word));
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        const int n = words.size();
        vector<int> ans(n);

        vector<pair<string, int>> wordPairs;
        for (int i = 0; i < n; ++i)
        {
            wordPairs.emplace_back(words[i], i);
        }

        sort(wordPairs.begin(), wordPairs.end());

        calculateScores(wordPairs, ans, n);

        reverse(wordPairs.begin(), wordPairs.end());
        calculateScores(wordPairs, ans, n);

        for (const auto &wp : wordPairs)
        {
            ans[wp.second] += wp.first.size();
        }

        return ans;
    }

private:
    void calculateScores(const vector<pair<string, int>> &wordPairs, vector<int> &ans, int n)
    {
        vector<int> dp(wordPairs.begin()->first.size());

        for (int i = 1; i < n; ++i)
        {
            const string &prev = wordPairs[i - 1].first;
            const string &curr = wordPairs[i].first;
            int idx = wordPairs[i].second;

            vector<int> ndp(curr.size());
            const int m = min(prev.size(), curr.size());

            for (int j = 0; j < m; ++j)
            {
                if (curr[j] != prev[j])
                    break;

                ndp[j] = dp[j] + 1;
                ans[idx] += ndp[j];
            }

            dp = move(ndp);
        }
    }
};
