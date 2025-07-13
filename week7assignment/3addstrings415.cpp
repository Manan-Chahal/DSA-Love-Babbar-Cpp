#include <iostream>
#include <algorithm>
using namespace std;

/*
Leetcode 415: Add Strings

Problem Statement:
------------------
Given two non-negative integers num1 and num2 represented as strings, return the sum of num1 and num2 as a string.

Approach 1 (Recursive Digit Addition - Build Result via Append & Reverse):
-------------------------------------------------------------------------
- Add digits from the end of both strings, simulating manual addition.
- Use recursion to process each digit and carry.
- Build the result string by appending digits, then reverse at the end.

Approach 2 (Recursive Digit Addition - Build Result via Concatenation):
----------------------------------------------------------------------
- Add digits from the end of both strings, simulating manual addition.
- Use recursion to process each digit and carry.
- Build the result string from least significant to most significant digit by concatenation.

Time Complexity (Both):
-----------------------
- O(max(N, M)), where N and M are the lengths of num1 and num2.

Space Complexity (Both):
------------------------
- O(max(N, M)), due to recursion stack and result string.
*/

// Approach 1: Build result via append and reverse (your preferred approach)
class SolutionAppendReverse {
public:
    // Recursive helper function to add digits and build result via appending
    void addRE(string& num1, int p1, string& num2, int p2, int carry, string& ans) {
        // Base case: both numbers finished
        if (p1 < 0 && p2 < 0) {
            if (carry != 0) ans.push_back(carry + '0'); // Append last carry if exists
            return;
        }
        // Fetch digits from num1 and num2 or use '0' if out of bounds
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry; // current sum
        int digit = csum % 10;      // digit to store
        carry = csum / 10;          // new carry
        ans.push_back(digit + '0'); // Append current digit
        addRE(num1, p1 - 1, num2, p2 - 1, carry, ans); // Recursive call to next digits
    }

    // Main function to add two strings using append & reverse
    string addStrings(string num1, string num2) {
        string ans = ""; // Result string
        addRE(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans); // Start recursion
        reverse(ans.begin(), ans.end());  // Reverse to get correct order
        return ans;
    }
};

class Solution1 {
public:
    void addRE(string& num1, int p1, string& num2, int p2, int carry, string& ans) {
        if (p1 < 0 && p2 < 0) {
            if (carry != 0) ans.push_back(carry + '0');
            return;
        }
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        int digit = csum % 10;
        carry = csum / 10;
        ans.push_back(digit + '0');
        addRE(num1, p1 - 1, num2, p2 - 1, carry, ans);
    }

    string addStrings(string num1, string num2) {
        string ans = "";
        addRE(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Test cases for both approaches
int main() {
    SolutionAppendReverse sol1;
    Solution1 sol2;

    // Test Case 1
    cout << "Approach 1 (Append & Reverse): " << sol1.addStrings("11", "123") << endl;   // Output: 134
    cout << "Approach 2 (Concat): " << sol2.addStrings("11", "123") << endl;   // Output: 134

    // Test Case 2
    cout << "Approach 1 (Append & Reverse): " << sol1.addStrings("456", "77") << endl;   // Output: 533
    cout << "Approach 2 (Concat): " << sol2.addStrings("456", "77") << endl;   // Output: 533

    // Test Case 3
    cout << "Approach 1 (Append & Reverse): " << sol1.addStrings("0", "0") << endl;      // Output: 0
    cout << "Approach 2 (Concat): " << sol2.addStrings("0", "0") << endl;      // Output: 0

    // Test Case 4
    cout << "Approach 1 (Append & Reverse): " << sol1.addStrings("999", "1") << endl;    // Output: 1000
    cout << "Approach 2 (Concat): " << sol2.addStrings("999", "1") << endl;    // Output: 1000

    // Test Case 5
    cout << "Approach 1 (Append & Reverse): " << sol1.addStrings("123456789", "987654321") << endl; // Output: 1111111110
    cout << "Approach 2 (Concat): " << sol2.addStrings("123456789", "987654321") << endl; // Output: 1111111110

    return 0;
}

/*
Explanation:
------------
- addRE (Append & Reverse): Recursively adds digits from the end of both strings, handles carry, and builds the result by appending digits. Reverse at the end.
- addRE (Concat): Recursively adds digits and builds the result by concatenation.
- addStrings: Entry point for both approaches.
- main: Runs several test cases and prints results for both approaches.

Time Complexity: O(max(N, M))
Space Complexity: O(max(N, M))
*/