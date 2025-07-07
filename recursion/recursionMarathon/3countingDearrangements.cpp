//---------- Count Derangements ----------
/*
Problem Statement:
------------------
Count the number of ways to arrange n elements such that no element appears in its original position.
A derangement is a permutation where no element appears in its original position.
For example, with n=3 elements [1,2,3], valid derangements are [2,3,1] and [3,1,2].

Approach:
---------
- Use recursion with the following relation:
    D(n) = (n-1) * (D(n-1) + D(n-2))
- Base cases:
    D(1) = 0 (no derangement possible for 1 element)
    D(2) = 1 (only one derangement for 2 elements: swap them)
*/

#include <iostream>
using namespace std;

int solve(int n) {
    // Base cases
    if(n == 1) {
        return 0;  // With 1 element, no derangement is possible
    }
    if(n == 2) {
        return 1;  // With 2 elements, only one derangement is possible
    }

    // Recurrence relation: D(n) = (n-1) * (D(n-1) + D(n-2))
    int ans = (n-1) * (solve(n-1) + solve(n-2));
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of derangements for n = " << n << " is: " << solve(n) << endl;

    // Test cases
    cout << "Test n=1: " << solve(1) << " (Expected: 0)" << endl;
    cout << "Test n=2: " << solve(2) << " (Expected: 1)" << endl;
    cout << "Test n=3: " << solve(3) << " (Expected: 2)" << endl;
    cout << "Test n=4: " << solve(4) << " (Expected: 9)" << endl;
    cout << "Test n=5: " << solve(5) << " (Expected: 44)" << endl;

    return 0;
}

