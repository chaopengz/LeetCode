//
// Created by chaopengz on 2017/10/10.
//
#include "head.h"


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *l = nullptr, *node, *p;
        //有一个为空列表
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        //列表都非空
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                node = new ListNode(l1->val);
                if (l)
                {
                    p->next = node;
                    p = p->next;
                } else
                {
                    l = node;
                    p = l;
                }
                l1 = l1->next;
            } else
            {
                node = new ListNode(l2->val);
                if (l)
                {
                    p->next = node;
                    p = p->next;
                } else
                {
                    l = node;
                    p = l;
                }
                l2 = l2->next;
            }
        }

        //此时l1,l2至少有一个为空
        if (!l1 && !l2)
        {
            return l;
        } else if (!l1)
        {
            p->next = l2;
        } else
        {
            p->next = l1;
        }

        return l;
    }
};