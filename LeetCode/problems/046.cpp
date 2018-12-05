//
// Created by chaopengz on 2017/11/7.
//

#include "head.h"
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        ans.push_back(nums);

        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);

        for(auto i:ans)
            cout<<i[0]<<i[1]<<i[2]<<endl;
        return ans;
    }
};