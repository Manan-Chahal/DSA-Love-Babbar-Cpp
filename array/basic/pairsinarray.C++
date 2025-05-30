#include <iostream>
using namespace std;

void printAllPairs(int arr[], int n) {
    // Loop through each element to form pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Print the pair
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
        }
    }
}

int main() {
    int n;

    // Ask user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input elements of the array from the user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print all pairs
    cout << "All pairs in the array are:" << endl;
    printAllPairs(arr, n);

    return 0;
}
