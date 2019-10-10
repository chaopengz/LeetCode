//
// Created by 张潮鹏 on 2017/9/8.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int m, n;
        m = (int) nums.size();
        n = (int) nums[0].size();
        if (m * n != r * c)
            return nums;

        vector<vector<int>> result;
        //r*c的二维数组
        result.resize(r, vector<int>(c));

        int sum = r * c;
        for (int i = 0; i < sum; ++i) {
            result[ i/c ][ i % c] = nums[ i/n ][ i % n];
        }
        return result;
    }
};