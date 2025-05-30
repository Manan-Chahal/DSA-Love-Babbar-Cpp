#include <iostream>
#include <algorithm> // For std::fill
using namespace std;

// Function to demonstrate the use of std::fill
void fillArray(int arr[], int size, int value) {
    // Fill the array with the specified value
    std::fill(arr, arr + size, value);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    const int size = 10;
    int arr[size];

    // Fill the array with the value 5
    fillArray(arr, size, 5);
    
    // Print the filled array
    cout << "Array after filling with 5: ";
    printArray(arr, size);

    // Fill the array with the value 10
    fillArray(arr, size, 10);
    
    // Print the filled array
    cout << "Array after filling with 10: ";
    printArray(arr, size);

    return 0;
}
