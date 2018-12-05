//
// Created by chaopengz on 2017/9/27.
//

#include "head.h"

class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int len = height.size();
        int i = 0, j = len - 1;
        int maxWater = 0, h;
        while (i < j)
        {
            h = min(height[i], height[j]);
            maxWater = max(maxWater, h * (j - i));
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }
        return maxWater;
    }
};