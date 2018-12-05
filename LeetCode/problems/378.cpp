//
// Created by cpz on 2017/12/13.
//

#include "head.h"

//class Solution {
//public:
//    int kthSmallest(vector<vector<int>> &matrix, int k)
//    {
//        int n = matrix.size();
//
//        int left = matrix[0][0];
//        int right = matrix[n - 1][n - 1];
//        //k最小总在[left,right]中
//        while (left < right)
//        {
//            int midv = (left + right) / 2;
//
//            int count = 0;  // number of elements no bigger than midv
//            for (int i = 0; i < n; i++)
//            {
//                vector<int> &row = matrix[i];
//                count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
//            }
//            //更新left与right边界值
//            if (count < k)
//            {
//                left = midv + 1;
//            } else//count >= k
//            {
//                right = midv;
//            }
//        }
//        return left;
//    }
//};

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int len = matrix[0].size();
        int left = matrix[0][0], right = matrix[len - 1][len - 1];
        int mid = (left + right) / 2;
        int sum;
        int count;
        while (left < right)
        {
            sum = 0;
            mid = (left + right) / 2;
            for (int i = 0; i < len; ++i)
            {
                count = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();// <=
                if (!count)
                    break;
                else
                    sum += count;
            }
            if (sum < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};