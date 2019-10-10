//
// Created by cpz on 2019-03-20.
//

#include "head.h"

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool comp(Interval a, Interval b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2)
            return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            Interval in = intervals[i];
            if (in.start > ans[ans.size() - 1].end)
                ans.push_back(in);
            else {
                ans[ans.size() - 1].start = min(ans[ans.size() - 1].start, in.start);
                ans[ans.size() - 1].end = max(ans[ans.size() - 1].end, in.end);

            }
        }
        return ans;
    }
};