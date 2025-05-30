#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        // Ensure the array is sorted
        sort(arr.begin(), arr.end());

        int ansIndex = -1;
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        // Perform binary search to find the missing number
        while (s <= e) {
            int number = arr[mid];
            int index = mid;
            int diff = number - index;

            if (diff == 0) {
                // Missing number must be in the right half
                s = mid + 1;
            } else if (diff == 1) {
                // Found a potential missing number
                ansIndex = index;
                e = mid - 1; // Move to the left half
            }
            mid = s + (e - s) / 2;
        }

        // If no missing number is found, return n (missing number is beyond the last index)
        if (ansIndex == -1) {
            return n;
        }
        return ansIndex;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> arr1 = {0, 1, 2, 4, 5};
    vector<int> arr2 = {0, 1, 3};
    vector<int> arr3 = {0, 1, 2, 3};
    vector<int> arr4 = {};

    cout << "Missing number in arr1: " << sol.missingNumber(arr1) << endl; // Output: 3
    cout << "Missing number in arr2: " << sol.missingNumber(arr2) << endl; // Output: 2
    cout << "Missing number in arr3: " << sol.missingNumber(arr3) << endl; // Output: 4
    cout << "Missing number in arr4: " << sol.missingNumber(arr4) << endl; // Output: 0

    return 0;
}
