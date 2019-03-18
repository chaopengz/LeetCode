//
// Created by laryzhang on 2019/3/10.
//
#include "head.h"

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
            return 0;
        stack<char> S;
        int start = 0;
        int ans = 0;
        int length = 0;
        while (s[start] == ')')//去掉前缀')'
        {
            start++;
        }
        if(start == s.size())
            return 0;
        S.push(s[start]);
        for (int i = start + 1; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == '(')
            {
                if (!S.empty())
                {
                    ans = max(length, ans);
                    length = 0;
                }
                S.push(c);
            } else if (c == ')')
            {
                if (!S.empty() && S.top() == '(')
                {
                    if (i != s.size() - 1)
                    {
                        length += 2;
                        S.pop();
                    }else // last one ')'
                    {

                        length += 2;
                    }
                } else // top is ')' or null, is not match
                {
                    ans = max(ans, length);
                    length = 0;
                    while (!S.empty())
                        S.pop();
                }
            }
        }
        return max(length, ans);
    }
};
