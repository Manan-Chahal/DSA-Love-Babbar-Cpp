#include <iostream>
#include <limits.h>
using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
    for (int index = 0; index < size; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;
}

// Basic Input/Output
void basicIO() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl;
}

// Array Manipulation
void arrayManipulation() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    printArray(arr, 5);
}

// Function for addition
int add(int a, int b) {
    return a + b;
}

// Control Structures
void controlStructures() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0) {
        cout << "Positive number" << endl;
    } else if (num < 0) {
        cout << "Negative number" << endl;
    } else {
        cout << "Zero" << endl;
    }
}

// Find Maximum in an Array
int findMax(int arr[], int size) {
    int maxVal = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Simple Search in Array
bool findTarget(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// Print Zeroes and Ones Count
void countZeroesAndOnes(int arr[], int size) {
    int zeroCount = 0, oneCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) zeroCount++;
        if (arr[i] == 1) oneCount++;
    }
    cout << "Zeroes: " << zeroCount << ", Ones: " << oneCount << endl;
}

// Extreme Print Using Two Pointers
void extremePrint(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            cout << arr[i] << " ";
        } else {
            cout << arr[i] << " " << arr[j] << " ";
        }
        i++;
        j--;
    }
    cout << endl;
}

// Main Function
int main() {
    // Basic I/O
    basicIO();
    
    // Array Manipulation
    arrayManipulation();

    // Control Structures
    controlStructures();

    // Find Maximum
    int arr1[] = {1, 2, 3, 4, 5};
    cout << "Max: " << findMax(arr1, 5) << endl;

    // Find Target
    int target = 3;
    cout << "Target found: " << findTarget(arr1, 5, target) << endl;

    // Count Zeroes and Ones
    int arr2[] = {0, 1, 0, 1, 1};
    countZeroesAndOnes(arr2, 5);

    // Extreme Print
    int arr3[] = {10, 20, 30, 40, 50, 60, 70};
    cout << "Extreme Print: ";
    extremePrint(arr3, 7);

    return 0;
}
