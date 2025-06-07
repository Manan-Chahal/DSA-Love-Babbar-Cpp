#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ---------------------- 1. Two's Complement of a Binary Number ----------------------
vector<int> find2sComplement(vector<int> binary) {
    int n = binary.size();
    vector<int> twosComp(n, 0);

    // Step 1: Flip all bits
    for (int i = 0; i < n; i++) {
        twosComp[i] = 1 - binary[i];
    }

    // Step 2: Add 1 to the flipped bits
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = twosComp[i] + carry;
        twosComp[i] = sum % 2;
        carry = sum / 2;
        if (carry == 0) break; // Optimization: Stop if carry is 0
    }

    return twosComp;
}

// ---------------------- 2. Maximum Subarray Sum (Kadane's Algorithm) ----------------------
class Solution1 {
public:
    int kadaneAlgo(vector<int> &nums) {
        int ans = INT_MIN, sum = 0;
        for (int num : nums) {
            sum += num;
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        return ans;
    }

    int maxSubArray(vector<int> &nums) {
        return kadaneAlgo(nums);
    }
};

// ---------------------- 3. Find Missing Element from Duplicated Array ----------------------
int findMissingElement(vector<int> &v) {
    v.insert(v.begin(), 737); // Inserting a dummy value at the beginning

    // Mark visited indices as negative
    for (int i = 1; i < v.size(); i++) {
        int index = abs(v[i]);
        if (index < v.size() && v[index] > 0) {
            v[index] *= -1;
        }
    }

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > 0) {
            return i;
        }
    }

    return -1;
}

// ---------------------- 4. Rotate a Matrix 90 Degrees Clockwise ----------------------
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// ---------------------- 5. Unordered Map Demonstration ----------------------
void demonstrateUnorderedMap() {
    unordered_map<int, int> desk_map;

    // Insertion
    desk_map[1] = 53;
    desk_map[2] = 54;
    desk_map[3] = 55;
    desk_map[2] = 57; // Overwriting key 2

    // Iteration
    cout << "Initial map entries:\n";
    for (auto it = desk_map.begin(); it != desk_map.end(); it++) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    // Finding a key
    if (desk_map.find(2) != desk_map.end()) {
        cout << "Found key 2 with value: " << desk_map[2] << endl;
    }

    // Deletion
    desk_map.erase(2);
    cout << "After erasing key 2:\n";
    for (auto it = desk_map.begin(); it != desk_map.end(); it++) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    // Finding again
    cout << "Find key 2 again: ";
    if (desk_map.find(2) != desk_map.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
}

// ---------------------- Main Function ----------------------
int main() {
    // 1. Two's Complement
    vector<int> binary = {0, 1, 1, 0, 1};
    vector<int> twosComp = find2sComplement(binary);
    cout << "Two's Complement: ";
    for (int bit : twosComp) cout << bit << " ";
    cout << endl;

    // 2. Kadane's Algorithm
    Solution1 sol1;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << sol1.maxSubArray(nums) << endl;

    // 3. Find Missing Element
    vector<int> arr = {1, 3, 5, 3, 4};
    cout << "Missing element: " << findMissingElement(arr) << endl;

    // 4. Rotate Matrix
    Solution2 sol2;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol2.rotate(matrix);
    cout << "Rotated Matrix:\n";
    for (auto row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    // 5. Unordered Map Demo
    demonstrateUnorderedMap();

    return 0;
}
