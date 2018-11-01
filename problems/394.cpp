//
// Created by cpz on 2017/11/22.
//

#include "head.h"

class Solution {
public:
    string decodeString(string s)
    {
        stack<string> chars;
        chars.push("");
        stack<int> nums;
        string c;
        string encode = "";
        string str;
        int n;
        string strOfNums = "";
        for (int i = 0; i < s.size(); ++i)
        {
            c = s[i];
            if (c == "[")
            {

                n = atoi(strOfNums.c_str());
                nums.push(n);
                strOfNums = "";

                chars.push("");
            } else if (c == "]")
            {
                str = chars.top();
                chars.pop();
                n = nums.top();
                nums.pop();
                encode = "";
                for (int j = 0; j < n; ++j)
                {
                    encode += str;
                }
                encode = chars.top() + encode;
                chars.pop();
                chars.push(encode);
            } else if (has_only_digits(c))//num
            {
                strOfNums += c;
            } else//字母
            {
                encode = chars.top();
                chars.pop();
                encode += c;
                chars.push(encode);
            }
        }
        return chars.top();
    }

    bool has_only_digits(const string s)
    {
        return s.find_first_not_of("0123456789") == string::npos;
    }
};