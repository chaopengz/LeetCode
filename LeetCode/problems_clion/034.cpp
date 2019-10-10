//
// Created by chaopengz on 2017/10/16.
//

#include "head.h"

// Using STL
//class Solution {
//public:
//    vector<int> searchRange(vector<int> &nums, int target)
//    {
//        vector<int>::iterator low, up;
//        low = lower_bound(nums.begin(), nums.end(), target);
//        up = upper_bound(nums.begin(), nums.end(), target);
//        vector<int> ans;
//
//        if (!binary_search(nums.begin(),nums.end(),target))
//        {
//            ans.push_back(-1);
//            ans.push_back(-1);
//        } else
//        {
//            ans.push_back(low - nums.begin());
//            ans.push_back(up - nums.begin() - 1);
//        }
//        return ans;
//    }
//};
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int low = 0, high = nums.size() - 1;
        int mid;
        int ans1 = -1, ans2 = -1;
        while (low <= high)//找最低
        {
            mid = (low + high) / 2;
            if (lowMatch(nums, target, mid))
            {
                ans1 = mid;
                break;
            } else if (nums[mid] < target)
                low = mid + 1;
            else// nums[mid]>=target
                high = mid - 1;//即使相等，也一定在左边找
        }

        low = 0, high = nums.size() - 1;

        while (low <= high)//找最高
        {
            mid = (low + high) / 2;
            if (highMatch(nums, target, mid))
            {
                ans2 = mid;
                break;
            } else if (nums[mid] <= target)//由上一个条件，即使跟target相等也不符合了
                low = mid + 1;
            else //nums[mid]>target
                high = mid - 1;//mid有可能是解
        }

        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }

    bool lowMatch(vector<int> &nums, int target, int i)
    {
        if (nums[i] != target)
            return false;
        if (i == 0)//第0个肯定是最左边的
            return true;
        else if (nums[i] != nums[i - 1])
            return true;
        return false;
    }

    bool highMatch(vector<int> &nums, int target, int i)
    {
        if (nums[i] != target)
            return false;
        if (i == nums.size() - 1)//最后一个肯定是最右边的
            return true;
        else if (nums[i] != nums[i + 1])
            return true;
        return false;
    }
};

