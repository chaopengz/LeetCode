#include "023.cpp"

int binarySearch(vector<int> v, int begin, int end, int target)
{
    int mid = (begin + end) / 2;
    while (begin < end)
    {
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
        {
            end = mid;
        } else
        {
            begin = mid;
        }
        mid = (begin + end) / 2;
    }
    return -1;
}

int main()
{

    int a[] = {4, 5, 6, 7};
    vector<int> v(a, a + 4);
    int i = 0, j = v.size() - 1;
    int mid = (i + j + 1) / 2;
    while (i < j)
    {
        if (v[i] < v[mid])
            i = mid;
        else
            j = mid;
        mid = (i + j + 1) / 2;
    }
    cout << binarySearch(v, 0, v.size() - 1, 7);
}

