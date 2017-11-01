//
// Created by chaopengz on 2017/11/1.
//
#include "head.h"

class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> ans;
        ans.push_back(0);

        if (!num)
            return ans;

        int i = 1;
        int count = 1;
        while (count < num)
        {
            for (int j = 0; j < i; ++j)
            {
                ans.push_back(ans[j] + 1);
            }
            i *= 2;
            count += i;
        }
        count -= i;
        for (int k = count; k < num; ++k)
        {
            ans.push_back(ans[k - count] + 1);
        }
        return ans;
    }
};