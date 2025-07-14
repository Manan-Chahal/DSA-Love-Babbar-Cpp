#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print subarrays using two pointers: start and end
void printSubarraysRecursively(const vector<int>& arr, int start, int end) {
    int n = arr.size();

    // Base case: when start reaches the end of the array
    if (start == n)
        return;

    // If end has reached the end of array, move start forward and reset end
    if (end == n) {
        printSubarraysRecursively(arr, start + 1, start + 1); // move to next start index
        return;
    }

    // Print current subarray from start to end
    cout << "[ ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    // Recursive call with same start, and end + 1
    printSubarraysRecursively(arr, start, end + 1);
}

int main() {
    vector<int> nums = {1, 2, 3}; // Sample vector

    // Initial call with start = 0 and end = 0
    printSubarraysRecursively(nums, 0, 0);

    return 0;
}
