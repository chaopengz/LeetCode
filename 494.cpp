//
// Created by chaopengz on 2017/11/16.
//
#include "head.h"

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int N = 20000;
        vector<vector<int>> dp;
        dp.resize(20, vector<int>(N));

        for (int j = -N/2; j < N/2; ++j)
        {
            if (!nums[0])//第一个为0,则dp[0][1000]有两个解，正0和负0
                dp[0][0] = 2;
            else if (j == nums[0] || j == -nums[0])
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]];
            }
        }
        return dp[nums.size() - 1][S];
    }
};