// 532. K-diff Pairs in an Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

 

// Example 1:

// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
// Example 3:

// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).
 

// Constraints:

// 1 <= nums.length <= 104
// -107 <= nums[i] <= 107
// 0 <= k <= 107
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // =============================
    // ✅ Approach 1: Two Pointer
    // Time: O(n log n) due to sorting + O(n)
    // Space: O(n) for set
    // =============================
    int findPairsTwoPointer(vector<int>& nums, int k) {
        if (k < 0) return 0; // Absolute difference cannot be negative

        sort(nums.begin(), nums.end()); // Sort the array
        set<pair<int, int>> ans;        // Store only unique pairs
        int i = 0, j = 1;
        int n = nums.size();

        while (j < n) {
            if (i == j) {
                j++; // i and j must point to different elements
                continue;
            }

            int diff = nums[j] - nums[i];

            if (diff == k) {
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            } else if (diff > k) {
                i++; // Need a smaller diff
            } else {
                j++; // Need a larger diff
            }
        }

        return ans.size();
    }

    // =============================
    // ✅ Approach 2: Binary Search
    // Time: O(n log n) for sorting + O(n log n) for binary search in loop
    // Space: O(n) for set
    // =============================
    int binarySearch(vector<int>& nums, int start, int x) {
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == x) return mid;
            else if (nums[mid] < x) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }

    int findPairsBinarySearch(vector<int>& nums, int k) {
        if (k < 0) return 0; // again, invalid case

        sort(nums.begin(), nums.end()); // Sort the array
        set<pair<int, int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            // Use binary search to look for nums[i] + k starting from i+1
            if (binarySearch(nums, i + 1, nums[i] + k) != -1) {
                ans.insert({nums[i], nums[i] + k});
            }
        }
        return ans.size();
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    cout << "Using Two Pointer Approach:" << endl;
    cout << "Number of unique k-diff pairs: " << sol.findPairsTwoPointer(nums, k) << endl;

    cout << "\nUsing Binary Search Approach:" << endl;
    cout << "Number of unique k-diff pairs: " << sol.findPairsBinarySearch(nums, k) << endl;

    return 0;
}
