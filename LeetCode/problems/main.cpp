#include "056.cpp"

int main() {
    vector<Interval> input;
    Interval a(1, 4);
    Interval b(4, 5);
//    Interval c(8, 10);
//    Interval d(15, 18);
    input.push_back(a);
    input.push_back(b);
//    input.push_back(c);
//    input.push_back(d);
    Solution s;
    s.merge(input);
}