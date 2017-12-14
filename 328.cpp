//
// Created by cpz on 2017/12/14.
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *currentNode = head, *nextNode;
        ListNode *secondNode = head->next;
        int count = 0;
        while (true)
        {
            count++;
            nextNode = currentNode->next;//先把下个节点保存起来

            if (count % 2)//奇
            {
                if (currentNode->next && currentNode->next->next)//不是最后一个奇节点
                {
                    currentNode->next = currentNode->next->next;
                } else//最后一个奇节点
                {
                    currentNode->next = secondNode;
                    break;
                }
            } else//偶
            {
                if (currentNode->next && currentNode->next->next)//不是最后一个偶节点
                    currentNode->next = currentNode->next->next;
                else//最后一个偶数节点
                    currentNode->next = nullptr;
            }
            currentNode = nextNode;
        }
        return head;
    }
};
