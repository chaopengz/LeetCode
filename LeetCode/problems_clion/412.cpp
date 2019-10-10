//
// Created by chaopengz on 2017/9/8.
//
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;

        for (int i = 1; i <= n; ++i) {
            if(i%5==0 && i%3 == 0)
                res.push_back("FizzBuzz");
            else if(i%5 == 0)
                res.push_back("Buzz");
            else if(i%3 ==0)
                res.push_back("Fizz");
            else
            {
                res.push_back(to_string(i));
            }
        }
        return res;

    }
};