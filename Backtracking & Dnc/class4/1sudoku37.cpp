// Leetcode 37: Sudoku Solver
/*
Problem Statement:
------------------
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes.

Approach (Backtracking):
------------------------
- For every empty cell ('.'), try placing digits '1' to '9'.
- For each digit, check if it's safe to place (row, column, and 3x3 box must not already have that digit).
- If safe, place the digit and recursively solve the rest of the board.
- If the board can't be solved, backtrack (remove the digit and try the next one).
- When all cells are filled, the board is solved.

Time Complexity:
----------------
- In the worst case, O(9^(n*n)), since for each empty cell, we try 9 digits.
- But backtracking and constraints prune many branches, so it's much faster in practice.

Space Complexity:
-----------------
- O(1) extra space (apart from the board and recursion stack).
- The board is modified in-place.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check if it's safe to place 'digit' at (row, col)
    bool isSafe(char digit, int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        // Row check
        for(int k = 0; k < n; k++) {
            if(board[row][k] == digit) return false;
        }
        // Column check
        for(int k = 0; k < n; k++) {
            if(board[k][col] == digit) return false;
        }
        // 3x3 Sub-box check
        for(int k = 0; k < n; k++) {
            if(board[3*(row/3) + k/3][3*(col/3) + k%3] == digit) return false;
        }
        // If all checks pass, it's safe
        return true;
    }

    // Recursive function to solve the Sudoku board
    bool solve(vector<vector<char>>& board) {
        // Traverse the board to find an empty cell
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    // Try all digits from '1' to '9'
                    for(char digit = '1'; digit <= '9'; digit++) {
                        if(isSafe(digit, i, j, board)) {
                            board[i][j] = digit; // Place digit
                            // Recursively solve for the rest of the board
                            if(solve(board)) {
                                return true; // If solved, return true
                            } else {
                                // Backtrack: remove the digit and try next
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If no digit fits, return false (trigger backtracking)
                    return false;
                }
            }
        }
        // If no empty cell is left, the board is solved
        return true;
    }

    // Main function to solve Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// Utility function to print the Sudoku board
void printBoard(const vector<vector<char>>& board) {
    for(const auto& row : board) {
        for(char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Test cases
int main() {
    Solution sol;

    // Test Case 1: Standard Sudoku
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Original Sudoku Board (Test Case 1):" << endl;
    printBoard(board1);

    sol.solveSudoku(board1);

    cout << "Solved Sudoku Board (Test Case 1):" << endl;
    printBoard(board1);

    // Test Case 2: Already Solved Sudoku
    vector<vector<char>> board2 = {
        {'8','2','7','1','5','4','3','9','6'},
        {'9','6','5','3','2','7','1','4','8'},
        {'3','4','1','6','8','9','7','5','2'},
        {'5','9','3','4','6','8','2','7','1'},
        {'4','7','2','5','1','3','6','8','9'},
        {'6','1','8','9','7','2','4','3','5'},
        {'7','8','6','2','3','5','9','1','4'},
        {'1','5','4','7','9','6','8','2','3'},
        {'2','3','9','8','4','1','5','6','7'}
    };

    cout << "Original Sudoku Board (Test Case 2):" << endl;
    printBoard(board2);

    sol.solveSudoku(board2);

    cout << "Solved Sudoku Board (Test Case 2):" << endl;
    printBoard(board2);

    return 0;
}

/*
Explanation of the code:
------------------------
- isSafe: Checks if a digit can be placed at a given cell by checking the row, column, and 3x3 sub-box.
- solve: Recursively finds empty cells and tries all digits. If a digit fits, it places it and recurses. If the board can't be solved, it backtracks.
- solveSudoku: Entry point for solving the board.
- printBoard: Utility to print the board for visualization.
- main: Runs two test cases (one unsolved, one already solved) and prints the board before and after solving.

Time Complexity:
----------------
- In the worst case, O(9^(n*n)), since for each empty cell, we try 9 digits.
- But backtracking and constraints prune many branches, so it's much faster in practice.

Space Complexity:
-----------------
- O(1) extra space (apart from the board and recursion stack).
- The board is modified in-place.
*/