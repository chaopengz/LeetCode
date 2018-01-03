//
// Created by chaopengz on 2017/10/15.
//
#include "head.h"

class Solution {
public:
    int binarySearch(vector<int> &v, int begin, int end, int target)
    {
        int mid = (begin + end) / 2;
        while (begin <= end)
        {
            if (v[mid] == target)
                return mid;
            else if (v[mid] > target)
            {
                end = mid - 1;
            } else
            {
                begin = mid + 1;
            }
            mid = (begin + end) / 2;
        }
        return -1;
    }

    bool maxMatch(vector<int> &nums, int i)
    {

    }

    int search(vector<int> &nums, int target)
    {
        if (!nums.size())
            return -1;
        int i = 0, j = nums.size() - 1;
        int mid = (i + j) / 2;
        if (nums[i] < nums[j])
            i = j;
        else
        {
            int mid = (i + j) / 2;
            while (i < j)
            {
                if (nums[i] < nums[mid])
                    i = mid;
                else
                    j = mid;
                mid = (i + j) / 2;
            }
        }

        //now i the max value index
        if (i == nums.size() - 1)
        {
            return binarySearch(nums, 0, nums.size() - 1, target);
        } else
        {
            if (target >= nums[0])
                return binarySearch(nums, 0, i, target);
            else
            {
                return binarySearch(nums, i + 1, nums.size() - 1, target);
            }
        }
    }

};