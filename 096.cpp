//
// Created by cpz on 2017/11/23.
//

#include "head.h"

class Solution {
public:
    int numTrees(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1));
        for (int len = 1; len < n; ++len)
        {
            for (int start = 1; start + len<= n ; ++start)
            {
                int end = start + len ;
                int sum = 0;
                for (int k = start; k <= end ; ++k)
                {
                    sum+=dp[start][k-1]*dp[k+1][end];
                }
                dp[start][end] = sum;
            }
        }
        return dp[1][n];
    }
};