class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end()); // Step 1: Find the maximum value in the array
        int maxLen = 0;     // Stores the longest subarray length with max AND
        int currentLen = 0; // Current streak of maxVal

        for (int num : nums) {
            if (num == maxVal) {
                currentLen++; // Continue the streak
                maxLen = max(maxLen, currentLen); // Update result if this streak is longer
            } else {
                currentLen = 0; // Reset if the number is not equal to maxVal
            }
        }

        return maxLen;
    }
};
