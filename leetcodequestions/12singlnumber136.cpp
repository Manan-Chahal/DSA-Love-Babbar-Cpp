#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Find the number which appears only once
        for (auto pair : freq) {
            if (pair.second == 1) {
                return pair.first;
            }
        }

        return -1; // This shouldn't happen as per constraints
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};

    cout << "Single number in [2,2,1]: " << sol.singleNumber(nums1) << endl;
    cout << "Single number in [4,1,2,1,2]: " << sol.singleNumber(nums2) << endl;
    cout << "Single number in [1]: " << sol.singleNumber(nums3) << endl;

    return 0;
}
