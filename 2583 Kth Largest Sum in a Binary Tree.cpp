#include <queue>
#include <vector>
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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long> levelSums;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            long levelSum = 0;

            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            levelSums.push_back(levelSum);
        }

        if (levelSums.size() < k)
            return -1;

        nth_element(levelSums.begin(), levelSums.begin() + k - 1, levelSums.end(), greater<>());

        return levelSums[k - 1];
    }
};