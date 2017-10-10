//
// Created by chaopengz on 2017/10/10.
//
#include "head.h"

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        int len = s.size();
        char c;
        for (int i = 0; i < len; ++i)
        {
            c = s[i];
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            switch (c)
            {
                case ')':
                    if (!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    } else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    } else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (!st.empty() && st.top() == '{')
                    {
                        st.pop();
                    } else
                    {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};