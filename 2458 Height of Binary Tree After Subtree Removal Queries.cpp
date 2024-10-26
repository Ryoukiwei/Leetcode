#include <vector>
#include <cstring>
#include <algorithm>
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
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        memset(heightAfterRemove, 0, sizeof(heightAfterRemove));
        memset(heightInit, 0, sizeof(heightInit));
        dfs(root, 0, 0);
        vector<int> ans;

        for (int query : queries)
        {
            ans.push_back(heightAfterRemove[query]);
        }

        return ans;
    }

private:
    int heightInit[100001];
    int heightAfterRemove[100001];

    void dfs(TreeNode *node, int level, int height)
    {
        if (!node)
            return;
        heightAfterRemove[node->val] = height;
        dfs(node->left, level + 1, max(height, level + getHeight(node->right)));
        dfs(node->right, level + 1, max(height, level + getHeight(node->left)));
    }

    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;
        if (heightInit[node->val])
            return heightInit[node->val];
        return heightInit[node->val] = max(getHeight(node->left), getHeight(node->right)) + 1;
    }
};