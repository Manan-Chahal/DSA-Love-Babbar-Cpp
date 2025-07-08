// N-Queens Problem (Leetcode 51)
// --------------------------------
/*
Problem Statement:
------------------
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.

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
};

// Test cases
int main() {
    Solution sol;
    int n1 = 4;
    cout << "N = 4 solutions:" << endl;
    vector<vector<string>> res1 = sol.solveNQueens(n1);
    for(const auto& board : res1) {
        for(const auto& row : board) {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }

    int n2 = 1;
    cout << "N = 1 solutions:" << endl;
    vector<vector<string>> res2 = sol.solveNQueens(n2);
    for(const auto& board : res2) {
        for(const auto& row : board) {
            cout << row << endl;
        }
        cout << "-----" << endl;
    }

    int n3 = 3;
    cout << "N = 3 solutions:" << endl;
    vector<vector<string>> res3 = sol.solveNQueens(n3);
    if(res3.empty()) cout << "No solution exists." << endl;
    else {
        for(const auto& board : res3) {
            for(const auto& row : board) {
                cout << row << endl;
            }
            cout << "-----" << endl;
        }
    }

    return 0;
}