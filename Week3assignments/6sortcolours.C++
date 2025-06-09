#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {  // Passed by reference
        int zero = 0, one = 0, two = 0;

        // Count occurrences of 0, 1, and 2
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) one++;
            else if (nums[i] == 2) two++;
        }

        // Reset index i for updating the array
        int i = 0;

        // Write the sorted elements back to the array
        while (zero--) {
            nums[i++] = 0;
        }
        while (one--) {
            nums[i++] = 1;
        }
        while (two--) {
            nums[i++] = 2;
        }
    }
};

int main() {
    vector<int> myColors = {2, 0, 2, 1, 1, 0};  // Input array
    Solution sol;

    // Call the function to sort colors (modifies myColors in place)
    sol.sortColors(myColors);

    // Output the sorted array
    for (int color : myColors) {
        cout << color << " ";  // Output will be: 0 0 1 1 2 2
    }
    cout << endl;

    return 0;  // Indicating successful execution
}
