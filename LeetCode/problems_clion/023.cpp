//
// Created by chaopengz on 2017/10/13.
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int INF = 2147483647;
        int Min;
        vector<vector<int>> vv;
        int len = lists.size();
        ListNode *p;
        int allNodes = 0;

        for (int i = 0; i < len; ++i)
        {
            vector<int> v;
            p = lists[i];
            while (p)
            {
                v.push_back(p->val);
                p = p->next;
            }
            v.push_back(INF);
            vv.push_back(v);
            allNodes += (v.size() - 1);
        }
        vector<int> index;
        for (int j = 0; j < len; ++j)
        {
            index.push_back(0);
        }
        int recoderIndex;
        ListNode *res = nullptr, *pre = nullptr;
        ListNode *pNode;
        for (int k = 0; k < allNodes; ++k)
        {
            Min = INF;
            for (int i = 0; i < len; ++i)
            {
                //找出最小的值
                if (vv[i][index[i]] < Min)
                {
                    Min = vv[i][index[i]];
                    //记录最小值所在的行
                    recoderIndex = i;
                }
            }

            pNode = new ListNode(Min);
            index[recoderIndex]++;
            if (res)
            {
                pre->next = pNode;
                pre = pNode;

            } else
            {
                res = pNode;
                pre = res;
            }
        }
        return res;
    }
};