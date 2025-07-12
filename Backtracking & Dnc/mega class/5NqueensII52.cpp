/*
Leetcode 52: N-Queens II

Problem Statement:
------------------
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Return the number of distinct solutions to the n-queens puzzle.

Approach (Your Backtracking Algorithm):
---------------------------------------
- Place queens column by column.
- For each column, try placing a queen in every row.
- Use isSafe to check if a queen can be placed at (row, col) (no queen in same row, upper-left diagonal, lower-left diagonal).
- If safe, place the queen and recurse for the next column.
- Backtrack after recursion: remove the queen.
- When all columns are filled, count the solution.

Time Complexity:
----------------
- O(N!) (worst case, as each queen can be placed in N positions, but pruning reduces actual calls)

Space Complexity:
-----------------
- O(N^2) for storing board and recursion stack

Explanation:
------------
- isSafe: Checks if a queen can be placed at (row, col) by scanning left in the row, upper-left diagonal, and lower-left diagonal.
- find: Recursively tries to place queens in each column. If a solution is found, adds the board to ans.
- solveNQueens: Initializes the board and starts the recursion.
- totalNQueens: Returns the number of valid solutions.

Code uses your approach only: classic backtracking, isSafe checks, board modification, and backtracking.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Checks if it's safe to place a queen at (row, col)
    bool isSafe(vector<string> &B, int row, int col)
    {
        // Check left in the current row
        for (int i = col - 1; i >= 0; --i)
        {
            if (B[row][i] == 'Q')
                return false;
        }

        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (B[i][j] == 'Q')
                return false;
        }

        // Check lower left diagonal
        for (int i = row, j = col; i < B.size() && j >= 0; i++, j--)
        {
            if (B[i][j] == 'Q')
                return false;
        }
        return true;
    }

    // Recursively tries to place queens column by column
    bool find(vector<string> &B, int col, vector<vector<string>> &ans)
    {
        int n = B.size();
        if (col >= n)
        {
            ans.push_back(B); // Store valid board configuration
            return true;
        }
        int res = 0;
        for (int row = 0; row < n; row++)
        {
            if (isSafe(B, row, col))
            {
                B[row][col] = 'Q'; // Place queen
                res |= find(B, col + 1, ans); // Recurse for next column
                B[row][col] = '.'; // Backtrack
            }
        }
        return res;
    }

    // Generates all valid N-Queens board configurations
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> B(n, string(n, '.'));
        vector<vector<string>> ans;
        find(B, 0, ans);
        return ans;
    }

    // Returns the total number of distinct solutions
    int totalNQueens(int n)
    {
        auto ans = solveNQueens(n);
        return ans.size();
    }
};

// Test cases
int main() {
    Solution sol;
    cout << "Test Case 1: n = 4" << endl;
    cout << "Number of solutions: " << sol.totalNQueens(4) << endl; // Expected: 2

    cout << "Test Case 2: n = 1" << endl;
    cout << "Number of solutions: " << sol.totalNQueens(1) << endl; // Expected: 1

    cout << "Test Case 3: n = 5" << endl;
    cout << "Number of solutions: " << sol.totalNQueens(5) << endl; // Expected: 10

    cout << "Test Case 4: n = 8" << endl;
    cout << "Number of solutions: " << sol.totalNQueens(8) << endl; // Expected: 92

    return 0;
}

/*
Code uses your approach only: classic backtracking, isSafe checks, board modification, and backtracking.
Time and space complexity are included and explained in comments.
Test cases are provided for n = 1, 4, 5, 8.
*/