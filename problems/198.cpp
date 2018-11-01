//
// Created by chaopengz on 2017/10/21.
//

#include "head.h"

class Solution {
public:
    int rob(vector<int> &nums)
    {

        int len = nums.size();
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        for (int i = 2; i < len + 2; ++i)
        {
            dp.push_back(max(dp[i - 2] + nums[i - 2], dp[i - 1]));
        }
        return dp[len + 1];
    }
};