//
// Created by cpz on 2019-09-23.
//

#include "head.h"

class Solution
{
public:
    void hannoi(int n, char from, char buffer, char to)
    {
        if (n == 0)
            return;
        hannoi(n - 1, from, to, buffer);
        cout << n << ":" << from << "-->" << to << endl;
        hannoi(n - 1, buffer, from, to);
    }
};