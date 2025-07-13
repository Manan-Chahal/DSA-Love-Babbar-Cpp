/*
Leetcode 52: N-Queens II

Problem Statement:
------------------
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Return the number of distinct solutions to the n-queens puzzle.

Approach (Your Optimized Backtracking with Hashmaps):
-----------------------------------------------------
- Place queens column by column.
- For each column, try placing a queen in every row.
- Use hashmaps to check if a row, lower diagonal, or upper diagonal is already occupied by a queen (for O(1) safety check).
- If safe, place the queen and recurse for the next column.
- Backtrack after recursion: remove the queen and update hashmaps.
- When all columns are filled, store the board configuration as a solution.

Time Complexity: O(N!) (worst case, as each queen can be placed in N positions, but pruning reduces actual calls)
Space Complexity: O(N^2) for storing all solutions and the board

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagnolCheck;
    unordered_map<int,bool> upperDiagnolCheck;

    // Store the current board configuration as a vector of strings
    void storeSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n ) {
        vector<string> tempAns;
        for(int i=0; i<n; i++) {
            string output = "";
            for(int j=0; j<n; j++) {
                output.push_back(board[i][j]);
            }
            tempAns.push_back(output);
        }
        ans.push_back(tempAns);
    }

    // Check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<vector<char>> &board) {
        // Check row, upper diagonal, and lower diagonal using hashmaps
        if(rowCheck[row] == true) return false;
        if(upperDiagnolCheck[row-col] == true) return false;
        if(lowerDiagnolCheck[row+col] == true) return false;
        return true;
    }

    // Recursive function to place queens column by column
    void solve(int n, vector<vector<char>> &board, vector<vector<string>> &ans, int col ) {
        // Base case: all queens are placed
        if(col >= n ) {
            storeSolution(ans, board, n);
            return;
        }
        // Try placing a queen in every row of the current column
        for(int row=0; row<n; row++) {
            if(isSafe(row,col,board)) {
                // Place queen
                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagnolCheck[row+col] = true;
                upperDiagnolCheck[row-col] = true;
                // Recurse for next column
                solve(n,board,ans,col+1);
                // Backtrack: remove queen and update hashmaps
                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagnolCheck[row+col] = false;
                upperDiagnolCheck[row-col] = false;
            }
        }
    }

    // Main function to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n,'.'));
        int col = 0;
        solve(n,board,ans,col);
        return ans;
    }

    // Function to return the total number of distinct solutions (for N-Queens II)
    int totalNQueens(int n)
    {
        auto ans = solveNQueens(n); // Get all valid solutions
        return ans.size(); // Return the count of solutions
    }
};

// Test cases
int main() {
    Solution sol;
    cout << "N-Queens II: Number of solutions for n = 4: " << sol.totalNQueens(4) << endl; // Expected: 2
    cout << "N-Queens II: Number of solutions for n = 1: " << sol.totalNQueens(1) << endl; // Expected: 1
    cout << "N-Queens II: Number of solutions for n = 5: " << sol.totalNQueens(5) << endl; // Expected: 10
    cout << "N-Queens II: Number of solutions for n = 8: " << sol.totalNQueens(8) << endl; // Expected: 92
    return 0;
}

/*
Code uses your approach only: optimized backtracking with hashmaps for row and diagonal checks.
Time and space complexity are included and explained in comments.
Test cases are provided for n = 1, 4, 5, 8.
*/