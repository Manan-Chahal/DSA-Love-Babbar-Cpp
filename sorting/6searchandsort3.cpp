/*
    🔢 Problem: Divide Two Integers Without Using Division or Modulo Operators

    Given two integers — a dividend and a divisor — return the **quotient**
    after dividing the dividend by the divisor **without using** the '/' or '%' operators.

    The integer division should **truncate** toward zero, meaning:
    - If the result is 3.333, return 3.
    - If the result is -3.333, return -3.

    ❗ Constraints:
    - You may assume that the dividend and divisor are not zero.
    - Do not use multiplication, division, or mod operator directly (only inside helper function logic is okay if controlled).
    - Consider negative inputs and ensure proper sign handling.

    ✅ Examples:
    Input:  dividend = 10, divisor = 2       → Output: 5
    Input:  dividend = 10, divisor = 3       → Output: 3
    Input:  dividend = 10, divisor = -2      → Output: -5
*/

#include <iostream>
using namespace std;

int getQuotient(int dividend, int divisor) {
    int start = 0;
    int end = dividend;
    int mid = start + ((end - start) >> 1);
    int ans = -1;

    while (start <= end) {
        if ((divisor * mid) == dividend) {
            return mid;
        }
        if ((divisor * mid) < dividend) {
            // Store and move right to get closer to dividend
            ans = mid;
            start = mid + 1;
        } else {
            // Move to the left
            end = mid - 1;
        }
        mid = start + ((end - start) >> 1);
    }
    return ans;
}

int main() {
    int dividend = 10;
    int divisor = -2;

    // Step 1: Work with absolute values
    int absDividend = abs(dividend);
    int absDivisor = abs(divisor);

    // Step 2: Compute positive quotient using binary search
    int quotient = getQuotient(absDividend, absDivisor);

    // Step 3: Handle sign
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        quotient = -quotient;
    }

    // Final answer
    cout << "Quotient: " << quotient << endl;

    return 0;
}

