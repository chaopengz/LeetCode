
//
// Created by chaopengz on 2017/10/20.
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *l, *p;
        l = new ListNode(0);
        while (head != nullptr)
        {
            p = new ListNode(head->val);

            p->next = l->next;
            l->next = p;

            head = head->next;
        }
        return l->next;
    }
};