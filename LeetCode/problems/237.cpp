//
// Created by chaopengz on 2017/12/11.
//

#include "head.h"

class Solution {
public:
    void deleteNode(ListNode *node)
    {
        *node = *node->next;
    }
};