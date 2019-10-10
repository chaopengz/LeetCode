#include "head.h"
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0, even = 0;
        for(auto i:chips)
        {
            if(i%2)
            {
                even +=1;
            }
            else
            {
                odd+=1;
            }
            
        }
        return min(even,odd);
    }
};
int main()
{
    vector<int> chips = {2,2,2,3,3};
    Solution s;
    cout<<s.minCostToMoveChips(chips);
}