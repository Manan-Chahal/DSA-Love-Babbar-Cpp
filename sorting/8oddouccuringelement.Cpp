// You are given a sorted array of integers where every element appears exactly twice, except for one element which appears only once.

// Your task is to find that single element.
// The algorithm must run in O(log n) time and O(1) space.
#include <iostream>
#include <vector>
using namespace std;

// Function to find the single element in a sorted array
int singleNonDuplicate(vector<int>& arr) {
    int s = 0;
    int n = arr.size();
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        // Case 1: only one element left
        if (s == e) {
            return arr[s];
        }

        // Get current mid value
        int currVal = arr[mid];

        // Values at neighbors (if they exist)
        int leftVal = (mid - 1 >= 0) ? arr[mid - 1] : -1;
        int rightVal = (mid + 1 < n) ? arr[mid + 1] : -1;

        // Case 2: current is not equal to neighbors => it's the single element
        if (currVal != leftVal && currVal != rightVal) {
            return currVal;
        }

        // Case 3: match with left neighbor
        if (currVal == leftVal) {
            int pairStart = mid - 1;
            if (pairStart % 2 == 0) {
                // Single element lies to the right
                s = mid + 1;
            } else {
                // Single element lies to the left
                e = mid - 2;
            }
        }
        // Case 4: match with right neighbor
        else if (currVal == rightVal) {
            int pairStart = mid;
            if (pairStart % 2 == 0) {
                // Single element lies to the right
                s = mid + 2;
            } else {
                // Single element lies to the left
                e = mid - 1;
            }
        }

        mid = s + (e - s) / 2;
    }

    return -1; // shouldn't reach here
}

// Main function to test the code
int main() {
    vector<int> arr = {3, 3, 7, 7, 10, 11, 11};
    int result = singleNonDuplicate(arr);
    cout << "Single element is: " << result << endl;
    return 0;
}
