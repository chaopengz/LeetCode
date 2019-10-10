//
// Created by cpz on 2019-09-17.
//
#include "head.h"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < m; ++i)//first row
        {
            if (matrix[0][i] == '1')
                dp[0][i] = 1;
        }
        for (int i = 0; i < n; ++i)//first col
        {
            if (matrix[i][0] == '1')
                dp[i][0] = 1;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};