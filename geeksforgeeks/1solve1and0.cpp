#include <iostream>
using namespace std;

void segregate0and1(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right)
            left++;
        while (arr[right] == 1 && left < right)
            right--;

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Utility to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Example usage
int main() {
    int arr[] = {0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    segregate0and1(arr, n);

    cout << "Modified array: ";
    printArray(arr, n);

    return 0;
}
