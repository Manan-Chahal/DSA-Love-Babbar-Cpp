// Problem26: Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. After modifying the array, return the number of unique elements, k.

// Change the array nums such that the first k elements contain the unique elements in the same order they were present in nums initially.
// It does not matter what you leave beyond the first k elements.
// Example 1:
// Input:
// nums = [1, 1, 2]
// Output:
// 2, nums = [1, 2, _]
// Explanation:
// Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively. The remaining elements can be ignored.

// Example 2:
// Input:
// nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
// Output:
// 5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]
// Explanation:
// Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively. The remaining elements can be ignored.

// Constraints:
// 1 <= nums.length <= 3 * 10^4
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0; // Edge case: if the array is empty
        
        int i = 1, j = 0; // Initialize two pointers
        while (i < nums.size()) {
            if (nums[j] == nums[i]) {
                i++; // Skip duplicate
            } else {
                nums[++j] = nums[i++]; // Move unique element and increment pointers
            }
        }
        return j + 1; // Return the number of unique elements
    }
};

// int main function to test the solution
int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "Number of unique elements: " << k1 << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "Number of unique elements: " << k2 << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
