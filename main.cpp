#include <iostream>
#include "575.cpp"

int main() {

    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    //v.push_back(2);
    //v.push_back(3);
    v.push_back(3);
    cout<<s.distributeCandies(v)<<endl;

}