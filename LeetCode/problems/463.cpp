//
// Created by chaopengz on 2017/9/8.
//
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int m, n;
        m = (int) grid.size();
        n = (int) grid[0].size();
        int countOfLand = 0, landSharedOfTwoRows = 0, landSharedOfTwoCols = 0, perimeter;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    countOfLand++;
                if (i > 0 && grid[i][j] + grid[i - 1][j] == 2)
                    landSharedOfTwoRows++;
                if (j > 0 && grid[i][j] + grid[i][j - 1] == 2)
                    landSharedOfTwoCols++;
            }
        }
        perimeter = 4 * countOfLand - 2 * (landSharedOfTwoCols + landSharedOfTwoRows);
        return perimeter;
    }
};