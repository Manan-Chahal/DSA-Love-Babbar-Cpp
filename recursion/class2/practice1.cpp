#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Function 1: Print all elements of the array using recursion
void printArray(int arr[], int size, int index) {
    // Base Case: Stop when index goes out of bounds
    if(index == size) {
        return;
    }

    // Process current element
    cout << arr[index] << " ";

    // Recur for the next element
    printArray(arr, size, index + 1);
}

// Function 2: Check if target element exists in array using recursion
bool searchInArray(int arr[], int size, int index, int target) {
    // Base Case: If index exceeds size, target not found
    if(index >= size) {
        return false;
    }

    // If element matches the target
    if(arr[index] == target) {
        return true;
    }

    // Otherwise, search in the remaining array
    return searchInArray(arr, size, index + 1, target);
}

// Function 3: Find the maximum element in array recursively
void maxInArray(int arr[], int size, int index, int &maxi) {
    // Base Case: When index goes beyond array size
    if(index == size) return;

    // Process current element
    maxi = max(maxi, arr[index]);

    // Recur for remaining elements
    maxInArray(arr, size, index + 1, maxi);
}

// Function 4: Find the minimum element in array recursively
void minInArray(int arr[], int size, int index, int &mini) {
    if(index == size) return;

    mini = min(mini, arr[index]);

    minInArray(arr, size, index + 1, mini);
}

// Function 5: Print all even numbers using recursion
void printAllEvens(int arr[], int size, int index) {
    if(index == size) return;

    if(arr[index] % 2 == 0) {
        cout << arr[index] << " ";
    }

    printAllEvens(arr, size, index + 1);
}

// Function 6: Store all odd numbers using recursion
void printAllOdds(int arr[], int size, int index, vector<int> &ans) {
    if(index == size) return;

    if(arr[index] % 2 != 0) {
        ans.push_back(arr[index]);
    }

    printAllOdds(arr, size, index + 1, ans);
}

// Main function to call each recursive function one by one
int main() {
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = 7;
    int index = 0;

    cout << "\n1. Printing Array: ";
    printArray(arr, size, index);

    cout << "\n\n2. Searching for 13: ";
    cout << (searchInArray(arr, size, index, 13) ? "Found" : "Not Found");

    cout << "\n\n3. Maximum Element: ";
    int maxi = INT_MIN;
    maxInArray(arr, size, index, maxi);
    cout << maxi;

    cout << "\n\n4. Minimum Element: ";
    int mini = INT_MAX;
    minInArray(arr, size, index, mini);
    cout << mini;

    cout << "\n\n5. Even Elements: ";
    printAllEvens(arr, size, index);

    cout << "\n\n6. Odd Elements: ";
    vector<int> oddNumbers;
    printAllOdds(arr, size, index, oddNumbers);
    for(int num : oddNumbers) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}
