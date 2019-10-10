//
// Created by cpz on 2018/7/9.
//
#include "head.h"

class Solution {
public:
    int get_max_num(vector<int> vec)
    {
        int len = vec.size();
        int ans = INT32_MIN;

        for (int i = 0; i < len - 3; ++i)
        {
            for (int j = i + 1; j < len - 2; ++j)
            {
                for (int p = j + 1; p < len - 1; ++p)
                {
                    for (int q = p + 1; q < len; ++q)
                    {
                        if (ans < vec[j] - vec[i] + vec[q] - vec[p])
                        {
                            ans = vec[j] - vec[i] + vec[q] - vec[p];
                            cout << i << " " << j << " " << p << " " << q << endl;
                        }

                    }
                }
            }
        }
        return ans;
    }

    int get_max_num2(vector<int> vec)
    {
        vector<int> up;
        int index = 1;

    }
};