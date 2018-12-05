//
// Created by cpz on 2018/1/3.
//
#include "head.h"

//
//class Solution {
//public:
//    int findMin(vector<int> &rotateArray)
//    {
//        if (!rotateArray.size())
//            return 0;
//        if (rotateArray.size() == 1)
//            return rotateArray[0];
//        int len = rotateArray.size();
//
//        if (rotateArray[0] < rotateArray[len - 1])//没有旋转
//            return rotateArray[0];
//
//
//        int low = 0, high = len - 1;
//        int mid;
//
//        while (low <= high)
//        {
//            mid = (low + high) / 2;
//            if (isFind(rotateArray, mid))
//                return rotateArray[mid];
//            else if (rotateArray[mid] > rotateArray[0])//[0,mid]单调增
//                low = mid + 1;
//            else
//                high = mid - 1;
//        }
//        return rotateArray[mid];
//    }
//
//    bool isFind(vector<int> nums, int index)
//    {
//        if (index == nums.size() - 1)
//            return nums[index] < nums[index - 1];
//        else if (index == 0)
//            return nums[index] < nums[nums.size() - 1];
//        else
//            return nums[index] <= nums[index + 1] && nums[index] < nums[index - 1];
//    }
//};
class Solution {
public:
    int findMin(vector<int> &array)
    {
//        int low = 0;
//        int high = array.size() - 1;
//        int mid;
//        while (low < high)
//        {
//            mid = low + (high - low) / 2;
//            if (array[mid] > array[high])//最小值一定在mid右边
//            {
//                low = mid + 1;
//            } else if (array[mid] == array[high])//最小值有可能在mid左边,也有可能在右边
//            {
//                high = high - 1;//去掉重复的
//            } else//array[mid]<array[high] => mid右边是单调,mid是右边最小得数,也可能是左边最小的数,所以high = mid,而非high = mid-1
//            {
//                high = mid;
//            }
//        }
//        return array[low];
        int minNum = INT32_MAX;
        for (auto i:array)
        {
            minNum = min(minNum, i);
        }
        return minNum;
    }
};

