//
// Created by cpz on 2018/2/3.
//

#include "head.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
            return string();
        int minLen = INT32_MAX, len;
        for (int i = 0; i < strs.size(); ++i)
        {
            len = strs[i].size();
            minLen = min(minLen, len);
        }
        int index = 0;
        while (index < minLen)
        {

            index++;
        }

    }
};