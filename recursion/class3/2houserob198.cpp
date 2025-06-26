#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Recursive function to explore all rob/not-rob decisions
    int solve(vector<int>& nums, int n, int i) {
        // Base case: if index is out of bounds
        if (i >= n) {
            return 0;
        }

        // Include current house and move to i + 2 (cannot rob adjacent house)
        int includeAns = nums[i] + solve(nums, n, i + 2);

        // Exclude current house and move to i + 1
        int excludeAns = 0 + solve(nums, n, i + 1);

        // Return max of include vs exclude
        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }

    int rob(vector<int>& nums) {
        int index = 0; // start from the 0th house
        int ans = solve(nums, nums.size(), index);
        return ans;
    }
};
