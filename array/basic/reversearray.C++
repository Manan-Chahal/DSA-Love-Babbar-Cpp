#include <iostream>
using namespace std;

// Function to reverse an array
void reverseArray(int arr[], int n) {
    int left = 0;        // Start pointer
    int right = n - 1;  // End pointer

    while (left < right) {
        // Swap the elements
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move the pointers
        left++;
        right--;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    reverseArray(arr, n);

    cout << "Reversed array: ";
    printArray(arr, n);

    return 0;
}
