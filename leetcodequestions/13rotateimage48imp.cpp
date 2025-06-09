#include <iostream>
#include <vector>
#include <algorithm> // for swap and reverse

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Size of the NxN matrix

        // Step 1: Transpose the matrix
        // Transpose means swapping matrix[i][j] with matrix[j][i] for i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]); // Swap across the diagonal
            }
        }

        // Step 2: Reverse each row
        // This mirrors the matrix horizontally to complete the rotation
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end()); // Reverse each row
        }
    }
};

int main() {
    Solution sol;

    // Example matrix (3x3)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the rotate function
    sol.rotate(matrix);

    // Output the rotated matrix
    cout << "Rotated Matrix by 90 degrees clockwise:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
