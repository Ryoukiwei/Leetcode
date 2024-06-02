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
    int deepestLeavesSum(TreeNode *root)
    {
        int ans = 0, maxDepth = 0;
        dfs(root, 0, maxDepth, ans);
        return ans;
    }

private:
    void dfs(TreeNode *node, int depth, int &maxDepth, int &ans)
    {
        if (!node)
            return;

        if (depth > maxDepth)
        {
            maxDepth = depth;
            ans = node->val;
        }
        else if (depth == maxDepth)
            ans += node->val;

        dfs(node->left, depth + 1, maxDepth, ans);
        dfs(node->right, depth + 1, maxDepth, ans);
    }
};

// class Solution
// {
// public:
//     int deepestLeavesSum(TreeNode *root)
//     {

//         targetDepth = maxDepth(root);
//         return dfs(root, 1);
//     }

// private:
//     int targetDepth;

//     int maxDepth(TreeNode *node)
//     {
//         if (!node)
//             return 0;
//         return 1 + max(maxDepth(node->left), maxDepth(node->right));
//     }

//     int dfs(TreeNode *node, int depth)
//     {
//         if (!node)
//             return 0;

//         if (depth == targetDepth)
//             return node->val;

//         return dfs(node->left, depth + 1) + dfs(node->right, depth + 1);
//     }
// };
