//
// Created by laryzhang on 2019/3/10.
//
#include "../head.h"

class Solution
{
public:
    int clumsy(int N)
    {
        char ops[] = {'*', '/', '+', '-'};
        stack<int> S;
        vector<int> Sub;
        for (int j = 1; j <= N; ++j)
        {
            S.push(j);
        }
        int num1, num2;
        for (int i = 0; i < N - 1; ++i)
        {
            char op = ops[i % 4];
            if (op == '*')
            {
                num1 = S.top();
                S.pop();
                num2 = S.top();
                S.pop();
                S.push(num1 * num2);
            } else if (op == '/')
            {
                num1 = S.top();
                S.pop();
                num2 = S.top();
                S.pop();
                S.push(num1 / num2);
            } else if (op == '+')
            {
                num1 = S.top();
                S.pop();
                num2 = S.top();
                S.pop();
                if (i == 2)
                    S.push(num1 + num2);
                else
                    S.push(num1 - num2);
            } else if (op == '-')
            {
                num1 = S.top();
                Sub.push_back(num1);
                S.pop();
            }

        }
        num1 = S.top();
        Sub.push_back(num1);
        S.pop();
        assert(S.size() == 0);
        int ans = Sub[0];
        for (int k = 1; k < Sub.size(); ++k)
        {
            ans = ans - Sub[k];
        }
        return ans;
    }
};
