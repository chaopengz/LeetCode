//
// Created by cpz on 2017/11/28.
//
#include "head.h"

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len <= 1)
            return 0;
        vector<int> s0;
        vector<int> s1;
        vector<int> s2;

        s0.push_back(0);
        s1.push_back(-prices[0]);
        s2.push_back(INT_MIN);

        for (int i = 1; i < len; ++i)
        {
            s0.push_back(max(s0[i - 1], s2[i - 1]));
            s1.push_back(max(s0[i - 1] - prices[i], s1[i - 1]));
            s2.push_back(s1[i - 1] + prices[i]);
        }
        return max(s0[len - 1], s2[len - 1]);
    }
};