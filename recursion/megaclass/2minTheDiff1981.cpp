#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

/*
    Problem: Given a matrix 'mat' where you must pick exactly one element from each row,
    find the minimum absolute difference between the sum of the chosen elements and a given target.

    Approach:
    - Use recursion to try every possible combination (pick one element from each row).
    - At each row, try all columns, add the value to the sum, and recurse to the next row.
    - When all rows are processed, update the minimum difference found so far.
    - This is a brute-force approach (no pruning or memoization).
*/

class Solution
{
public:
    // Recursive helper function to try all combinations
    void solve(vector<vector<int>> &mat, int &target, int sum, int row, int &mini)
    {
        // Base case: all rows processed
        if (row == mat.size())
        {
            mini = min(mini, abs(target - sum)); // update minimum difference
            return;
        }

        // Try picking each element in the current row
        for (int col = 0; col < mat[row].size(); col++)
        {
            solve(mat, target, sum + mat[row][col], row + 1, mini);
        }
    }

    // Main function to call the recursive helper
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int sum = 0, row = 0, mini = INT_MAX;
        solve(mat, target, sum, row, mini);
        return mini;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int target1 = 13;
    cout << "Test 1: " << sol.minimizeTheDifference(mat1, target1) << " (Expected: 0)" << endl;
    // Explanation: 2 + 4 + 7 = 13, so difference is 0.

    // Test Case 2
    vector<vector<int>> mat2 = {
        {1},
        {2},
        {3}};
    int target2 = 7;
    cout << "Test 2: " << sol.minimizeTheDifference(mat2, target2) << " (Expected: 1)" << endl;
    // Explanation: 1+2+3=6, difference is 1.

    // Test Case 3
    vector<vector<int>> mat3 = {
        {10, 20},
        {30, 40}};
    int target3 = 60;
    cout << "Test 3: " << sol.minimizeTheDifference(mat3, target3) << " (Expected: 10)" << endl;
    // Explanation: Closest sum is 50 (10+40 or 20+30), difference is 10.

    // Test Case 4
    vector<vector<int>> mat4 = {
        {5, 8, 6},
        {19, 7, 2},
        {3, 13, 1}};
    int target4 = 30;
    cout << "Test 4: " << sol.minimizeTheDifference(mat4, target4) << " (Expected: 0)" << endl;
    // Explanation: 8+19+3=30, difference is 0.

    // Test Case 5
    vector<vector<int>> mat5 = {
        {1, 2},
        {3, 4},
        {5, 6}};
    int target5 = 20;
    cout << "Test 5: " << sol.minimizeTheDifference(mat5, target5) << " (Expected: 7)" << endl;
    // Explanation: Max sum is 2+4+6=12, difference is 8. But 2+4+5=11, difference is 9, so 12 is closest.

    return 0;
}

/*
Time Complexity (TC):
---------------------
Let n = number of rows, m = number of columns per row.
- For each row, we try all m columns, so total combinations = m^n.
- For each combination, we do O(n) work (sum), but since we pass sum as a parameter, it's O(1) per call.
- So, TC = O(m^n), which is exponential and only feasible for small n (e.g., n <= 8~10).

Space Complexity (SC):
----------------------
- The recursion stack can go as deep as n (number of rows).
- So, SC = O(n) (ignoring input and output storage).

Explanation:
------------
- The solution tries every way to pick one element from each row.
- For each complete pick, it checks the absolute difference with the target and keeps track of the minimum.
- This is a brute-force solution, but it guarantees the correct answer for small input sizes.
*/