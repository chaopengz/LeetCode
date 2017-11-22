//
// Created by cpz on 2017/11/22.
//

#include "head.h"

class Solution {
public:
    string decodeString(string s)
    {
        stack<string> chars;
        stack<int> nums;
        string result = "";
        string encoded;

        string c;
        string pre;
        bool isdecoding = false;
        int n;
        for (int i = 0; i < s.size(); ++i)
        {
            c = s[i];

            if (c == "[")
            {
                isdecoding = true;
                encoded = "";
            } else if (c == "]")
            {

                if (nums.empty() && chars.empty())
                {
                    isdecoding = false;
                }
            } else if (has_only_digits(c))
            {
                if(isdecoding)
                {

                }
                n = atoi(c);
                nums.push(n);
            } else
            {
                if (!isdecoding)
                {
                    result += c;
                } else
                {
                    encoded += c;
                }
            }

        }
    }

    bool has_only_digits(const string s)
    {
        return s.find_first_not_of("0123456789") == string::npos;
    }
};