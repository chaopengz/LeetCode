//
// Created by chaopengz on 2017/11/7.
//

#include "head.h"




class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        ans = max(countPath(root->left)+countPath(root->right)+1,ans);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return ans-1;
    }

    int countPath(TreeNode *root)//count root to leaft
    {
        if (!root)
            return 0;
        else
            return max(countPath(root->left), countPath(root->right)) + 1;

    }

    int ans = 0;
};