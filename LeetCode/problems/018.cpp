//
// Created by Chaopeng Zhang on 2019-08-19.
//

#include "head.h"

class Solution {
public:

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        //n^3
        if (nums.size() < 4)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 3; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second < nums.size() - 2; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                int third = second + 1;
                int fourth = nums.size() - 1;
                while (third < fourth) {
                    int cur = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (cur == target) {
                        vector<int> v = {nums[first], nums[second], nums[third], nums[fourth]};
                        ans.push_back(v);
                        //Attention
                        third++;
                        fourth--;
                        while (third < fourth && nums[third] == nums[third - 1])
                            third++;
                        while (third < fourth && nums[fourth] == nums[fourth + 1])
                            fourth--;

                    } else if (cur < target) {
                        third++;
                    } else {
                        fourth--;
                    }
                }
            }
        }
        return ans;
    }
};