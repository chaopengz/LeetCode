//
// Created by chaopengz on 2017/9/27.
//
#include "head.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        int j, k, sum;
        vector<vector<int>> res;


        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i)
        {
            if (i == 0 || nums[i] != nums[i - 1])//a = nums[i]取值不重复
            {
                j = i + 1;
                k = len - 1;
                sum = 0 - nums[i];
                while (j < k)
                {
                    if (nums[j] + nums[k] == sum)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j++]);
                        v.push_back(nums[k--]);
                        res.push_back(v);
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    } else if (nums[j] + nums[k] > sum)
                    {
                        k--;
                    } else
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};