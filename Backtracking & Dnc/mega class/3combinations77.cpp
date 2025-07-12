/*
Leetcode 77: Combinations

Problem Statement:
------------------
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Example:
- Input: n = 4, k = 2
- Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

Approach (Your Backtracking Algorithm):
---------------------------------------
- Use recursion to generate all combinations.
- At each step, try all numbers from 'start' to 'n'.
- Add each number to current combination and recurse with k-1.
- When k becomes 0, we have a valid combination of size k.
- Backtrack by removing the last added number.

Time Complexity:
----------------
- O(C(n,k) * k), where C(n,k) is the binomial coefficient.

Space Complexity:
-----------------
- O(k) for recursion stack + O(C(n,k) * k) for storing all combinations.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive function to generate all combinations
    void solve(vector<vector<int>> &ans, vector<int> &curr, int k, int start, int n)
    {
        // Base case: if we've selected k numbers
        if (k == 0)
        {
            ans.push_back(curr);
            return;
        }

        // Try all numbers from start to n
        for (int i = start; i <= n; i++)
        {
            curr.push_back(i);           // Choose current number
            solve(ans, curr, k - 1, i + 1, n); // Recurse with k-1 and start from i+1
            curr.pop_back();             // Backtrack: remove current number
        }
    }

    // Main function to return all combinations
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, curr, k, 1, n);
        return ans;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test Case 1: n = 4, k = 2
    cout << "Test Case 1 (n = 4, k = 2):" << endl;
    vector<vector<int>> res1 = sol.combine(4, 2);
    for(const auto& combination : res1) {
        cout << "[";
        for(int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if(i < combination.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    // Test Case 2: n = 1, k = 1
    cout << "\nTest Case 2 (n = 1, k = 1):" << endl;
    vector<vector<int>> res2 = sol.combine(1, 1);
    for(const auto& combination : res2) {
        cout << "[";
        for(int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if(i < combination.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    // Test Case 3: n = 5, k = 3
    cout << "\nTest Case 3 (n = 5, k = 3):" << endl;
    vector<vector<int>> res3 = sol.combine(5, 3);
    for(const auto& combination : res3) {
        cout << "[";
        for(int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if(i < combination.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- solve: Recursively builds all combinations by trying each number from start to n.
- combine: Initializes and starts recursion.
- main: Runs three test cases and prints all combinations.

Time Complexity: O(C(n,k) * k)
Space Complexity: O(k) recursion + O(C(n,k) * k)
*/