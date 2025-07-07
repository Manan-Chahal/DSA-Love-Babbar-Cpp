#include <iostream>
#include <vector>
using namespace std;

/*
Leetcode 198: House Robber

Problem Statement:
------------------
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Approach (Your Recursive Approach):
-----------------------------------
- At every house (index i), you have two choices:
    1. Rob the current house: Add its value to your total and skip the next house (move to i+2).
    2. Skip the current house: Move to the next house (i+1).
- Recursively compute the maximum money for both choices and return the maximum.
- Base case: If the index goes out of bounds, return 0.
- This approach explores all possible combinations of robbing and skipping houses.

Time Complexity: O(2^n) (since every house leads to two recursive calls)
Space Complexity: O(n) (recursion stack)
*/

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

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: {1, 2, 3, 1} -> " << sol.rob(nums1) << " (Expected: 4)" << endl;

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test 2: {2, 7, 9, 3, 1} -> " << sol.rob(nums2) << " (Expected: 12)" << endl;

    vector<int> nums3 = {2, 1, 1, 2};
    cout << "Test 3: {2, 1, 1, 2} -> " << sol.rob(nums3) << " (Expected: 4)" << endl;

    vector<int> nums4 = {5, 3, 4, 11, 2};
    cout << "Test 4: {5, 3, 4, 11, 2} -> " << sol.rob(nums4) << " (Expected: 16)" << endl;

    vector<int> nums5 = {1, 3, 1, 3, 100};
    cout << "Test 5: {1, 3, 1, 3, 100} -> " << sol.rob(nums5) << " (Expected: 103)" << endl;

    return 0;
}
