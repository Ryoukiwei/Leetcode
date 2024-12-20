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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, true);
        return root;
    }

private:
    void dfs(TreeNode *lNode, TreeNode *rNode, bool isOddLevel)
    {
        if (!lNode)
            return;

        if (isOddLevel)
            swap(lNode->val, rNode->val);

        dfs(lNode->left, rNode->right, !isOddLevel);
        dfs(lNode->right, rNode->left, !isOddLevel);
    }
};