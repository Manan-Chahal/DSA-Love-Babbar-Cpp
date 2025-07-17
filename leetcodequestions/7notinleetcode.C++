// Problem : Move All Negative Numbers to the Left (Partition Problem)

// Time complexity= O(n);

#include <iostream>
using namespace std;

void moveAllNegToLeft(int* a, int n) {
    // Dutch National flag Algo.
    int l = 0, h = n - 1;
    while (l < h) {
        if (a[l] < 0) {
            l++;
        }
        else if (a[h] > 0) {
            h--;
        }
        else {
            swap(a[l], a[h]);
        }
    }
}
int main() {
    int arr[] = {-5, 3, -2, 4, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveAllNegToLeft(arr, n);

    // Print the rearranged array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
