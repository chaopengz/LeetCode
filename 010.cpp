//
// Created by chaopengz on 2017/9/25.
//
#include "head.h"

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        dp[0][1] = false;
        for (int j = 2; j <= n; ++j)//s为空
        {
            if (p[j] == '*')//a*只能出现0次，以为s为空
                dp[0][j] = dp[0][j - 2];
            else//p[j]为.或*
                dp[0][j] = false;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')//x*出现0次或者多次
                {
                    if (p[j - 2] == '.')
                    {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    } else
                    {
                        dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] && dp[i - 1][j]);
                    }
                } else if (p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};