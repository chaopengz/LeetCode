//
// Created by chaopengz on 2017/12/9.
//
#include "head.h"

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (!len)
            return 0;
        int ans = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (prices[i + 1] > prices[i])
                ans += prices[i + 1] - prices[i];
        }
        return ans;

    }
};