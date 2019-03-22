//
// Created by laryzhang on 2019/3/10.
//
#include "head.h"

//My ans
//class Solution
//{
//public:
//    int longestValidParentheses(string s)
//    {
//        if (s.size() < 2)
//            return 0;
//        stack<char> S;
//        int start = 0;
//        int ans = 0;
//        int length = 0;
//        while (s[start] == ')')//去掉前缀')'
//        {
//            start++;
//        }
//        if(start == s.size())
//            return 0;
//        S.push(s[start]);
//        for (int i = start + 1; i < s.size(); ++i)
//        {
//            char c = s[i];
//            if (c == '(')
//            {
//                S.push(c);
//            } else if (c == ')')
//            {
//                if (!S.empty() && S.top() == '(')
//                {
//                    if (i != s.size() - 1)
//                    {
//                        length += 2;
//                        S.pop();
//                    }else // last one ')'
//                    {
//
//                        length += 2;
//                    }
//                } else // top is ')' or null, is not match
//                {
//                    ans = max(ans, length);
//                    length = 0;
//                    while (!S.empty())
//                        S.pop();
//                }
//            }
//        }
//        return max(length, ans);
//    }
//};


//记录断的位置
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        if (s.size() < 2)
            return 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == '(')
            {
                st.push(i);
            } else //c==')'
            {
                if (st.size() > 1 && s[st.top()] == '(')
                {
                    st.pop();
                } else
                {
                    st.push(i);
                }
            }
        }
        st.push(s.size());
        int ans = 0;
        int pre = st.top();
        st.pop();
        while (!st.empty())
        {
            ans = max(ans, pre - st.top() - 1);
            pre = st.top();
            st.pop();
        }
        return ans;
    }


};