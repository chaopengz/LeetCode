//
// Created by chaopengz on 2017/10/11.
//

#include "head.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        int len = nums.size();
        if (!len)
            return 0;
        if (len == 1)
            return nums[0];
        else
        {
            int sum = nums[0];
            int minPreSum = min(0, nums[0]);
            int ans = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                sum += nums[i];
                ans = max(ans, sum - minPreSum);
                minPreSum = min(sum, minPreSum);
            }
            return ans;
        }

    }
};