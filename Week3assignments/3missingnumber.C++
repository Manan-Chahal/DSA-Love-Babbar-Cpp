// Problem: 268 Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], find and return the only number in the range that is missing from the array.

// Example 1:
// Input:
// nums = [3, 0, 1]
// Output:
// 2
// Explanation:
// n = 3 since there are 3 numbers, so all numbers are in the range [0, 3]. The missing number is 2, as it does not appear in nums.

// Example 2:
// Input:
// nums = [0, 1]
// Output:
// 2
// Explanation:
// n = 2 since there are 2 numbers, so all numbers are in the range [0, 2]. The missing number is 2, as it does not appear in nums.

// Example 3:
// Input:
// nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
// Output:
// 8
// Explanation:
// n = 9 since there are 9 numbers, so all numbers are in the range [0, 9]. The missing number is 8, as it does not appear in nums.

// Constraints:
// n == nums.length
// 1 <= n <= 10^4
// 0 <= nums[i] <= n
// All numbers in nums are unique.
// Follow-up:
// Can you implement a solution that uses O(1) extra space complexity and O(n) time complexity?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sortingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums[i]) {
                continue;
            } else {
                return i;
            }
        }
        return nums.size();
    }

    int xorr(vector<int>& nums) {
        int ans = 0;
        // XOR all numbers in the array
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        // XOR with all numbers in the range [0, n]
        for (int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }
        return ans;
    }

    int missingNumber(vector<int>& nums) {
        // You can choose to use either sortingNumber or xorr for finding the missing number.
        // return sortingNumber(nums);
        return xorr(nums);
    }
};

// int main function to test the solution
int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {3, 0, 1};
    cout << "Missing number in [3, 0, 1]: " << sol.missingNumber(nums1) << endl; // Expected output: 2

    // Test case 2
    vector<int> nums2 = {0, 1};
    cout << "Missing number in [0, 1]: " << sol.missingNumber(nums2) << endl; // Expected output: 2

    // Test case 3
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing number in [9, 6, 4, 2, 3, 5, 7, 0, 1]: " << sol.missingNumber(nums3) << endl; // Expected output: 8

    return 0;
}
