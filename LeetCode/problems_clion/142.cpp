//
// Created by cpz on 2019-09-18.
//

#include "head.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode *p1;
        p1 = hasCycle(head);
        if (!p1)
            return nullptr;
        else
        {
            //count n
            ListNode *p2 = p1->next;
            int cnt = 1;
            while (p2 != p1)
            {
                p2 = p2->next;
                cnt++;
            }

            p1 = head;
            p2 = head;
            while (cnt--)
            {
                p1 = p1->next;
            }
            while (p1 != p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }

    }

private:
    ListNode *hasCycle(ListNode *head)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p2->next && p2->next->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2)
                return p1;
        }
        return nullptr;
    }

};