//
// Created by chaopengz on 2017/12/21.
//

#include "head.h"


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        queue<TreeLinkNode *> qNode;
        TreeLinkNode *node;
        if (!root)
            return;
        qNode.push(root);
        int len;
        while (!qNode.empty())
        {
            len = qNode.size();
            for (int i = 0; i < len; ++i)
            {
                node = qNode.front();
                qNode.pop();

                if (!qNode.empty())
                    node->next = qNode.front();

                if (node->left)
                    qNode.push(node->left);
                if (node->right)
                    qNode.push(node->right);

            }
            node->next = nullptr;
        }
    }
};