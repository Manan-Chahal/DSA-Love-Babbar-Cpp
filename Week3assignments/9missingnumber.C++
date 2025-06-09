#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void findmissing(int *a, int n) {
    // Loop to mark indices
    for (int i = 0; i < n; i++) {
        int index = abs(a[i]);
        if (index <= n && a[index - 1] > 0) { // Ensure within bounds
            a[index - 1] *= -1;
        }
    }

    // Loop to find missing elements
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) { // Positive means missing
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}
// second method ;
void findmissing2(int *a, int n) {
    // Place elements in their correct positions
    for (int i = 0; i < n; ) 
    {
        if (a[i] > 0 && a[i] <= n && a[i] != a[a[i] - 1]) {
            swap(a[i], a[a[i] - 1]); // Swap to place a[i] at the correct index
        } else {
            i++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) { // Positive means missing
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}

int main() {
    int a[] = {1,3,5,3,4}; // Example with missing number 5
    int n = sizeof(a) / sizeof(int);
    findmissing2(a, n);
    return 0;
}
