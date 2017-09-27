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

        while (i < n || j < m) {
            if (i == n) {
                nums.push_back(nums2[j]);
                j++;
            } else if (j == m) {
                nums.push_back(nums1[i]);
                i++;
            } else if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            } else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        double ans;
        int count = m + n;

        if ((count) % 2)
            ans = nums[(count - 1) / 2];
        else
            ans = (nums[(count) / 2] + nums[(count) / 2 - 1]) / 2.0;

        return ans;

    }
};