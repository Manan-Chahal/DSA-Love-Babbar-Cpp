#include <iostream>
#include <climits>  // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // Step 1: Initialize required variables
        int i = 0;                  // Iterator
        int sign = 1;               // Sign variable: 1 for positive, -1 for negative
        long long num = 0;          // Store number (long long to handle overflow safely)

        // Step 2: Skip leading whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 3: Check if sign exists
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 4: Read digits and convert to number
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 5: Check for overflow BEFORE adding digit
            if (num > (INT_MAX - digit) / 10) {
                // Overflow detected
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return static_cast<int>(sign * num);
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.myAtoi("42") << endl;              // Output: 42
    cout << sol.myAtoi("   -042") << endl;         // Output: -42
    cout << sol.myAtoi("1337c0d3") << endl;        // Output: 1337
    cout << sol.myAtoi("0-1") << endl;             // Output: 0
    cout << sol.myAtoi("words and 987") << endl;   // Output: 0
    cout << sol.myAtoi("-91283472332") << endl;    // Output: -2147483648 (INT_MIN)

    return 0;
}
