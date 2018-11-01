//
// Created by 张潮鹏 on 2017/9/7.
//
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

/*
 * C++'s vector's size() returns size_type which is unsigned. Hence, if size() returns 0,
 * doing -1 would cause an overflow. One method is to first convert size_type into int before doing -1.
*/
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //字符串切割，切割后的单词存在v中
        vector<string> v;
        string c = " ";
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (std::string::npos != pos2) {
            v.push_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));


        string result = "";
        //对vector是否为空进行判断，避免出现RuntimeError
        if (v.size() == 0)
            return result;
        //对切分后的逐个单词进行反转，以中间字符为对称轴进行前后交换
        char temp;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size() / 2; ++j) {
                temp = v[i][v[i].size() - j - 1];
                v[i][v[i].size() - j - 1] = v[i][j];
                v[i][j] = temp;
            }
        }
        //将反转好的逐个单词拼接回字符串
        for (int i = 0; i < v.size() - 1; ++i) {
            cout << v[i] << endl;
            result += v[i] + " ";
        }
        result += v[v.size() - 1];
        return result;
    }
};