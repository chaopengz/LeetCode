//
// Created by chaopengz on 2017/9/28.
//

#include "head.h"

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> array;
        array.push_back("abc");//2
        array.push_back("def");//3
        array.push_back("ghi");//4
        array.push_back("jkl");//5
        array.push_back("mno");//6
        array.push_back("pqrs");//7
        array.push_back("tuv");//8
        array.push_back("wxyz");//9

        int n,lenQ;
        queue<string> q;
        string s1, s2, s3,s4,s5;
        vector<string> res;

        for (int i = 0; i < digits.length(); ++i)
        {
            s1 = digits[i];
            n = stoi(s1.c_str());
            n -= 2;//map n to array index
            s2 = array[n];//abc
            lenQ = q.size();
            if (lenQ)
            {
                for (int j = 0; j < lenQ; ++j)
                {
                    s4 = q.front();
                    q.pop();
                    for (int k = 0; k < s2.length(); ++k)
                    {
                        s3 = s2[k];
                        s5 = s4 + s3;
                        q.push(s5);
                    }
                }
            }
            else//j=0
            {
                for (int j = 0; j < s2.length(); ++j)
                {
                    s3 = s2[j];
                    q.push(s3);
                }
            }
        }

        lenQ = q.size();
        for (int l = 0; l < lenQ; ++l)
        {
            s1 = q.front();
            res.push_back(s1);
            q.pop();
        }

        return res;
    }
};