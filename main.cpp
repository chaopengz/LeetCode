#include "015.cpp"

int main()
{
    int a[] = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<int> n(a, a + 15);
    Solution s;
    vector<vector<int>> v;
    v = s.threeSum(n);
    for (int i = 0; i < v.size(); ++i)
    {

        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}