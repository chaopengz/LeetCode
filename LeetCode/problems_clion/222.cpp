//
// Created by cpz on 2019-09-17.
//
#include "head.h"

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        vector<int> path;
        countNodesHelper(root, path);
        int ans = 1;
        for (auto i:path)
        {
            if (i == 0)
                ans *= 2;
            else
                ans = 2 * ans + 1;
        }
        return ans;
    }

    void countNodesHelper(TreeNode *root, vector<int> &path)
    {
        int l_h = getHeight(root->left);
        int r_h = getHeight(root->right);

        //leaf node
        if (l_h == 0 && r_h == 0)
            return;

        if (l_h > r_h)
        {
            path.push_back(0);
            countNodesHelper(root->left, path);
        } else
        {
            path.push_back(1);
            countNodesHelper(root->right, path);
        }

    }

    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return getHeight(root->left) + 1;
    }

};