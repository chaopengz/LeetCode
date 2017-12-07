//
// Created by chaopengz on 2017/10/20.
//

#include "head.h"

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        int minN = prices[0], maxN = INT32_MIN;

        for (int i = 1; i < len; ++i)
        {
            minN = min(minN, prices[i - 1]);
            maxN = max(prices[i] - minN, maxN);
        }
        return max(maxN, 0);
    }
};