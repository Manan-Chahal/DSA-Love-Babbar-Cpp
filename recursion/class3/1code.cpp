#include <iostream>
#include <vector>
using namespace std;

// Function to print all subsequences of a string
void printSubsequences(string str, int i, string output, vector<string> &ans) {
    // Base case: if we've considered all characters
    if (i == str.length()) {
        ans.push_back(output); // Add the current subsequence to the answer
        return;
    }
    char ch = str[i];
    // Include the current character
    printSubsequences(str, i + 1, output + ch, ans);
    // Exclude the current character
    printSubsequences(str, i + 1, output, ans);
}

// Function to check if an array is sorted in strictly increasing order
bool checkSorted(int arr[], int n, int index) {
    // Base case: single element is always sorted
    if (index == n - 1) {
        return true;
    }
    bool currAns = false;
    bool recursionKaAns = false;
    // Check if current element is less than next
    if (arr[index + 1] > arr[index]) {
        currAns = true;
    }
    // Recursively check the rest of the array
    recursionKaAns = checkSorted(arr, n, index + 1);

    return (currAns && recursionKaAns);
}

// Function to check if an array is sorted in strictly descending order
bool checkSortedDescending(int arr[], int n, int index) {
    // Base case: single element is always sorted
    if (index == n - 1) {
        return true;
    }
    bool currAns = false;
    bool recursionKaAns = false;
    // Check if current element is greater than next
    if (arr[index] > arr[index + 1]) {
        currAns = true;
    }
    // Recursively check the rest of the array
    recursionKaAns = checkSortedDescending(arr, n, index + 1);

    return (currAns && recursionKaAns);
}

int main() {
    // Test cases for printSubsequences
    string str = "abc";
    string output = "";
    int index = 0;

    vector<string> ans;
    printSubsequences(str, index, output, ans);
    cout << "Total subsequences: " << ans.size() << endl;
    for (auto i : ans) {
        cout << i << endl;
    }

    // Test cases for checkSortedDescending
    cout << "\nTesting checkSortedDescending:\n";

    int arr1[] = {9, 7, 5, 3, 1}; // strictly descending
    cout << "Test 1: {9, 7, 5, 3, 1} -> " << (checkSortedDescending(arr1, 5, 0) ? "True" : "False") << endl;

    int arr2[] = {10, 8, 8, 5, 2}; // not strictly descending (duplicate)
    cout << "Test 2: {10, 8, 8, 5, 2} -> " << (checkSortedDescending(arr2, 5, 0) ? "True" : "False") << endl;

    int arr3[] = {100}; // single element
    cout << "Test 3: {100} -> " << (checkSortedDescending(arr3, 1, 0) ? "True" : "False") << endl;

    int arr4[] = {5, 4, 3, 2, 1, 0, -1}; // strictly descending
    cout << "Test 4: {5, 4, 3, 2, 1, 0, -1} -> " << (checkSortedDescending(arr4, 7, 0) ? "True" : "False") << endl;

    int arr5[] = {3, 2, 4, 1}; // not descending
    cout << "Test 5: {3, 2, 4, 1} -> " << (checkSortedDescending(arr5, 4, 0) ? "True" : "False") << endl;

    return 0;
}