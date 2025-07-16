#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Using <= and ansIndex tracking
    int peakIndexWithAnsIndex(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid;
        int ansIndex = -1;

        while (s <= e) {
            mid = s + (e - s) / 2;

            // Avoid out-of-bound access for arr[mid+1]
            if (mid < arr.size() - 1 && arr[mid] < arr[mid + 1]) {
                // We're on the increasing side of the mountain
                s = mid + 1;
            } else {
                // We're on the decreasing side (or at the peak)
                ansIndex = mid;
                e = mid - 1;
            }
        }

        return ansIndex;
    }

    // Approach 2: Cleaner binary search (recommended)
    int peakIndexSimplified(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Move to the right half
                start = mid + 1;
            } else {
                // Stay on left side including mid
                end = mid;
            }
        }

        // Start and end point to the peak
        return start;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> arr1 = {0, 1, 0};
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr3 = {0, 10, 5, 2};

    cout << "=== Using peakIndexWithAnsIndex() ===" << endl;
    cout << "Peak index in [0, 1, 0]: " << sol.peakIndexWithAnsIndex(arr1) << endl; // 1
    cout << "Peak index in [0, 2, 1, 0]: " << sol.peakIndexWithAnsIndex(arr2) << endl; // 1
    cout << "Peak index in [0, 10, 5, 2]: " << sol.peakIndexWithAnsIndex(arr3) << endl; // 1

    cout << "\n=== Using peakIndexSimplified() ===" << endl;
    cout << "Peak index in [0, 1, 0]: " << sol.peakIndexSimplified(arr1) << endl; // 1
    cout << "Peak index in [0, 2, 1, 0]: " << sol.peakIndexSimplified(arr2) << endl; // 1
    cout << "Peak index in [0, 10, 5, 2]: " << sol.peakIndexSimplified(arr3) << endl; // 1

    return 0;
}
