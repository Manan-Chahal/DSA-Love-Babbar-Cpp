/*
Leetcode 240: Search a 2D Matrix II

Problem Statement:
------------------
Write an efficient algorithm that searches for a value target in an m x n integer matrix.
This matrix has the following properties:
- Integers in each row are sorted in ascending order from left to right.
- Integers in each column are sorted in ascending order from top to bottom.

Approach (Start from Top-Right Corner):
---------------------------------------
- Start from the top-right corner of the matrix.
- If the current element equals target, return true.
- If target is smaller than current element, move left (decrease column).
- If target is larger than current element, move down (increase row).
- Continue until target is found or we go out of bounds.

Time Complexity:
----------------
- O(m + n), where m is number of rows and n is number of columns.

Space Complexity:
-----------------
- O(1), only using constant extra space.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1; // Start from top-right corner
        
        while (i >= 0 and i < n and j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (target < matrix[i][j])
                j--; // Move left
            else
                i++; // Move down
        }
        return false;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1,  4,  7,  11, 15},
        {2,  5,  8,  12, 19},
        {3,  6,  9,  16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    cout << "Test Case 1:" << endl;
    cout << "Matrix 1, target = 5: " << (sol.searchMatrix(matrix1, 5) ? "Found" : "Not Found") << endl;
    cout << "Matrix 1, target = 14: " << (sol.searchMatrix(matrix1, 14) ? "Found" : "Not Found") << endl;
    cout << "Matrix 1, target = 20: " << (sol.searchMatrix(matrix1, 20) ? "Found" : "Not Found") << endl;
    
    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    cout << "\nTest Case 2:" << endl;
    cout << "Matrix 2, target = 11: " << (sol.searchMatrix(matrix2, 11) ? "Found" : "Not Found") << endl;
    cout << "Matrix 2, target = 13: " << (sol.searchMatrix(matrix2, 13) ? "Found" : "Not Found") << endl;
    cout << "Matrix 2, target = 26: " << (sol.searchMatrix(matrix2, 26) ? "Found" : "Not Found") << endl;
    
    // Test Case 3 - Single element
    vector<vector<int>> matrix3 = {{1}};
    
    cout << "\nTest Case 3:" << endl;
    cout << "Matrix 3, target = 1: " << (sol.searchMatrix(matrix3, 1) ? "Found" : "Not Found") << endl;
    cout << "Matrix 3, target = 2: " << (sol.searchMatrix(matrix3, 2) ? "Found" : "Not Found") << endl;
    
    return 0;
}

/*
Explanation:
------------
- Start from top-right corner (0, m-1).
- If current element equals target, return true.
- If target is smaller, move left (eliminate current column).
- If target is larger, move down (eliminate current row).
- This works because of the sorted property of the matrix.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/