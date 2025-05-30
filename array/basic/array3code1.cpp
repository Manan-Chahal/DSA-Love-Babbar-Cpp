#include<iostream>
#include<climits>
using namespace std;

// Function to search for an element in a 2D array
bool search2DArray(int arr[][4], int rowSize, int colSize, int target) {
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            if(arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the minimum element in a 2D array
int findMinimumIn2DArray(int arr[][4], int rowSize, int colSize) {
    int minValue = INT_MAX;
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            minValue = min(arr[i][j], minValue);
        }
    }
    return minValue;
}

// Function to find the maximum element in a 2D array
int findMaximumIn2DArray(int arr[][4], int rowSize, int colSize) {
    int maxAns = INT_MIN;
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            maxAns = max(arr[i][j], maxAns);
        }
    }
    return maxAns;
}

// Function to print the sum of each row in a 2D array
void printRowSum(int arr[][4], int rowSize, int colSize) {
    for(int i=0; i<rowSize; i++) {
        int sum = 0;
        for(int j=0; j<colSize; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i << " sum: " << sum << endl;
    }
}

// Function to print the sum of each column in a 2D array
void printColumnSum(int arr[][4], int rowSize, int colSize) {
    for(int col=0; col<colSize; col++) {
        int sum = 0;
        for(int row=0; row<rowSize; row++) {
            sum += arr[row][col];
        }
        cout << "Column " << col << " sum: " << sum << endl;
    }
}

// Function to print the diagonal sum of a square matrix
void printDiagnolSum(int arr[][3], int rowSize, int colSize) {
    int sum = 0;
    for(int i=0; i<rowSize; i++) {
        sum += arr[i][i]; // Summing up the diagonal elements
    }
    cout << "Diagonal sum: " << sum << endl;
}

// Function to transpose a square matrix
void transposeMatrix(int arr[][3], int rowSize, int colSize) {
    for(int i=0; i<rowSize; i++) {
        for(int j=i; j<colSize; j++) {
            swap(arr[i][j], arr[j][i]); // Swap element arr[i][j] with arr[j][i]
        }
    }

    // Printing the transposed matrix
    cout << "Transposed matrix:" << endl;
    for(int i=0; i<rowSize; i++) {
        for(int j=0; j<colSize; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 2D array example (3x3 matrix)
    int arr[3][3] = {
                    {10, 11, 12},
                    {20, 21, 22},
                    {30, 31, 32}
                    };
    int rowSize = 3;
    int colSize = 3;

    // Step 1: Print the original matrix
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Step 2: Transpose the matrix and print it
    transposeMatrix(arr, rowSize, colSize);
    cout << endl;

    // Step 3: Print the row-wise sums
    cout << "Row-wise Sums:" << endl;
    // Convert 3x3 to 3x4 compatible function for demo
    int arr4[3][4] = {
                    {10, 11, 12, 0},
                    {20, 21, 22, 0},
                    {30, 31, 32, 0}
                    };
    printRowSum(arr4, 3, 4);
    cout << endl;

    // Step 4: Print the column-wise sums
    cout << "Column-wise Sums:" << endl;
    printColumnSum(arr4, 3, 4);
    cout << endl;

    // Step 5: Find and print the maximum value in the matrix
    int maxAns = findMaximumIn2DArray(arr4, 3, 4);
    cout << "Maximum value in the matrix: " << maxAns << endl;
    cout << endl;

    // Step 6: Find and print the minimum value in the matrix
    int minAns = findMinimumIn2DArray(arr4, 3, 4);
    cout << "Minimum value in the matrix: " << minAns << endl;
    cout << endl;

    // Step 7: Print diagonal sum of the matrix
    cout << "Diagonal Sum of the Matrix: ";
    printDiagnolSum(arr, rowSize, colSize);
    cout << endl;

    // Step 8: Search for an element in the matrix
    int target = 21; // Change target as needed
    bool found = search2DArray(arr4, 3, 4, target);
    cout << "Element " << target << (found ? " found." : " not found.") << endl;

    return 0;
}
