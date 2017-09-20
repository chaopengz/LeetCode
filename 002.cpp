//
// Created by chaopengz on 2017/9/12.
//

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *res, *node, *pre;
        int jinwei = 0;
        int sum = l1->val + l2->val + jinwei;
        jinwei = sum / 10;
        res = new ListNode(sum % 10);
        pre = res;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            sum = l1->val + l2->val + jinwei;
            node = new ListNode(sum % 10);
            pre->next = node;
            jinwei = sum / 10;;
            pre = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        // l1,l2都为空了，如[5]+[5]
        if ((!l1) && (!l2)) {
            if (jinwei) {
                node = new ListNode(1);
                pre->next = node;
            }
        } else {
            if (l1) {
                while (jinwei && l1) {
                    sum = l1->val + 1;
                    node = new ListNode(sum % 10);
                    jinwei = sum / 10;
                    pre->next = node;
                    pre = node;
                    l1 = l1->next;
                }
                if (jinwei) {
                    node = new ListNode(1);
                    pre->next = node;
                } else {
                    pre->next = l1;
                }

            } else {
                while (jinwei && l2) {
                    sum = l2->val + 1;
                    node = new ListNode(sum % 10);
                    jinwei = sum / 10;
                    pre->next = node;
                    pre = node;
                    l2 = l2->next;
                }
                if (jinwei) {
                    node = new ListNode(1);
                    pre->next = node;
                } else {
                    pre->next = l2;
                }
            }
        }
        return res;
    }
};