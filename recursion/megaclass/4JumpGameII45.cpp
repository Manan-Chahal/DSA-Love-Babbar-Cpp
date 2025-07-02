#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    // Recursive helper to try all jump possibilities from index i
    void solve(vector<int> &nums, int i, int &ans, int step)
    {
        // If we've reached the last index, update answer with minimum steps
        if (i == nums.size() - 1)
        {
            ans = min(ans, step);
            return;
        }
        // If out of bounds, return
        if (i >= nums.size())
            return;
        // if(nums[i] == 0) return; // stuck at that index

        // Try all possible jumps from current index (from 1 to nums[i])
        for (int jump = 1; jump <= nums[i]; jump++)
            solve(nums, i + jump, ans, step + 1);
    }

    // Main function to find minimum jumps to reach end
    int jump(vector<int> &nums)
    {
        int ans = INT_MAX;
        solve(nums, 0, ans, 0);
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: {2, 3, 1, 1, 4} -> " << sol.jump(nums1) << " (Expected: 2)" << endl;

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test 2: {2, 3, 0, 1, 4} -> " << sol.jump(nums2) << " (Expected: 2)" << endl;

    vector<int> nums3 = {1, 1, 1, 1};
    cout << "Test 3: {1, 1, 1, 1} -> " << sol.jump(nums3) << " (Expected: 3)" << endl;

    vector<int> nums4 = {1, 2};
    cout << "Test 4: {1, 2} -> " << sol.jump(nums4) << " (Expected: 1)" << endl;

    vector<int> nums5 = {0};
    cout << "Test 5: {0} -> " << sol.jump(nums5) << " (Expected: 0)" << endl;

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
The recursion stack can go as deep as n (the length of nums), so O(n)
*/