//
// Created by chaopengz on 2017/9/9.
//
#include <vector>

using namespace std;
/*
 *  vector初始化示例
 *
    int a1[] = {4, 1, 2};
    int a2[] = {1, 3, 4, 2};
    vector<int> v1(a1, a1 + 3), v2(a2, a2 + 4);

    */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        vector<int> res;
        int num;
        bool finded;
        for (int i = 0; i < findNums.size(); ++i) {
            finded = false;
            num = findNums[i];
            for (int j = 0; j < nums.size(); ++j) {
                if (num == nums[j])
                    finded = true;
                if (finded && nums[j] > num) {
                    res.push_back(nums[j]);
                    break;
                }
                if (j == nums.size() - 1)
                    res.push_back(-1);
            }
        }
        return res;
    }
};
