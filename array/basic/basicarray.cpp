#include <iostream>
#include <algorithm> // For std::fill
using namespace std;

// Function to fill an array with specific values
void fillArray(int arr[], int size) {
    fill(arr, arr + size / 2, 67);       // Fill first half with 67
    fill(arr + size / 2, arr + size, 100); // Fill second half with 100
}

// Function to reverse an array
void reverseArray(int arr[], int n) {
    int l = 0, h = n - 1;
    while (l < h) {
        // XOR swapping method
        arr[l] = arr[l] ^ arr[h];
        arr[h] = arr[h] ^ arr[l];
        arr[l] = arr[l] ^ arr[h];
        l++;
        h--;
    }
}

// Function to demonstrate different methods of swapping
void demonstrateSwap() {
    int a = 5, b = 6;

    // Using built-in swap function
    cout << "Before swap using built-in: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap using built-in: a = " << a << ", b = " << b << endl;

    // Using a temporary variable
    a = 5; b = 6; // Reset values
    cout << "Before swap using temp variable: a = " << a << ", b = " << b << endl;
    int temp = a; // Store value of a
    a = b;        // Assign value of b to a
    b = temp;    // Assign stored value to b
    cout << "After swap using temp variable: a = " << a << ", b = " << b << endl;

    // Using arithmetic method
    a = 5; b = 6; // Reset values
    cout << "Before swap using arithmetic: a = " << a << ", b = " << b << endl;
    a = a + b; // a becomes 11
    b = a - b; // b becomes 5
    a = a - b; // a becomes 6
    cout << "After swap using arithmetic: a = " << a << ", b = " << b << endl;

    // Using XOR method
    a = 5; b = 6; // Reset values
    cout << "Before swap using XOR: a = " << a << ", b = " << b << endl;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << "After swap using XOR: a = " << a << ", b = " << b << endl;
}

int main() {
    const int size = 10;
    int arr[size] = {1, 1, 1, 1, 1}; // Initialize an array with some values

    // Fill the array
    fillArray(arr, size);

    // Print filled array
    cout << "Filled array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << " --> " << arr[i] << endl;
    }

    // Reverse the array
    reverseArray(arr, size);
    
    // Print reversed array
    cout << "\nReversed array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    // Demonstrate various swap methods
    cout << "\nDemonstrating various swap methods:" << endl;
    demonstrateSwap();

    return 0;
}
