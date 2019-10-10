 //
// Created by laryzhang on 2019/3/26.
//
#include "head.h"

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> sort_nums = nums;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while (start < nums.size())
        {
            if (nums[start] != sort_nums[start])
                break;
            start++;
        }
        while (end > 0)
        {
            if (nums[end] != sort_nums[end])
                break;
            end--;
        }
        int ans = end - start + 1;
        return max(ans, 0);
    }
};