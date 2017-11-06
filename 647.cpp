//
// Created by chaopengz on 2017/11/1.
//

#include "head.h"

class Solution {
public:
    int countSubstrings(string s)
    {
        int len = (int) s.size();
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i; j < len; ++j)
            {
                if (ispalindromic(s, i, j))
                    ans++;
            }
        }
        return ans;
    }

    bool ispalindromic(string s, int i, int j)
    {
        if (i == j)
            return true;
        int len = j - i;
        for (int k = 0; k < (len + 1) / 2; ++k)
        {
            if (s[i + k] != s[j - k])
                return false;
        }
        return true;
    }
};