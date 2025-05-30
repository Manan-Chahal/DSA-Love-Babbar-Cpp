#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findFirstOccurrence(const vector<int>& arr, int n, int target, int &ansIndex) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            cout << "FirstOccurrence -> s: " << s << ", e: " << e << ", mid: " << mid << ", ansIndex: " << ansIndex << endl;

            if (arr[mid] == target) {
                ansIndex = mid; // Store potential first occurrence
                e = mid - 1;    // Move left
            } else if (target > arr[mid]) {
                s = mid + 1;    // Move right
            } else {
                e = mid - 1;    // Move left
            }

            mid = s + (e - s) / 2; // Recalculate mid
        }
    }

    void findLastOccurrence(const vector<int>& arr, int n, int target, int &ansIndex) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            cout << "LastOccurrence -> s: " << s << ", e: " << e << ", mid: " << mid << ", ansIndex: " << ansIndex << endl;

            if (arr[mid] == target) {
                ansIndex = mid; // Store potential last occurrence
                s = mid + 1;    // Move right
            } else if (target > arr[mid]) {
                s = mid + 1;    // Move right
            } else {
                e = mid - 1;    // Move left
            }

            mid = s + (e - s) / 2; // Recalculate mid
        }
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();

        int firstOccIndex = -1;
        findFirstOccurrence(arr, n, target, firstOccIndex);

        int lastOccIndex = -1;
        findLastOccurrence(arr, n, target, lastOccIndex);

        vector<int> temp(2);
        temp[0] = firstOccIndex;
        temp[1] = lastOccIndex;
        return temp;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(arr, target);
    cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
