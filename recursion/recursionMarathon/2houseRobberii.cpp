#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive function to get max loot from s to e
    int solve(vector<int>& nums, int s, int e) {
        if (s > e) return 0;

        int option1 = nums[s] + solve(nums, s + 2, e);
        int option2 = solve(nums, s + 1, e);

        return max(option1, option2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int option1 = solve(nums, 0, n - 2); // exclude last house
        int option2 = solve(nums, 1, n - 1); // exclude first house

        return max(option1, option2);
    }
};
