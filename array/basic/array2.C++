#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1. Find Unique Number (XOR Method)
int findUniqueNumber(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// 2. Sort Array of Zeros and Ones
void sortZeroOne(int arr[], int n) {
    int zeroCount = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) zeroCount++;
    }
    fill(arr, arr + zeroCount, 0);
    fill(arr + zeroCount, arr + n, 1);
}

// 3. Print All Pairs in an Array
void printAllPairs(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
        }
    }
}

// 4. TwoSum (Brute Force) - Find Indices
vector<int> twoSum(int arr[], int n, int target) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

// 5. Print All Triplets in an Array
void printAllTriplets(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")" << endl;
                count++;
            }
        }
    }
    cout << "Total triplets: " << count << endl;
}

// 6. ThreeSum Problem (Brute Force)
void checkThreeSum(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == target) {
                    cout << "Triplet Found: " << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
                }
            }
        }
    }
}

// 7. Rotate Array by N Places
void rotateArray(int arr[], int size, int n) {
    n = n % size; // In case n is larger than array size
    if(n == 0) return;

    int temp[10000];
    int index = 0;

    // Step 1: Copy the last n elements into temp
    for(int i = size - n; i < size; i++) {
        temp[index++] = arr[i];
    }

    // Step 2: Shift the rest of the array to the right
    for(int i = size - 1; i >= n; i--) {
        arr[i] = arr[i - n];
    }

    // Step 3: Copy temp back to the start
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// 8. LeetCode-style Single Number (XOR Method)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

// 9. LeetCode-style TwoSum Problem (Find Indices)
vector<int> twoSumLeetCode(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    // Test 1: Find Unique Number
    int arr1[] = {1, 2, 3, 2, 1};
    int size1 = 5;
    cout << "Unique number is: " << findUniqueNumber(arr1, size1) << endl;

    // Test 2: Sort Zeros and Ones
    int arr2[] = {0, 1, 1, 0, 1, 0};
    int size2 = 6;
    sortZeroOne(arr2, size2);
    cout << "Sorted array (0s and 1s): ";
    for(int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Test 3: Print All Pairs
    int arr3[] = {1, 2, 3};
    int size3 = 3;
    cout << "All pairs:" << endl;
    printAllPairs(arr3, size3);

    // Test 4: TwoSum (Brute Force)
    int arr4[] = {2, 7, 11, 15};
    int size4 = 4;
    int target = 9;
    vector<int> result = twoSum(arr4, size4, target);
    if(!result.empty()) {
        cout << "TwoSum Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    // Test 5: Print All Triplets
    int arr5[] = {1, 2, 3};
    int size5 = 3;
    cout << "All triplets:" << endl;
    printAllTriplets(arr5, size5);

    // Test 6: Check ThreeSum
    int arr6[] = {1, 2, 3, 4, 5};
    int size6 = 5;
    int threeSumTarget = 9;
    cout << "ThreeSum triplets (target = " << threeSumTarget << "):" << endl;
    checkThreeSum(arr6, size6, threeSumTarget);

    // Test 7: Rotate Array
    int arr7[] = {10, 20, 30, 40, 50, 60};
    int size7 = 6;
    int rotateBy = 2;
    cout << "Before rotation: ";
    for(int i = 0; i < size7; i++) {
        cout << arr7[i] << " ";
    }
    cout << endl;
    rotateArray(arr7, size7, rotateBy);
    cout << "After rotation: ";
    for(int i = 0; i < size7; i++) {
        cout << arr7[i] << " ";
    }
    cout << endl;

    // Test 8: Single Number (LeetCode-style)
    vector<int> singleNumArr = {4, 1, 2, 1, 2};
    cout << "Single number (LeetCode-style): " << singleNumber(singleNumArr) << endl;

    // Test 9: TwoSum (LeetCode-style)
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSumLeetCode(nums2, target2);
    if(!result2.empty()) {
        cout << "TwoSum Indices (LeetCode-style): " << result2[0] << ", " << result2[1] << endl;
    } else {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}
