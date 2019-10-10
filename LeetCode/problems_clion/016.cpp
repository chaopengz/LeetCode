//
// Created by Chaopeng Zhang on 2019-08-18.
//

#include "head.h"

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size() - 2; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int second = first + 1;
            int third = nums.size() - 1;
            int cur;
            while (second < third) {
                cur = nums[first] + nums[second] + nums[third];
                if (cur == target)
                    return cur;
                if (abs(target - cur) < abs(target - ans))
                    ans = cur;
                if (cur > target)
                    third--;
                else
                    second++;
            }
        }
        return ans;
    }
};