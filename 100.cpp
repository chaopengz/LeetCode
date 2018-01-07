//
// Created by cpz on 2018/1/7.
//
#include "head.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (p && q)
        {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else
            return false;
    }
};
