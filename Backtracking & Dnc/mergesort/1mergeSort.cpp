#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays into a single sorted vector (not used in main, but good for learning)
/// This function merges two sorted arrays arr[] and brr[] into ans[]
// void mergeSortedArrays(int arr[], int sizeArr, int brr[], int sizeBrr, vector<int> &ans) {
//   int i = 0;
//   int j = 0;
//   // i -> arr; j -> brr
//   // Loop until either array is exhausted
//   while( i < sizeArr && j < sizeBrr) {
//     if(arr[i] < brr[j]) {
//       ans.push_back(arr[i]);
//       i++;
//     }
//     else {
//       ans.push_back(brr[j]);
//       j++;
//     }
//   }
//   // If elements remain in arr, add them
//   while(i < sizeArr) {
//     ans.push_back(arr[i]);
//     i++;
//   }
//   // If elements remain in brr, add them
//   while(j < sizeBrr) {
//     ans.push_back(brr[j]);
//     j++;
//   }
// }

// Function to merge two sorted halves of arr[] (from s to mid, and mid+1 to e)
void merge(int arr[], int s, int e, int mid) {
  // Calculate lengths of left and right subarrays
  int leftLength = mid - s + 1;
  int rightLength = e - mid;

  // Dynamically allocate arrays for left and right halves
  int *leftArr = new int[leftLength];
  int *rightArr = new int[rightLength];

  // Copy data to leftArr
  int index = s;
  for(int i = 0; i < leftLength; i++) {
    leftArr[i] = arr[index];
    index++;
  }
  // Copy data to rightArr
  index = mid + 1;
  for(int i = 0; i < rightLength; i++) {
    rightArr[i] = arr[index];
    index++;
  }

  // Merge the two sorted arrays back into arr[]
  int i = 0; // pointer for leftArr
  int j = 0; // pointer for rightArr
  int mainArrayIndex = s; // pointer for arr

  // Compare elements and merge
  while(i < leftLength && j < rightLength) {
    if(leftArr[i] < rightArr[j]) {
      arr[mainArrayIndex] = leftArr[i];
      i++;
    } else {
      arr[mainArrayIndex] = rightArr[j];
      j++;
    }
    mainArrayIndex++;
  }

  // If any elements remain in leftArr, copy them
  while(i < leftLength) {
    arr[mainArrayIndex] = leftArr[i];
    i++;
    mainArrayIndex++;
  }

  // If any elements remain in rightArr, copy them
  while(j < rightLength) {
    arr[mainArrayIndex] = rightArr[j];
    j++;
    mainArrayIndex++;
  }

  // Free dynamically allocated memory
  delete[] leftArr;
  delete[] rightArr;
}

// Recursive function to perform merge sort on arr[] from index s to e
void mergeSort(int arr[], int s, int e) {
  // Base case: if the array has one or zero elements, it's already sorted
  if(s >= e) {
    return;
  }
  // Find the middle index
  int mid = (s + e) / 2;
  // Recursively sort the left half
  mergeSort(arr, s, mid);
  // Recursively sort the right half
  mergeSort(arr, mid + 1, e);
  // Merge the two sorted halves
  merge(arr, s, e, mid);
}

int main() {
  // Example array to sort
  int arr[] = {10, 80, 110, 90, 50, 30, 40, 20};
  int size = 8;
  int s = 0;
  int e = size - 1;

  // Print array before sorting
  cout << "Before: " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Call mergeSort to sort the array
  mergeSort(arr, s, e);

  // Print array after sorting
  cout << "After: " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Uncomment below to test merging two sorted arrays
  /*
  int arr[] = {10,30,50,70};
  int sizeArr = 4;
  int brr[] = {20,40,60,80,90,100};
  int sizeBrr = 6;
  vector<int> ans;
  mergeSortedArrays(arr, sizeArr, brr, sizeBrr, ans);
  // Print merged array
  for(int num: ans) {
    cout << num << " ";
  }
  */

  return 0;
}

/*
EXPLANATION OF THE CODE:

1. mergeSortedArrays: (commented out, for learning)
   - Merges two sorted arrays into a single sorted vector using two pointers.

2. merge:
   - Merges two sorted halves of the array (from s to mid, and mid+1 to e).
   - Uses temporary arrays for left and right halves.
   - Merges them back into the original array in sorted order.

3. mergeSort:
   - Recursively divides the array into halves until each part has one element.
   - Then merges the sorted halves using the merge function.

4. main:
   - Demonstrates merge sort on an example array.
   - Prints the array before and after sorting.

TIME COMPLEXITY:
----------------
- Merge Sort divides the array log(n) times and merges n elements at each level.
- So, Time Complexity = O(n log n)

SPACE COMPLEXITY:
-----------------
- Uses O(n) extra space for temporary arrays during merging.
*/