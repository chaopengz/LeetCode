//
// Created by cpz on 2018/1/7.
//

#include "head.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        else
            return hasPathSumHelp(root, sum);
    }

    bool hasPathSumHelp(TreeNode *root, int sum)
    {
        if (!root)
            return sum == 0;
        else
            return hasPathSumHelp(root->left, sum - root->val)
                   || hasPathSumHelp(root->right, sum - root->val);
    }
};