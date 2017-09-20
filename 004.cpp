//
// Created by chaopengz on 2017/9/20.
//

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        if(!n){
            nums = nums2;
        }
        if(!m){
            nums = nums1;
        }
        while (i < n || j < m) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        double ans;

        if ((m + n) % 2)
            ans = nums[(m + n - 1) / 2];
        else
            ans = (nums[(m + n) / 2] + nums[(m + n) / 2 - 1]) / 2;

        return ans;

    }
};