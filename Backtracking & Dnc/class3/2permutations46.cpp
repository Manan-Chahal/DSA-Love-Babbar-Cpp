/*
Leetcode 46: Permutations

Problem Statement:
------------------
Given an array nums of distinct integers, return all possible permutations.

Approach (Backtracking):
------------------------
- At each index i, try every element at position i (by swapping with j from i to end).
- Recursively generate permutations for the rest of the array.
- When i reaches the end, store the current permutation.
- Backtrack by swapping back after recursion.

Example for nums = {'a','b','c'} (Recursive Tree):

Level 0: i=0, nums = [a, b, c]
|
|-- swap(0,0): [a, b, c]
|   |
|   |-- swap(1,1): [a, b, c]
|   |   |-- swap(2,2): [a, b, c]  (store)
|   |
|   |-- swap(1,2): [a, c, b]
|       |-- swap(2,2): [a, c, b]  (store)
|
|-- swap(0,1): [b, a, c]
|   |
|   |-- swap(1,1): [b, a, c]
|   |   |-- swap(2,2): [b, a, c]  (store)
|   |
|   |-- swap(1,2): [b, c, a]
|       |-- swap(2,2): [b, c, a]  (store)
|
|-- swap(0,2): [c, b, a]
    |
    |-- swap(1,1): [c, b, a]
    |   |-- swap(2,2): [c, b, a]  (store)
    |
    |-- swap(1,2): [c, a, b]
        |-- swap(2,2): [c, a, b]  (store)

Total permutations: 6

*/

#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to generate permutations using backtracking
    void solve(vector<int>& nums, int i, vector<vector<int>> &ans) {
        // Base case: If all positions are fixed, store the permutation
        if(i >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        // For each position from i to end, swap and recurse
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);           // Give each element a chance at position i
            solve(nums, i + 1, ans);          // Recursively fix the next position
            swap(nums[i], nums[j]);           // Backtrack: restore the array for the next iteration
        }
    }

    // Main function to return all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums, i, ans);
        return ans;
    }
};

// Example usage
#include <iostream>
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    cout << "All permutations:" << endl;
    for(const auto& perm : result) {
        for(int num : perm) cout << num << " ";
        cout << endl;
    }
    return 0;
}