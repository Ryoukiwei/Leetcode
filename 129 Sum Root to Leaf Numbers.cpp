#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

private:
    void dfs(TreeNode *node, int prevPath, int &ans)
    {
        if (!node)
            return;

        const int cur = prevPath * 10 + node->val;

        if (!node->left && !node->right)
        {
            ans += cur;
            return;
        }

        dfs(node->left, cur, ans);
        dfs(node->right, cur, ans);
    }
};