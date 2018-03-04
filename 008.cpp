//
// Created by cpz on 2018/1/30.
//
#include "head.h"

class Solution {
public:
    int myAtoi(string str)
    {
        if (!str.size())
            return 0;
        if (str == "-2147483648")
            return INT32_MIN;
        int ans = 0, start = 0;
        bool isNag = false;
        while (true)
        {
            if (str[start] == ' ')
                start++;
            else
                break;
        }
        if (str[start] == '-' || str[start] == '+')
        {
            if (str[start] == '-')
                isNag = true;
            start++;
        }
        char c;
        for (int i = start; i < str.size(); ++i)
        {
            c = str[i];
            if (c >= '0' && c <= '9')
            {
                if ((INT32_MAX - (c - '0')) / 10 < ans)
                {
                    if (isNag)
                        return INT32_MIN;
                    else
                        return INT32_MAX;
                } else
                    ans = ans * 10 + c - '0';
            } else
            {
                if (isNag)
                    return -ans;
                else
                    return ans;
            }
        }

        if (isNag)
            return -ans;
        else
            return ans;
    }
};