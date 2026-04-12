#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> result;
        int n = nums.size();

        if (n == 0) {
            result.push_back({lower, upper});
            return result;
        }

        // First range
        if ((long long)lower < nums[0]) {
            result.push_back({lower, nums[0] - 1});
        }

        // Middle ranges
        for (int i = 1; i < n; i++) {
            long long prev = nums[i - 1];
            long long curr = nums[i];

            if (curr - prev > 1) {
                result.push_back({(int)(prev + 1), (int)(curr - 1)});
            }
        }

        // Last range
        if ((long long)upper > nums[n - 1]) {
            result.push_back({nums[n - 1] + 1, upper});
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 10};  // input array
    int lower = 1;
    int upper = 12;

    vector<vector<int>> result = sol.findMissingRanges(nums, lower, upper);

    cout << "Missing Ranges: ";
    for (auto &range : result) {
        cout << "[" << range[0] << ", " << range[1] << "] ";
    }
    cout << endl;

    return 0;
}