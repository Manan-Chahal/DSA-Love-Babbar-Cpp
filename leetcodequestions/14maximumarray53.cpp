#include <iostream>
#include <vector>
#include <climits>  // for INT_MIN
using namespace std;
// Brute force method nogt optimized
class Solution {
public:
    // Brute-force method to find the maximum subarray sum
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN; // Start with the smallest possible integer

        // Outer loop: Starting index of subarray
        for (int i = 0; i < n; i++) {
            int currentSum = 0;

            // Inner loop: Ending index of subarray
            for (int j = i; j < n; j++) {
                currentSum += nums[j];          // Add current element to the subarray sum
                maxSum = max(maxSum, currentSum); // Update maxSum if this subarray is larger
            }
        }

        return maxSum;
    }
};

// Function to print test results
void runTest(vector<int> nums, int testCaseNumber) {
    Solution sol;
    int result = sol.maxSubArray(nums);
    cout << "Test Case " << testCaseNumber << ": Maximum Subarray Sum = " << result << endl;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    runTest(nums1, 1); // Expected output: 6

    // Test Case 2
    vector<int> nums2 = {1};
    runTest(nums2, 2); // Expected output: 1

    // Test Case 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    runTest(nums3, 3); // Expected output: 23

    // Test Case 4 (All negatives)
    vector<int> nums4 = {-8, -3, -6, -2, -5, -4};
    runTest(nums4, 4); // Expected output: -2

    return 0;
}
