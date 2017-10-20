//
// Created by chaopengz on 2017/10/20.
//

#include "head.h"

class Solution {
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len / 2];
    }
};