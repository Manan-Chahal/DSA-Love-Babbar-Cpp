// Problem724:
// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

// Examples:
// Example 1:
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

// Constraints:
// 1 <= nums.length <= 10^4
// -1000 <= nums[i] <= 1000
// Notes:
// The pivot index should be returned as the leftmost one if multiple valid indices exist.
// The sum on either side of the pivot does not include the pivot itself.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute force approach
    int bruteforce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int lsum = 0;
            int rsum = 0;
            for (int j = 0; j < i; j++) {
                lsum += nums[j];
            }
            for (int j = i + 1; j < nums.size(); j++) {
                rsum += nums[j];
            }
            if (lsum == rsum) {
                return i;
            }
        }
        return -1;
    }

    // Prefix sum approach
    int prefixSumApproach(vector<int>& nums) {
        vector<int> lsum(nums.size(), 0);
        vector<int> rsum(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            lsum[i] = lsum[i - 1] + nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            rsum[i] = rsum[i + 1] + nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (lsum[i] == rsum[i]) {
                return i;
            }
        }
        return -1;
    }

    // Optimized prefix sum approach
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;

        // Calculate total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Traverse through the array and calculate left sum at each index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum would be totalSum - leftSum - nums[i]
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;  // Found the pivot index
            }
            leftSum += nums[i];  // Update left sum for the next index
        }

        return -1;  // If no pivot index is found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 7, 3, 6, 5, 6};  // Example input

    // Using optimized prefix sum approach
    int result = solution.pivotIndex(nums);

    // Output result
    cout << "Pivot Index: " << result << endl;

    return 0;
}
