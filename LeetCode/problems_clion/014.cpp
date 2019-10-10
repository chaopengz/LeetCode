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
            len = (int)strs[i].size();
            minLen = min(minLen, len);
        }
        int index = 0;
        bool equal;
        while (index < minLen)
        {
            equal = true;
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i][index] != strs[i - 1][index])
                {
                    equal = false;
                }
            }
            if (equal)
                index++;
            else
                break;
        }
        string ans = "";
        for (int j = 0; j < index; ++j)
        {
            ans += strs[0][j];
        }
        return ans;
    }
};