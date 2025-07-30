class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);         // Final result: minimum subarray length from each index
        vector<int> bitIndex(32, -1);     // Stores latest index for each of the 32 bits (0–31)

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Update bitIndex with current number's set bits
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    bitIndex[b] = i;
                }
            }

            // Calculate how far we must go to include all bits set in the max OR
            int farthest = i;
            for (int b = 0; b < 32; ++b) {
                if (bitIndex[b] != -1) {
                    farthest = max(farthest, bitIndex[b]);
                }
            }

            result[i] = farthest - i + 1;
        }

        return result;
    }
};

