//
// Created by chaopengz on 2017/10/11.
//

#include "head.h"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        #define MAXN 1000005 
        int a[MAXN];
        int n = nums.size();
        vector<int> ans;
        for (int j = 0; j < MAXN; ++j)
        {
            a[j] = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            a[nums[i]] = 1;
        }
        for (int k = 1; k < n+1 ; ++k)
        {
            if (!a[k])
                ans.push_back(k);
        }
        return ans;
    }
};