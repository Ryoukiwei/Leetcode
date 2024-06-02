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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);

        m_val = val;
        m_depth = depth;
        dfs(root, 1);
        return root;
    }

private:
    int m_val, m_depth;

    void dfs(TreeNode *node, int curDepth)
    {
        if (!node)
            return;

        if (curDepth == m_depth - 1)
        {
            node->left = new TreeNode(m_val, node->left, nullptr);
            node->right = new TreeNode(m_val, nullptr, node->right);
            return;
        }

        dfs(node->left, curDepth + 1);
        dfs(node->right, curDepth + 1);
    }
};

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);

        queue<TreeNode *> q{{root}};
        int cur = 0;

        while (!q.empty())
        {
            ++cur;
            const size_t n = q.size();
            for (size_t i = n; i > 0; --i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (cur == depth - 1)
                {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }
            }
        }

        return root;
    }
};