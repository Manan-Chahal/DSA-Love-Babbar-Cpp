#include <iostream>
using namespace std;

// ===============================
// Function 1: Print digits of a number using recursion
// e.g., input: 21478 -> output: 2 1 4 7 8
// ===============================
void printDigits(int n) {
    // Base case: when number reduces to 0, stop
    if (n == 0) {
        return;
    }

    // Recursive call to process the remaining digits (except the last one)
    printDigits(n / 10);  // Example: if n = 1234, this will recurse as 1234 → 123 → 12 → 1 → 0 (stop)

    // Process current digit (in reverse stack, so prints left to right)
    int digit = n % 10;   // Extract the last digit at this level
    cout << digit << " "; // Print the digit
}

// ===============================
// Function 2: Binary Search (Recursive version)
// Searches for target in sorted array using recursion
// ===============================
int binarySearchRecursive(int arr[], int start, int end, int target) {
    // Base case: if start > end, target not found
    if (start > end) {
        return -1;
    }

    // Calculate mid index
    int mid = (start + end) / 2;

    // If target found at mid
    if (arr[mid] == target) {
        return mid;
    }

    // If target is greater, search in right half
    if (target > arr[mid]) {
        return binarySearchRecursive(arr, mid + 1, end, target);
    }

    // Else search in left half
    return binarySearchRecursive(arr, start, mid - 1, target);
}

// ===============================
// Function 3: Binary Search (Iterative version)
// Uses loop instead of recursion to find target
// ===============================
int binarySearchIterative(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        // Calculate mid
        int mid = (start + end) / 2;

        // If found
        if (arr[mid] == target) {
            return mid;
        }
        // Go right
        else if (target > arr[mid]) {
            start = mid + 1;
        }
        // Go left
        else {
            end = mid - 1;
        }
    }

    // If not found
    return -1;
}

// ===============================
// Main Function to Run All Examples
// ===============================
int main() {
    // ----- Example 1: Print Digits -----
    cout << "Printing digits of number 21478: ";
    int num = 21478;
    printDigits(num);
    cout << endl;

    // ----- Example 2: Binary Search Recursive -----
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int target = 60;

    int recursiveAns = binarySearchRecursive(arr, 0, size - 1, target);
    cout << "Recursive Binary Search: Index of " << target << " is " << recursiveAns << endl;

    // ----- Example 3: Binary Search Iterative -----
    int iterativeAns = binarySearchIterative(arr, size, target);
    cout << "Iterative Binary Search: Index of " << target << " is " << iterativeAns << endl;

    return 0;
}
