#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to explore all jump paths
    bool solve(vector<int>& nums, int i) {
        // Base case: if we reach or exceed the last index
        if (i >= nums.size() - 1) {
            return true;
        }

        // Try every possible jump from this position
        for (int jump = 1; jump <= nums[i]; jump++) {
            if (solve(nums, i + jump)) {
                return true; // if any path leads to the end
            }
        }

        // If no path works
        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0); // start from index 0
    }
};

// Driver code to test
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4}; // true
    // vector<int> nums = {3, 2, 1, 0, 4}; // false
    bool result = sol.canJump(nums);
    cout << (result ? "Can reach the end!" : "Cannot reach the end.") << endl;
    return 0;
}
