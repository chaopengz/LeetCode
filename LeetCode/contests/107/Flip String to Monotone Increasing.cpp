//
// Created by laryzhang on 2018/11/8.
//
#include "../head.h"

class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int len = S.size();
        int first_one_index = len;
        int last_zero_index = 0;

        int ones_before_last_zeor = 0;

        for (int j = 0; j < len; ++j)
        {
            if (S[j] == '1')
            {
                first_one_index = j;
                break;
            }
        }
        for (int i = len - 1; i >= 0; --i)
        {
            if (S[i] == '0')
            {
                last_zero_index = i;
                break;
            }
        }
        int sub_len = last_zero_index - first_one_index;
        int num_of_zero = 0;
        int num_of_one = 0;
        for (int k = first_one_index; k <= last_zero_index; ++k)
        {
            if (S[k] == '0')
                num_of_zero += 1;
            else
                num_of_one += 1;
        }
        int ans = min(num_of_one, num_of_zero);
        return ans;
    }
};
