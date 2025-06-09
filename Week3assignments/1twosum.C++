// 1. Two Sum
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        
        // Iterate through the array to find the pair of numbers that add up to target
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    ans.push_back(i);  // Store the first index
                    ans.push_back(j);  // Store the second index
                    return ans;  // Return the result as soon as we find a match
                }
            }
        }
        return ans;  // Return empty answer (though the problem guarantees a solution)
    }
};

int main() {
    // Example 1:
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    
    Solution sol;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Indices: [" << result1[0] << ", " << result1[1] << "]" << endl;  // Output: [0, 1]

    // Example 2:
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Indices: [" << result2[0] << ", " << result2[1] << "]" << endl;  // Output: [1, 2]

    // Example 3:
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Indices: [" << result3[0] << ", " << result3[1] << "]" << endl;  // Output: [0, 1]

    return 0;
}
