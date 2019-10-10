//
// Created by laryzhang on 2019/3/26.
//
#include "head.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int index = 0;
        while (index < nums.size())
        {
            int max_num = INT32_MIN;
            int max_index = 0;
            for (int i = index + 1; i <= index + nums[index] && i < nums.size(); ++i)
            {
                if (nums[i] + i >= max_num)
                {
                    max_num = nums[i] + i;
                    max_index = i;
                }
            }
            index = max_index;
//            std::cout << "index: " << index << std::endl;
            if (index == nums.size() - 1)
                return true;
            if (nums[index] == 0)
                return false;

        }
        return true;
    }
};