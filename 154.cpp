//
// Created by cpz on 2018/1/3.
//
#include "head.h"

class Solution {
public:
    int findMin(vector<int> &rotateArray)
    {
        if (!rotateArray.size())
            return 0;
        if (rotateArray.size() == 1)
            return rotateArray[0];
        int len = rotateArray.size();

        if (rotateArray[0] < rotateArray[len - 1])//没有旋转
            return rotateArray[0];


        int low = 0, high = len - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (isFind(rotateArray, mid))
                return rotateArray[mid];
            else if (rotateArray[mid] >= rotateArray[0])//[0,mid]单调增
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }

    bool isFind(vector<int> nums, int index)
    {
        if (index == nums.size() - 1)
            return nums[index] < nums[index - 1];
        else if (index == 0)
            return nums[index] < nums[nums.size() - 1];
        else
            return nums[index] <= nums[index + 1] && nums[index] < nums[index - 1];
    }

    bool findMax(vector<int> nums)
    {
        int low = 0, high = nums.size();
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;

        }
        return nums[low];
    }

};


