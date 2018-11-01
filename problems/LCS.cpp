//
// Created by chaopengz on 2017/9/27.
//
#include "head.h"

#define MAXN 1005

int LCS(string s1, string s2)
{
    int dp[MAXN][MAXN];
    int lenS1 = s1.size(), lenS2 = s2.size();
    int longest = 0, endi, endj;

    for (int i = 0; i < lenS1; ++i)
    {
        for (int j = 0; j < lenS2; ++j)
        {

            if (i && j)
            {//不在首行和首列的时候
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                {
                    dp[i][j] = 0;
                }
            } else
            {
                //首行和首列初始化
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1;
                } else
                {
                    dp[i][j] = 0;
                }

            }
            if (dp[i][j] > longest && s1[i - dp[i][j] + 1] == s2[j])
            {
                longest = dp[i][j];
                endi = i;
            }
        }
    }
    string res = "";
    for (int k = 0; k < longest; ++k)
    {
        res += s1[endi--];
    }
    cout << res << endl;
    return longest;
}