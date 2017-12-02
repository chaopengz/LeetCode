//
// Created by chaopengz on 2017/12/2.
//

#include "head.h"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        if(!len)
            return 0;
        int ans = 1;
        vector<int> dp(len, 1);

        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);//子问题：dp[j]
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};