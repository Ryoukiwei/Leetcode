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
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> temp;
        toVector(root, temp);
        return rebuild(temp.begin(), temp.end());
    }

private:
    void toVector(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;

        toVector(root->left, vec);
        vec.emplace_back(root->val);
        toVector(root->right, vec);
    }

    TreeNode *rebuild(vector<int>::iterator begin, vector<int>::iterator end)
    {
        if (!(begin < end))
            return nullptr;

        auto mid = begin + (end - begin) / 2;
        TreeNode *node = new TreeNode(*mid, rebuild(begin, mid), rebuild(mid + 1, end));

        return node;
    }
};