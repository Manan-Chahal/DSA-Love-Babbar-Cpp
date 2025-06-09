/*
==========================================
         🔍 UNBOUNDED BINARY SEARCH
==========================================

✅ WHAT IS IT?

Unbounded Binary Search is used when you are dealing with an array (or stream) of unknown or infinite size.
It helps find a target value efficiently by:

1. **Finding a valid search window** [start, end] where the target can exist
2. **Applying Binary Search** within that window

------------------------------------------
✅ USE CASES

- Searching in a sorted infinite array
- Searching data streams where length is not known
- Searching Google-like paginated results

------------------------------------------
⚙️ HOW IT WORKS

1️⃣ Step 1: Find the search window
    - Start with start = 0, end = 1
    - Keep doubling end until arr[end] >= target

2️⃣ Step 2: Binary search in [start, end]

------------------------------------------
✅ C++ CODE EXAMPLE
*/

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class InfiniteArray {
public:
    vector<int> arr;

    InfiniteArray(vector<int> data) {
        arr = data;
    }

    // Access method simulating infinite size
    int get(int index) {
        if (index >= arr.size()) return INT_MAX; // Simulated infinity
        return arr[index];
    }
};

class Solution {
public:
    int unboundedBinarySearch(InfiniteArray& infArr, int target) {
        int start = 0;
        int end = 1;

        // Step 1: Expand range exponentially
        while (infArr.get(end) < target) {
            start = end;
            end *= 2;
        }

        // Step 2: Binary Search in range [start, end]
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midVal = infArr.get(mid);

            if (midVal == target) return mid;
            else if (midVal < target) start = mid + 1;
            else end = mid - 1;
        }

        return -1; // Not found
    }
};

int main() {
    InfiniteArray infArr({3, 5, 7, 9, 10, 13, 18, 21, 35, 50});
    Solution sol;

    int target = 13;
    int result = sol.unboundedBinarySearch(infArr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

/*
------------------------------------------
🕒 TIME COMPLEXITY

- Range Finding: O(log p)
- Binary Search: O(log p)
- TOTAL:        O(log p), where p is position of target

------------------------------------------
🧠 SUMMARY

| Step | Description                                                  |
|------|--------------------------------------------------------------|
| 1️⃣   | Expand range to find [start, end] where target may exist    |
| 2️⃣   | Do Binary Search in the range                               |
| ✅   | Great for sorted, infinite or unknown-length data structures |

*/
