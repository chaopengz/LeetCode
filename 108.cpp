//
// Created by cpz on 2017/12/14.
//

#include "head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int len = nums.size();
        if (!len)
            return nullptr;
        TreeNode *root = buildBSTree(nums, 0, len - 1);
        return root;
    }

    TreeNode *buildBSTree(vector<int> nums, int i, int j)//build between [i...k]
    {
        int mid = (i + j) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        if (mid > i)
            node->left = buildBSTree(nums, i, mid - 1);
        if (mid < j)
            node->right = buildBSTree(nums, mid + 1, j);
        return node;
    }
};