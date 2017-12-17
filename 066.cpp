//
// Created by cpz on 2017/12/17.
//

#include "head.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ans;
        int len = digits.size();
        if (!len)
            return ans;
        int jw = 1;
        int



                gw;
        int sum;
        for (int i = len - 1; i >= 0; --i)
        {
            sum = digits[i] + jw;
            gw = sum % 10;
            jw = sum / 10;
            ans.push_back(gw);
        }
        if (jw)
            ans.push_back(jw);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};