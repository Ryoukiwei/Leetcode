#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        size_t m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (helper(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

private:
    bool helper(vector<vector<char>> &board, const string &word, int i, int j, int k)
    {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return false;

        if (board[i][j] != word[k] || board[i][j] == '@')
            return false;

        if (k == word.length() - 1)
            return true;

        const char temp = board[i][j];
        board[i][j] = '@';
        const bool isExist = helper(board, word, i + 1, j, k + 1) ||
                             helper(board, word, i - 1, j, k + 1) ||
                             helper(board, word, i, j + 1, k + 1) ||
                             helper(board, word, i, j - 1, k + 1);

        board[i][j] = temp;

        return isExist;
    }
};