// Problem287: Find the Duplicate Number
// You are given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

// Example 1:
// Input:
// nums = [1,3,4,2,2]

// Output:
// 2

// Example 2:
// Input:
// nums = [3,1,3,4,2]

// Output:
// 3

// Example 3:
// Input:
// nums = [3,3,3,3,3]

// Output:
// 3

// Constraints:
// 1 <= n <= 10^5
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.
// Follow-up:
// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity (O(n)) while using only constant extra space (O(1))?
#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <cmath>     // for std::abs

using namespace std;

class Solution
{
public:
    // Method 1: Using Sorting
    int findDuplicateSorting(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the array
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {                   // Check for adjacent duplicates
                return nums[i]; // Return the duplicate number
            }
        }
        return -1; // Should never reach here if the input is valid
    }

    // Method 2: Marking Visited Elements
    int findDuplicateMarking(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]); // Get the absolute value
            if (nums[index] < 0)
            {                 // Check if it has been visited
                return index; // Return the duplicate number
            }
            nums[index] *= -1; // Mark as visited by negating the value
        }
        return -1; // Should never reach here if the input is valid
    }

    // Method 3: Cycle Detection (Floyd's Tortoise and Hare)
    int findDuplicateCycleDetection(vector<int> &nums)
    {
        int tortoise = nums[0];
        int hare = nums[0];

        // Phase 1: Finding the intersection point
        do
        {
            tortoise = nums[tortoise]; // Move one step
            hare = nums[nums[hare]];   // Move two steps
        } while (tortoise != hare); // Keep moving until they meet

        // Phase 2: Find the entrance to the cycle
        tortoise = nums[0]; // Start from the beginning
        while (tortoise != hare)
        { // Move both pointers until they meet
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare; // or tortoise, both are the same at this point
    }
};

int main()
{
    Solution solution;

    // Example 1: Using Sorting
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Method 1: Using Sorting" << endl;
    cout << "Input: [1, 3, 4, 2, 2]" << endl;
    int result1 = solution.findDuplicateSorting(nums1);
    cout << "The duplicate number is: " << result1 << endl
         << endl;

    // Example 2: Marking Visited Elements
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Method 2: Marking Visited Elements" << endl;
    cout << "Input: [3, 1, 3, 4, 2]" << endl;
    int result2 = solution.findDuplicateMarking(nums2);
    cout << "The duplicate number is: " << result2 << endl
         << endl;

    // Example 3: Cycle Detection
    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << "Method 3: Cycle Detection" << endl;
    cout << "Input: [3, 3, 3, 3, 3]" << endl;
    int result3 = solution.findDuplicateCycleDetection(nums3);
    cout << "The duplicate number is: " << result3 << endl;

    return 0;
}
// explanation of the third approach i used in this code

// Let’s consider the input array:

// plaintext
// Copy code
// nums = [3, 1, 3, 4, 2]
// Initialization:

// Tortoise starts at nums[0] (3).
// Hare also starts at nums[0] (3).
// Finding the Intersection:

// We keep moving the tortoise one step and the hare two steps until they meet.

// Iteration 1:
// Tortoise moves to nums[tortoise], which is nums[3] (4).
// Hare moves to nums[nums[hare]], which is nums[3] (4).
// Current Position:
// Tortoise: 4 (nums[3])
// Hare: 4 (nums[3])
// Both pointers meet at 4.
// Finding the Entrance to the Cycle: Now that we have an intersection, we need to find the entrance to the cycle:

// Reset the tortoise to the beginning (index 0).

// Now, move both the tortoise and hare one step at a time until they meet again.

// Reset Tortoise:

// Tortoise starts at nums[0] (3).
// Hare remains at nums[4] (2).
// Iteration 1:

// Tortoise moves to nums[3] (4).
// Hare moves to nums[2] (3).
// Current Position:
// Tortoise: 4 (nums[3])
// Hare: 3 (nums[2])
// Iteration 2:

// Tortoise moves to nums[4] (2).
// Hare moves to nums[3] (4).
// Current Position:
// Tortoise: 2 (nums[4])
// Hare: 4 (nums[3])
// Iteration 3:

// Tortoise moves to nums[2] (3).
// Hare moves to nums[4] (2).
// Current Position:
// Tortoise: 3 (nums[2])
// Hare: 2 (nums[4])
// Iteration 4:

// Tortoise moves to nums[3] (4).
// Hare moves to nums[3] (4).
// Current Position:
// Tortoise: 4 (nums[3])
// Hare: 4 (nums[3])
// Both pointers meet again at 4.