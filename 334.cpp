//
// Created by chaopengz on 2017/12/16.
//

#include "head.h"

class Solution {
public:
    int increasingTriplet(vector<int> &nums)
    {
        int len = nums.size();
        if (len < 3)
            return false;
        vector<int> dp;
        vector<int>::iterator low;
        for (auto i:nums)
        {
            low = lower_bound(dp.begin(), dp.end(), i);

            if (low == dp.end())
            {
                dp.push_back(i);
                if (dp.size() == 3)
                    return true;
            } else
            {
                dp[low - dp.begin()] = i;
            }

        }
        return false;
    }
};