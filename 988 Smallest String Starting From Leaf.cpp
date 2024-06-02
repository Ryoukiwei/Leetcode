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
    string smallestFromLeaf(TreeNode *root)
    {
        string ans;
        dfs(root, "", ans);
        return ans;
    }

private:
    void dfs(TreeNode *node, string &&path, string &ans)
    {
        if (!node)
            return;

        path.push_back(node->val + 'a');

        if (!node->left && !node->right)
        {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans)
                ans = path;
            reverse(path.begin(), path.end());
        }

        dfs(node->left, move(path), ans);
        dfs(node->right, move(path), ans);
        path.pop_back();
    }
};

class Solution
{
public:
    string smallestFromLeaf(TreeNode *root)
    {
        return dfs(root, "");
    }

private:
    string dfs(TreeNode *node, string path)
    {
        if (!node)
            return path + static_cast<char>(26 + 'a');

        path.push_back(node->val + 'a');

        if (!node->left && !node->right)
            return path;

        string left = dfs(node->left, path);
        string right = dfs(node->right, path);

        return min(left, right);
    }
};