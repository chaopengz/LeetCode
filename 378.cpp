//
// Created by cpz on 2017/12/13.
//

#include "head.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();

        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right)
        {
            int midv = (left + right) / 2;

            int count = 0;  // number of elements no bigger than midv
            for (int i = 0; i < n; i++)
            {
                vector<int> &row = matrix[i];
                count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
            }

            if (count < k)
            {
                left = midv + 1;
            } else
            {
                right = midv;
            }
        }
        return left;
    }
};