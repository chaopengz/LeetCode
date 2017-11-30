//
// Created by chaopengz on 2017/11/30.
//

#include "head.h"

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len - k];
    }
};