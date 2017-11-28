//
// Created by cpz on 2017/11/28.
//

#include "head.h"

class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        ans.clear();
        if (!root)
            return ans;
        queue<TreeNode *> tree;
        tree.push(root);
        int len;
        while (!tree.empty())
        {
            vector<int> v;
            len = tree.size();
            for (int i = 0; i < len; ++i)
            {
                TreeNode *node = tree.front();
                tree.pop();
                v.push_back(node->val);
                if (node->left)
                    tree.push(node->left);
                if (node->right)
                    tree.push(node->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};