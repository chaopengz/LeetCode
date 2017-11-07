//
// Created by chaopengz on 2017/11/7.
//

#include "head.h"

class Solution {
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> m;
        int n = nums.size();
        for (int j = 1; j < n; ++j)
        {
            m[j] = 0;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]]++;
        }
        int ans;

        for (int k = 1; k < n; ++k)
        {
            if (m[k] > 1)
                ans = k;
        }
        return ans;
    }
};