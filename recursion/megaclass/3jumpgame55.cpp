#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive function to check if we can reach the last index from position i
    bool solve(vector<int> &nums, int i)
    {
        if (i == nums.size() - 1)
            return true; // reached the last index
        if (i >= nums.size())
            return false; // out of bounds
        // if(nums[i] == 0) return false; // stuck at that index

        bool reAns = false;
        for (int jump = 1; jump <= nums[i]; jump++)
            reAns = reAns || solve(nums, i + jump);

        return reAns;
    }

    bool canJump(vector<int> &nums)
    {
        return solve(nums, 0);
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: {2, 3, 1, 1, 4} -> " << (sol.canJump(nums1) ? "Can reach the end!" : "Cannot reach the end.") << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: {3, 2, 1, 0, 4} -> " << (sol.canJump(nums2) ? "Can reach the end!" : "Cannot reach the end.") << endl;

    vector<int> nums3 = {0};
    cout << "Test 3: {0} -> " << (sol.canJump(nums3) ? "Can reach the end!" : "Cannot reach the end.") << endl;

    vector<int> nums4 = {2, 0, 0};
    cout << "Test 4: {2, 0, 0} -> " << (sol.canJump(nums4) ? "Can reach the end!" : "Cannot reach the end.") << endl;

    vector<int> nums5 = {1, 2, 0, 1};
    cout << "Test 5: {1, 2, 0, 1} -> " << (sol.canJump(nums5) ? "Can reach the end!" : "Cannot reach the end.") << endl;

    return 0;
}

/*
Time Complexity:
----------------
This recursive solution tries every possible jump at every index.
For each index, up to nums[i] recursive calls are made.
In the worst case, the number of calls grows exponentially with the input size (O(n^n) in the worst case).

Space Complexity:
-----------------
The recursion stack can go as deep as n (the length of nums), so the space complexity is O(n) in the worst case due to the recursion stack.
*/