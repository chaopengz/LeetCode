//
// Created by chaopengz on 2017/11/21.
//
#include "head.h"

class Solution {
public:
    int maxCoins(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> balloons;
        balloons.push_back(1);
        for (auto x:nums)
            balloons.push_back(x);
        balloons.push_back(1);

        vector<vector<int>> dp(balloons.size(), vector<int>(balloons.size(), 0));

        for (int i = 1; i <= len; ++i)
        {
            for (int j = i; j <= len; ++j)
            {//计算dp[i][j]
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
//    int maxCoins(vector<int>& nums) {
//        int N = nums.size();
//        nums.insert(nums.begin(), 1);
//        nums.insert(nums.end(), 1);
//
//        // rangeValues[i][j] is the maximum # of coins that can be obtained
//        // by popping balloons only in the range [i,j]
//        vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));
//
//        // build up from shorter ranges to longer ranges
//        for (int len = 1; len <= N; ++len) {
//            for (int start = 1; start <= N - len + 1; ++start) {
//                int end = start + len - 1;
//                // calculate the max # of coins that can be obtained by
//                // popping balloons only in the range [start,end].
//                // consider all possible choices of final balloon to pop
//                int bestCoins = 0;
//                for (int final = start; final <= end; ++final) {
//                    int coins = rangeValues[start][final-1] + rangeValues[final+1][end]; // coins from popping subranges
//                    coins += nums[start-1] * nums[final] * nums[end+1]; // coins from final pop
//                    if (coins > bestCoins) bestCoins = coins;
//                }
//                rangeValues[start][end] = bestCoins;
//            }
//        }
//        return rangeValues[1][N];
//    }
};