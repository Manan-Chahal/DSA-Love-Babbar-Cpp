// // Definition: Lower Bound
// // In a sorted array, the lower bound of a value x is the 
// // first position (i.e., index) where x could be inserted without 
// // violating the order — in other words, the first index where arr[i] >= x.
//  Step-by-step dry run of lowerBound(arr, 4)
// Initial:

// cpp
// Copy
// Edit
// start = 0
// end = 5
// ans = 5 (initially set to last index)
// 🔁 First iteration:
// cpp
// Copy
// Edit
// mid = (0 + 5) / 2 = 2
// arr[mid] = 3
// Since 3 < 4, we ignore the left side:

// cpp
// Copy
// Edit
// start = mid + 1 = 3
// 🔁 Second iteration:
// cpp
// Copy
// Edit
// mid = (3 + 5) / 2 = 4
// arr[mid] = 7
// Now, 7 >= 4 → possible answer:

// cpp
// Copy
// Edit
// ans = 4
// end = mid - 1 = 3
// 🔁 Third iteration:
// cpp
// Copy
// Edit
// mid = (3 + 3) / 2 = 3
// arr[mid] = 5
// Again, 5 >= 4 → update answer:

// cpp
// Copy
// Edit
// ans = 3
// end = 2
// ✅ Loop Ends: start > end
// Final answer:

// cpp
// Copy
// Edit
// return ans = 3
// So, arr[3] = 5 is the first element that is ≥ 4, and index 3 is the lower bound.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // Function to find the first index where arr[index] >= x
    int lowerBound(vector<int> &arr, int x) {
        int start = 0, end = arr.size() - 1;
        int ans = end; // Initialize answer to last index
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] >= x) {
                ans = mid;      // mid could be our answer, but search left
                end = mid - 1;
            } else {
                start = mid + 1; // search right
            }
        }
        return ans;
    }

    // Binary Search Based Sliding Window Method
    vector<int> bs_method(vector<int>& arr, int k, int x) {
        int h = lowerBound(arr, x); // Right pointer starts from the lower bound
        int l = h - 1;              // Left pointer just before right

        while (k--) { // We need to select k closest elements
            if (l < 0) {
                h++; // If left goes out of bounds, move right
            } else if (h >= arr.size()) {
                l--; // If right goes out of bounds, move left
            } else if (abs(arr[l] - x) <= abs(arr[h] - x)) {
                l--; // Prefer closer left element
            } else {
                h++; // Otherwise, choose from right
            }
        }

        // Return the subarray from index l+1 to h-1
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }

    // Your two-pointer shrinking window method
    vector<int> twoPtrMethod(vector<int>& arr, int k, int x) {
        int l = 0, h = arr.size() - 1;
        while (h - l >= k) { // Shrink window until size is exactly k
            if (abs(x - arr[l]) > abs(arr[h] - x)) {
                l++; // Remove left if farther from x
            } else {
                h--; // Otherwise remove right
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }

    // Main function to return k closest elements using either method
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        return bs_method(arr, k, x); // You can change to twoPtrMethod(arr, k, x)
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 3, 4, 5}; // Sorted input array
    int k = 4;
    int x = -1;

    vector<int> result = sol.findClosestElements(arr, k, x); // Call main logic

    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
