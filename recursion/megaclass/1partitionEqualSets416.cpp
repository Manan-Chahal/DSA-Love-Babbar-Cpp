#include <iostream>
#include <vector>
#include <numeric> // for accumulate

using namespace std;

class Solution
{
public:
    // Recursive helper function to check if a subset with given target sum exists
    bool solve(vector<int> &nums, int target, int i)
    {
        // If target becomes negative or we've considered all elements, return false
        if (target < 0 || i == nums.size())
            return false;
        // If target is 0, we've found a valid subset
        if (target == 0)
            return true;

        // Include current element in the subset
        bool inc = solve(nums, target - nums[i], i + 1);
        // Exclude current element from the subset
        bool exc = solve(nums, target, i + 1);

        // Return true if either including or excluding leads to a solution
        return inc || exc;
    }

    // Main function to check if array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // If sum is odd, can't partition into two equal subsets
        if ((sum % 2) != 0)
            return false;

        int target = sum >> 1; // target sum for each subset
        return solve(nums, target, 0);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test 1: {1, 5, 11, 5} -> " << (sol.canPartition(nums1) ? "True" : "False") << endl;

    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test 2: {1, 2, 3, 5} -> " << (sol.canPartition(nums2) ? "True" : "False") << endl;

    vector<int> nums3 = {2, 2, 3, 5};
    cout << "Test 3: {2, 2, 3, 5} -> " << (sol.canPartition(nums3) ? "True" : "False") << endl;

    vector<int> nums4 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 4: {1, 1, 1, 1, 1, 1, 1, 1} -> " << (sol.canPartition(nums4) ? "True" : "False") << endl;

    vector<int> nums5 = {100, 100};
    cout << "Test 5: {100, 100} -> " << (sol.canPartition(nums5) ? "True" : "False") << endl;

    // Additional test cases
    vector<int> nums6 = {1, 2, 5};
    cout << "Test 6: {1, 2, 5} -> " << (sol.canPartition(nums6) ? "True" : "False") << endl;

    vector<int> nums7 = {3, 3, 3, 4, 5};
    cout << "Test 7: {3, 3, 3, 4, 5} -> " << (sol.canPartition(nums7) ? "True" : "False") << endl;

    vector<int> nums8 = {2, 2, 2, 2};
    cout << "Test 8: {2, 2, 2, 2} -> " << (sol.canPartition(nums8) ? "True" : "False") << endl;

    vector<int> nums9 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 9: {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} -> " << (sol.canPartition(nums9) ? "True" : "False") << endl;

    vector<int> nums10 = {1};
    cout << "Test 10: {1} -> " << (sol.canPartition(nums10) ? "True" : "False") << endl;

    return 0;
}

/*
Time Complexity Explanation:
---------------------------
This recursive solution explores every subset of the array to check if a subset with sum = totalSum/2 exists.
For each element, there are two choices: include or exclude, leading to 2^n possible subsets (where n = nums.size()).
Thus, the time complexity is O(2^n), which is exponential and not efficient for large arrays.

Space Complexity:
-----------------
The space complexity is O(n) due to the recursion stack (maximum depth of recursion is n).
This is acceptable for n up to around 20, but for very large n, it could cause a stack overflow.
Iterative solutions or solutions with memoization would be more efficient in terms of space.
*/