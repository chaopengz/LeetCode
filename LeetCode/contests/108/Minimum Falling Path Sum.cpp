//
// Created by laryzhang on 2018/11/1.
//

#include "../head.h"

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {


        //dp[i][j] 以A[i][j]为结尾的时候的最小值
        int len = A[0].size();
        if (len == 1)
        {
            return A[0][0];
        }

        std::vector<std::vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));

        for (int i = 0; i < len; ++i)
        {
            dp[0][i] = A[0][i];
        }
        for (int i = 1; i < len; ++i)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
            for (int j = 1; j < len - 1; ++j)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + A[i][j];
            }
            dp[i][len - 1] = min(dp[i - 1][len - 2], dp[i - 1][len - 1]) + A[i][len - 1];
        }

        int ans = INT32_MAX;
        for (int k = 0; k < len; ++k)//last row
        {
            ans = min(ans, dp[len - 1][k]);
        }
        return ans;
    }
};