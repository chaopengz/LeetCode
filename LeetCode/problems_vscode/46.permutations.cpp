/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include "head.h"
// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(0,nums,ans);
        return ans;
    }

    void dfs(int pos, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (pos == nums.size())
            ans.push_back(nums);
        else
        {
            for (int i = pos; i < nums.size(); i++)
            {
                swap(nums[i], nums[pos]);
                dfs(pos + 1, nums, ans);
                swap(nums[i], nums[pos]);
            }
        }
    }
};
// @lc code=end
