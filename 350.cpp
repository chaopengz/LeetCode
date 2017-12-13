//
// Created by cpz on 2017/12/13.
//

#include "head.h"

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> v(len1 + len2);
        vector<int>::iterator it;
        it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());

        v.resize(it - v.begin());

        return v;
    }
};