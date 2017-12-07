//
// Created by chaopengz on 2017/12/7.
//

#include "head.h"

class Solution {
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        int left = 0, right = len - 1;
        int ans = 0;
        int maxLeft = INT32_MIN, maxRight = INT32_MIN;
        while (left <= right)
        {
            if (height[left] <= height[right])//由短板来决定
            {
                if(height[left]>maxLeft) maxLeft = height[left];
                else
                {
                    ans += maxLeft - height[left];
                    left ++;
                }
            } else
            {
                if(height[right]>maxRight) maxRight = height[right];
                else
                {
                    ans += maxRight - height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};