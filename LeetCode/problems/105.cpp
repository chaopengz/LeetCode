//
// Created by laryzhang on 2019/3/26.
//
#include "head.h"

class Solution
{
public:
    TreeNode *buildTreeHelp(vector<int> &preorder, vector<int> &inorder, int start_i, int start_j, int len)
    {
        if (len <= 0)
            return nullptr;
        int root_val = preorder[start_i];
        TreeNode *root = new TreeNode(root_val);
        int k = start_j;
        int num = 0;
        while (inorder[k] != root_val)
        {
            k++;
            num++;
        }

        root->left = buildTreeHelp(preorder, inorder, start_i + 1, start_j, num);

        root->right = buildTreeHelp(preorder, inorder, start_i + num + 1, k + 1, len - num - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        return buildTreeHelp(preorder, inorder, 0, 0, preorder.size());
    }
};