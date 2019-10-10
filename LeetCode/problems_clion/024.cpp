//
// Created by Chaopeng Zhang on 2019-08-20.
//
#include "head.h"

class Solution {
public:
    void swapPoint(ListNode **p1, ListNode **p2) {
        ListNode *temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }

    void swapNode(ListNode *p1, ListNode *p2) {
        ListNode *temp = p2->next;
        p2->next = p1;
        p1->next = temp;
    }
//遍历
//    ListNode *swapPairs(ListNode *head) {
//        if (!head)
//            return nullptr;
//        ListNode *p1 = head;
//        ListNode *p2 = p1->next;
//        if (!p2)//only one node
//            return head;
//        //at least two nodes
//        swapNode(p1, p2);
//        ListNode *ans = p2;
//        swapPoint(&p1, &p2);
//        ListNode* pre = p2;
//        while (p2->next) {
//            p2 = p2->next;
//            if(!p2->next)
//                break;
//            p2 = p2->next;
//            p1 = p1->next->next;
//            pre->next = p2;
//            swapNode(p1,p2);
//            swapPoint(&p1,&p2);
//            pre = p2;
//        }
//        return ans;
//    }

    //递归
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *ans = head->next;
        head->next = swapPairs(ans->next);
        ans->next = head;
        return ans;
    }
};