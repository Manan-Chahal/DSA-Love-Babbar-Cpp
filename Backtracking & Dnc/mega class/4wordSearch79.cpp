/*
Leetcode 79: Word Search

Problem Statement:
------------------
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:
- Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
- Output: true

Approach (Your Backtracking Algorithm):
---------------------------------------
- Try starting from each cell in the grid.
- For each starting position, use DFS with backtracking to find the word.
- Mark current cell as visited ('%') and explore all 4 directions.
- If word is found, return true; otherwise backtrack and try next possibility.
- Restore the cell value after backtracking.

Time Complexity:
----------------
- O(m * n * 4^L), where m and n are grid dimensions and L is word length.

Space Complexity:
-----------------
- O(L) for recursion stack depth.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &B, string &word, int row, int col, int i)
    {
        // Base case: all characters matched
        if (i == word.size()) 
            return true;

        // Boundary checks and character match check
        if (row < 0 || row >= B.size() || col < 0 || col >= B[0].size() || B[row][col] != word[i] || B[row][col] == '%')
            return false;

        // Current character matches, mark as visited
        char temp = B[row][col];
        B[row][col] = '%'; // Mark as visited

        // Explore all 4 directions
        bool found = solve(B, word, row + 1, col, i + 1)     // Down
                     || solve(B, word, row - 1, col, i + 1)  // Up
                     || solve(B, word, row, col + 1, i + 1)  // Right
                     || solve(B, word, row, col - 1, i + 1); // Left

        // Backtrack: restore the original character
        B[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        // Try starting from each cell
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (solve(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<char>> board1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    cout << "Test Case 1:" << endl;
    cout << "Board 1, word = 'ABCCED': " << (sol.exist(board1, "ABCCED") ? "Found" : "Not Found") << endl;
    cout << "Board 1, word = 'SEE': " << (sol.exist(board1, "SEE") ? "Found" : "Not Found") << endl;
    cout << "Board 1, word = 'ABCB': " << (sol.exist(board1, "ABCB") ? "Found" : "Not Found") << endl;
    
    // Test Case 2
    vector<vector<char>> board2 = {
        {'A','B'},
        {'C','D'}
    };
    
    cout << "\nTest Case 2:" << endl;
    cout << "Board 2, word = 'ABDC': " << (sol.exist(board2, "ABDC") ? "Found" : "Not Found") << endl;
    cout << "Board 2, word = 'AB': " << (sol.exist(board2, "AB") ? "Found" : "Not Found") << endl;
    
    // Test Case 3
    vector<vector<char>> board3 = {
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','B'},
        {'A','A','A','A','B','A'}
    };
    
    cout << "\nTest Case 3:" << endl;
    cout << "Board 3, word = 'AAAAAAAAAAAABB': " << (sol.exist(board3, "AAAAAAAAAAAABB") ? "Found" : "Not Found") << endl;
    
    return 0;
}

/*
Explanation:
------------
- solve: Uses DFS with backtracking to find the word starting from (row, col).
- exist: Tries starting the search from every cell in the grid.
- main: Runs multiple test cases to verify the solution.

Time Complexity: O(m * n * 4^L)
Space Complexity: O(L) for recursion stack depth
*/