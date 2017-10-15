//
// Created by chaopengz on 2017/10/11.
//

#include "head.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum;
        int n = nums.size();
        int ans = -2147483647;
        for (int i = 0; i < n ; ++i)
        {
            sum = 0;
            for (int j = i ; j < n; ++j)
            {
                sum +=  nums[j];
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};