//
// Created by chaopengz on 2017/12/14.
//

#include "head.h"

class Solution {
public:
    bool isPowerOfThree(int n)
    {
        vector<int> v;
        for (int i = 1; i < INT32_MAX; i *= 3)
        {
            v.push_back(i);
            if (i > (INT32_MAX / 3))
                break;
        }
        return binary_search(v.begin(), v.end(), n);
    }
};