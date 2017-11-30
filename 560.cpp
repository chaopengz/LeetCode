//
// Created by chaopengz on 2017/11/30.
//

#include "head.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k)
    {

        map<int, int> preSum;//preSum<a,b>:前缀和为a的有b种可能
        int ans = 0;
        int sum = 0;
        int findNum;
        preSum[0]++;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            findNum = sum - k;
            ans += preSum[findNum];
            preSum[sum]++;
        }
        return ans;
    }
};