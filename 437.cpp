//
// Created by chaopengz on 2017/11/29.
//
#include "head.h"

class Solution {
public:
    int pathSumFromNode(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        return (root->val == sum ? 1 : 0) + pathSumFromNode(root->left, sum - root->val) +
               pathSumFromNode(root->right, sum - root->val);

    }

    int pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        return pathSumFromNode(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};