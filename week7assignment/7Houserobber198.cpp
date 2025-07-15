#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Recursive helper function to calculate max amount from index i
    int robHelper(vector<int>& nums, int i) {
        // Base case: if index is out of bounds
        if (i >= nums.size()) {
            return 0;
        }

        // Option 1: Rob this house and skip the next one
        int robAmt1 = nums[i] + robHelper(nums, i + 2);

        // Option 2: Skip this house and move to the next
        int robAmt2 = robHelper(nums, i + 1);

        // Take the maximum of both options
        return max(robAmt1, robAmt2);
    }

    // Initial function call
    int rob(vector<int>& nums) {
        return robHelper(nums, 0);
    }
};

// Test cases
int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,1};
    cout << "Max Robbed Amount (Test 1): " << sol.rob(nums1) << endl; // Output: 4

    vector<int> nums2 = {2,7,9,3,1};
    cout << "Max Robbed Amount (Test 2): " << sol.rob(nums2) << endl; // Output: 12

    vector<int> nums3 = {2,1,1,2};
    cout << "Max Robbed Amount (Test 3): " << sol.rob(nums3) << endl; // Output: 4

    vector<int> nums4 = {5};
    cout << "Max Robbed Amount (Test 4): " << sol.rob(nums4) << endl; // Output: 5

    vector<int> nums5 = {};
    cout << "Max Robbed Amount (Test 5): " << sol.rob(nums5) << endl; // Output: 0

    return 0;
}

/*
Time Complexity: O(2^N)
- Each house has two choices (rob or skip), leading to exponential calls.

Space Complexity: O(N)
- Due to recursion stack depth (maximum N).
*/
