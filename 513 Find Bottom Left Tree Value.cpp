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
    int findBottomLeftValue(TreeNode *root)
    {
        int depth = 0;
        int ans = 0;

        if (!root->left && !root->right)
            return root->val;

        helper(root, 0, depth, ans);
        return ans;
    }

private:
    void helper(TreeNode *node, int curDepth, int &depth, int &ans)
    {
        if (!node)
            return;

        if (curDepth > depth)
        {
            ans = node->val;
            depth = curDepth;
        }

        helper(node->left, curDepth + 1, depth, ans);
        helper(node->right, curDepth + 1, depth, ans);
    }
};

// class Solution
// {
// public:
//     int findBottomLeftValue(TreeNode *root)
//     {
//         if (!root->left && !root->right)
//             return root->val;

//         TreeNode *node;
//         queue<TreeNode *> q;
//         q.push(root);

//         while (q.size())
//         {
//             node = q.front();
//             q.pop();

//             if (node->right)
//                 q.push(node->right);
//             if (node->left)
//                 q.push(node->left);
//         }

//         return node->val;
//     }
// };