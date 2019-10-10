//
// Created by laryzhang on 2019/3/26.
//

#include "head.h"

class Solution
{
public:
    TreeNode *buildTreeHelp(vector<int> &inorder, vector<int> &postorder, int start_i, int start_j, int len)
    {
        if (len <= 0)
            return nullptr;
        int root_val = postorder[start_j + len - 1];
        TreeNode *root = new TreeNode(root_val);
        int k = start_i;
        int num = 0;
        while (inorder[k] != root_val)
        {
            k++;
            num++;
        }

        root->left = buildTreeHelp(inorder, postorder, start_i, start_j, num);

        root->right = buildTreeHelp(inorder, postorder, k + 1, start_j + num, len - num - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        return buildTreeHelp(inorder, postorder, 0, 0, inorder.size());
    }
};