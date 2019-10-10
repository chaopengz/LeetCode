//
// Created by cpz on 2019-09-10.
//
#include "head.h"

//最小堆维护最早结束的会议室
class Solution
{
public:
    struct Interval
    {
        int start;
        int end;
    };

    static bool cmp(Interval a, Interval b)
    {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if(!intervals.size())
            return 0;
        vector<Interval> inters;
        for (auto i:intervals)
        {
            Interval In;
            In.start = i[0];
            In.end = i[1];
            inters.push_back(In);
        }
        sort(inters.begin(), inters.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(inters[0].end);
        for (int j = 1; j < inters.size(); ++j)
        {
            if (inters[j].start > pq.top())
            {
                pq.pop();
            }
            pq.push(inters[j].end);
        }
        return (int)pq.size();
    }
};