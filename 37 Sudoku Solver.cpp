#include <bits/stdc++.h>
using namespace std;
using table = vector<vector<char>>;

class Solution
{
public:
    void solveSudoku(table &board)
    {
        sudokuHelper(board, 0, 0);
    }

private:
    bool sudokuHelper(table &board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j >= 9)
            return sudokuHelper(board, i + 1, 0);

        if (board[i][j] != '.')
            return sudokuHelper(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++)
        {
            if (isVaild(board, i, j, c))
            {
                board[i][j] = c;

                if (sudokuHelper(board, i, j + 1))
                    return true;

                board[i][j] = '.';
            }
        }

        return false;
    }

    bool isVaild(table &board, int i, int j, char c)
    {
        bool colCheck = any_of(board[i].begin(), board[i].end(), [c](char x)
                               { return x == c; });
        bool rowCheck = any_of(board.begin(), board.end(), [j, c](const auto &row)
                               { return row[j] == c; });

        if (colCheck || rowCheck)
            return false;

        int row = i - i % 3, col = j - j % 3;
        return !any_of(board.begin() + row, board.begin() + row + 3, [col, c](const auto &row)
                       { return any_of(row.begin() + col, row.begin() + col + 3, [c](char x)
                                       { return x == c; }); });
    }
};