//
// Created by chaopengz on 2017/11/16.
//
#include "head.h"

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for(auto i:nums)
            sum += i;
        int cols = 2*sum+1;
        if (S > sum)
            return 0;

        int dp[20][2005];
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < cols; ++j)
        {
            if (!nums[0])//第一个为0,则dp[0][1000]有两个解，正0和负0
                dp[0][sum] = 2;
            else if (j == nums[0] + sum || j == -nums[0] + sum)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout<<"j-nums[i] "<<j - nums[i]<<" j + nums[i] "<<j + nums[i]<<endl;
                dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]];
            }
        }

        return dp[nums.size() - 1][sum+S];
    }
};






