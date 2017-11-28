//
// Created by cpz on 2017/11/28.
//
#include "head.h"

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        else if (s && t)
        {
            if (s->val != t->val)
                return isSubtree(s->left, t) || isSubtree(s->right, t);
            else
                return (isSameTree(s->left, t->left) && isSameTree(s->right, t->right)) ||
                       (isSubtree(s->left, t) || isSubtree(s->right, t));
        } else
            return false;
    }

    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        else if (s && t)
        {
            if (s->val == t->val)
                return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
            else
                return false;
        } else
            return false;
    }
};