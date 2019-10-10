//
// Created by cpz on 2019-09-09.
//
#include "head.h"

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k <= 0)
            return nullptr;
        int cnt = 0;
        for (ListNode *i = head; i; i = i->next, cnt++);

        ListNode *ans = new ListNode(0);
        ans->next = head;
        ListNode *pre = ans;
        ListNode *tail = head;
        for (; cnt >= k; cnt -= k)
        {
            for (int i = 1; i < k; ++i)
            {
                ListNode *next = tail->next->next;
                tail->next->next = pre->next;
                pre->next = tail->next;
                tail->next = next;
            }
            pre = tail;
            tail = tail->next;
        }
        return ans->next;
    }
};

