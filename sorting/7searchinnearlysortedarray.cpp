#include <iostream>
using namespace std;

/*
    📌 Problem: Search in Nearly Sorted Array

    Given a sorted array arr[] of size N, some elements of the array are moved to either of the adjacent positions,
    i.e., arr[i] may be present at arr[i+1] or arr[i-1].
    The task is to search for an element in this array in O(log n) time.

    ✅ Input:
        - A nearly sorted array where each element can be at index i, i-1, or i+1.
        - An integer target.

    ✅ Output:
        - The index of the target if found, otherwise -1.

    🔍 Examples:

        Input: arr[] = {10, 3, 40, 20, 50, 80, 70}, target = 40
        Output: 2
        Explanation: 40 is present at index 2.

        Input: arr[] = {10, 3, 40, 20, 50, 80, 70}, target = 90
        Output: -1
        Explanation: 90 is not present in the array.
*/

// Function to perform binary search on a nearly sorted array
int applyBinarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        // Check mid, mid - 1, mid + 1
        if (arr[mid] == target)
            return mid;
        if (mid - 1 >= s && arr[mid - 1] == target)
            return mid - 1;
        if (mid + 1 <= e && arr[mid + 1] == target)
            return mid + 1;

        // Move search boundaries accordingly
        if (target > arr[mid])
        {
            // Search right, skipping mid and mid + 1
            s = mid + 2;
        }
        else
        {
            // Search left, skipping mid and mid - 1
            e = mid - 2;
        }
    }

    // Target not found
    return -1;
}

// Main function to test the code
int main()
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int size = 7;
    int target = 20;

    int ans = applyBinarySearch(arr, size, target);

    if (ans != -1)
        cout << "✅ Target found at index: " << ans << endl;
    else
        cout << "❌ Target not found in the array." << endl;

    return 0;
}
