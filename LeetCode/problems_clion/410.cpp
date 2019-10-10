//
// Created by cpz on 2019-09-10.
//

#include "head.h"

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        if (!nums.size() || nums.size() < m || m <= 0)
            return 0;
        vector<long> pre_sum;
        long sum = 0;
        for (auto i:nums)
        {
            sum += i;
            pre_sum.push_back(sum);
        }
        int n = nums.size();
        vector<vector<long>> dp(n, vector<long>(m, 0));
        for (int j = 0; j < n; ++j)
        {
            dp[j][0] = pre_sum[j];
        }
        int max_num = INT32_MIN;
        for (int i = 0; i < m; ++i)
        {
            max_num = max(max_num, nums[i]);
            dp[i][i] = max_num;
        }
        for (int j = 1; j < m; ++j)
        {
            for (int i = j + 1; i < n; ++i)
            {
                long min_sub_sum = INT32_MAX;
                for (int k = j - 1; k < i; ++k)
                {
                    min_sub_sum = min(max(dp[k][j - 1], pre_sum[i] - pre_sum[k]),
                                      min_sub_sum);
                }
                dp[i][j] = min_sub_sum;
            }
        }
        return (int) dp[n - 1][m - 1];
    }
};