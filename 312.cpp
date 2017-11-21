//
// Created by chaopengz on 2017/11/21.
//
#include "head.h"

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int len = nums.size();
        vector<int> balloons;
        balloons.push_back(1);
        for (auto x:nums)
            balloons.push_back(x);
        balloons.push_back(1);

        vector<vector<int>> dp(balloons.size(), vector<int>(balloons.size(), 0));

        for (int step = 0; step < len; ++step) {
            for (int i = 0; i <= len - step; ++i) {
                int j = i + step;
                for (int k = i; k <= j; ++k)//k为[i,j]最后一个戳破的气球
                {
                    dp[i][j] = max(
                            dp[i][j],
                            dp[i][k - 1] + dp[k + 1][j] + balloons[i - 1] * balloons[k] * balloons[j + 1]
                    );
                }
            }
        }
        return dp[1][len];
    }
};