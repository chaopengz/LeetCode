//
// Created by chaopengz on 2017/12/2.
//

#include "head.h"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        if (!len)
            return 0;
        vector<int> dp;
        vector<int>::iterator low;
        for (auto i:nums)
        {
            low = lower_bound(dp.begin(),dp.end(),i);

            if(low == dp.end())
                dp.push_back(i);
            else
                dp[low-dp.begin()] = i;
        }
        int ans = dp.size();
        return ans;
    }
};