//
// Created by chaopengz on 2017/10/23.
//
#include "head.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *p1 = head;//跑得慢
        ListNode *p2 = head;//跑得快

        while (p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)//类似跑操场，跑得快得肯定会追上跑得慢的，快一圈相遇
                return true;
        }
        return false;

    }
};