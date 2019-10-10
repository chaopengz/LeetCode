//
// Created by cpz on 2017/12/26.
//
#include "head.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (!matrix.size())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT32_MIN;
        vector<vector<int>> dpInc(m, vector<int>(n, 1));
        vector<vector<int>> dpDes(m, vector<int>(n, 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

            }
        }

    }
};