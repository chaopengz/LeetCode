//
// Created by cpz on 2019-09-09.
//
#include "head.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if(!nums.size())
            return 0;
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else
            {
                nums[++cnt] = nums[i];
            }
        }
        nums.resize((unsigned long)cnt+1);
        return cnt+1;
    }
};