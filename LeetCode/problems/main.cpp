#include "064.cpp"

int main()
{
    Solution s;
    vector<vector<int>> input{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    std::cout << s.minPathSum(input);

}