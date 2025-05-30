#include <iostream>
#include <vector>
using namespace std;

bool search2DArray(vector<vector<int>> arr, int target) {
    int rowSize = arr.size();
    int colSize = arr[0].size();

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Initialize a 4x3 matrix with all elements as 0
    vector<vector<int>> arr(4, vector<int>(3, 0));
    int rowSize = arr.size();
    int colSize = arr[0].size();

    // Take input from the user to populate the matrix
    cout << "Enter 12 elements for a 4x3 matrix: " << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cin >> arr[i][j];  // Semicolon added here
        }
    }

    // Target value to search for
    int target = 40;

    // Search for the target value in the matrix
    bool ans = search2DArray(arr, target);
    
    // Print the result
    cout << "ans: " << (ans ? "true" : "false") << endl;

    return 0;
}
