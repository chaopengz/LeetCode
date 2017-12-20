//
// Created by chaopengz on 2017/12/21.
//

#include "head.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> v;
        bool even = false;
        queue<TreeNode *> qNode;
        TreeNode *node;
        int len;
        if (!root)
            return vector<vector<int>>();
        qNode.push(root);
        while (!qNode.empty())
        {
            v.clear();
            len = qNode.size();
            for (int i = 0; i < len; ++i)
            {
                node = qNode.front();
                qNode.pop();
                v.push_back(node->val);
                if (node->left)
                    qNode.push(node->left);
                if (node->right)
                    qNode.push(node->right);
            }
            if (even)
            {
                reverse(v.begin(), v.end());
            }
            even = !even;
            ans.push_back(v);
        }

        return ans;
    }
};