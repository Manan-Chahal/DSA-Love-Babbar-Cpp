/*
✅ What is Exponential Search?

Exponential Search is an algorithm used to search sorted arrays efficiently.

📌 Use Case:
* Works well when the element is closer to the beginning.
* Often used when you don’t know the size of the array (like with infinite streams or linked structures).
* First finds a range [bound/2, bound] where the element could be,
  then performs Binary Search in that range.

🔍 Steps of Exponential Search:
1. Check if the element is at index 0.
2. Keep doubling the index `i` (1, 2, 4, 8, ...) until you go beyond the array size or find arr[i] >= target.
3. Perform Binary Search in the range [i/2, min(i, n-1)].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function: Binary Search in the range [low, high]
    int binarySearch(vector<int>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return mid;           // Element found
            else if (arr[mid] < target) low = mid + 1;     // Move right
            else high = mid - 1;                           // Move left
        }
        return -1; // Element not found
    }

    // Main Exponential Search function
    int exponentialSearch(vector<int>& arr, int target) {
        int n = arr.size();

        if (n == 0) return -1;
        if (arr[0] == target) return 0; // Check index 0

        // Step 1: Find the range where the element could exist
        int i = 1;
        while (i < n && arr[i] <= target) {
            i *= 2; // Exponentially increase the index
        }

        // Step 2: Binary Search within the valid range
        int low = i / 2;
        int high = min(i, n - 1);
        return binarySearch(arr, low, high, target);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 10, 15, 20, 40, 80, 100};
    int target = 20;

    int index = sol.exponentialSearch(arr, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    return 0;
}

/*
🔁 Dry Run Example:
Input:
arr = [2, 4, 10, 15, 20, 40, 80, 100], target = 20

Step 1: i = 1 → 2 → 4 → 8 (stops when arr[i] > target)
Step 2: Binary Search from index 4 to 7
Result: Finds 20 at index 4

⏱️ Time Complexity:
* O(log i), where i is the index at which the target is found
* Best case: O(1), Worst case: O(log n)
*/
// | Case          | Time Complexity |
// | ------------- | --------------- |
// | Best case     | O(1)            |
// | Average/Worst | O(log n)        |
