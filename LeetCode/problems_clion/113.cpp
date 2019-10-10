//
// Created by cpz on 2019-09-23.
//
#include "head.h"

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if(!root)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> v;
        dfs(root, sum, v, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int sum, vector<int> v, vector<vector<int>> &ans)
    {
        if (!root->left && !root->right)
        {
            if (root->val == sum)
            {
                v.push_back(root->val);
                ans.push_back(v);
            }
        } else
        {
            v.push_back(root->val);

            if (root->left)
                dfs(root->left, sum - root->val, v, ans);

            if (root->right)
                dfs(root->right, sum - root->val, v, ans);
        }
    }
};