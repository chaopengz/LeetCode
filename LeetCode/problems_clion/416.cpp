//
// Created by chaopengz on 2017/12/1.
//
#include "head.h"

class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int len = nums.size();

        for (auto i:nums)
            sum += i;

        sort(nums.begin(), nums.end());

        if (sum % 2)
            return false;


        vector<vector<bool>> dp(len, vector<bool>(len * 100 + 1, false));

        dp[0][0] = true;
        dp[0][nums[0]] = true;

        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = 0; j <= len * 100; ++j)
            {
                if (dp[i][j])
                {
                    dp[i + 1][j] = true;
                    dp[i + 1][j + nums[i + 1]] = true;
                }
            }
        }

        int target = sum / 2;
        return dp[len - 1][target];

    }


};