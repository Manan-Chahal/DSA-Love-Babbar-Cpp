#include <iostream>
#include <algorithm> // for std::fill
using namespace std;

// Function to sort an array of 0s and 1s
void sortZeroesAndOnes(int arr[], int n, int &count0, int &count1) {
    count0 = 0; // Initialize count of zeros
    count1 = 0; // Initialize count of ones

    // First pass: Count the number of 0s and 1s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count0++;
        } else {
            count1++;
        }
    }

    // Use std::fill to assign 0s and 1s based on the counts
    fill(arr, arr + count0, 0); // Fill the first count0 elements with 0
    fill(arr + count0, arr + n, 1); // Fill the rest with 1
}

int main() {
    int n;

    // Ask user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input elements of the array from the user
    cout << "Enter " << n << " elements (only 0s and 1s):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // Validate input (0s and 1s only)
        while (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input! Please enter 0 or 1: ";
            cin >> arr[i];
        }
    }

    int count0, count1;

    // Sort the array and count the 0s and 1s in O(n) time
    sortZeroesAndOnes(arr, n, count0, count1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the count of 0s and 1s
    cout << "Number of 0s: " << count0 << endl;
    cout << "Number of 1s: " << count1 << endl;

    return 0;
}
