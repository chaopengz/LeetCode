//
// Created by 张潮鹏 on 2017/9/8.
//
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        char temp;
        string word = s;
        for (int i = 0; i < word.size()/2; ++i) {
            temp = word[i];
            word[i] = word[word.size() - i - 1];
            word[word.size() - i - 1] = temp;
        }
        return word;
    }
};