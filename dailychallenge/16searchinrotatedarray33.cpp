#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Step 1: Find the index of the pivot (the largest element)
    int getPivotIndex(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            // If only one element is left, that's the pivot
            if (s == e) return s;

            mid = s + (e - s) / 2;

            // Check if mid is pivot
            if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // Decide which side to move
            if (arr[s] > arr[mid]) {
                // Pivot is in left half
                e = mid - 1;
            } else {
                // Pivot is in right half
                s = mid + 1;
            }
        }

        return -1; // should never reach here if input is rotated sorted array
    }

    // Step 2: Perform normal binary search on given range
    int binarySearch(int s, int e, int target, vector<int> arr) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) return mid;

            if (target > arr[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }

    // Step 3: Search the target using pivot to identify the right subarray
    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);
        int n = nums.size();

        // Determine which side of the pivot the target lies on
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            // Target lies in the left (first) sorted part
            return binarySearch(0, pivotIndex, target, nums);
        } else {
            // Target lies in the right (second) sorted part
            return binarySearch(pivotIndex + 1, n - 1, target, nums);
        }

        // Target not found
        return -1;
    }
};

// Example usage
int main() {
    Solution sol;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;
    cout << "Index of 0: " << sol.search(nums1, target1) << endl; // Output: 4

    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3;
    cout << "Index of 3: " << sol.search(nums2, target2) << endl; // Output: -1

    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Index of 0: " << sol.search(nums3, target3) << endl; // Output: -1

    return 0;
}
