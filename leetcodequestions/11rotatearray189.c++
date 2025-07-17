#include <iostream>
#include <vector>
#include <algorithm> // For swap

using namespace std;

class Solution {
public:
    // Helper function to reverse a portion of the array
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            // Swap elements at start and end indices
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // In case k is larger than the size of the array
        k = k % n;

        // Step 1: Reverse the whole array
        reverseArray(nums, 0, n - 1);

        // Step 2: Reverse the first k elements
        reverseArray(nums, 0, k - 1);

        // Step 3: Reverse the remaining n - k elements
        reverseArray(nums, k, n - 1);
    }
};

// Test the solution
int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    sol.rotate(nums, k);

    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
