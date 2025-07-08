//---------- Maximal Square ----------
/*
Problem: Find the area of largest square containing only 1's in a binary matrix
- Each '1' is a cell that can be part of square
- Each '0' breaks potential squares
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution4 {
public: 
    // Recursive function to find largest square of 1's starting at (i, j)
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
        // Base case: Out of bounds
        if(i >= row || j >= col) {
            return 0;
        }

        // Recursively explore all three directions to form a square
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagonal = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        // If current cell is '1', try to form a square
        if(matrix[i][j] == '1') {
            // The size of square is 1 + minimum of squares in all three directions
            int ans = 1 + min(right, min(down, diagonal));
            // Update the maximum square size found so far
            maxi = max(maxi, ans);
            return ans;
        }
        else {
            // Current cell is '0', can't form a square here
            return 0;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;  // Tracks maximum square side length
        
        // Start recursion from every cell (to ensure all squares are checked)
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                solve(matrix, i, j, row, col, maxi);
            }
        }
        
        // Return area of largest square
        return maxi * maxi;
    }
};

// Example usage and test cases
int main() {
    Solution4 sol;
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Maximal square area (Expected 4): " << sol.maximalSquare(matrix1) << endl;

    vector<vector<char>> matrix2 = {
        {'0','1'},
        {'1','0'}
    };
    cout << "Maximal square area (Expected 1): " << sol.maximalSquare(matrix2) << endl;

    vector<vector<char>> matrix3 = {
        {'0'}
    };
    cout << "Maximal square area (Expected 0): " << sol.maximalSquare(matrix3) << endl;

    vector<vector<char>> matrix4 = {
        {'1','1','1','1'},
        {'1','1','1','1'},
        {'1','1','1','1'}
    };
    cout << "Maximal square area (Expected 9): " << sol.maximalSquare(matrix4) << endl;

    return 0;
}