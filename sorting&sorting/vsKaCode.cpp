#include <iostream>
using namespace std;

// Function to find the first occurrence of the target
void findFirstOccurrence(int arr[], int n, int target, int &ansIndex) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == target) {
            ansIndex = mid;  // Potential first occurrence
            e = mid - 1;     // Continue searching in the left half
        }
        else if (target > arr[mid]) {
            s = mid + 1;     // Target is in the right half
        }
        else {
            e = mid - 1;     // Target is in the left half
        }
        mid = s + (e - s) / 2;
    }
}

// Function to find the last occurrence of the target
void findLastOccurrence(int arr[], int n, int target, int &ansIndex)
//we are using reference variable here &andIndex
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == target) {
            ansIndex = mid;  // Potential last occurrence
            s = mid + 1;     // Continue searching in the right half
        }
        else if (target > arr[mid]) {
            s = mid + 1;     // Target is in the right half
        }
        else {
            e = mid - 1;     // Target is in the left half
        }
        mid = s + (e - s) / 2;
    }
}

int main() {
    // Input array and target
    int arr[] = {5, 10, 20, 20, 20, 20, 20, 30, 40, 50, 60};
    int n = 11; // Number of elements in the array
    int target = 20;

    // Finding first and last occurrences
    int firstOccIndex = -1, lastOccIndex = -1;

    // Call the functions
    findFirstOccurrence(arr, n, target, firstOccIndex);
    findLastOccurrence(arr, n, target, lastOccIndex);

    // Output results
    cout << "First occurrence of " << target << " is at index: " << firstOccIndex << endl;
    cout << "Last occurrence of " << target << " is at index: " << lastOccIndex << endl;

    return 0;
}
