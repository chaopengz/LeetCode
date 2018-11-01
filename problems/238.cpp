//
// Created by chaopengz on 2017/11/1.
//

#include "head.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = (int) nums.size();
        vector<int> ans;
        vector<int> fromBegin;
        vector<int> fromEnd;
        int sumBegin = 1, sumEnd = 1;
        fromBegin.push_back(1);
        fromEnd.push_back(1);
        for (int i = 0; i < len; ++i)
        {
            sumBegin *= nums[i];
            sumEnd *= nums[len - 1 - i];
            fromBegin.push_back(sumBegin);
            fromEnd.push_back(sumEnd);
        }
        for (int j = 0; j < len; ++j)
        {
            ans.push_back(fromBegin[j] * fromEnd[len - j - 1]);
        }
        return ans;
    }
};