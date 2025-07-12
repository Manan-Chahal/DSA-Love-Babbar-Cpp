/*
Leetcode 22: Generate Parentheses

Problem Statement:
------------------
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Approach (Your Backtracking Algorithm):
---------------------------------------
- Use recursion and backtracking to build all valid strings.
- At each step, you can add '(' if open < n.
- You can add ')' if close < open.
- When open + close == 2*n, add the current string to the answer.

Time Complexity:
----------------
- O(2^2n) in the worst case, but only valid combinations are generated (Catalan number: O(4^n / n^{1.5})).

Space Complexity:
-----------------
- O(n) recursion stack + O(number of valid combinations) for output.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Recursive function to generate all valid parentheses
    void solve(vector<string> &ans, string &out, int open, int close, int n)
    {
        // Base case: if we've used all parentheses
        if (open + close == 2 * n)
        {
            ans.push_back(out);
            return;
        }

        // Add '(' if we still have some left
        if (open < n)
        {
            out.push_back('(');
            solve(ans, out, open + 1, close, n);
            out.pop_back(); // backtracking
        }

        // Add ')' if it won't invalidate the sequence
        if (close < open)
        {
            out.push_back(')');
            solve(ans, out, open, close + 1, n);
            out.pop_back(); // backtracking
        }
    }

    // Main function to return all combinations
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string out;
        solve(ans, out, 0, 0, n);
        return ans;
    }
};

// Test cases
int main()
{
    Solution sol;
    int n1 = 3;
    cout << "Test Case 1 (n = 3):" << endl;
    vector<string> res1 = sol.generateParenthesis(n1);
    for (const string &s : res1)
        cout << s << " ";
    cout << endl;

    int n2 = 1;
    cout << "Test Case 2 (n = 1):" << endl;
    vector<string> res2 = sol.generateParenthesis(n2);
    for (const string &s : res2)
        cout << s << " ";
    cout << endl;

    int n3 = 4;
    cout << "Test Case 3 (n = 4):" << endl;
    vector<string> res3 = sol.generateParenthesis(n3);
    for (const string &s : res3)
        cout << s << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- solve: Recursively builds all valid parentheses strings using your backtracking logic.
- generateParenthesis: Initializes and starts recursion.
- main: Runs three test cases and prints all valid combinations.

Time Complexity: O(4^n / n^{1.5})
Space Complexity: O(n) recursion + O(Catalan(n))
*/