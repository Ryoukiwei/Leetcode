#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<string>> board)
{
    for (auto &r : board)
    {
        for (auto &c : r)
        {
            cout << c << "\n";
        }
        cout << "____\n____\n";
    }
}

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<int> move(n, -1);
        solveNQueens_helper(move, 0, n, result);

        return result;
    }

private:
    bool isVaild(vector<int> &move, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            // same col or on the diagonal
            if (move[i] == col || abs(move[i] - col) == abs(i - row))
                return false;
        }

        return true;
    }

    void solveNQueens_helper(vector<int> &move, int row, int n, vector<vector<string>> &result)
    {
        if (n == 0 || n == 2)
            return;

        if (n == 1)
        {
            result.push_back({"Q"});
            return;
        }

        if (row == n)
        {
            vector<string> board(n, string(n, '.')); // set board

            for (int i = 0; i < n; i++)
            {
                string &temp = board[i];
                temp.replace(move[i], 1, "Q");
            }

            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isVaild(move, row, col))
            {
                move[row] = col;
                solveNQueens_helper(move, row + 1, n, result);
                // backtracking
                move[row] = -1;
            }
        }
    }
};

int main()
{
    Solution solution;
    int n = 4;

    vector<vector<string>> solutions = solution.solveNQueens(n);
    printBoard(solutions);

    return 0;
}