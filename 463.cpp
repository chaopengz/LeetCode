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
        int countOfLandOfOneRow, countOfLandOfPreRow = 0, perimeter = 0;
        for (int i = 0; i < m; ++i) {

            countOfLandOfOneRow = 0;

            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    countOfLandOfOneRow++;
            }
            if(countOfLandOfOneRow)
            {
                perimeter += 2 * countOfLandOfOneRow + 2;
                perimeter -= 2 * min(countOfLandOfOneRow, countOfLandOfPreRow);
                countOfLandOfPreRow = countOfLandOfOneRow;
            }
        }
        return perimeter;
    }
};