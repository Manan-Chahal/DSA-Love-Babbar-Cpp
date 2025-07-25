#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        // Use a set to automatically get all the unique numbers from the input.
        std::unordered_set<int> unique_nums(nums.begin(), nums.end());

        int positive_sum = 0;
        bool has_positive = false;

        // Iterate through the unique numbers and sum up only the positive ones.
        for (int num : unique_nums) {
            if (num > 0) {
                positive_sum += num;
                has_positive = true;
            }
        }

        // If there was at least one positive number, the answer is the sum
        // of all unique positive numbers.
        if (has_positive) {
            return positive_sum;
        } else {
            // If there were no positive numbers, the best possible score comes
            // from picking the single largest element from the original array.
            return *std::max_element(nums.begin(), nums.end());
        }
    }
};