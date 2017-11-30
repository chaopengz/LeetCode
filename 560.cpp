//
// Created by cpz on 2017/11/29.
//
#include "head.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int len = nums.size();
        int ans = 0;
        int sum;

        for (int i = 1; i <= len; ++i)
        {
            sum = 0;
            for (int j = i; j <= len; ++j)
            {
                sum += nums[j - 1];
                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};