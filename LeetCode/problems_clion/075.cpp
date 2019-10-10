//
// Created by chaopengz on 2017/12/3.
//


#include "head.h"

class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        map<int,int> m;
        m[0] = 0;
        m[1] = 0;
        m[2] = 0;
        for(auto i:nums)
            m[i]++;
        nums.clear();
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < m[i]; ++j)
            {
                nums.push_back(i);
            }
        }
    }
};