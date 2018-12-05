//
// Created by chaopengz on 2017/12/18.
//
#include "head.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len-1; ++i)
        {
            if(nums[i]>nums[i+1])//导数小于0
                return i;
        }
        return len-1;
    }
};