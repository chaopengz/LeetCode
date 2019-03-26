//
// Created by laryzhang on 2019/3/26.
//
#include "head.h"

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int ans = 0;
        for (auto i:J)
        {
            for (auto j:S)
            {
                if (i == j)
                    ans++;
            }
        }
        return ans;
    }
};
