//
// Created by laryzhang on 2018/11/6.
//

//
// Created by laryzhang on 2018/11/5.
//
#include "../head.h"

class Solution
{
public:
    int knightDialer(int N)
    {
        const int M = 1000000000 + 7;
        if (N == 1)
            return 10;
        else
        {
            vector<vector<int>> dp(5005, vector<int>(10, 1));
            //init
            for (int i = 2; i <= N; ++i)
            {
                dp[i][0] = (dp[i - 1][4] % M + dp[i - 1][6] % M) % M;
                dp[i][1] = (dp[i - 1][6] % M + dp[i - 1][8] % M) % M;
                dp[i][2] = (dp[i - 1][7] % M + dp[i - 1][9] % M) % M;
                dp[i][3] = (dp[i - 1][4] % M + dp[i - 1][8] % M) % M;
                dp[i][4] = ((dp[i - 1][0] % M + dp[i - 1][3] % M) % M + dp[i - 1][9] % M) % M;
                dp[i][6] = ((dp[i - 1][0] % M + dp[i - 1][1] % M) % M + dp[i - 1][7] % M) % M;
                dp[i][7] = (dp[i - 1][2] % M + dp[i - 1][6] % M) % M;
                dp[i][8] = (dp[i - 1][1] % M + dp[i - 1][3] % M) % M;
                dp[i][9] = (dp[i - 1][2] % M + dp[i - 1][4] % M) % M;
            }
            dp[N][5] = 0;

            int ans = 0;
            for (int j = 0; j <= 9; ++j)
            {
                ans = (ans % M + dp[N][j] % M) % M;
            }
            return ans;
        }
    }
};