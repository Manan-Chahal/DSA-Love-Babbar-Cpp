/*
=========================================================================
                  SLIDING WINDOW PATTERN USING QUEUE
=========================================================================

The sliding window pattern is an algorithmic technique used to process arrays or lists 
by maintaining a "window" of elements and sliding it through the data structure.

1. CONCEPT
----------
- A "window" is a contiguous sequence of elements in an array/string
- The window "slides" through the array from left to right
- Useful for solving problems involving subarrays or substring operations
- Can significantly reduce time complexity from O(n²) to O(n)

2. TYPES OF SLIDING WINDOW
--------------------------
a) Fixed-Size Window: 
   - The size of the window is constant throughout
   - Example: Find max sum subarray of size k

b) Variable-Size Window:
   - Window size changes based on certain conditions
   - Example: Find smallest subarray with sum ≥ target

3. QUEUE-BASED IMPLEMENTATION
----------------------------
Queue is particularly useful when:
- You need to maintain order of elements in the window
- You need to keep track of the first/oldest element in the window
- Elements need to be processed in FIFO (First-In-First-Out) order

4. COMMON SLIDING WINDOW PROBLEMS
--------------------------------
- Maximum/minimum element in sliding window of size k
- First negative integer in every window of size k
- Count occurrences of anagrams in a string
- Longest substring with k distinct characters
- Minimum window substring containing all characters of another string

5. EXAMPLE: MAXIMUM IN SLIDING WINDOW
------------------------------------
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to find maximum element in each sliding window of size k
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Stores indices of potential maximum elements
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside current window (older than i-k+1)
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        // Remove elements smaller than current element from the back
        // These elements can never be the maximum
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        
        // Add current element (index) to the deque
        dq.push_back(i);
        
        // Store maximum of current window (front of deque)
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    
    return result;
}

/*
6. EXAMPLE: FIRST NEGATIVE IN WINDOW OF SIZE K
---------------------------------------------
*/

vector<int> firstNegativeInWindow(vector<int>& nums, int k) {
    queue<int> negatives;  // Stores indices of negative numbers
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Add current element if negative
        if (nums[i] < 0)
            negatives.push(i);
        
        // If window has moved beyond the oldest negative number
        if (!negatives.empty() && negatives.front() <= i - k)
            negatives.pop();
        
        // For a complete window, add result
        if (i >= k - 1) {
            if (!negatives.empty())
                result.push_back(nums[negatives.front()]);
            else
                result.push_back(0); // No negative in current window
        }
    }
    
    return result;
}

/*
7. GENERAL TEMPLATE FOR SLIDING WINDOW
------------------------------------
*/

void slidingWindowTemplate() {
    /*
    // Fixed Size Window Template
    int windowSize = k;
    queue<int> window;
    
    for (int i = 0; i < array.size(); i++) {
        // Add current element to window
        window.push(array[i]);
        
        // If window is not of full size yet, continue
        if (i < windowSize - 1) continue;
        
        // Process current window (of size k)
        // ... your processing logic here ...
        
        // Remove the oldest element as window slides
        window.pop();
    }
    
    // Variable Size Window Template
    int start = 0;
    for (int end = 0; end < array.size(); end++) {
        // Expand window by including current element
        // ... update window state ...
        
        // Contract window from left if certain condition is met
        while (condition_to_shrink_window) {
            // ... update window state ...
            start++;
        }
        
        // Process current window
        // ... your processing logic here ...
    }
    */
}

/*
8. WHEN TO USE QUEUE VS DEQUE VS OTHER DATA STRUCTURES
---------------------------------------------------
- Queue: When you only need to track the first element in window (FIFO)
- Deque: When you need to access both ends of window efficiently or maintain elements in order
- Hash Map: When you need to track frequencies or mappings within window
- Heap: When you need to maintain a sorted order of elements in window

9. TIME & SPACE COMPLEXITY
------------------------
- Time Complexity: Usually O(n) where n is array length
  - Each element is processed at most twice (once when entering, once when leaving)
  
- Space Complexity: Typically O(k) where k is window size
  - Queue/Deque usually stores at most k elements

10. TIPS FOR SOLVING SLIDING WINDOW PROBLEMS
-----------------------------------------
- Identify if problem involves subarrays/substrings with constraints
- Determine if window size is fixed or variable
- Choose appropriate data structure based on operations needed
- Carefully handle edge cases (empty arrays, k > array size, etc.)
- For variable windows, maintain meaningful state that can be updated efficiently
*/

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    
    cout << "Maximum in sliding window of size " << k << ": ";
    vector<int> maxResult = maxSlidingWindow(nums, k);
    for (int num : maxResult)
        cout << num << " ";
    cout << endl;
    
    cout << "First negative in sliding window of size " << k << ": ";
    vector<int> negResult = firstNegativeInWindow(nums, k);
    for (int num : negResult)
        cout << num << " ";
    cout << endl;
    
    return 0;
}