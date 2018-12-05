//
// Created by chaopengz on 2017/10/17.
//

#include "head.h"

class Solution {
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        int len = nums.size();
        while (j < len)
        {
            while (nums[j] == 0)
            {
                j++;
            }
            if (j < len)
            {
                swap(nums[i++], nums[j++]);
            }
        }
    }

};