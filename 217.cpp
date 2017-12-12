//
// Created by chaopengz on 2017/12/12.
//

#include "head.h"

class Solution {
public:
    bool containsDuplicate(vector<int> &nums)
    {

        bool ans = false;
        unordered_map<int, int> m;
        for (auto i:nums)
        {
            if (m[i] > 0)
                return true;
            m[i]++;
        }
        return ans;
    }
};