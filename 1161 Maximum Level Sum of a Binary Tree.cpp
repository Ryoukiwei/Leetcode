#include <vector>
#include <algorithm>
#include <iterator>
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
    int maxLevelSum(TreeNode *root)
    {
        vector<int> levelSums;
        dfs(root, 0, levelSums);
        return distance(levelSums.begin(), max_element(levelSums.begin(), levelSums.end())) + 1;
    }

private:
    void dfs(TreeNode *root, int level, vector<int> &levelSums)
    {
        if (!root)
            return;
        if (levelSums.size() == level)
            levelSums.emplace_back(0);

        levelSums[level] += root->val;

        dfs(root->left, level + 1, levelSums);
        dfs(root->right, level + 1, levelSums);
    }
};