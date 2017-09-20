#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;
//        nums1.push_back(0);
//        nums2.push_back(0);
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        if (!n) {
            nums = nums2;
        } else if (!m) {
            nums = nums1;
        } else {
            while (i < n || j < m) {
                if (nums1[i] <= nums2[j]) {
                    nums.push_back(nums1[i]);
                    i++;
                } else {
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
        }

        double ans;
        int count = m + n;

        if ((count) % 2)
            ans = nums[(count- 1) / 2];
        else
            ans = (nums[(count) / 2] + nums[(count) / 2 - 1]) / 2;

        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}