//
// Created by laryzhang on 2018/11/5.
//

#include "../head.h"

class RecentCounter
{
public:
    RecentCounter()
    {}

    int ping(int t)
    {
        while (!q.empty() && t - q.front() > 3000) q.pop();
        q.push(t);
        return q.size();
    }

private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */