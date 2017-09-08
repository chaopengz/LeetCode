//
// Created by 张潮鹏 on 2017/9/7.
//
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        map<char, int> alphabetToInt;

        alphabetToInt['q'] = 1;
        alphabetToInt['w'] = 1;
        alphabetToInt['e'] = 1;
        alphabetToInt['r'] = 1;
        alphabetToInt['t'] = 1;
        alphabetToInt['y'] = 1;
        alphabetToInt['u'] = 1;
        alphabetToInt['i'] = 1;
        alphabetToInt['o'] = 1;
        alphabetToInt['p'] = 1;
        alphabetToInt['a'] = 2;
        alphabetToInt['s'] = 2;
        alphabetToInt['d'] = 2;
        alphabetToInt['f'] = 2;
        alphabetToInt['g'] = 2;
        alphabetToInt['h'] = 2;
        alphabetToInt['j'] = 2;
        alphabetToInt['k'] = 2;
        alphabetToInt['l'] = 2;
        alphabetToInt['z'] = 3;
        alphabetToInt['x'] = 3;
        alphabetToInt['c'] = 3;
        alphabetToInt['v'] = 3;
        alphabetToInt['b'] = 3;
        alphabetToInt['n'] = 3;
        alphabetToInt['m'] = 3;
        alphabetToInt['Q'] = 1;
        alphabetToInt['W'] = 1;
        alphabetToInt['E'] = 1;
        alphabetToInt['R'] = 1;
        alphabetToInt['T'] = 1;
        alphabetToInt['Y'] = 1;
        alphabetToInt['U'] = 1;
        alphabetToInt['I'] = 1;
        alphabetToInt['O'] = 1;
        alphabetToInt['P'] = 1;
        alphabetToInt['A'] = 2;
        alphabetToInt['S'] = 2;
        alphabetToInt['D'] = 2;
        alphabetToInt['F'] = 2;
        alphabetToInt['G'] = 2;
        alphabetToInt['H'] = 2;
        alphabetToInt['J'] = 2;
        alphabetToInt['K'] = 2;
        alphabetToInt['L'] = 2;
        alphabetToInt['Z'] = 3;
        alphabetToInt['X'] = 3;
        alphabetToInt['C'] = 3;
        alphabetToInt['V'] = 3;
        alphabetToInt['B'] = 3;
        alphabetToInt['N'] = 3;
        alphabetToInt['M'] = 3;

        string word;
        int sum;
        int num;
        vector<string> result;

        for (int i = 0; i < words.size(); ++i) {
            sum = 0;
            word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                num = alphabetToInt[word[j]];
                sum += num;
            }
            if (sum == alphabetToInt[word[0]] * word.size()) {
                result.push_back(word);
            }
        }
        return result;
    }

};
