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
    int distributeCoins(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        const int l = dfs(root->left, ans);
        const int r = dfs(root->right, ans);
        ans += abs(l) + abs(r);

        return root->val + l + r - 1;
    }
};