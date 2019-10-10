//
// Created by cpz on 2019-09-11.
//
#include "head.h"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT32_MIN;
        maxRootSum(root, ans);
        return ans;
    }

    int maxRootSum(TreeNode *node, int &ans)
    {
        if (!node) return 0;
        int l = max(0, maxRootSum(node->left, ans));
        int r = max(0, maxRootSum(node->right, ans));

        ans = max(ans, l + r + node->val);

        return max(l, r) + node->val;

    }
};