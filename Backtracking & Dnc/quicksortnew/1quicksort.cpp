#include <iostream>
using namespace std;

class Solution {
public:
    // Function to perform QuickSort using your custom approach
    void quickSort(int arr[], int start, int end) {
        if (start >= end) return; // base case

        int pivot = end;      // use last element as pivot
        int i = start - 1;    // i starts from one less than start
        int j = start;        // j starts from start

        // Partition the array
        while (j < pivot) {
            if (arr[j] < arr[pivot]) {
                i++; // move i to right
                swap(arr[i], arr[j]); // swap current with smaller element
            }
            j++; // move to next element
        }

        // Place the pivot in its correct position
        swap(arr[i + 1], arr[pivot]);

        // Recursive calls on left and right of pivot
        quickSort(arr, start, i);
        quickSort(arr, i + 2, end);
    }
};

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    sol.quickSort(arr, 0, n - 1); // call quickSort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
