//
// Created by chaopengz on 2017/10/16.
//

#include "head.h"

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int>::iterator low, up;
        low = lower_bound(nums.begin(), nums.end(), target);
        up = upper_bound(nums.begin(), nums.end(), target);
        vector<int> ans;

        if (!binary_search(nums.begin(),nums.end(),target))
        {
            ans.push_back(-1);
            ans.push_back(-1);
        } else
        {
            ans.push_back(low - nums.begin());
            ans.push_back(up - nums.begin() - 1);
        }
        return ans;
    }
};